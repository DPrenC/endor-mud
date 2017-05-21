/****************************************************************************
Fichero: patio05.c
Autor: Ratwor
Fecha: 28/12/2007
Descripción: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("patio/patio_base");

create(){
    ::create();
    AddExit("este", "./patio06");
    AddExit("oeste",  "./patio04");
    AddExit("sur", "./patio11");
    AddExit("sudeste", "./patio12");
    AddExit("suroeste", "./patio10");
    AddExit("norte", "./patio01");
}


