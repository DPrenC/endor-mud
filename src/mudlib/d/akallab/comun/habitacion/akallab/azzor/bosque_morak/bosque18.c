/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque18.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit BOSQUE_MORAK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_MORAK("bosque03"));
    AddExit("nordeste",BOSQUE_MORAK("bosque19"));
    AddExit("este",BOSQUE_MORAK("bosque36"));
    AddExit("oeste",BOSQUE_MORAK("bosque17"));
}
