/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque16.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("oeste",BOSQUE_TALEK("bosque15"));
    AddExit("norte",BOSQUE_TALEK("bosque25"));
    AddExit("este",BOSQUE_TALEK("bosque17"));
}
