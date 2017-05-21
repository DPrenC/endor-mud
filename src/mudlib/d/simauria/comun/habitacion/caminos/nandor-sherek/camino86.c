/* Archivo        camino86.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripción:   Camino a la abadía (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("sur", CNSH("camino85"));
    AddExit("noreste", CNSH("camino87"));
    Bichejo();
}
