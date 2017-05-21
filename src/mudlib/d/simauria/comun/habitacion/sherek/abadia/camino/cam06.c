/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/cam06.c
Autor: Yalin
Fecha: 21/06/2009 23:02
Descripci�n: Camino de monta�a hacia la abad�a
****************************************************************************/

#include "path.h"
inherit SHERAB("std/camino");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"En este punto se desv�a un poco al noroeste, para aproximarse a la "
        "cantera, con el objeto de aprovechar el terreno ya aplanado por el continuo deslizamiento "
        "de los grandes bloques de piedra.\n");
    AddExit("noroeste", SHERAB("camino/cam07"));
    AddExit("sur", SHERAB("camino/cam05"));
}
