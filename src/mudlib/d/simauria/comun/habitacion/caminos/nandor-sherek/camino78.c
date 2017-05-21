/* Archivo        camino78.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripción:   Camino a la abadía (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("oeste", CNSH("camino77"));
    AddExit("noreste", CNSH("camino79"));
    Bichejo();
}
