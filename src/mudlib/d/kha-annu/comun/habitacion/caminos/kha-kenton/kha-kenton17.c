#include "./camino.h"

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetDesc();
    SetIndoors(0);
    AddExit("norte",CAMINO+"kha-kenton16");
    AddExit("sur",CAMINO+"kha-kenton18");
    SetLocate("Camino de Kha-Annu");
}
