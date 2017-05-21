/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque69.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("nordeste",BOSQUE_TALEK("bosque72"));
    AddExit("este",BOSQUE_TALEK("bosque70"));
    AddExit("sur",BOSQUE_TALEK("bosque65"));
}
