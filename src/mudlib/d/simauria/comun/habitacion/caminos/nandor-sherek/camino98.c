/* Archivo        camino98.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripci�n:   Camino a la abad�a (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("oeste", CNSH("camino97"));
    AddExit("este", CNSH("camino99"));
    Bichejo();
}
