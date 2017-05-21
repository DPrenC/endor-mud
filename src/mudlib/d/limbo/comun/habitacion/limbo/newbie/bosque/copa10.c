/*
DESCRIPCION  : copa de un arbol del parque de entrenamiento
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/copa10.c
MODIFICACION : 07-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("copa_a");

create()
{
    ::create();
    AddExit("este",BOSQUE("copa11"));
    AddExit("sur",BOSQUE("copa06"));
    AddExit("abajo",BOSQUE("arbol10"));
    AddItem(PNJ("ardilla"), REFRESH_DESTRUCT, 1);
}

