/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque13.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("nordeste",BOSQUE_TALEK("bosque23"));
    AddExit("oeste",BOSQUE_TALEK("bosque12"));
    AddExit("norte",BOSQUE_TALEK("bosque22"));
}
