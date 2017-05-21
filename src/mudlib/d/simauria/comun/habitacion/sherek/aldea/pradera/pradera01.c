/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/pradera/pradera01.c
Autor: Lug y Yalin
Fecha: 19/08/2006
Descripción: pradera al sur de la aldea.
****************************************************************************/

#include "path.h"
inherit SHERALD("pradera/pradera");

create()
{
    ::create();
    SetLocate("Aldea de Sloch");
    SetIntShort("una pradera al sur de la aldea");
    SetIntLong(QueryIntLong()+"Al norte se halla el camino a la aldea, mientras "
        "que la pradera continúa en las demás direcciones.\n");
    AddExit("norte", SHERALD("calles/caminop"));
    AddExit("sur", SHERALD("pradera/pradera11"));
    AddExit("este", SHERALD("pradera/pradera00"));
    AddExit("oeste", SHERALD("pradera/pradera02"));
    poner_pnj();
}
