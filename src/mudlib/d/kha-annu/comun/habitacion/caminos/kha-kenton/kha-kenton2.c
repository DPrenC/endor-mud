#include "./camino.h"

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetDesc();
    SetIndoors(0);
    AddExit("norte",CAMINO+"kha-kenton1");
    AddExit("sudeste",CAMINO+"kha-kenton3");
    SetLocate("Camino de Kha-Annu");
}
