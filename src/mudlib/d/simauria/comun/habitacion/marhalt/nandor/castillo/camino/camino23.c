/****************************************************************************
Fichero: camino23.c
Autor: Ratwor
Fecha: 24/12/2007
Descripci�n: El camino del castillo
****************************************************************************/

#include "./path.h"
inherit CASTILLO("camino/junto_foso");
create(){
    ::create();
    AddExit("oeste", "./camino24");
    AddExit("este", "./camino22");
}

