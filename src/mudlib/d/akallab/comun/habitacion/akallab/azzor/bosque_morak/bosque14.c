/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque14.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("oeste",BOSQUE_MORAK("bosque38"));
    AddExit("sur",BOSQUE_MORAK("bosque22"));
    AddExit("este",BOSQUE_MORAK("camino11"));
}
