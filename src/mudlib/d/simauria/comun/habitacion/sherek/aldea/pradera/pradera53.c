/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/pradera/pradera53.c
Autor: Lug y Yalin
Fecha: 19/08/2006
Descripci�n: pradera al sur de la aldea.
****************************************************************************/

#include "path.h"
inherit SHERALD("pradera/pradera");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Un muro te cierra el paso hacia el oeste. En las "
        "dem�s direcciones contin�a la pradera.\n");
    AddDetail(({"muro","tapia"}), "Es un muro de piedra que separa la "
        "pradera de los vi�edos.\n");
    AddExit("norte", SHERALD("pradera/pradera43"));
    AddExit("sur", SHERALD("pradera/pradera63"));
    AddExit("este", SHERALD("pradera/pradera52"));
    poner_pnj();
}
