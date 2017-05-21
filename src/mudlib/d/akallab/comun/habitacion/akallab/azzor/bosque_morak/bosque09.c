/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque09.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("este",BOSQUE_MORAK("bosque11"));
    AddExit("oeste",BOSQUE_MORAK("bosque23"));
    AddExit("sur",BOSQUE_MORAK("camino07"));
}
