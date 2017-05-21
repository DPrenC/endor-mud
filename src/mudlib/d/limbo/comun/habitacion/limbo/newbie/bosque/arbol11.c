/*
DESCRIPCION  : arbol en un bosquecillo del parque newbie
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/arbol11.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("arbol_b");

create()
{
    ::create();
    AddExit("sur",BOSQUE("arbol07"));
    AddExit("este",BOSQUE("arbol12"));
    AddExit("oeste",BOSQUE("arbol10"));
    AddExit("arriba",BOSQUE("copa11"));
}

