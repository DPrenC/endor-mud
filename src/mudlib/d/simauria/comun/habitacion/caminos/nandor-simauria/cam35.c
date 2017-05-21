
/****************************************************************************
Fichero: cam35.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();
    AddExit("norte","./cam34");
    AddExit("sur","./cam36");
    AddExit("este", MARH("nandor/bosque/bosque149"));
    HideExit("este",1);
}

