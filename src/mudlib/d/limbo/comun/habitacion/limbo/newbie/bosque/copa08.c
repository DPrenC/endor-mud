/*
DESCRIPCION  : copa de un arbol del parque de entrenamiento
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/copa08.c
MODIFICACION : 07-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("copa_b");

create()
{
    ::create();
    AddExit("oeste",BOSQUE("copa07"));
    AddExit("norte",BOSQUE("copa12"));
    AddExit("sur",BOSQUE("copa05"));
    AddExit("abajo",BOSQUE("arbol08"));
}

