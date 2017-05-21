/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque02.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("sur",BOSQUE_MORAK("camino01"));
    AddExit("oeste",BOSQUE_MORAK("bosque47"));
    AddExit("este",BOSQUE_MORAK("bosque05"));
}
