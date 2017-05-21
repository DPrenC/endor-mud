/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque46.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("suroeste",BOSQUE_TALEK("bosque38"));
    AddExit("oeste",BOSQUE_TALEK("bosque45"));
    AddExit("sur",BOSQUE_TALEK("bosque39"));
}
