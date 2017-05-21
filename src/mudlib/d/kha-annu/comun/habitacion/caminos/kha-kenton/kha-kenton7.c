#include "./camino.h"

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetDesc();
    SetIndoors(0);
    AddExit("este",CAMINO+"kha-kenton8");
    AddExit("oeste",CAMINO+"kha-kenton6");
    SetLocate("Camino de Kha-Annu");
}
