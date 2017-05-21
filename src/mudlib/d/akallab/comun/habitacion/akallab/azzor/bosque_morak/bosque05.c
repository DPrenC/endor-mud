/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque05.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("este",BOSQUE_MORAK("camino03"));
    AddExit("oeste",BOSQUE_MORAK("bosque02"));
    AddExit("norte",BOSQUE_MORAK("bosque08"));
}
