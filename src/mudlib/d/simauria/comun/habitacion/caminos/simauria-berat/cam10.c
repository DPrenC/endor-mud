
/****************************************************************************
Fichero: cam10.c
Autor: Ratwor
Fecha: 16/06/2007
Descripci�n: Camino Ishtria-Berat.
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";

create() {
    ::create();

    AddExit("sur","./cam11");
    AddExit("norte","./cam09");
}

