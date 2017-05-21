/****************************************************************************
Fichero: camino27.c
Autor: Ratwor
Fecha: 24/12/2007
Descripción: El camino del castillo
****************************************************************************/

#include "./path.h"

inherit CASTILLO("camino/camino_base");
create(){
    ::create();
    SetIntShort("el sendero de la colina, frente al castillo");
    AddExit("noroeste", "./camino28");
    AddExit("sur", "./camino26");
}

