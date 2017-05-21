/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque36.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("noroeste",BOSQUE_TALEK("bosque42"));
    AddExit("sur",BOSQUE_TALEK("bosque31"));
}
