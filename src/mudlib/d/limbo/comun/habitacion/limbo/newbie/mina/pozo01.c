/*
DESCRIPCION  : parte media de un pozo de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/pozo01.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("pozo_b");

create()
{
    ::create();
    AddExit("arriba",MINA("pozo00"));
    AddExit("abajo",MINA("pozo02"));
    AddItem(PNJ("murcielago2"), REFRESH_DESTRUCT, 1);
}
