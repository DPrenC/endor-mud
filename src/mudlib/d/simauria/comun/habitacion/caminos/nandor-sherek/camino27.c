/* Archivo        camino27.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripción:   Camino a la abadía (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("sur", CNSH("camino26"));
    AddExit("norte", CNSH("camino28"));
    Bichejo();
}
