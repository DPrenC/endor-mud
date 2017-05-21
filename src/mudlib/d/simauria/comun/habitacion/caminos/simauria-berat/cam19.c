
/****************************************************************************
Fichero: cam19.c
Autor: Ratwor
Fecha: 16/06/2007 17:46
Descripción: Camino Ishtria-Berat.
****************************************************************************/
#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";

create() {
    ::create();

    AddExit("sur","./cam20");
    AddExit("norte","./cam18");
}

