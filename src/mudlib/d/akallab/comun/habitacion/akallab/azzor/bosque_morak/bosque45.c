/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque45.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_MORAK("bosque28"));
    AddExit("sudeste",BOSQUE_MORAK("bosque44"));
    AddExit("oeste",BOSQUE_MORAK("bosque39"));
}
