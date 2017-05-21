/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/cam17.c
Autor: Yalin
Fecha: 04/07/2009 23:07
Descripción: Camino de montaña hacia la abadía
****************************************************************************/

#include "path.h"
inherit SHERAB("std/camino");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"El camino se dirige al norte prácticamente en línea recta, "
        "ascendiendo hacia la abadía, cuya silueta puede ya vislumbrarse desde aquí, y "
        "descendiendo por el sur hacia el valle.\n");
    AddExit("norte", SHERAB("camino/cam18"));
    AddExit("sur", SHERAB("camino/cam16"));
}
