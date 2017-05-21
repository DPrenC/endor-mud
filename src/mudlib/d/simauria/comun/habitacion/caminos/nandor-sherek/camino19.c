/* Camino a la abadía (proyecto) */
#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("oeste", CNSH("camino18"));
    AddExit("este", CNSH("camino20"));
    Bichejo();
}
