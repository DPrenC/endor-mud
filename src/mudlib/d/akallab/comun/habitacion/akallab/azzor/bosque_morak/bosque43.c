/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque43.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_MORAK("bosque42"));
    AddExit("este",BOSQUE_MORAK("bosque41"));
}
