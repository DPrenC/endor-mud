/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque10.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("este",BOSQUE_MORAK("camino07"));
    AddExit("sur",BOSQUE_MORAK("camino06"));
}
