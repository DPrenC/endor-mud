/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque35.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("este",BOSQUE_MORAK("bosque33"));
    AddExit("oeste",BOSQUE_MORAK("bosque19"));
    AddExit("sur",BOSQUE_MORAK("bosque34"));
}
