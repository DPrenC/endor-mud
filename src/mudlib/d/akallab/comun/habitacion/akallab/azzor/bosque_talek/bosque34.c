/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque34.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("sur",BOSQUE_TALEK("camino02"));
    AddExit("oeste",BOSQUE_TALEK("camino01"));
    AddExit("norte",BOSQUE_TALEK("bosque41"));
    AddExit("este",BOSQUE_TALEK("bosque35"));
}
