/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque08.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("oeste",BOSQUE_TALEK("bosque07"));
    AddExit("este",BOSQUE_TALEK("bosque09"));
}
