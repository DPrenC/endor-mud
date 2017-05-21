/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque15.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("oeste",BOSQUE_TALEK("bosque14"));
    AddExit("suroeste",BOSQUE_TALEK("bosque05"));
    AddExit("este",BOSQUE_TALEK("bosque16"));
}
