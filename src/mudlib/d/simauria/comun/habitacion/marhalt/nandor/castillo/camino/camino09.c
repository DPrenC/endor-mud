/****************************************************************************
Fichero: camino09.c
Autor: Ratwor
Fecha: 24/12/2007
Descripción: El camino del castillo
****************************************************************************/

#include "./path.h"
inherit CASTILLO("camino/sendero_base");
create(){
    ::create();

    AddExit("noroeste", "./camino10");
    AddExit("este", "./camino08");
}

