#include "./camino.h"

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetDesc();
    SetIndoors(0);
    AddExit("noroeste",CAMINO+"kha-kenton9");
    AddExit("sudeste",CAMINO+"kha-kenton11");
    SetLocate("Camino de Kha-Annu");
}
