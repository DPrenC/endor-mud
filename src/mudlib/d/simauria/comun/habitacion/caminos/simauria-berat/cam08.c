
/****************************************************************************
Fichero: cam08.c
Autor: Ratwor
Fecha: 16/06/2007
Descripción: Camino Ishtria-Berat.
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";

create() {
    ::create();

    AddExit("suroeste","./cam09");
    AddExit("norte","./cam07");
}

