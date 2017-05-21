/* Camino a la abadía (proyecto) */
#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("oeste", CNSH("camino16"));
    AddExit("este", CNSH("camino18"));
    Bichejo();
}
