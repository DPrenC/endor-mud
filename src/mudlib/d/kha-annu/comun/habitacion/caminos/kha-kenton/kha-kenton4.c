#include "./camino.h"

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetIntLong("Este sendero te permite viajar desde Kha-annu hasta el bosque de Kenton "
        "siguiendo la traves�a del r�o Kilok. Hacia el oeste puedes ver una entrada hacia la "
        "monta�a.\n");
    SetIndoors(0);
    AddDetail("entrada","Parece un t�nel hacia el coraz�n de la monta�a.\n");
    AddExit("norte",CAMINO+"kha-kenton3");
    AddExit("sudeste",CAMINO+"kha-kenton5");
    AddExit("oeste",CAMINO+"entra_mina");
    SetLocate("Camino de Kha-Annu");
}
