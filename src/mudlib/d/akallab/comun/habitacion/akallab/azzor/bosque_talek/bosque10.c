/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque10.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("suroeste",BOSQUE_TALEK("bosque03"));
    AddExit("sur",BOSQUE_TALEK("bosque04"));
    AddExit("este",BOSQUE_TALEK("bosque11"));
}
