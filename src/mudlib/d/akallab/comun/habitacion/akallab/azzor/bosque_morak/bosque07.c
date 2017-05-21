/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque07.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("sur",BOSQUE_MORAK("camino04"));
    AddExit("norte",BOSQUE_MORAK("bosque21"));
}
