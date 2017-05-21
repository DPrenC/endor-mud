/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque35.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("sur",BOSQUE_TALEK("camino03"));
    AddExit("oeste",BOSQUE_TALEK("bosque34"));
}
