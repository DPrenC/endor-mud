/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/cam09.c
Autor: Yalin
Fecha: 21/06/2009 23:02
Descripción: Camino de montaña hacia la abadía
****************************************************************************/

#include "path.h"
inherit SHERAB("std/camino");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"El camino discurre en este tramo en paralelo a la cantera, "
        "probablemente para aprovechar el terreno alisado por el arrastre de las piedras.\n");
    AddExit("norte", SHERAB("camino/cam10"));
    AddExit("sur", SHERAB("camino/cam08"));
}
