/* Archivo        camino83.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripción:   Camino a la abadía (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("suroeste", CNSH("camino82"));
    AddExit("noreste", CNSH("camino84"));
    Bichejo();
}
