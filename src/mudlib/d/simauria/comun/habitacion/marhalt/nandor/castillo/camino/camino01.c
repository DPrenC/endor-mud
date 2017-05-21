/****************************************************************************
Fichero: camino01.c
Autor: Ratwor
Fecha: 24/12/2007
Descripción: El camino del castillo
****************************************************************************/

#include "./path.h"

inherit CASTILLO("camino/sendero_base");
create(){
    ::create();

    AddExit("noroeste", "./camino02");
    AddExit("nordeste", CAMINOS "/norte_marhalt/camino04");
}

