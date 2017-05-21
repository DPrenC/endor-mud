/****************************************************************************
Fichero: camino26.c
Autor: Ratwor
Fecha: 12/11/2006
Descripción: El nuevo camino Gorat-Ishtria.
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-gorat/camino_base";
create()
{
    ::create();
    SetIntLong(QueryIntLong()+" Al suroeste empiezas a divisar unas construcciones que "
        "deben pertenecer a Gorat.\n");
    AddExit("suroeste", "./camino27");
    AddExit("este", "./camino25");
}
