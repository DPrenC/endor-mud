/*
DESCRIPCION  : copa de un arbol del parque de entrenamiento
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/copa12.c
MODIFICACION : 07-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("copa_a");

create()
{
    ::create();
    AddExit("oeste",BOSQUE("copa11"));
    AddExit("sur",BOSQUE("copa08"));
    AddExit("abajo",BOSQUE("arbol12"));
    AddItem(PNJ("gorrion"), REFRESH_DESTRUCT, 1);
}

