/* Archivo        camino91.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripci�n:   Camino a la abad�a (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("oeste", CNSH("camino90"));
    AddExit("noreste", CNSH("camino92"));
    Bichejo();
}
