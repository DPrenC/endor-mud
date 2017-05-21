
/****************************************************************************
Fichero: cam11.c
Autor: Ratwor
Fecha: 16/06/2007 17:39
Descripción: Camino Ishtria-Berat.
****************************************************************************/
#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";

create() {
    ::create();

    AddExit("sudeste","./cam12");
    AddExit("norte","./cam10");
}

