
/****************************************************************************
Fichero: cam2.c
Autor: Ratwor
Fecha: 16/06/2007
Descripción: Camino Ishtria-Berat.
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";

create() {
    ::create();

    AddExit("sur","./cam03");
    AddExit("nordeste","./cam01");
}

