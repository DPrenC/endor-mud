/****************************************************************************
Fichero: cam13.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();
    AddExit("oeste","./cam14");
    AddExit("norte","./cam12");
    AddExit("sur", MARH("nandor/bosque/bosque065"));
    HideExit("sur",1);
}

