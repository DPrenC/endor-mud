/*
DESCRIPCION  : parte media de un pozo de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/pozo04.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("pozo_b");

create()
{
    ::create();
    AddExit("arriba",MINA("pozo03")); 
    AddExit("abajo",MINA("pozo05"));
    AddItem(PNJ("murcielago"), REFRESH_DESTRUCT, 1);
}
