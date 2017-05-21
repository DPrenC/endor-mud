/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/pradera/pradera12.c
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
    AddExit("norte", SHERALD("pradera/pradera02"));
    AddExit("sur", SHERALD("pradera/pradera22"));
    AddExit("este", SHERALD("pradera/pradera11"));
    AddExit("oeste", SHERALD("pradera/pradera13"));
    poner_pnj();
}
