/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/pradera/pradera11.c
Autor: Lug y Yalin
Fecha: 19/08/2006
Descripción: pradera al sur de la aldea.
****************************************************************************/

#include "path.h"
inherit SHERALD("pradera/pradera");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"La pradera se extiende a tu alrededor, en todas "
        "direcciones.\n");
    AddExit("norte", SHERALD("pradera/pradera01"));
    AddExit("sur", SHERALD("pradera/pradera21"));
    AddExit("este", SHERALD("pradera/pradera10"));
    AddExit("oeste", SHERALD("pradera/pradera12"));
    poner_pnj();
}
