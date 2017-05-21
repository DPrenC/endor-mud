/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque42.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("noroeste",BOSQUE_TALEK("bosque47"));
    AddExit("sudeste",BOSQUE_TALEK("bosque36"));
    AddExit("este",BOSQUE_TALEK("bosque43"));
}
