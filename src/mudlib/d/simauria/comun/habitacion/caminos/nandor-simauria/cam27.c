
/****************************************************************************
Fichero: cam27.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino nandor-ishtria
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    AddExit("sur","./cam28");
    AddExit("norte","./cam26");
    AddExit("este", MARH("nandor/bosque/bosque114"));
    HideExit("este",1);
}

