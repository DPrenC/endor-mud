/****************************************************************************
Fichero: cam07.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino Nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();

    AddExit("este","./cam08");
    AddExit("noroeste","./cam06");
}

