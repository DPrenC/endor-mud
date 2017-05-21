
/****************************************************************************
Fichero: cam29.c
Autor: Ratwor
Fecha: 21/01/2007
Descripción: camino nandor-ishtria.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

create() {
    ::create();
    SetIntLong(QueryIntLong()+ "Un ancho hueco entre la vegetación del bosque te "
        "permite adentrarte, sin dificultad, hacia el este.\n");
    AddExit("oeste","./cam30");
    AddExit("norte","./cam28");
    AddExit("este", MARH("nandor/bosque/bosque125"));
    AddExit("sudeste", MARH("nandor/bosque/bosque131"));
    HideExit("sudeste",1);
}

