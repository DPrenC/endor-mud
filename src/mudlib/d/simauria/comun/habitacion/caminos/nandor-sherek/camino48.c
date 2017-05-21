/* Archivo        camino48.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripción:   Camino a la abadía (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("sureste", CNSH("camino47"));
    AddExit("norte", CNSH("camino49"));
    Bichejo();
}
