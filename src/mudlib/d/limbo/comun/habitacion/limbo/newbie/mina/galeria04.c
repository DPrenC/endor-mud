/*
DESCRIPCION  : galeria de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/galeria04.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("galeria_a");

create()
{
    ::create();
    AddExit("norte",MINA("galeria03"));
    AddExit("oeste",MINA("pozo06"));
    AddItem(PNJ("murcielago"), REFRESH_DESTRUCT, 1);
}
