/* Archivo        camino71.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripci�n:   Camino a la abad�a (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("suroeste", CNSH("camino70"));
    AddExit("noreste", CNSH("camino72"));
    Bichejo();
}
