#include "./camino.h"

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetDesc();
    SetIndoors(0);
    AddExit("sudeste",CAMINO+"kha-kenton9");
    AddExit("oeste",CAMINO+"kha-kenton7");
    SetLocate("Camino de Kha-Annu");
}
