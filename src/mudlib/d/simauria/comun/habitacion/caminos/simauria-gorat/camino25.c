/****************************************************************************
Fichero: camino25.c
Autor: Ratwor
Fecha: 12/11/2006
Descripción: El nuevo camino Gorat-Ishtria
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-gorat/camino_base";
create()
{
    ::create();

    AddExit("oeste", "./camino26");
    AddExit("sur", "./camino24");
}
