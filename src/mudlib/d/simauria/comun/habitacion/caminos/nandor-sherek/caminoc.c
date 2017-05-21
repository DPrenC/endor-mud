/*          sendero14.c : Aldea de Nandor
            Creado por : Blackrider
            Fecha : 24-10-97

 */

#include "path.h"

#include <properties.h>
#include <moving.h>
inherit SIM_ROOM;

abrir_puertas(string str)
{
    if (!str) write("¿Qué quieres abrir? ¿La cabeza de alguien?\n");
    else
    {
        if (str!="puertas" && str!="puerta") 
          write("¡No hay nada parecido a "+str+" por aquí!\n");
        else write("¿Cómo quieres abrirlas? Míralas bien...\n");
    }
    return 1;
}

empujar_puertas(string str)
{
    int dur; // Dureza de las bisagras...
    if (!str) write("¿Empujar QUÉ?\n");
    else
    {
        if (str!="puertas" && str!="puerta") 
          write("Creo que lo único que puedes empujar son las puertas...\n");
        else
        {
            dur=random(TP->QueryStr()*3);
            write("Empiezas a empujar las pesadas puertas del cementerio");
            if (dur<((TP->QueryStr()+TP->QueryDex())/2))
            {
                write(". Parece que se empiezan a abrir, y entras en el cementerio...\n");
                tell_room(MARH("nandor/cementerio/cemen1"),
                    TP->QueryName()+" ha entrado al cementerio.\n");
                TP->move(MARH("nandor/cementerio/cemen1"), M_SILENT);
                tell_room(CNSH("camino03"),TP->QueryName()+" empuja las puertas y, con gran "
                    "esfuerzo, logra abrirlas y entrar en el cementerio. Las puertas se "
                    "cierran tras él con gran ruido.\n");
                write("Las puertas se cierran tras de ti haciendo un gran ruido.\n");
            }
            else
            {
                write(", pero no logras abrirlas... Quizá si lo intentas de nuevo...\n");
            }
        }
    }
    return 1;
}

tirar_puertas(str)
{
    if (str=="puertas" || str=="puerta")
    {
        write("Tiras de las puertas con todas tus fuerzas. Ahora están bien cerradas.\n");
        return 1;
    }
    return 0;
}

haz_norte()
{
    write("Deberías abrir las puertas primero...\n");
    return 1;
}

init()
{
    ::init();
    add_action("empujar_puertas","empujar");
    add_action("abrir_puertas","abrir");
    add_action("tirar_puertas","tirar");
}

create()
{
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("la entrada del Cementerio de Nandor");
    SetIntLong("Estás enfrente de las puertas de un cementerio. A través de sus rejas ves un "
        "gran número de tumbas y unos grandes cipreses. No parece que haya nadie en el "
        "interior. Al fondo del cementerio ves una pequeña ermita con un campanario, aunque no "
        "tiene muy buen aspecto.\n");
    SetIndoors(0);
    AddDetail(({"puertas", "puerta"}),
    "Las puertas están cerradas..., aunque quizá podrías empujarlas.\n");
    AddDetail("ermita", "No parece estar en muy buen estado.\n");
    AddDetail("campanario","Es muy alto. Seguramente se tendrá una buena vista de la comarca "
        "desde él.\n");
    AddExit("sur","camino03");
    AddExit("norte",SF(haz_norte));
    HideExit("norte",1);
}
