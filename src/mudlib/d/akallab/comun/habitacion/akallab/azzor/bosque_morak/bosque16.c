/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque16.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_MORAK("cantera1"));
    AddExit("este",BOSQUE_MORAK("camino05"));
    AddExit("oeste",BOSQUE_MORAK("bosque40"));
}
