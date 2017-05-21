/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/pradera/pradera00.c
Autor: Lug y Yalin
Fecha: 19/08/2006
Descripción: pradera al sur de la aldea.
****************************************************************************/

#include "path.h"
inherit SHERALD("pradera/pradera");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Un muro te cierra el paso hacia el este, "
        "mientras que al norte se encuentra el límite de la aldea. La "
        "pradera continúa al sur y al oeste.\n");
    AddDetail(({"muro","tapia","pared"}), "Es la pared trasera de las "
        "dependencias de la granja.\n");
    AddExit("sur", SHERALD("pradera/pradera10"));
    AddExit("oeste", SHERALD("pradera/pradera01"));
    poner_pnj();
}
