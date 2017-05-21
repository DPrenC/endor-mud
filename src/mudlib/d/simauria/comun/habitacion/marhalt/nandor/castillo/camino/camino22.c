/****************************************************************************
Fichero: camino22.c
Autor: Ratwor
Fecha: 24/12/2007
Descripción: El camino del castillo
****************************************************************************/

#include "./path.h"
inherit CASTILLO("camino/junto_foso");
create(){
    ::create();
    AddExit("oeste", "./camino23");
    AddExit("este", "./camino21");
}

