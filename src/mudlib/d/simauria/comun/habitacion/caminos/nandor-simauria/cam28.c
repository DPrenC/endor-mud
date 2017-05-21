
/****************************************************************************
Fichero: cam28.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    AddExit("sur","./cam29");
    AddExit("norte","./cam27");
    AddExit("nordeste", MARH("nandor/bosque/bosque114"));
    AddExit("sudeste", MARH("nandor/bosque/bosque125"));
    HideExit("nordeste",1);
    HideExit("sudeste",1);
}

