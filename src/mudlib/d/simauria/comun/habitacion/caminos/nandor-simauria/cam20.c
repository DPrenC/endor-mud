
/****************************************************************************
Fichero: cam20.c
Autor: Ratwor
Fecha: 21/01/2007 13:59/
Descripción: camino nandor-ishtria.
****************************************************************************/



#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    AddExit("este","./cam21");
    AddExit("noroeste","./cam19");
    AddExit("norte", MARH("nandor/bosque/bosque084"));
    AddExit("nordeste", MARH("nandor/bosque/bosque085"));
    HideExit("norte",1);
    HideExit("nordeste",1);
}

