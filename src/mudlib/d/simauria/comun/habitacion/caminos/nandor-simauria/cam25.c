
/****************************************************************************
Fichero: cam25.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();
    AddExit("oeste","./cam26");
    AddExit("norte","./cam24");
    AddExit("nordeste", MARH("nandor/bosque/bosque105"));
    AddExit("sur", MARH("nandor/bosque/bosque114"));
    HideExit("sur",1);
    HideExit("nordeste",1);
}

