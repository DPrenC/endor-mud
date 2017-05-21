#include "./camino.h"

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetDesc();
    SetIndoors(0);
    AddExit("nordeste",CAMINO+"kha-kenton14");
    AddExit("suroeste",CAMINO+"kha-kenton16");
    SetLocate("Camino de Kha-Annu");
}
