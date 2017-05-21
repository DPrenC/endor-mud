/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque24.c
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
    SetIntLong("El agua del arroyo que queda al este discurre impetuosa por "
        "su cauce atravesando el bosque de Morak en dirección al sur. "
        "Sientes la blanda y húmeda tierra de la orilla bajo tus pies\n"+
        QueryIntLong());
#include "arroyo.h"
    AddExit("sudeste",BOSQUE_MORAK("bosque11"));
    AddExit("norte",BOSQUE_MORAK("bosque25"));
}
