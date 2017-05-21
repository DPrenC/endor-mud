/*
DESCRIPCION  : final de una galeria de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/fin04.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("fin_a");

create()
{
    ::create();
    AddExit("este",MINA("galeria07"));
    AddItem(PNJ("rata"), REFRESH_DESTRUCT, 1);
    AddItem(OTRO("cristal"), REFRESH_DESTRUCT, 1);
}

