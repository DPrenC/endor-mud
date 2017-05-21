/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque71.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("oeste",BOSQUE_TALEK("camino20"));
    AddExit("sur",BOSQUE_TALEK("bosque71"));
    AddItem(QUEST+"curandera/cuervo",REFRESH_DESTRUCT,1);
}
