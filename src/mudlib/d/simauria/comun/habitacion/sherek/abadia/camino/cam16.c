/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/cam16.c
Autor: Yalin
Fecha: 25/06/2009 22:49
Descripción: Camino de montaña hacia la abadía
****************************************************************************/

#include "path.h"
inherit SHERAB("std/camino");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"En este punto gira de norte a suroeste, descendiendo desde la "
        "abadía situada en la cima hacia el valle del Kandal.\n");
    AddExit("norte", SHERAB("camino/cam17"));
    AddExit("suroeste", SHERAB("camino/cam15"));
}
