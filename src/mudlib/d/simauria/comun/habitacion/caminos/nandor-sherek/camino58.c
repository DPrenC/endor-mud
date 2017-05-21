/* Archivo        camino58.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripción:   Camino a la abadía (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("sureste", CNSH("camino57"));
    AddExit("noroeste", CNSH("camino59"));
    Bichejo();
}
