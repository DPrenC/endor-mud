
/****************************************************************************
Fichero: cam17.c
Autor: Ratwor
Fecha: 16/06/2007 17:44
Descripción: Camino Ishtria-Berat.
****************************************************************************/
#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";

create() {
    ::create();

    AddExit("sur","./cam18");
    AddExit("nordeste","./cam16");
}

