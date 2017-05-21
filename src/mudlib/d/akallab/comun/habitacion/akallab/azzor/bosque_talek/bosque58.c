/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque58.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("nordeste",BOSQUE_TALEK("bosque63"));
    AddExit("oeste",BOSQUE_TALEK("bosque57"));
}
