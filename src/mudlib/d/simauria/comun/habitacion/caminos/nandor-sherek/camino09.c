/*
Archivo        camino09.c
Autor:         Yalin y Lug
Fecha:         30/04/2006
Descripci�n:   Camino de Nandor a Sherek
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el sur y suroeste, se extiende un bosque de j�venes "
        "robles y encinas.\n");
    AddExit("oeste", CNSH("camino08"));
    AddExit("este", CNSH("camino10"));
    AddExit("sur", MARH("nandor/bosque/bosque006"));
    Bichejo();
}
