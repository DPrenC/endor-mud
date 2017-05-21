/*
DESCRIPCION  : parte baja inundada de un pozo de la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/pozo02.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit MINA("pozo_c");

create()
{
    ::create();
    AddExit("arriba",MINA("pozo01"));
    AddExit("sur",MINA("cruce03"));
}
