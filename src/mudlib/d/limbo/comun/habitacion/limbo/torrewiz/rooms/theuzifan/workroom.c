/**
 * /torrewiz/rooms/theuzifan/workroom.c
 */

#include "path.h"
inherit ROOM;

create () {
    ::create();

    SetIntShort("la choza de Theuzifan");
    SetIntLong("Esta es la choza de Theuzifan.\n");
    SetIndoors(1);
    SetIntBright(50);
    AddExit("torre", TORRE("piso4/center"));
}

