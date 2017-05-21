/****************************************************************************
Fichero: cam01.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: Camino Nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();
    SetIntLong(QueryIntLong()+" hacia el norte se ve un cruce y más allá un grupo de "
        "casas que debe ser la villa de Nandor.\n");
    AddExit("sur","./cam02");
    AddExit("norte",MARH("/nandor/cruce"));
}

