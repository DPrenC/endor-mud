/****************************************************************************
Fichero: camino36.c
Autor: Ratwor
Fecha: 24/12/2007
Descripción: El camino del castillo
****************************************************************************/

#include "./path.h"

inherit CASTILLO("camino/camino_base");
create(){
    ::create();
    AddExit("norte", CAMINOS "/norte_marhalt/camino39");
    AddExit("suroeste", "./camino35");
}

