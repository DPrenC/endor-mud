/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque21.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_TALEK("claro00"));
    AddExit("nordeste",BOSQUE_TALEK("bosque28"));
    AddExit("este",BOSQUE_TALEK("bosque22"));
}
