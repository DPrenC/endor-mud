
/****************************************************************************
Fichero: cam17.c
Autor: Ratwor
Fecha: 16/06/2007 17:44
Descripci�n: Camino Ishtria-Berat.
****************************************************************************/
#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";

create() {
    ::create();

    AddExit("sur","./cam18");
    AddExit("nordeste","./cam16");
}

