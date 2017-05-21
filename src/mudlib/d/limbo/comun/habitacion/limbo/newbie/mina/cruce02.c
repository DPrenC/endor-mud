/*
DESCRIPCION  : cruce de galerias en la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/cruce02.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("cruce_a");

create()
{
    ::create();
    AddExit("sur",MINA("pozo12"));
    AddExit("oeste",MINA("pozo10"));
    AddExit("norte",MINA("cruce01"));
}

