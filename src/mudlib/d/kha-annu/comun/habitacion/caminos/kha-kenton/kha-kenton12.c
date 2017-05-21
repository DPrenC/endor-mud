#include "./camino.h"

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetDesc();
    SetIndoors(0);
    AddExit("norte",CAMINO+"kha-kenton11");
    AddExit("sur",CAMINO+"kha-kenton13");
    SetLocate("Camino de Kha-Annu");
}
