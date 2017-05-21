/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque23.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_TALEK("camino09"));
    AddExit("oeste",BOSQUE_TALEK("bosque22"));
    AddExit("suroeste",BOSQUE_TALEK("bosque13"));
    AddItem(QUEST+"curandera/hiedra",REFRESH_DESTRUCT,1);
}
