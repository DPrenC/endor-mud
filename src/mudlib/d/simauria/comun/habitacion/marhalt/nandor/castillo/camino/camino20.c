/****************************************************************************
Fichero: camino20.c
Autor: Ratwor
Fecha: 24/12/2007
Descripción: El camino del castillo
****************************************************************************/

#include "./path.h"
inherit CASTILLO("camino/junto_foso");
create(){
    ::create();
    AddExit("suroeste", "./camino21");
    AddExit("nordeste", "./camino19");
}

