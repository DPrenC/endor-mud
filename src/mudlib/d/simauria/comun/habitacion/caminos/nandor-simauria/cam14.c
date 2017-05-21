
/****************************************************************************
Fichero: cam14.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    AddExit("oeste","./cam15");
    AddExit("este","./cam13");
    AddExit("sudeste", MARH("nandor/bosque/bosque065"));
    HideExit("sudeste",1);
}

