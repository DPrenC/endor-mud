/* Archivo        camino35.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripci�n:   Camino a la abad�a (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("sureste", CNSH("camino34"));
    AddExit("noroeste", CNSH("camino36"));
    Bichejo();
}
