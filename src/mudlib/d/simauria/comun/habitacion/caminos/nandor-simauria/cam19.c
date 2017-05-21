
/****************************************************************************
Fichero: cam19.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    AddExit("sudeste","./cam20");
    AddExit("norte","./cam18");
    AddExit("este", MARH("nandor/bosque/bosque084"));
    HideExit("este",1);
}

