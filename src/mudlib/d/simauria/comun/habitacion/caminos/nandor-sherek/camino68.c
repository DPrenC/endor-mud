/* Archivo        camino68.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripci�n:   Camino a la abad�a (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("noroeste", CNSH("camino67"));
    AddExit("este", CNSH("camino69"));
    Bichejo();
}
