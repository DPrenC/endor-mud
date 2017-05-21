/****************************************************************************
Fichero: cam08.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino Nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();
    AddExit("sur","./cam09");
    AddExit("oeste","./cam07");
    AddExit("sudeste", MARH("nandor/bosque/bosque039"));
    HideExit("sudeste",1);
}

