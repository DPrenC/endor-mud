/**
 * /torrewiz/rooms/nyh/workroom.c
 */

#include "path.h"
inherit ROOM;

create () {
    ::create();

    SetIntShort("la habitación de Nyh");
    SetIntLong(
"Estás en la habitación de Nyh. En estos momentos está completamente vacía, "
"esperando ser llenada en algún momento.\n");
    SetIntBright(50);
    SetIndoors(1);
    AddExit("torre", TORRE("piso4/center"));
}
