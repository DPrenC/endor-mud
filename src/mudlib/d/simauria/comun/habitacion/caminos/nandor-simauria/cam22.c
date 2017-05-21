
/****************************************************************************
Fichero: cam22.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    AddExit("sudeste","./cam23");
    AddExit("norte","./cam21");
    AddExit("nordeste", MARH("nandor/bosque/bosque090"));
    AddExit("este", MARH("nandor/bosque/bosque094"));
    HideExit("nordeste",1);
    HideExit("este",1);
}

