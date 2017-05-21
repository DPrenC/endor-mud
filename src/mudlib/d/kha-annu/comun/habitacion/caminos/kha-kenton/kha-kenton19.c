#include "./camino.h"

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetIntLong("Hacia el noroeste comienza un largo sendero que llega hasta la cima de las "
        "montañas. Puedes entrar en el poblado de Flenton si sigues hacia el oeste.\n");
    SetIndoors(0);
    AddExit("nordeste",CAMINO+"kha-kenton18");
    AddExit("oeste",CAMINO+"kha-kenton20");
    SetLocate("Camino de Kha-Annu");
}
