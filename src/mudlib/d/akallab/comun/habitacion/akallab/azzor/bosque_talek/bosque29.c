/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque29.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("este",BOSQUE_TALEK("bosque30"));
}
