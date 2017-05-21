/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/cam08.c
Autor: Yalin
Fecha: 21/06/2009 23:02
Descripci�n: Camino de monta�a hacia la abad�a
****************************************************************************/

#include "path.h"
inherit SHERAB("std/camino");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"El camino discurre en este tramo en paralelo a la cantera, "
        "probablemente para aprovechar el terreno alisado por el arrastre de las piedras.\n");
    AddExit("norte", SHERAB("camino/cam09"));
    AddExit("sur", SHERAB("camino/cam07"));
}
