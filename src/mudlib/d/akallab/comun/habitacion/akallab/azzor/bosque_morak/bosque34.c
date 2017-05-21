/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque34.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_MORAK("bosque35"));
    AddExit("nordeste",BOSQUE_MORAK("bosque33"));
    AddExit("oeste",BOSQUE_MORAK("bosque36"));
}
