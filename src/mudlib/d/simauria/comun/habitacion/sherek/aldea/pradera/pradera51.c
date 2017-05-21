/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/pradera/pradera51.c
Autor: Lug y Yalin
Fecha: 19/08/2006
Descripci�n: pradera al sur de la aldea.
****************************************************************************/

#include "path.h"
inherit SHERALD("pradera/pradera");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"La pradera se extiende a tu alrededor, en todas "
        "direcciones.\n");
    AddExit("norte", SHERALD("pradera/pradera41"));
    AddExit("sur", SHERALD("pradera/pradera61"));
    AddExit("este", SHERALD("pradera/pradera50"));
    AddExit("oeste", SHERALD("pradera/pradera52"));
    poner_pnj();
}