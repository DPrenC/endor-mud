/* Archivo        camino64.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripción:   Camino a la abadía (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("noroeste", CNSH("camino63"));
    AddExit("sureste", CNSH("camino65"));
    Bichejo();
}
