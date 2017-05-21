/****************************************************************************
Fichero: camino32.c
Autor: Ratwor
Fecha: 24/12/2007
Descripción: El camino del castillo
****************************************************************************/

#include "./path.h"

inherit CASTILLO("camino/camino_base");
create(){
    ::create();
    AddExit("noroeste", "./camino33");
    AddExit("este", "./camino31");
}

