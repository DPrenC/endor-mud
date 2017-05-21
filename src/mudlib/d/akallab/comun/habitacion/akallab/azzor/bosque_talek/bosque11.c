/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque11.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("noroeste",BOSQUE_TALEK("bosque19"));
    AddExit("oeste",BOSQUE_TALEK("bosque10"));
    AddExit("este",BOSQUE_TALEK("bosque12"));
}
