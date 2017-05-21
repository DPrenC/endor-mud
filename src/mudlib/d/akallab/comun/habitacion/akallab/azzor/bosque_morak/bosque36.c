/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque36.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("este",BOSQUE_MORAK("bosque34"));
    AddExit("oeste",BOSQUE_MORAK("bosque18"));
}
