/****************************************************************************
Fichero: patio06.c
Autor: Ratwor
Fecha: 28/12/2007
Descripción: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("patio/patio_base");

create(){
    ::create();
    AddExit("este", "./patio08");
    AddExit("oeste",  "./patio06");
    AddExit("sur", "./patio13");
    AddExit("suroeste", "./patio12");
}


