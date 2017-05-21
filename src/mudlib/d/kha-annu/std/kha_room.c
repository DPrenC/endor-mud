/****************************************************************************
Fichero: kha_room.c
Autor: Kastwey
Creaci�n: 24/07/2005
Descripci�n: Fichero base para las habitaciones de Kha-annu
****************************************************************************/

#include "path.h"
#include <commands.h>

inherit ROOM;

int cmd_mirar(string str)
{
    string verb;
    if (!str || str != "tiempo") return 0;
    if (member(({"m","mi","mir","mira","mirar"}),(verb = query_verb())) < 0) return 0;
    if (QueryIndoors())
    // estamos en un interior
    {
        write("Desde aqu� no puedes ver el tiempo que hace.\n");
        return 42;
    }
    write("/obj/chronos"->QueryWeatherMsg());
    return 42;
}


public create()
{
    ::create();
    SetServer(SERVER);
    SetLocate("Kha-annu");
}

    public void init()
{
    ::init();
    add_action ("cmd_mirar","m",AA_SHORT);
}
