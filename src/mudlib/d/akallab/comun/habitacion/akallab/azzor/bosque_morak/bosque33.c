/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque33.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_MORAK("bosque20"));
    AddExit("este",BOSQUE_MORAK("bosque32"));
    AddExit("suroeste",BOSQUE_MORAK("bosque34"));
    AddExit("oeste",BOSQUE_MORAK("bosque35"));
}
