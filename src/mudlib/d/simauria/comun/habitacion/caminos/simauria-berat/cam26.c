/****************************************************************************
Fichero: cam26.c
Autor: Ratwor
Fecha: 29/09/2007
Descripción: El camino de Berat.
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";
create() {
    ::create();

    AddExit("suroeste","./cam27");
    AddExit("nordeste","./cam25");
}

