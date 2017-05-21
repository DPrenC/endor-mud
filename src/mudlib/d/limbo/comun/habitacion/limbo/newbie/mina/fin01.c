/*
DESCRIPCION  : final de una galeria de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/fin01.c
MODIFICACION : 04-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("fin_a");

create()
{
    ::create();
    AddExit("norte",MINA("galeria00"));
    AddItem(PNJ("vibora"), REFRESH_DESTRUCT, 1);
    AddItem(OTRO("cristal"), REFRESH_DESTRUCT, 1);
}

