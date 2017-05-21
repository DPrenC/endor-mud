/****************************************************************************
Fichero: camino06.c
Autor: Ratwor
Fecha: 27/12/2007
Descripción: El camino del norte de Marhalt.
****************************************************************************/

#include "./path.h"

inherit CAMINOS "/norte_marhalt/camino_base";
create(){
    ::create();
    AddExit("nordeste", "./camino07");
    AddExit("sur", "./camino05");
}

