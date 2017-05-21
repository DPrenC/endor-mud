/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque38.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("oeste",BOSQUE_TALEK("camino11"));
    AddExit("sur",BOSQUE_TALEK("camino08"));
    AddExit("nordeste",BOSQUE_TALEK("bosque46"));
}
