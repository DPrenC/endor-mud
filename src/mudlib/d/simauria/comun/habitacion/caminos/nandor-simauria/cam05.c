/****************************************************************************
Fichero: cam05.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: Camino Nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");


create() {
    ::create();

    AddExit("sudeste","./cam06");
    AddExit("norte","./cam04");
    AddExit("este", MARH("nandor/bosque/bosque024"));
    HideExit("este",1);
}

