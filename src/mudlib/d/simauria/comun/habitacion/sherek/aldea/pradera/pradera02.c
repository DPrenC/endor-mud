/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/pradera/pradera02.c
Autor: Lug y Yalin
Fecha: 19/08/2006
Descripci�n: pradera al sur de la aldea.
****************************************************************************/

#include "path.h"
inherit SHERALD("pradera/pradera");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al norte el l�mite de la aldea te impide seguir, "
        "mientras que la pradera contin�a en las dem�s direcciones.\n");
    AddExit("sur", SHERALD("pradera/pradera12"));
    AddExit("este", SHERALD("pradera/pradera01"));
    AddExit("oeste", SHERALD("pradera/pradera03"));
    poner_pnj();
}
