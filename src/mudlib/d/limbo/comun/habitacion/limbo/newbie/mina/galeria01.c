/*
DESCRIPCION  : galeria de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/galeria01.c
MODIFICACION : 04-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("galeria_a");

create()
{
    ::create();
    AddExit("norte",MINA("galeria02"));
    AddExit("sur",MINA("galeria00"));
    AddItem(PNJ("osezno"), REFRESH_DESTRUCT, 1);
}

