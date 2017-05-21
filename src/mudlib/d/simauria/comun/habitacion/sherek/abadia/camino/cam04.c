/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/cam04.c
Autor: Yalin
Fecha: 21/06/2009 23:02
Descripción: Camino de montaña hacia la abadía
****************************************************************************/

#include "path.h"
inherit SHERAB("std/camino");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"El camino trepa por la falda de la montaña, dirigiéndose a la "
        "abadía situada en la cima.\n");
    AddExit("norte", SHERAB("camino/cam05"));
    AddExit("sur", SHERAB("camino/cam03"));
}
