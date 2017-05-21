/* Archivo        camino79.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripción:   Camino a la abadía (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("suroeste", CNSH("camino78"));
    AddExit("noreste", CNSH("camino80"));
    Bichejo();
}
