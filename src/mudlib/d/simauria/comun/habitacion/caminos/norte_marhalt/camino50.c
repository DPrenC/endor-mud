/****************************************************************************
Fichero: camino50.c
Autor: Ratwor
Fecha: 27/12/2007
Descripción: El camino del norte de Marhalt.
****************************************************************************/

#include "./path.h"

inherit CAMINOS "/norte_marhalt/camino_base";
create(){
    ::create();
    AddExit("este", "./camino49");
    AddExit("noroeste",POMARHAB"sendero01");
}

