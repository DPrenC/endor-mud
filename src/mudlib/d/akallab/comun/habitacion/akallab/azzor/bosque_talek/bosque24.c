/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque24.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("nordeste",BOSQUE_TALEK("bosque30"));
    AddExit("este",BOSQUE_TALEK("bosque25"));
}
