#include "path.h"
#include <properties.h>
#include <magia.h>
#include <moving.h>
inherit ROOM;

create()
{
    ::create();
    SetIntShort("un peque�o vest�bulo");
    SetIntLong("No es m�s que un peque�o espacio cuadrangular que sirve de acceso a otras habitaciones.\n");
    SetIntBright(25);
    AddExit("este", TORRE("rooms/yalin/labor"));
    AddExit("oeste", TORRE("rooms/yalin/cocina"));
    AddExit("sur", TORRE("rooms/yalin/workroom"));
}
    