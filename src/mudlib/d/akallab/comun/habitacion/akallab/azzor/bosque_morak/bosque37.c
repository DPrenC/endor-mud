/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque37.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("suroeste",BOSQUE_MORAK("bosque13"));
    AddExit("este",BOSQUE_MORAK("bosque44"));
}
