/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque19.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_TALEK("camino04"));
    AddExit("sudeste",BOSQUE_TALEK("bosque11"));
    AddExit("oeste",BOSQUE_TALEK("bosque18"));
}
