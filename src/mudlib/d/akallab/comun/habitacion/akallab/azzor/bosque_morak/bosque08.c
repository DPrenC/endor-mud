/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque08.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("sur",BOSQUE_MORAK("bosque05"));
    AddExit("oeste",BOSQUE_MORAK("bosque22"));
    AddExit("este",BOSQUE_MORAK("camino10"));
}
