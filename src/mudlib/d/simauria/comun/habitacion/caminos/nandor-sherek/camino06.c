/*
Archivo: /d/simauria/comun/habitacion/caminos/nandor-sherek/camino06.c
Autor:         Yalin y Lug
Fecha:         30/04/2006
Descripci�n:   Camino de Nanador a Sherek
*/

#include "path.h"
inherit ABDCAM;
create()
{
    ::create();
    SetIntLong(QueryIntLong()+"A trav�s de los �rboles puedes ver unas murallas al norte, y, "
        "m�s lejos, al noroeste, una edificaci�n.\nAl sur del camino se extiende un bosque "
        "joven de robles y encinas.\n");
    AddDetail(({"muro", "muros", "muralla", "murallas"}), "Se trata de los "
        "muros que rodean un viejo cementerio, posiblemente perteneciente a "
        "la aldea de Nandor.\n");
    AddDetail(({"edificacion", "edificaci�n"}), "parece una iglesia, pero "
        "est�s demasiado lejos para asegurarlo.\n");
    AddExit("oeste", CNSH("camino05"));
    AddExit("este", CNSH("camino07"));
    AddExit("suroeste", MARH("nandor/bosque/bosque004"));
    Bichejo();
}
