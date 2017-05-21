
/****************************************************************************
Fichero: cam15.c
Autor: Ratwor
Fecha: 16/06/2007 17:43
Descripción: Camino Ishtria-Berat.
****************************************************************************/
#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";

create() {
    ::create();

    AddExit("sur","./cam16");
    AddExit("nordeste","./cam14");
}

