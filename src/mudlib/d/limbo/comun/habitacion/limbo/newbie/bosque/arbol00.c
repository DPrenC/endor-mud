/*
DESCRIPCION  : arbol en un bosquecillo del parque newbie
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/arbol00.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("arbol_a");

create()
{
    ::create();
    AddExit("norte",BOSQUE("arbol03"));
    AddExit("este",BOSQUE("arbol01"));
    AddExit("arriba",BOSQUE("copa00"));
    AddItem(PNJ("serpiente"), REFRESH_DESTRUCT, 1);
}

