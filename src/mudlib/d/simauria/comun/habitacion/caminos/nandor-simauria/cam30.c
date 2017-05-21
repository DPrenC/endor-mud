
/****************************************************************************
Fichero: cam30.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    AddExit("este","./cam29");
    AddExit("sur","./cam31");
}

