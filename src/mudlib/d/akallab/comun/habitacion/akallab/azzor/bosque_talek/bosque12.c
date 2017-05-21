/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque12.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("noroeste",BOSQUE_TALEK("bosque20"));
    AddExit("oeste",BOSQUE_TALEK("bosque11"));
    AddExit("este",BOSQUE_TALEK("bosque13"));
}
