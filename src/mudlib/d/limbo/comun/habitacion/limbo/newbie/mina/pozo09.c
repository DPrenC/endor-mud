/*
DESCRIPCION  : parte baja inundada de un pozo de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/pozo09.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("pozo_c");

create()
{
    ::create();
    AddExit("arriba",MINA("pozo08"));
    AddExit("oeste",MINA("pozo05"));
    AddItem(PNJ("aranya"), REFRESH_DESTRUCT, 1);
}
