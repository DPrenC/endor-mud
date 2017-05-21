/*
Archivo: /d/simauria/comun/habitacion/caminos/nandor-sherek/camino06.c
Autor:         Yalin y Lug
Fecha:         30/04/2006
Descripción:   Camino de Nanador a Sherek
*/

#include "path.h"
inherit ABDCAM;
create()
{
    ::create();
    SetIntLong(QueryIntLong()+"A través de los árboles puedes ver unas murallas al norte, y, "
        "más lejos, al noroeste, una edificación.\nAl sur del camino se extiende un bosque "
        "joven de robles y encinas.\n");
    AddDetail(({"muro", "muros", "muralla", "murallas"}), "Se trata de los "
        "muros que rodean un viejo cementerio, posiblemente perteneciente a "
        "la aldea de Nandor.\n");
    AddDetail(({"edificacion", "edificación"}), "parece una iglesia, pero "
        "estás demasiado lejos para asegurarlo.\n");
    AddExit("oeste", CNSH("camino05"));
    AddExit("este", CNSH("camino07"));
    AddExit("suroeste", MARH("nandor/bosque/bosque004"));
    Bichejo();
}
