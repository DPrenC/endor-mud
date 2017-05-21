/****************************************************************************
Fichero: minero_base.c
Autor: Riberales
Creación: 28/10/05
Descripción: el base de los mineros.
****************************************************************************/

#include "path.h"
#include <properties.h>


inherit PNJ_MINAS("pnj_base");


string descripcion_larga();
int NoEsEnemigo();
object victima;




create()
{
    ::create();
    seteuid(getuid());

    SetShort("un minero enano");

    SetWhimpy(30);
    SetIds(({"minero","minero enano","enano","pnj_minas"}));
    SetAggressive(2);
    SetFriendFunction(SF(NoEsEnemigo));
    SetScreamHealth(100); // grita siempre que lucha


    InitChats(4,({
              "El enano silba mientras busca algún buen sitio para picar.\n",
              "El minero enano examina las paredes de la zona buscando una "
              "buena pieza para picar.\n","El enano murmura... Hum... si "
              "encontrase un buen pedazo de mithril...\n","El minero se pone "
              "a picar.\n"}));

}


string descripcion_larga()
{
    string generico = "Se trata de un enano bastante fornido. Sus brazos y "
                      "espalda demuestran que pasa gran parte del día en las "
                      "minas. ";

    if (TP->QueryRace() != "enano")
    {
        return generico + "Te mira de manera inquisidora, pues estas minas "
               "sólo pueden ser explotadas por su pueblo. Mejor no intentar "
               "extraer mineral en su presencia.\n";
    }
    return generico + "Te mira y hace una reverencia muy típica entre los de "
           "vuestra raza.\n";
}


//Funciones de defensa y ataque.

int NoEsEnemigo(object victima)
{
    object *pico;
    //if (victima->QueryRace() == "enano") return 1;
    if (!sizeof(pico = (filter(victima->QueryWeapons(),(:CanSeeObject($1) && $1->id("pico"):)))))
    {
        return 1;
    }

    command_me("gritar ¡Guardia! ¡Guardia!");

    return 1;
}

void catch_tell(string  str)
{
    object *pico;
    string quien,que;

    if (sscanf(str,"%s empuña %s",quien,que) == 2)
    {
    if (   quien != TP->QueryName() || !CanSeeObject(TP)
        || TP->QueryRace() == "enano")
    {
        return ::catch_tell(str);
    }

    pico = filter(TP->QueryWeapons(),(:CanSeeObject($1) && $1->id("pico"):));

        if (sizeof (pico) < 1) return catch_tell(str);
    command_me("gritar ¡Guardia! ¡Guardia!");

    }
    return ::catch_tell(str);
}

