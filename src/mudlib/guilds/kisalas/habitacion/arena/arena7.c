/****************************************************************************
Fichero: arena7.c
Autor: Kastwey
Fecha: 19/02/2006
Descripción: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();

    SetIntLong("Al sur, un saliente natural se adentra en el lago, mientras el "
               "bosque continúa en todas direcciones.\n");

    AnadeDetalleLago("sur");

    AddExit("oeste","arena4");
    AddExit("este","arena8");
    AddExit("norte","arena9");
    AddExit("noroeste","arena1");
    AddExit("nordeste","arena10");
    AddExit("sur","arena5");
    AddExit("sudeste","arena6");





}


