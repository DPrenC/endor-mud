/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque01.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_TALEK("bosque07"));
    AddExit("noroeste",BOSQUE_TALEK("bosque06"));
}
