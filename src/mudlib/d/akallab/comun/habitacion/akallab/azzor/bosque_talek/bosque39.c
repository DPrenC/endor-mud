/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque39.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("sudeste",BOSQUE_TALEK("bosque33"));
    AddExit("sur",BOSQUE_TALEK("bosque32"));
    AddExit("norte",BOSQUE_TALEK("bosque46"));
}
