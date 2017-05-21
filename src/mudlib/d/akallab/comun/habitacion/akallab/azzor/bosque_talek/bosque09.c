/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque09.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("oeste",BOSQUE_TALEK("bosque08"));
    AddExit("sur",BOSQUE_TALEK("bosque03"));
    AddExit("norte",BOSQUE_TALEK("bosque18"));
}
