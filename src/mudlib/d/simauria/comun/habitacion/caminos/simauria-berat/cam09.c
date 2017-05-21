
/****************************************************************************
Fichero: cam09.c
Autor: Ratwor
Fecha: 16/06/2007 17:37
Descripción: Camino Ishtria-Berat
****************************************************************************/
#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";

create() {
    ::create();

    AddExit("sur","./cam10");
    AddExit("nordeste","./cam08");
}

