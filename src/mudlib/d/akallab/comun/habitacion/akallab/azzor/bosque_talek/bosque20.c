/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque20.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_TALEK("camino05"));
    AddExit("sudeste",BOSQUE_TALEK("bosque12"));
}
