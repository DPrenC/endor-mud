/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque05.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("sur",BOSQUE_TALEK("bosque00"));
    AddExit("este",BOSQUE_TALEK("bosque06"));
    AddExit("nordeste",BOSQUE_TALEK("bosque15"));
}
