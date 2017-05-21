/****************************************************************************
Fichero: camino18.c
Autor: Ratwor
Fecha: 27/12/2007
Descripción: El camino del norte de Marhalt.
****************************************************************************/

#include "./path.h"

inherit CAMINOS "/norte_marhalt/camino_base";
create(){
    ::create();
    AddExit("noroeste", "./camino19");
    AddExit("este", "./camino17");
}

