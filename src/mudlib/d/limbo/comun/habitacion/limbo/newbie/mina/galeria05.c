/*
DESCRIPCION  : galeria de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/galeria05.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("galeria_a");

create()
{
    ::create();
    AddExit("norte",MINA("pozo00"));
    AddExit("este",MINA("pozo18"));
    AddItem(PNJ("rata"), REFRESH_DESTRUCT, 1);
}
