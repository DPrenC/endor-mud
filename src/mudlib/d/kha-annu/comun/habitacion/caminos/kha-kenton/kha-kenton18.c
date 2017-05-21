#include "./camino.h"

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetIntLong("Te encuentras casi en la falda de la montaña, y puedes divisar un pequeño "
        "poblado hacia el oeste. Si sigues el sendero hacia arriba, llegarás hasta la ciudad de "
        "Kha-annu.\n");
    SetIndoors(0);
    AddExit("norte",CAMINO+"kha-kenton17");
    AddExit("suroeste",CAMINO+"kha-kenton19");
    SetLocate("Camino de Kha-Annu");
}
