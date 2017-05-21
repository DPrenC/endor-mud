/*
DESCRIPCION  : arbol en un bosquecillo del parque newbie
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/arbol08.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("arbol_b");

create()
{
    ::create();
    AddExit("norte",BOSQUE("arbol12"));
    AddExit("oeste",BOSQUE("arbol07"));
    AddExit("sur",BOSQUE("arbol05"));
    AddExit("arriba",BOSQUE("copa08"));
}

