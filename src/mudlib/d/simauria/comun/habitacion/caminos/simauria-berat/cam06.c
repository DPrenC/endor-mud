
/****************************************************************************
Fichero: cam06.c
Autor: Ratwor
Fecha: 16/06/2007 17:32
Descripción: Camino Ihstria-Berat
****************************************************************************/
#include "./path.h"
inherit CAMINOS "/simauria-berat/camino";

create() {
    ::create();

    AddExit("sur","./cam07");
    AddExit("nordeste","./cam05");
}

