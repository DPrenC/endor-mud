/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque12.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_MORAK("camino08"));
    AddExit("sur",BOSQUE_MORAK("bosque29"));
    AddExit("oeste",BOSQUE_MORAK("bosque30"));
}
