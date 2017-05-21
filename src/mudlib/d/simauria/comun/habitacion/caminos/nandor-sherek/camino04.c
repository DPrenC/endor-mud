/*
Archivo        /d/simauria/comun/habitacion/caminos/nandor-sherek/camino04.c
Autor:         Yalin y Lug
Fecha:         30/04/2006
Descripción:   Camino de Nandor a Sherek
*/

#include "path.h"
inherit ABDCAM;

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al norte de aquí, entre los árboles,  puedes ver un muro de "
        "piedras, mientras que al sur del camino se extiende un bosque joven de robles y "
        "encinas.\n");
    AddDetail(({"muro", "muros", "muralla", "murallas"}), "Parece ser la muralla de un "
        "cementerio.\n");
    AddExit("oeste", CNSH("camino03"));
    AddExit("este", CNSH("camino05"));
    AddExit("sur", MARH("nandor/bosque/bosque003"));
    Bichejo();
}
