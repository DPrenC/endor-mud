/*
DESCRIPCION  : parte superior de un pozo de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/pozo08.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("pozo_a");

create()
{
    ::create();
    AddExit("sur",MINA("cruce00"));
    AddExit("abajo",MINA("pozo09"));
    AddItem(PNJ("vibora"), REFRESH_DESTRUCT, 1);
}
