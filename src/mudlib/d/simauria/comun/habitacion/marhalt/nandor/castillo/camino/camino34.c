/****************************************************************************
Fichero: camino34.c
Autor: Ratwor
Fecha: 24/12/2007
Descripción: El camino del castillo
****************************************************************************/

#include "./path.h"

inherit CASTILLO("camino/camino_base");
create(){
    ::create();
    AddExit("norte", "./camino35");
    AddExit("sudeste", "./camino33");
}

