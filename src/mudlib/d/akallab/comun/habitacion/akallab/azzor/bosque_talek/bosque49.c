/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque49.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_TALEK("camino14"));
    AddExit("este",BOSQUE_TALEK("camino13"));
}
