/*
DESCRIPCION  : copa de un arbol del parque de entrenamiento
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/copa04.c
MODIFICACION : 07-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("copa_a");

create()
{
    ::create();
    AddExit("oeste",BOSQUE("copa03"));
    AddExit("sur",BOSQUE("copa01"));
    AddExit("abajo",BOSQUE("arbol04"));
    AddItem(PNJ("gorrion"), REFRESH_DESTRUCT, 1);
}

