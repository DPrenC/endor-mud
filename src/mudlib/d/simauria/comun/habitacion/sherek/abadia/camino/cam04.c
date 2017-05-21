/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/cam04.c
Autor: Yalin
Fecha: 21/06/2009 23:02
Descripci�n: Camino de monta�a hacia la abad�a
****************************************************************************/

#include "path.h"
inherit SHERAB("std/camino");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"El camino trepa por la falda de la monta�a, dirigi�ndose a la "
        "abad�a situada en la cima.\n");
    AddExit("norte", SHERAB("camino/cam05"));
    AddExit("sur", SHERAB("camino/cam03"));
}
