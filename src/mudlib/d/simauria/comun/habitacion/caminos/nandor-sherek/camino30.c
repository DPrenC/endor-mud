/* Archivo        camino30.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripci�n:   Camino a la abad�a (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("suroeste", CNSH("camino29"));
    AddExit("noreste", CNSH("camino31"));
    Bichejo();
}
