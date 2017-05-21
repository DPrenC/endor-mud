/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque33.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("sur",BOSQUE_TALEK("camino10"));
    AddExit("noroeste",BOSQUE_TALEK("bosque39"));
}
