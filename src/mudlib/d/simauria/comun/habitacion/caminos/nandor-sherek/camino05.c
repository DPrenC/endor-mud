/*
Archivo: /d/simauria/comun/habitacion/caminos/nandor-sherek/camino05.c
Autor:         Yalin y Lug
Fecha:         30/04/2006
Descripción:   Camino de Nandor a Sherek
*/

#include "path.h"
inherit ABDCAM;

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"Puedes ver un muro al norte, tras los árboles, mientras que al "
        "sur se extiende un bosque joven de robles y encinas.\n");
    AddDetail(({"muro", "muros", "muralla", "murallas"}), "Parece ser la muralla de un "
        "cementerio.\n");
    AddExit("oeste", CNSH("camino04"));
    AddExit("este", CNSH("camino06"));
    AddExit("sur", MARH("nandor/bosque/bosque004"));
    Bichejo();
}
