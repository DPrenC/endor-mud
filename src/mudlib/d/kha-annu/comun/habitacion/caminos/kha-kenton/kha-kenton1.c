#include "./camino.h"
create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetIntLong("La gran ciudad de Kha-annu queda justo al norte de este camino, mientras que "
        "hacia el sur puedes seguir el curso del r�o, bajando por un sendero.\n");
    SetIndoors(0);
    AddDetail(({"r�o","rio"}),"El r�o sale de la ciudad y fluye en direcci�n sur-suroeste.\n");
    AddDetail("sendero","Baja desde la ciudad de Kha-annu hasta lo que parece una peque�a "
        "aldea.\n");
    AddExit("norte",PUERTASUR+"entrada");
    AddExit("sur",CAMINO+"kha-kenton2");
    SetLocate("Camino de Kha-Annu");
}
