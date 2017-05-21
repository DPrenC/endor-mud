#include "./camino.h"

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetDesc();
    SetIndoors(0);
    AddExit("noroeste",CAMINO+"kha-kenton8");
    AddExit("sudeste",CAMINO+"kha-kenton10");
    SetLocate("Camino de Kha-Annu");
}
