/*
DESCRIPCION  : galeria inundada de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/galeria06.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("galeria_b");

create()
{
    ::create();
    AddExit("oeste",MINA("cruce03"));
    AddExit("sur",MINA("galeria07"));
}
