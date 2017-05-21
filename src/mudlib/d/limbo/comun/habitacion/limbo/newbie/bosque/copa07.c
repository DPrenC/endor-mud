/*
DESCRIPCION  : copa de un arbol del parque de entrenamiento
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/copa07.c
MODIFICACION : 07-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("copa_a");

create()
{
    ::create();
    AddExit("oeste",BOSQUE("copa06"));
    AddExit("este",BOSQUE("copa08"));
    AddExit("norte",BOSQUE("copa11"));
    AddExit("abajo",BOSQUE("arbol07"));
    AddItem(PNJ("gorrion"), REFRESH_DESTRUCT, 1);
}

