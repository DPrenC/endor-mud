/*
DESCRIPCION  : copa de un arbol del parque de entrenamiento
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/copa09.c
MODIFICACION : 07-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("copa_b");

create()
{
    ::create();
    AddExit("abajo",BOSQUE("arbol09"));
    AddItem(PNJ("gorrion"), REFRESH_DESTRUCT, 1);
}

