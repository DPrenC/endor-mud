/* Archivo        camino33.c
Autor:         Yalin y Lug
Fecha:         30/04/2006
Descripci�n:   Camino a la abad�a (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("sur", CNSH("camino32"));
    AddExit("noroeste", CNSH("camino34"));
    Bichejo();
}
