/* Archivo        camino26.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripci�n:   Camino a la abad�a (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("sur", CNSH("camino25"));
    AddExit("norte", CNSH("camino27"));
    Bichejo();
}
