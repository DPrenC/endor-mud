/****************************************************************************
Fichero: camino07.c
Autor: Ratwor
Fecha: 24/12/2007
Descripci�n: El camino del castillo
****************************************************************************/

#include "./path.h"
inherit CASTILLO("camino/sendero_base");
create(){
    ::create();

    AddExit("suroeste", "./camino08");
    AddExit("este", "./camino06");
}

