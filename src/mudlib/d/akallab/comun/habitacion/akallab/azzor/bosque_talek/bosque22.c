/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque22.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("sur",BOSQUE_TALEK("bosque13"));
    AddExit("oeste",BOSQUE_TALEK("bosque21"));
    AddExit("este",BOSQUE_TALEK("bosque23"));
}
