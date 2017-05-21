/****************************************************************************
Fichero: cam09.c
Autor: Buh
Fecha: 21/01/2007
Descripción: camino Nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    AddExit("sur","./cam10");
    AddExit("norte","./cam08");
    AddExit("este", MARH("nandor/bosque/bosque039"));
    AddExit("sudeste", MARH("nandor/bosque/bosque043"));
    HideExit("este",1);
    HideExit("sudeste",1);
}

