/* Archivo        camino08.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripción:   Camino de Nandor a Sherek
*/

#include "path.h"
inherit ABDCAM;

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Un joven bosque, en su mayor parte robles y encinas, se "
        "extiende al sur del camino.\n");
    AddExit("oeste", CNSH("camino07"));
    AddExit("este", CNSH("camino09"));
    AddExit("sur", MARH("nandor/bosque/bosque005"));
    Bichejo();
}
