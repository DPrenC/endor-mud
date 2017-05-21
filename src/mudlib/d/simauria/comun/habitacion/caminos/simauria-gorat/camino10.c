/****************************************************************************
Fichero: camino10.c
Autor: Ratwor
Fecha: 12/11/2006
Descripción: El nuevo camino Gorat-Ishtria
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-gorat/camino_base";
create()
{
    ::create();

    AddExit("noroeste", "./camino11");
    AddExit("este", "./camino09");
}
