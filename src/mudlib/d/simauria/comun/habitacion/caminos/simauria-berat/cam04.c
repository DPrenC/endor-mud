
/****************************************************************************
Fichero: cam04.c
Autor: Ratwor
Fecha: 16/06/2007 17:29
Descripción: Camino Ishtria-Berat.
****************************************************************************/
#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";

create() {
    ::create();

    AddExit("sudeste","./cam05");
    AddExit("norte","./cam03");
}

