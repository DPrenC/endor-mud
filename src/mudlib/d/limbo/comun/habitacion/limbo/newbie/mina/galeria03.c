/*
DESCRIPCION  : galeria de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/galeria03.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("galeria_a");

create()
{
    ::create();
    AddExit("sur",MINA("galeria04"));
    AddExit("oeste",MINA("pozo11"));
}
