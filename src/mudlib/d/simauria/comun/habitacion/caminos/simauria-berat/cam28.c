/****************************************************************************
Fichero: cam28.c
Autor: Ratwor
Fecha: 29/09/2007
Descripción: El camino de Berat.
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";
create() {
    ::create();

    AddExit("sur","./cam29");
    AddExit("noroeste","./cam27");
}

