/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque55.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("sudeste",BOSQUE_TALEK("bosque52"));
    AddExit("oeste",BOSQUE_TALEK("bosque54"));
}
