/****************************************************************************
Fichero: camino21.c
Autor: Ratwor
Fecha: 24/12/2007
Descripci�n: El camino del castillo
****************************************************************************/

#include "./path.h"
inherit CASTILLO("camino/junto_foso");
create(){
    ::create();
    AddExit("oeste", "./camino22");
    AddExit("nordeste", "./camino20");
}

