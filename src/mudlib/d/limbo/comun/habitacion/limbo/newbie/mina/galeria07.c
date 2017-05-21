/*
DESCRIPCION  : galeria inundada de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/galeria07.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("galeria_b");

create()
{
    ::create();
    AddExit("oeste",MINA("fin04"));
    AddExit("norte",MINA("galeria06"));
    AddItem(PNJ("murcielago"), REFRESH_DESTRUCT, 1);
    AddItem(PNJ("murcielago2"), REFRESH_DESTRUCT, 1);
}
