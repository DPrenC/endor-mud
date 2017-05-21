/*
DESCRIPCION  : copa de un arbol del parque de entrenamiento
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/copa00.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("copa_a");

create()
{
    ::create();
    AddExit("este",BOSQUE("copa01"));
    AddExit("norte",BOSQUE("copa03"));
    AddExit("abajo",BOSQUE("arbol00"));
    AddItem(PNJ("ardilla"), REFRESH_DESTRUCT, 1);
}

