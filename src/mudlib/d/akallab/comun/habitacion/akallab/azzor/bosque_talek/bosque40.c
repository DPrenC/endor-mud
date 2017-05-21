/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque40.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("nordeste",BOSQUE_TALEK("bosque47"));
    AddExit("este",BOSQUE_TALEK("bosque41"));
    AddItem(QUEST+"curandera/tomillo",REFRESH_DESTRUCT,1);
}
