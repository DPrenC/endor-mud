/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque44.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("sur",BOSQUE_MORAK("bosque23"));
    AddExit("oeste",BOSQUE_MORAK("bosque37"));
    AddExit("noroeste",BOSQUE_MORAK("bosque45"));
}
