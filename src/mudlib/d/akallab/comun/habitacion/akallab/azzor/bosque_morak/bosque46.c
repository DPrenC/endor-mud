/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque46.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("sur",BOSQUE_MORAK("bosque39"));
    AddExit("oeste",BOSQUE_MORAK("cantera2"));
}
