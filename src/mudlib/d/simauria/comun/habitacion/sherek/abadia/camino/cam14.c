/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/cam14.c
Autor: Yalin
Fecha: 25/06/2009 22:49
Descripción: Camino de montaña hacia la abadía
****************************************************************************/

#include "path.h"
inherit SHERAB("std/camino");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"El trazado continúa en dirección nordeste, alejándose de la "
        "cantera que queda al sur, acercándose algo más a la ribera del Kandal, mientras prosigue "
        "su ascenso hacia la abadía situada en la cima.\n");
    AddExit("nordeste", SHERAB("camino/cam15"));
    AddExit("suroeste", SHERAB("camino/cam13"));
}
