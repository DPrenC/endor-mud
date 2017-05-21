/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque72.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("este",BOSQUE_TALEK("camino20"));
    AddExit("suroeste",BOSQUE_TALEK("bosque69"));
}
