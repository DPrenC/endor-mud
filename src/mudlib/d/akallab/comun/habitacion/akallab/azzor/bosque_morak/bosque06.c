/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque05.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_MORAK("camino04"));
    AddExit("este",BOSQUE_MORAK("bosque20"));
    AddExit("oeste",BOSQUE_MORAK("bosque04"));
}
