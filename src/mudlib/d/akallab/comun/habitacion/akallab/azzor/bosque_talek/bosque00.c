/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque00.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_TALEK("bosque05"));
}
