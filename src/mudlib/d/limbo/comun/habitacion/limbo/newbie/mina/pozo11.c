/*
DESCRIPCION  : parte superior de un pozo de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/pozo11.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("pozo_a");

create()
{
    ::create();
    AddExit("este",MINA("galeria03"));
    AddExit("abajo",MINA("pozo10"));
    AddItem(PNJ("murcielago2"), REFRESH_DESTRUCT, 1);
}
