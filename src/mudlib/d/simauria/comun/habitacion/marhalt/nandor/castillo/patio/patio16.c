/****************************************************************************
Fichero: patio16.c
Autor: Ratwor
Fecha: 28/12/2007
Descripción: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("patio/patio_base");

create(){
    ::create();
    AddExit("este",  "./patio17");
    AddExit("norte", "./patio14");
    AddExit("nordeste", "./patio15");
    AddExit("sur", "./patio18");
    AddExit("sudeste", "./patio19");
}


