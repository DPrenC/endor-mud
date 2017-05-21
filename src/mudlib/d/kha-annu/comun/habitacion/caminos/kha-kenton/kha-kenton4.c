#include "./camino.h"

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetIntLong("Este sendero te permite viajar desde Kha-annu hasta el bosque de Kenton "
        "siguiendo la travesía del río Kilok. Hacia el oeste puedes ver una entrada hacia la "
        "montaña.\n");
    SetIndoors(0);
    AddDetail("entrada","Parece un túnel hacia el corazón de la montaña.\n");
    AddExit("norte",CAMINO+"kha-kenton3");
    AddExit("sudeste",CAMINO+"kha-kenton5");
    AddExit("oeste",CAMINO+"entra_mina");
    SetLocate("Camino de Kha-Annu");
}
