
/****************************************************************************
Fichero: cam17.c
Autor: Ratwor
Fecha: 21/01/2007
Descripci�n: camino nandor-ishtria
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();
    SetIntLong(QueryIntLong()+ "Entre la vegetaci�n del bosque, una peque�a senda te "
        "permite introducirte hacia el este.\n");
    AddExit("sur","./cam18");
    AddExit("norte","./cam16");
    AddExit("este", MARH("nandor/bosque/bosque069"));
}

