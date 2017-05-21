
/****************************************************************************
Fichero: cam21.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    AddExit("sur","./cam22");
    AddExit("oeste","./cam20");
    AddExit("norte", MARH("nandor/bosque/bosque085"));
    AddExit("noroeste", MARH("nandor/bosque/bosque084"));
    AddExit("este", MARH("nandor/bosque/bosque090"));
    AddExit("sudeste", MARH("nandor/bosque/bosque094"));
    HideExit("noroeste",1);
    HideExit("norte",1);
    HideExit("este",1);
    HideExit("sudeste",1);

}

