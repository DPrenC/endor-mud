/*
DESCRIPCION  : copa de un arbol del parque de entrenamiento
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/copa03.c
MODIFICACION : 07-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("copa_b");

create()
{
    ::create();
    AddExit("este",BOSQUE("copa04"));
    AddExit("sur",BOSQUE("copa00"));
    AddExit("abajo",BOSQUE("arbol03"));
}

