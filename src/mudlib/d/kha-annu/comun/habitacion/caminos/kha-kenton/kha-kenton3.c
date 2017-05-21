#include "./camino.h"

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetDesc();
    SetIndoors(0);
    AddExit("noroeste",CAMINO+"kha-kenton2");
    AddExit("sur",CAMINO+"kha-kenton4");
    SetLocate("Camino de Kha-Annu");
}
