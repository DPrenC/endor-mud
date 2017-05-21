/* Archivo        camino65.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripción:   Camino a la abadía (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("noroeste", CNSH("camino64"));
    AddExit("sureste", CNSH("camino66"));
    Bichejo();
}
