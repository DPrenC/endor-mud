/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque04.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("oeste",BOSQUE_MORAK("camino02"));
    AddExit("este",BOSQUE_MORAK("bosque06"));
    AddExit("sur",BOSQUE_MORAK("bosque19"));
}
