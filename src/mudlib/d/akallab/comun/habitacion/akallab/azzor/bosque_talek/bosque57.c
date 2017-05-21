/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque57.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("sudeste",BOSQUE_TALEK("bosque54"));
    AddExit("oeste",BOSQUE_TALEK("bosque56"));
    AddExit("este",BOSQUE_TALEK("bosque58"));
    AddExit("norte",BOSQUE_TALEK("bosque61"));
    SetIntSmell("Hueles un fresco aroma a lavanda...\n");
}

