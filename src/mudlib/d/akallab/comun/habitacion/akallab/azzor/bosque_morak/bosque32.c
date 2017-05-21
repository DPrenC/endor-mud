/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque32.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_MORAK("bosque31"));
    AddExit("nordeste",BOSQUE_MORAK("bosque29"));
    AddExit("oeste",BOSQUE_MORAK("bosque33"));
}
