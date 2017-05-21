/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/pradera/pradera03.c
Autor: Lug y Yalin
Fecha: 19/08/2006
Descripción: pradera al sur de la aldea.
****************************************************************************/

#include "path.h"
inherit SHERALD("pradera/pradera");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Un muro te cierra el paso hacia el oeste, "
        "mientras que al norte se encuentra el límite de la aldea. La "
        "pradera continúa al sur y al este.\n");
    AddDetail(({"muro","tapia"}), "Es un muro de piedra que separa la "
        "pradera de los viñedos.\n");
    AddExit("sur", SHERALD("pradera/pradera13"));
    AddExit("este", SHERALD("pradera/pradera02"));
    poner_pnj();
}
