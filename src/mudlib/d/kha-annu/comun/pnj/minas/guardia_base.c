/****************************************************************************
Fichero: guardia_Base.c
Autor: Riberales
Fecha: 04/02/2006
Descripción: El base de los guardianes mineros.
****************************************************************************/


#include "path.h"
#include <combat.h>
#include <properties.h>
#include <moving.h>
#include <messages.h>


inherit  PNJ_MINAS("pnj_base");

private int is_jefe, is_capitan;

public int QueryJefePlanta() { return is_jefe; }
public int SetJefePlanta(int i) { return is_jefe = i; }
public int QueryCapitanMinas() { return is_capitan; }
public int SetCapitanMinas(int i) { return is_capitan = i; }

int NoEsEnemigo(object victima)
{
    object *pico;
    //if (victima->QueryRace() == "enano") return 1;
    if (!sizeof(pico = (filter(victima->QueryWeapons(),(:CanSeeObject($1) && $1->id("pico"):)))))
    {
        return 1;
    }

    tell_object(victima,"El guardián te grita: ¿Cómo se te ocurre intentar picar "
                        "en nuestras minas?\n");
    tell_room(environment(victima),"Un guardián enano le grita a " +CAP(victima
              ->QueryName())+ ": Eh, " +victima->QueryRace()+ ", ¿cómo se "
              "te ocurre intentar picar en nuestras minas?\n",({victima}));

    return 0;
}

void CompruebaPeleas() //Esto es una chapuza, revisar
{
    object *inv, *enemigos = ({}), env;
    if (!(env = environment())) return;
    filter(all_inventory(env),(:($1->QueryPnjMinasKhaAnnu() && $1 != TO?
                                 ($2 += $1->QueryEnemies() || ({})) : 0):),
           &enemigos);
    // agregamos los enemies
    AddEnemies(enemigos);
}


public varargs int move(mixed dest, int method, mixed extra)
{
    int res = ::move(dest, method, extra);
    CompruebaPeleas();
    return res;
}

/* funciones para moverse cuando un enano grita en otra habitación pidiendo ayuda */

void CheckScream(string str)
// chequea si un string pasado por el catch_tell, es un grito
// y comprueba dirección para intentar moverse hasta ella.
{
    string direccion, *direcciones, *total = ({});
    int i;

    if (Fighting() || !TP ||!TP->QueryPnjMinasKhaAnnu() || present(TP, environment())) return;
    if (   sscanf(str, "Alguien grita desde %s, ", direccion) == 1
        || sscanf(str, "Alguien grita desde %s: ", direccion) == 1
        || sscanf(str, "Alguien grita muy fuerte desde %s, ", direccion) == 1
        || sscanf(str, "Alguien grita muy fuerte desde %s.", direccion) == 1)
    {
        if (direccion[..1] == "el") direccion = direccion[3..];
        direcciones = explode(direccion, " y ");

        // recorremos las direcciones, y si son compuestas, las añadimos
        // desglosadas en el array de total
        for (i = sizeof(direcciones);i--;)
        {
            switch(direcciones[i])
            {
                case "nordeste":
                     total += ({"norte", "este"});
                     break;
                case "noroeste":
                     total += ({"norte", "oeste"});
                     break;
                case "sudeste":
                     total += ({"sur", "este"});
                     break;
                case "suroeste":
                     total += ({"sur", "oeste"});
                     break;
                default: total += ({direcciones[i]});
            }
        }

        // añadimos las direcciones tal cual a total, por si hay salidas de ese tipo
        total += direcciones;

        // Si son el jefe o los capitanes de la entrada, hacemos que se
        // queden quietos.
        if (QueryJefePlanta()) return ;
        if (QueryCapitanMinas())
        {
            object jefe;
            if ((jefe = present("jefe_planta")) && living(jefe))
            {
                tell_room(environment(),"Romli dice: Hum, no podemos dejar la "
                                        "entrada libre, que acudan los "
                                        "guardias.\n");
            }
            return ;
        }


        // una vez tenemos todas las direcciones, intentamos movernos a alguna de ellas
        call_out("acudir", 1, total);
    }
}

// se le pasa un array de direcciones posibles de donde proviene el grito, a las
// que intentará moverse.
public void acudir (string *total)
{
    string *salidas;
    int i;

    tell_room(environment(), ({MSG_SEE,
              (QueryName() || QueryShort()) + " escucha con atención.\n"}));
    salidas = m_indices(environment()->QueryExits());
    for (i=sizeof(total);i--;)
    {
        if (member(salidas, total[i]) >= 0)
        {
            command_me(total[i]);
            break;
        }
    }
}

/* funciones para controlar si un player empuña un pico de forma ilegal, y también
   el grito de los enanos de habitaciones colindantes */


void catch_tell(string  str)
{
    object *pico;
    string quien,que;

    // comprobamos si es un grito
    CheckScream(str);

    if (sscanf(str,"%s empuña %s",quien,que) == 2)
    {

        if (   quien != TP->QueryName() || !CanSeeObject(TP)
            || TP->QueryRace() == "enano")
        {
            return ::catch_tell(str);
        }

        if (sizeof ((pico = filter(TP->QueryWeapons(),(:CanSeeObject($1) && $1->id("pico"):)))) > 0)
        {
            call_out("no_empunyar",1);
        }
    }
    return ::catch_tell(str);
}

void no_empunyar()
{


    object *pico =  filter(TP->QueryWeapons(),(:CanSeeObject($1) && $1->id("pico"):));
    if (!present(TP,environment())) return ;

    if (!sizeof (pico)) return ;

    tell_object(TP,"Un guardián minero te grita: Eh,"+TP->QueryRace()+ ", ¿qué"
                   " pretendes empuñando "+ (sizeof(pico) > 1 ? "esos malditos "
                   "picos" : "ese maldito pico")+ "?\n");
    tell_room(environment(),"Un guardián reprende a "+CAP(TNAME)+" por empuñar "
                            "un pico.\n",({TP}));
    TO->Kill(TP);
    return ;
}





create()
{
    ::create();
    seteuid(getuid());

    SetGoChance(85);
    SetIds(({"guardia","guardián","guardian","guardia enano",
             "guardia enano","guardián enano","guardian_minas","pnj_minas"}));

    SetAggressive(2);
    SetFriendFunction(SF(NoEsEnemigo));
    SetScreamHealth(49); // cuando le quede menos de un 50% de vida, pide ayuda

}


public void VenirAqui()
{
    if (Fighting()) return ;
    move(PO,M_SPECIAL,({"se va corriendo","llega corriendo"}));
    return ;
}


