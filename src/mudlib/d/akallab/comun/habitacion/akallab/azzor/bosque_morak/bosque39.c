/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque39.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_MORAK("bosque46"));
    AddExit("este",BOSQUE_MORAK("bosque45"));
    AddExit("sur",BOSQUE_MORAK("bosque15"));
    AddExit("oeste",BOSQUE_MORAK("cantera0"));
}
