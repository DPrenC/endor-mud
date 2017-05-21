/****************************************************************************
Fichero: camino21.c
Autor: Ratwor
Fecha: 27/12/2007
Descripción: El camino del norte de Marhalt.
****************************************************************************/

#include "./path.h"

inherit CAMINOS "/norte_marhalt/camino_base";
create(){
    ::create();
    AddExit("oeste", "./camino22");
    AddExit("sudeste", "./camino20");
}

