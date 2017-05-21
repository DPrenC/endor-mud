/*
DESCRIPCION  : final de una galeria de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/fin03.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("fin_a");

create()
{
    ::create();
    AddExit("sur",MINA("pozo17"));
    AddItem(PNJ("aranya"), REFRESH_DESTRUCT, 1);
    AddItem(OTRO("cristal"), REFRESH_DESTRUCT, 1);
}

