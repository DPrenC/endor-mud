/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque47.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("nordeste",BOSQUE_MORAK("bosque22"));
    AddExit("este",BOSQUE_MORAK("bosque02"));
    AddExit("sur",BOSQUE_MORAK("bosque01"));
}
