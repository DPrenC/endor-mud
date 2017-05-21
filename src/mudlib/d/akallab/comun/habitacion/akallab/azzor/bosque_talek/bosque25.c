/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque25.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("sur",BOSQUE_TALEK("bosque16"));
    AddExit("oeste",BOSQUE_TALEK("bosque24"));
}
