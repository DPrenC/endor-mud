/* Archivo        camino99.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripción:   Camino a la abadía (proyecto)
*/

#include "path.h"
inherit STAGECOACH_STOP;
inherit ABDCAM;

create ()
{
    ::create();
    SetLocate("el camino Nandor-Sherek");
    SetIntLong("Esta es la parada de la diligencia Masher, que une los "
        "dominios de Sherek con la lejana ciudad de Nandor.\nEl camino "
        "transitable discurre de este a oeste, mientras que hacia el sudeste "
        "se abre el sendero que lleva a la aldea de Sloch, un protectorado de "
        "la abadía de Sherek, y hacia el norte, un camino asciende por la montaña, en dirección a "
        "una cantera de granito, propiedad de los monjes que habitan esta abadía.\n");
    SetNombreParada("Sloch");
    SetKeeper(PNJ("diligencia/taquillero"));
    SetClimateServer(SERVER);
    AddExit("norte",SHERCAN("camino00"));
    AddExit("sureste", SHERALD("calles/sendero00"));
    AddExit("oeste", CNSH("camino98"));
    AddExit("este", CNSH("camino100"));
    Bichejo();
    AddDiligencia("/d/simauria/comun/transporte/diligencia/masher/masher");
}
