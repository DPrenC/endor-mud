/*
DESCRIPCION  : parte baja inundada de un pozo de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/pozo17.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("pozo_c");

create()
{
    ::create();
    AddExit("arriba",MINA("pozo16"));
    AddExit("norte",MINA("fin03"));
    AddItem(PNJ("vibora"), REFRESH_DESTRUCT, 1);
}
