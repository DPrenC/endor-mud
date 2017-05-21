/****************************************************************************
Fichero: cam06.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: Camino Nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    AddExit("sudeste","./cam07");
    AddExit("noroeste","./cam05");
    AddExit("norte", MARH("nandor/bosque/bosque024"));
    AddExit("nordeste", MARH("nandor/bosque/bosque025"));
    HideExit("norte",1);
    HideExit("nordeste",1);
}

