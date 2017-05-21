/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque30.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("este",BOSQUE_MORAK("bosque12"));
    AddExit("sur",BOSQUE_MORAK("bosque31"));
    AddExit("oeste",BOSQUE_MORAK("camino06"));
}
