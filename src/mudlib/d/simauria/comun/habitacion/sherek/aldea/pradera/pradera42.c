/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/pradera/pradera42.c
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
    AddExit("norte", SHERALD("pradera/pradera32"));
    AddExit("sur", SHERALD("pradera/pradera52"));
    AddExit("este", SHERALD("pradera/pradera41"));
    AddExit("oeste", SHERALD("pradera/pradera43"));
    poner_pnj();
}
