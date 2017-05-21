/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque03.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_MORAK("camino02"));
    AddExit("sur",BOSQUE_MORAK("bosque18"));
    AddExit("oeste",BOSQUE_MORAK("bosque00"));
}
