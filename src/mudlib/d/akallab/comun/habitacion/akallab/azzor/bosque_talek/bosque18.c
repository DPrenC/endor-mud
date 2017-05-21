/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque18.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("noroeste",BOSQUE_TALEK("bosque26"));
    AddExit("este",BOSQUE_TALEK("bosque19"));
    AddExit("sur",BOSQUE_TALEK("bosque09"));
}
