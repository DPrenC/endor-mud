/****************************************************************************
Fichero: camino05.c
Autor: Ratwor
Fecha: 12/11/2006
Descripci�n: El nuevo camino Gorat-Ishtria
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-gorat/camino_base";
create()
{
    ::create();

    AddExit("suroeste", "./camino06");
    AddExit("este", "./camino04");
}
