/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque11.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    SetPreIntShort("junto a");
    SetIntShort("un arroyo en el bosque de Morak");
    SetIntLong("Te encuentras en la orilla de un arroyo que recorre el "
        "bosque. El arroyo, al este de aquí, avanza rápido serpenteando por "
        "un cauce pedregoso.\n"+QueryIntLong());
#include "arroyo.h"
    AddExit("oeste",BOSQUE_MORAK("bosque09"));
    AddExit("noroeste",BOSQUE_MORAK("bosque24"));
    AddExit("sur",BOSQUE_MORAK("camino08"));
}
