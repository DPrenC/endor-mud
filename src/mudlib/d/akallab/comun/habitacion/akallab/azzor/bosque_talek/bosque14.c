/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque14.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Ves una pequenya cueva al norte de aqui.\n");
    AddExit("este",BOSQUE_TALEK("bosque15"));
    AddExit("norte",BOSQUE_TALEK("cueva"));
}

