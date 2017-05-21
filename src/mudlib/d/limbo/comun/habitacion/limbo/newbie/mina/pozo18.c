/*
DESCRIPCION  : parte superior de un pozo de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/pozo18.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("pozo_a");

create()
{
    ::create();
    AddExit("oeste",MINA("galeria05"));
    AddExit("abajo",MINA("cruce01"));
    AddItem(PNJ("aranya"), REFRESH_DESTRUCT, 1);
}
