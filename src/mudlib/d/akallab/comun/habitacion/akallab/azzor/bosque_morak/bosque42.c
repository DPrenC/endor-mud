/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque42.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("nordeste",BOSQUE_MORAK("bosque40"));
    AddExit("sudeste",BOSQUE_MORAK("bosque41"));
    AddExit("sur",BOSQUE_MORAK("bosque43"));
}
