/****************************************************************************
Fichero: camino26.c
Autor: Ratwor
Fecha: 27/12/2007
Descripci�n: El camino del norte de Marhalt.
****************************************************************************/

#include "./path.h"

inherit CAMINOS "/norte_marhalt/camino_base";
create(){
    ::create();
    AddExit("noroeste", "./camino27");
    AddExit("este", "./camino25");
}

