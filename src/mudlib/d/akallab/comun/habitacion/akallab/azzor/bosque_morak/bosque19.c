/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque19.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_MORAK("bosque04"));
    AddExit("este",BOSQUE_MORAK("bosque35"));
    AddExit("suroeste",BOSQUE_MORAK("bosque18"));
}
