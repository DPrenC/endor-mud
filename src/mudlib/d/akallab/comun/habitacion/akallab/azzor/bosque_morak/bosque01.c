/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque01.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("este",BOSQUE_MORAK("camino01"));
    AddExit("norte",BOSQUE_MORAK("bosque47"));
}
