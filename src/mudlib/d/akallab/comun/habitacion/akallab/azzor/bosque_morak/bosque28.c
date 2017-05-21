/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque28.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("sur",BOSQUE_MORAK("bosque45"));
    AddExit("este",BOSQUE_MORAK("bosque27"));
}
