
/****************************************************************************
Fichero: cam31.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    AddExit("norte","./cam30");
    AddExit("sur","./cam32");
}

