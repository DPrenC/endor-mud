#include "path.h"
inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("la abad�a de Sherek");
    SetIntLong("Est�s en alguna habitaci�n por determinar, en la abad�a de Sherek.\n");
    SetIndoors(1);
    SetIntBright(50);
}
