/****************************************************************************
Fichero: camino12.c
Autor: Ratwor
Fecha: 24/12/2007
Descripción: El camino del castillo
****************************************************************************/

#include "./path.h"
inherit CASTILLO("camino/sendero_base");
create(){
    ::create();

    AddExit("noroeste", "./camino13");
    AddExit("sur", "./camino11");
}

