/****************************************************************************
Fichero: cam11.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: Camino Nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    AddExit("sur","./cam12");
    AddExit("nordeste","./cam10");
    AddExit("este", MARH("nandor/bosque/bosque049"));
    HideExit("este",1);
}

