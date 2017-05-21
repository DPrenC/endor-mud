/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque45.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("nordeste",BOSQUE_TALEK("bosque52"));
    AddExit("oeste",BOSQUE_TALEK("bosque44"));
    AddExit("este",BOSQUE_TALEK("bosque46"));
}
