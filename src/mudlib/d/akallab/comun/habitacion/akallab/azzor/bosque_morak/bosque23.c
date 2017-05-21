/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque23.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_MORAK("bosque44"));
    AddExit("este",BOSQUE_MORAK("bosque09"));
    AddExit("oeste",BOSQUE_MORAK("bosque21"));
}
