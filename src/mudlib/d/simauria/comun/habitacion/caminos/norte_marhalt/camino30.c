/****************************************************************************
Fichero: camino30.c
Autor: Ratwor
Fecha: 27/12/2007
Descripción: El camino del norte de Marhalt.
****************************************************************************/

#include "./path.h"

inherit CAMINOS "/norte_marhalt/camino_base";
create(){
    ::create();
    AddExit("oeste", "./camino31");
    AddExit("nordeste", "./camino29");
}

