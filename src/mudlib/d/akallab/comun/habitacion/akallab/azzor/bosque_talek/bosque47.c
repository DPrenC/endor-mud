/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque47.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("suroeste",BOSQUE_TALEK("bosque40"));
    AddExit("sudeste",BOSQUE_TALEK("bosque42"));
    AddExit("este",BOSQUE_TALEK("bosque48"));
}
