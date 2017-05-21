
/****************************************************************************
Fichero: cam32.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino nandor ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    AddExit("norte","./cam31");
    AddExit("oeste","./cam33");
    AddExit("sudeste", MARH("nandor/bosque/bosque142"));
    HideExit("sudeste",1);
}

