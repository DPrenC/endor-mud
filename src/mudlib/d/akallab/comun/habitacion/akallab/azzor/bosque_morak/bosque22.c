/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque22.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_MORAK("bosque14"));
    AddExit("este",BOSQUE_MORAK("bosque08"));
    AddExit("suroeste",BOSQUE_MORAK("bosque47"));
    AddExit("oeste",BOSQUE_MORAK("bosque41"));
}
