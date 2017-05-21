
/****************************************************************************
Fichero: cam12.c
Autor: Ratwor
Fecha: 16/06/2007 17:40
Descripción: Camino Ishtria-Berat
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";

create() {
    ::create();

    AddExit("sur","./cam13");
    AddExit("noroeste","./cam11");
}

