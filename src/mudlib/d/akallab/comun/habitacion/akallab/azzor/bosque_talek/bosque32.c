/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque32.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("sur",BOSQUE_TALEK("camino09"));
    AddExit("norte",BOSQUE_TALEK("bosque39"));
}
