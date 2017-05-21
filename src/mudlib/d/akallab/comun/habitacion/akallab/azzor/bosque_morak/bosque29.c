/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque29.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_MORAK("bosque12"));
    AddExit("suroeste",BOSQUE_MORAK("bosque32"));
    AddExit("oeste",BOSQUE_MORAK("bosque31"));
}
