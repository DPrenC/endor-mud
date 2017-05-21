
/****************************************************************************
Fichero: cam16.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    AddExit("sur","./cam17");
    AddExit("norte","./cam15");
    AddExit("sudeste", MARH("nandor/bosque/bosque069"));
    HideExit("sudeste",1);
}

