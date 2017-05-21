/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque41.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("este",BOSQUE_MORAK("bosque22"));
    AddExit("noroeste",BOSQUE_MORAK("bosque42"));
    AddExit("oeste",BOSQUE_MORAK("bosque43"));
}
