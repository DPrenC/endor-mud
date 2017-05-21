/* Archivo        camino07.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripción:   Camino de Nandor a Sherek
*/

#include "path.h"
inherit ABDCAM;

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al sur se extiende un joven bosque, casi todo él robles y "
        "encinas.\n");
    AddExit("oeste", CNSH("camino06"));
    AddExit("este", CNSH("camino08"));
    AddExit("sureste", MARH("nandor/bosque/bosque005"));
    Bichejo();
}
