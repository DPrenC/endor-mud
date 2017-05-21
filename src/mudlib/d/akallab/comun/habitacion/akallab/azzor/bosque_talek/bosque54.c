/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque54.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("noroeste",BOSQUE_TALEK("bosque57"));
    AddExit("nordeste",BOSQUE_TALEK("bosque59"));
    AddExit("este",BOSQUE_TALEK("bosque55"));
    AddExit("sur",BOSQUE_TALEK("bosque50"));
}
