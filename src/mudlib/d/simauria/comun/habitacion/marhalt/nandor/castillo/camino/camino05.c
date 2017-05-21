/****************************************************************************
Fichero: camino05.c
Autor: Ratwor
Fecha: 24/12/2007
Descripción: El camino del castillo
****************************************************************************/

#include "./path.h"
inherit CASTILLO("camino/sendero_base");
create(){
    ::create();

    AddExit("suroeste", "./camino06");
    AddExit("este", "./camino04");
}

