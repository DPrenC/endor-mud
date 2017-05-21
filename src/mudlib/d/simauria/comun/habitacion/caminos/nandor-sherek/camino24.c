/* Archivo        camino24.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripción:   Camino a la abadía (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("oeste", CNSH("camino23"));
    AddExit("noreste", CNSH("camino25"));
    Bichejo();
}
