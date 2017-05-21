
/****************************************************************************
Fichero: cam23.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();
    AddExit("sur","./cam24");
    AddExit("noroeste","./cam22");
    AddExit("norte", MARH("nandor/bosque/bosque094"));
    AddExit("nordeste", MARH("nandor/bosque/bosque095"));
    AddExit("sudeste", MARH("nandor/bosque/bosque105"));
    HideExit("norte",1);
    HideExit("nordeste",1);
    HideExit("sudeste",1);
}

