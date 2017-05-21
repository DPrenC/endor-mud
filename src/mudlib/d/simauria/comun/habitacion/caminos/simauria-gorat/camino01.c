/****************************************************************************
Fichero: camino01.c
Autor: Ratwor
Fecha: 12/11/2006
Descripción: El nuevo camino Gorat-Ishtria
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-gorat/camino_base";

create()
{
    ::create();
    SetIntLong(QueryIntLong()+" Hacia el este se ve un cruce haciéndose un poco más "
        "espeso el bosque.\n");
    AddExit("este", CNS("cam18"));
    AddExit("oeste", "./camino02");
}
