
/****************************************************************************
Fichero: cam3.c
Autor: Ratwor
Fecha: 16/06/2007 17:26
Descripción: Camino Ishtria-Berat.
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";

create() {
    ::create();

    AddExit("sur","./cam04");
    AddExit("norte","./cam02");
}

