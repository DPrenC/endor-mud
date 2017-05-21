/****************************************************************************
Fichero: patio03.c
Autor: Ratwor
Fecha: 28/12/2007
Descripción: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("patio/patio_base");

create(){
    ::create();
    SetIntShort("el patio de armas, zona de entrenamiento");
    AddExit("este", "./patio04");
    AddExit("oeste",  "./patio02");
    AddExit("sur", "./patio09");
    AddExit("sudeste", "./patio10");
}


