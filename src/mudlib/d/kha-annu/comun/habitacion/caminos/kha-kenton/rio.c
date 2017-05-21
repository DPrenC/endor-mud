#include "./path.h"

inherit KHA_ROOM;

/* camino de Kha-Annu a Kenton */

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetIntLong("El camino te conduce desde la Ciudad de Kha-Annu a Kenton.\n");
    SetIntBright(MAX_SUNBRIGHT);
    SetIndoors(0);
    AddExit("este",CAMINO+"rio1");
    AddExit("oeste",CAMINO+"kha-kenton8");
    SetLocate("Camino de Kha-Annu");
}
