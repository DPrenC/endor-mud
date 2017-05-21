/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque25.c
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
    SetIntLong("Te encuentras en la orilla de un arroyo cuyas aguas bajan de "
        "forma rápida e impetuosa por su irregular cauce a través del bosque. "
        "La húmeda tierra de su orilla cede bajo tus pasos.\n"+QueryIntLong());
#include "arroyo.h"
    AddExit("noroeste",BOSQUE_MORAK("bosque27"));
    AddExit("oeste",BOSQUE_MORAK("bosque26"));
    AddExit("sur",BOSQUE_MORAK("bosque24"));
}
