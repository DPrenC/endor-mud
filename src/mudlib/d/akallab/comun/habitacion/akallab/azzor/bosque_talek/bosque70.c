/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque70.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("oeste",BOSQUE_TALEK("bosque69"));
    AddExit("este",BOSQUE_TALEK("camino19"));
}
