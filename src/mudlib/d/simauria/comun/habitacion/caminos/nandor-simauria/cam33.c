
/****************************************************************************
Fichero: cam33.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    AddExit("este","./cam32");
    AddExit("sur","./cam34");
}

