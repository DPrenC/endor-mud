/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/cam17.c
Autor: Yalin
Fecha: 04/07/2009 23:07
Descripci�n: Camino de monta�a hacia la abad�a
****************************************************************************/

#include "path.h"
inherit SHERAB("std/camino");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"El camino se dirige al norte pr�cticamente en l�nea recta, "
        "ascendiendo hacia la abad�a, cuya silueta puede ya vislumbrarse desde aqu�, y "
        "descendiendo por el sur hacia el valle.\n");
    AddExit("norte", SHERAB("camino/cam18"));
    AddExit("sur", SHERAB("camino/cam16"));
}
