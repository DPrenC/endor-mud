/**************************************************************************
fichero: enano_borracho.c
Autor: kastwey
		[T] Tagoras
Creaci�n: 20/07/2005
Descripci�n: Un enano borracho para la taberna
[T] 23/03/2009: A�ado sonidos
**************************************************************************/

#include "path.h"
#include <guild.h>
#include <properties.h>
#include <moving.h>
#include <sounds.h>

inherit NPC;

int pDormido;
object env;

string armar_juerga();

public int QueryDormido() { return pDormido; }
public void create()
{
    if (::create()) return;
    seteuid(getuid());
    SetStandard("un enano borracho","enano",([GC_LUCHADOR:25 + random(6)]),
                GENDER_MALE);
    SetLong(W("Es un enano del Centro de Adiestramiento de Guerreros que "
              "parece estar desinhibi�ndose un poco del duro trabajo. No para "
              "de re�rse injustificadamente y de cantar lo primero que se "
              "le pasa por la cabeza. Lleva el casco reglamentario del "
              "Centro un poco torcido, pero aun as�, piensas que es "
              "feliz.\n"));
    AddId(({"borracho","enano borracho","enano_borracho"}));
    AddItem(BEB_ANNUFAM("ciudad/jarra_cerveza"),REFRESH_REMOVE,1);
    AddItem(PROT_CENTRO_ANNUFAM("casco_guerrero"),REFRESH_REMOVE,1);
    InitChats(5,({#'armar_juerga}));
    SetAlcohol(10);
}



string mostrar_mensaje(string fichero)
{
    string *lineas;
    string contenido;
    if (!fichero) return "";
    if (file_size(fichero) < 0)
    // el archivo no existe
    {
        return "";
    }
    contenido = read_file(fichero);
    lineas = explode(contenido,"\n");
    return lineas[random(sizeof(lineas))] + "\n";
}


string armar_juerga()
{
    object jarra;
    int alcohol, total, nuevo;
    if (pDormido)
    // Est� durmiendo la pea
    {
        if (QueryAlcohol() < QueryMaxAlcohol() / 2)
        // si ya ha metabolizado m�s de la mitad de su capacidad de alcohol...
        // lo despertamos
        {
            pDormido = 0;
            Set(P_CANT_FIGHT,0);
            Set(P_CANT_STEAL,0);
            return W("Un enano levanta la cabeza de la mesa en la que "
                     "permanec�a dormido y dice con poca convicci�n:\n"
                     "�" + (env->KeeperName() || "taberneerooo") + "! Dame "
                     "otda cedveza que etoy depeeedmizo! �Hip!\n");
        }
		play_sound(environment(), SND_SUCESOS("ronquido1"));
        return "Un enano ronca sonoramente: wruaaaaaaaaaaag!\n";
    }

    // sigue despierto.
    // si no tiene nada de alcohol, le regalamos otra jarra de cerveza
    // si no tiene ya otra jarra, claro
    if (!QueryAlcohol() && !present("jarra_cerveza",TO))
    {
        AddItem(BEB_ANNUFAM("ciudad/jarra_cerveza"),REFRESH_DESTRUCT,1);
    }
    // comprobamos si tiene alcohol suficiente para dormirlo
    if (QueryAlcohol() >= QueryMaxAlcohol() - 20)
    // est� hasta los topes.
    // a dormir la pea.
    {
        //Set(P_CANT_FIGHT,W("�No te da nada por el cuerpo atacar a un pobre borracho inconsciente?\n"));
		Set(P_CANT_FIGHT, 1);
        Set(P_CANT_STEAL,W("No te da verg�enza robar a un enano borracho e inconsciente?\n"));
        pDormido = 1;
        return W("Un enano farfulla algo ininteligible mientras observas "
                 "como su cabeza desciende hasta caer en la mesa con un sonoro: �Clonch!\n"
                 "Inmediatamente, el enano comienza a roncar ruidosamente.\n");
    }

    // sigue despierto y con ganas de juerga
    if (random(10) > 6)
    // por poner algo :P
    // un traguito de cerveza...
    {
        if (!(jarra = present("jarra_cerveza",TO)))
        // no tiene jarra. Eso es que se la han robado o algo
        {
            return W("Un enano alza la mano y hace como si bebiese de una jarra "
                     "inexistente.\n"
                     "Cuando se da cuenta de que no tiene nada, sonr�e "
                     "confundido mientras dice: Judad�a que hace un momento "
                     "ten�a una jadda.\n" +
                     (env->QueryKeeper()?"eeeeh " + env->KeeperName() + "! otda "
                                       "jadda! Hip!":
                                       "Mira hacia todos lados buscando al "
                                       "tabernero, y al no encontrarlo, "
                                       "murmura algo entre dientes.") + "\n");
        }

        // tiene una jarra y se va a tomar un traguito
        alcohol = 10 + random(30);
        total = jarra->QueryFull();
        if (total)
        // le queda a�n a la jarra
        {
            // si el total de la jarra es menor que lo que tiene que beber,
            // vaciamos la jarra
            jarra->SetFull((nuevo = total < alcohol?0:jarra->QueryFull() - alcohol));
            // se calcula el alcohol que va a beber
            alcohol = total - nuevo;
            // a�adimos el alcohol, teniendo en cuenta el porcentaje de
            // alcohol de la bebida
            AddAlcohol(alcohol * jarra->QueryFoodAlc() / 100);
            return W("Un enano da un largo trago de su jarra de cerveza.\n");
        }

        // borramos el �tem del enano
        RemoveItem(blueprint(object_name(jarra)));
        // la jarra va al suelo
        jarra->move(environment(),M_SILENT);
        return W("Un enano mira pensativo su jarra vac�a, y a continuaci�n "
                 "la deja en el suelo.\n"
                 "�Eeeeeh! �fiignuus! �chame otda jaddita! �Hip!\n");
    }

    // vamos a cantar!
    if (sizeof(filter(all_inventory(environment()),
                      (:   $1 != TO && $1->id("enano_borracho")
                        && !$1->QueryDormido():))))
    // hay m�s enanos borrachos con este, as� que puede cantar en
    // compa��a ;)
    {
        // muestra tanto los mensajes de solo como los de acompa�ados
        if (random(100) >= 50)
        {
            return W(mostrar_mensaje(HAB_TABERNAS_ANNUFAM("enanos_borrachos.txt")));
        }
        else
        {
            return W(mostrar_mensaje(HAB_TABERNAS_ANNUFAM("enano_borracho.txt")));
        }
    }

    // est� s�lo
    return W(mostrar_mensaje(RAIZ + "docs/annufam/enano_borracho.txt"));
}


public varargs string QueryLong(string what)
{
    if (pDormido)
    {
        return W("Es un enano del centro de entrenamiento de la ciudad.\n"
                 "Tiene la cabeza apoyada en la mesa mientras ronca "
                 "ruidosamente.\n");
    }
    return ::QueryLong();
}


public void init()
{
    ::init();
    env = environment();
}
