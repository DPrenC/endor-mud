/* Archivo        camino76.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripci�n:   Camino a la abad�a (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("oeste", CNSH("camino75"));
    AddExit("este", CNSH("camino77"));
    Bichejo();
}
