/**
 * /torrewiz/rooms/nyh/workroom.c
 */

#include "path.h"
inherit ROOM;

create () {
    ::create();

    SetIntShort("la habitaci�n de Nyh");
    SetIntLong(
"Est�s en la habitaci�n de Nyh. En estos momentos est� completamente vac�a, "
"esperando ser llenada en alg�n momento.\n");
    SetIntBright(50);
    SetIndoors(1);
    AddExit("torre", TORRE("piso4/center"));
}
