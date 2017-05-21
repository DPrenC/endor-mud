/*
DESCRIPCION  : galeria de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/galeria02.c
MODIFICACION : 04-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("galeria_a");

create()
{
    ::create();
    AddExit("oeste",MINA("pozo03"));
    AddExit("sur",MINA("galeria01"));
    AddItem(PNJ("rata"), REFRESH_DESTRUCT, 1);
}

