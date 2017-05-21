/****************************************************************************
Fichero: patio14.c
Autor: Ratwor
Fecha: 28/12/2007
Descripción: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("patio/patio_base");

create(){
    ::create();
    AddExit("este",  "./patio15");
    AddExit("norte", "./patio12");
    AddExit("nordeste", "./patio13");
    AddExit("sur", "./patio16");
    AddExit("sudeste", "./patio17");
}


