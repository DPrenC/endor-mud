
/****************************************************************************
Fichero: cam24.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    AddExit("sur","./cam25");
    AddExit("norte","./cam23");
    AddExit("este", MARH("nandor/bosque/bosque105"));
    HideExit("este",1);
}

