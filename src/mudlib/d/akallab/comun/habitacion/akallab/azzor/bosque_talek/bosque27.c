/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque27.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_TALEK("camino03"));
    AddExit("oeste",BOSQUE_TALEK("bosque26"));
    AddItem(QUEST+"curandera/cuervo",REFRESH_DESTRUCT,1);
}

