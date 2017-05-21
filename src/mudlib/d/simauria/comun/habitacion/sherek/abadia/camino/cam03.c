/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/cam03.c
Autor: Yalin
Fecha: 21/06/2009 23:02
Descripción: Camino de montaña hacia la abadía
****************************************************************************/

#include "path.h"
inherit SHERAB("std/camino");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"El camino continúa en línea recta hacia el norte para dirigirse a "
        "la cima de la montaña donde se encuentra la abadía, mientras que desciende en dirección "
        "sur hacia el camino que lleva a las lejanas tierras de Marhalt.\n");
    AddExit("norte", SHERAB("camino/cam04"));
    AddExit("sur", SHERAB("camino/cam02"));
}
