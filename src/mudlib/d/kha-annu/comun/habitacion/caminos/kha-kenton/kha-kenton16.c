#include "./camino.h"

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetDesc();
    SetIndoors(0);
    AddExit("nordeste",CAMINO+"kha-kenton15");
    AddExit("sur",CAMINO+"kha-kenton17");
    SetLocate("Camino de Kha-Annu");
}
