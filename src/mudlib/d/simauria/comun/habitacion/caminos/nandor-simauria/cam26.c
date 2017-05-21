
/****************************************************************************
Fichero: cam26.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino nandor-ishtria
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    AddExit("sur","./cam27");
    AddExit("este","./cam25");
    AddExit("sudeste", MARH("nandor/bosque/bosque114"));
    HideExit("sudeste",1);
}

