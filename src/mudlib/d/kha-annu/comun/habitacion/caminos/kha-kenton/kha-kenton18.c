#include "./camino.h"

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetIntLong("Te encuentras casi en la falda de la monta�a, y puedes divisar un peque�o "
        "poblado hacia el oeste. Si sigues el sendero hacia arriba, llegar�s hasta la ciudad de "
        "Kha-annu.\n");
    SetIndoors(0);
    AddExit("norte",CAMINO+"kha-kenton17");
    AddExit("suroeste",CAMINO+"kha-kenton19");
    SetLocate("Camino de Kha-Annu");
}
