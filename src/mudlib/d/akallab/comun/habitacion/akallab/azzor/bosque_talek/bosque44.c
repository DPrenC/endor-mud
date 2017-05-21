/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque44.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_TALEK("bosque50"));
    AddExit("este",BOSQUE_TALEK("bosque45"));
    AddExit("oeste",BOSQUE_TALEK("camino12"));
}
