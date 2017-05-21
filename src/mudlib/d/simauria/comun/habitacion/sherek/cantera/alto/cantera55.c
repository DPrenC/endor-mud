/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera55.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
#include <moving.h>
inherit SHERCAN("alto/cantera");

private int IrAbajo()
{
    if (!TP->QueryAttribute("sabeminas")) return notify_fail("¡Vaya, pues no "
        "es una salida. sólo es un hoyo en la roca.\n",NOTIFY_NOT_VALID);
    write("Bajas con mucha desconfianza..., ¡y haces bien...!\n"
        "¡Brrrrrrún pataplúm!. De repente, no hallas suelo bajo tus pies, y "
        "caes desde gran altura.\nEl agujero de donde saliste, queda lejos, "
        "muchos metros arriba. No puedes volver por allí.\n");
    int celda, road, col;
    road = d6();
    col = d6();
    celda = 100+(road*10)+col;
    tell_room(SHERCAN("medio/cantera"+celda),CAP(TP->QueryName())+" cae "
        "misteriosamente desde arriba.\n");
    TP->SetFollowers(0);
    TP->AddHP(-10);
    return TP->move(SHERCAN("medio/cantera"+celda), M_GO);
}

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Un desprendimiento ha dejado lo que parece "
        "ser una galería hacia abajo.\n");
    AddExit("norte",SHERCAN("alto/cantera65"));
    AddExit("abajo",SF(IrAbajo));
    pongo();
}
