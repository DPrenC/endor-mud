/****************************************************************************
Fichero: viejo02.c
Autor: Riberales
Creación: 09/12/05
Descripción: Un viejo en la posada.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <guild.h>

inherit NPC;

string charla();

public create()
{
    ::create();

    seteuid(getuid());

    SetStandard("Proruk","orco",([GC_NINGUNO:42]),GENDER_MALE);
    SetShort("Proruk el sabio");
    SetLong("Proruk es un orco de avanzada edad, mas los años no parecen que "
               "hayan pasado por su cabeza. Cuando lo miras sientes que una "
               "gran sabiduría lo rodea, y que es un individuo bastante "
               "sociable.\n");

    SetIds(({"Proruk","proruk","orco","sabio","el sabio"}));

    InitChats(4,SF(charla));

    AddItem("/std/thing.c",REFRESH_REMOVE,([
            P_SHORT: "un libro",
            P_LONG: "Se trata de un libro  con el lomo de cuero. En la "
                    "portada puedes leer: ¡Filosofía orca: Los grandes "
                    "pensadores'.\n",
            P_READ_MSG: "¿De veras te crees capaz de leer un libro de "
                       "filosofía orca?\n",
            P_IDS: ({"libro","libro de filosofia","libro_orco"})]));

}

string charla()
{
    string msg;
    switch(random(3))
    {
        case 0:
            object libro;
            if (present("libro_orco",TO))
            {
                msg="Proruk se pone a leer.\n";
                break;
            }
            if (libro = present("libro_orco",environment()))
            {
                libro->move(TO);
                msg="Proruk recoge su libro del suelo.\n";
                break;
            }
            msg="Proruk dice: ¿Dónde habré dejado el libro?\n";
        break;
        case 1:
            object viejo;
            if ((viejo = present("marvag",environment())) && living(viejo))
            {
                msg="Proruk dice: Marvag, tendrías que mejorar tus modales."
                    "\n\nMarvag dice: Déjame en paz, viejo amargado.\n";
                break;
            }
            msg="Proruk se pone a observar la chimenea.\n";
        break;
        case 2:
            msg="Proruk te mira profundamente mientras te sonríe.\n";
        break;
    }
    return msg;
}
