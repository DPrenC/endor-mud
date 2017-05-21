#include "./camino.h"

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetDesc();
    SetIndoors(0);
    AddExit("norte",CAMINO+"kha-kenton12");
    AddExit("suroeste",CAMINO+"kha-kenton14");
    SetLocate("Camino de Kha-Annu");
}
