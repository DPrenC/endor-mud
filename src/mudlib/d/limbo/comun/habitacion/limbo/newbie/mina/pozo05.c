/*
DESCRIPCION  : parte baja inundada de un pozo de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/pozo05.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("pozo_c");

create()
{
    ::create();
    AddExit("arriba",MINA("pozo04"));
    AddExit("este",MINA("pozo09"));
    AddItem(PNJ("rata"), REFRESH_DESTRUCT, 1);
}
