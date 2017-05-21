/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque40.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("este",BOSQUE_MORAK("bosque16"));
    AddExit("sur",BOSQUE_MORAK("bosque38"));
    AddExit("suroeste",BOSQUE_MORAK("bosque42"));
}
