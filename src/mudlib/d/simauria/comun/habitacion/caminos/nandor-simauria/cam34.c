
/****************************************************************************
Fichero: cam34.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    AddExit("norte","./cam33");
    AddExit("sur","./cam35");
    AddExit("sudeste", MARH("nandor/bosque/bosque149"));
    HideExit("sudeste",1);
}

