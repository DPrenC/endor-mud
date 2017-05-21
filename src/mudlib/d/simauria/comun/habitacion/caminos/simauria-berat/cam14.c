
/****************************************************************************
Fichero: cam14.c
Autor: Ratwor
Fecha: 16/06/2007 17:42
Descripción: Camino Ishtria-Berat
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";

create() {
    ::create();

    AddExit("suroeste","./cam15");
    AddExit("norte","./cam13");
}

