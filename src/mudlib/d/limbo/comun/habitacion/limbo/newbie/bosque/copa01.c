/*
DESCRIPCION  : copa de un arbol del parque de entrenamiento
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/copa01.c
MODIFICACION : 07-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("copa_b");

create()
{
    ::create();
    AddExit("oeste",BOSQUE("copa00"));
    AddExit("este",BOSQUE("copa02"));
    AddExit("norte",BOSQUE("copa04"));
    AddExit("abajo",BOSQUE("arbol01"));
}

