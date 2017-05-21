/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque13.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("nordeste",BOSQUE_MORAK("bosque37"));
    AddExit("este",BOSQUE_MORAK("bosque21"));
    AddExit("oeste",BOSQUE_MORAK("camino11"));
}
