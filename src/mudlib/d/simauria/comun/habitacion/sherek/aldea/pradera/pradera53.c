/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/pradera/pradera53.c
Autor: Lug y Yalin
Fecha: 19/08/2006
Descripción: pradera al sur de la aldea.
****************************************************************************/

#include "path.h"
inherit SHERALD("pradera/pradera");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Un muro te cierra el paso hacia el oeste. En las "
        "demás direcciones continúa la pradera.\n");
    AddDetail(({"muro","tapia"}), "Es un muro de piedra que separa la "
        "pradera de los viñedos.\n");
    AddExit("norte", SHERALD("pradera/pradera43"));
    AddExit("sur", SHERALD("pradera/pradera63"));
    AddExit("este", SHERALD("pradera/pradera52"));
    poner_pnj();
}
