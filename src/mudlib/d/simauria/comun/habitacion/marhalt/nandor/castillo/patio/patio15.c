/****************************************************************************
Fichero: patio15.c
Autor: Ratwor
Fecha: 28/12/2007
Descripción: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("patio/patio_base");

create(){
    ::create();
    AddExit("oeste",  "./patio14");
    AddExit("norte", "./patio13");
    AddExit("noroeste", "./patio12");
    AddExit("sur", "./patio17");
    AddExit("suroeste", "./patio16");
}


