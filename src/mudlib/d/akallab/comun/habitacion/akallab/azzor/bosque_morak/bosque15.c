/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque15.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("oeste",BOSQUE_MORAK("camino05"));
    AddExit("norte",BOSQUE_MORAK("bosque39"));
}
