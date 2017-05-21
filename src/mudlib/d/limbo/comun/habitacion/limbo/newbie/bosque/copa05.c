/*
DESCRIPCION  : copa de un arbol del parque de entrenamiento
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/copa05.c
MODIFICACION : 07-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("copa_a");

create()
{
    ::create();
    AddExit("norte",BOSQUE("copa08"));
    AddExit("abajo",BOSQUE("arbol05"));
    AddItem(PNJ("ardilla"), REFRESH_DESTRUCT, 1);
}

