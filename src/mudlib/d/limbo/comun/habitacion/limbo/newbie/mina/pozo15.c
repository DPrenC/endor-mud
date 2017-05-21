/*
DESCRIPCION  : parte superior de un pozo de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/pozo15.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("pozo_a");

create()
{
    ::create();
    AddExit("norte",MINA("pozo16"));
    AddExit("abajo",MINA("pozo14"));
    AddItem(PNJ("rata"), REFRESH_DESTRUCT, 1);
}
