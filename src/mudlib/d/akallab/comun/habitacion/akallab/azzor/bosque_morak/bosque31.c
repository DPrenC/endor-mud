/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque31.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_MORAK("bosque30"));
    AddExit("sur",BOSQUE_MORAK("bosque32"));
    AddExit("este",BOSQUE_MORAK("bosque29"));
}
