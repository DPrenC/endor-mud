/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque17.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_TALEK("bosque26"));
    AddExit("oeste",BOSQUE_TALEK("bosque16"));
    AddExit("suroeste",BOSQUE_TALEK("bosque07"));
}
