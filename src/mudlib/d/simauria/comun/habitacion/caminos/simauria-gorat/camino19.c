/****************************************************************************
Fichero: camino19.c
Autor: Ratwor
Fecha: 12/11/2006
Descripción: El nuevo camino Gorat-Ishtria
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-gorat/camino_base";
create()
{
    ::create();

    AddExit("suroeste", "./camino20");
    AddExit("este", "./camino18");
}
