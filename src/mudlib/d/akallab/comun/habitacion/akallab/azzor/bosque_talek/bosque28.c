/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque28.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_TALEK("camino08"));
    AddExit("suroeste",BOSQUE_TALEK("bosque21"));
}
