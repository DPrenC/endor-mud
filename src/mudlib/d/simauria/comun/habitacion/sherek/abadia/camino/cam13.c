/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/cam13.c
Autor: Yalin
Fecha: 21/06/2009 23:02
Descripción: Camino de montaña hacia la abadía
****************************************************************************/

#include "path.h"
inherit SHERAB("std/camino");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"En este punto gira al nordeste, dejando la cantera al sur para "
        "acercarse a la ribera del Kandal, al tiempo que continúa su ascenso hacia la abadía "
        "situada en la cima.\n");
    AddExit("nordeste", SHERAB("camino/cam14"));
    AddExit("sur", SHERAB("camino/cam12"));
}
