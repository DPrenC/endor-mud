/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque26.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_TALEK("camino02"));
    AddExit("este",BOSQUE_TALEK("bosque27"));
    AddExit("sudeste",BOSQUE_TALEK("bosque18"));
    AddExit("sur",BOSQUE_TALEK("bosque17"));
}
