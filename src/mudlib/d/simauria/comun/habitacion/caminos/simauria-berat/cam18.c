
/****************************************************************************
Fichero: cam18.c
Autor: Ratwor
Fecha: 16/06/2007 17:45
Descripción: Camino Ishtria-Berat.
****************************************************************************/
#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";

create() {
    ::create();

    AddExit("sur","./cam19");
    AddExit("norte","./cam17");
}

