#include "./camino.h"

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetDesc();
    SetIndoors(0);
    AddExit("noroeste",CAMINO+"kha-kenton5");
    AddExit("este",CAMINO+"kha-kenton7");
    SetLocate("Camino de Kha-Annu");
}
