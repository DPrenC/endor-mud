#include "path.h"
inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("la abadía de Sherek");
    SetIntLong("Estás en alguna habitación por determinar, en la abadía de Sherek.\n");
    SetIndoors(1);
    SetIntBright(50);
}
