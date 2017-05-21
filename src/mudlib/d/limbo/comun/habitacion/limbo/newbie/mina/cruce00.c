/*
DESCRIPCION  : cruce de galerias en la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/cruce00.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("cruce_a");

create()
{
    ::create();
    AddExit("norte",MINA("pozo08"));
    AddExit("este",MINA("entrada"));
    AddExit("oeste",MINA("cruce01"));
}

