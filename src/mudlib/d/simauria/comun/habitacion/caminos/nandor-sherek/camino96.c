/* Archivo        camino96.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripci�n:   Camino a la abad�a (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("suroeste", CNSH("camino95"));
    AddExit("este", CNSH("camino97"));
    Bichejo();
}
