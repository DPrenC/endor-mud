/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/cam13.c
Autor: Yalin
Fecha: 21/06/2009 23:02
Descripci�n: Camino de monta�a hacia la abad�a
****************************************************************************/

#include "path.h"
inherit SHERAB("std/camino");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"En este punto gira al nordeste, dejando la cantera al sur para "
        "acercarse a la ribera del Kandal, al tiempo que contin�a su ascenso hacia la abad�a "
        "situada en la cima.\n");
    AddExit("nordeste", SHERAB("camino/cam14"));
    AddExit("sur", SHERAB("camino/cam12"));
}
