/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque00.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_MORAK("camino01"));
    AddExit("este",BOSQUE_MORAK("bosque03"));
    AddExit("sur",BOSQUE_MORAK("bosque17"));
}
