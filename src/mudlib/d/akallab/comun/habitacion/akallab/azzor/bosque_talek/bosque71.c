/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque71.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_TALEK("bosque73"));
    AddExit("oeste",BOSQUE_TALEK("camino19"));
    AddExit("sudeste",BOSQUE_TALEK("bosque68"));
}
