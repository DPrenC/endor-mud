/* Archivo        camino69.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripción:   Camino a la abadía (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("oeste", CNSH("camino68"));
    AddExit("noreste", CNSH("camino70"));
    Bichejo();
}
