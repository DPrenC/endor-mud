
/****************************************************************************
Fichero: cam20.c
Autor: Ratwor
Fecha: 16/06/2007 17:47
Descripci�n: Camino Ishtria-Berat.
****************************************************************************/
#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";

create() {
    ::create();

    AddExit("sudeste","./cam21");
    AddExit("norte","./cam19");
}

