/****************************************************************************
Fichero: cam24.c
Autor: Ratwor
Fecha: 29/09/2007
Descripci�n: El camino de Berat.
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";
create() {
    ::create();

    AddExit("sur","./cam25");
    AddExit("noroeste","./cam23");
}

