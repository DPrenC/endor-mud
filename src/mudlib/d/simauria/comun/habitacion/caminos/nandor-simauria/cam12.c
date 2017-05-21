/****************************************************************************
Fichero: cam12.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: Camino nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    AddExit("sur","./cam13");
    AddExit("norte","./cam11");
    AddExit("nordeste", MARH("nandor/bosque/bosque049"));
    HideExit("nordeste",1);
}

