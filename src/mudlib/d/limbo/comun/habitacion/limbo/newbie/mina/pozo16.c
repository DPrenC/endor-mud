/*
DESCRIPCION  : parte superior de un pozo de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/pozo16.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("pozo_a");

create()
{
    ::create();
    AddExit("sur",MINA("pozo15"));
    AddExit("abajo",MINA("pozo17"));
}
