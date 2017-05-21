/*
DESCRIPCION  : arbol en un bosquecillo del parque newbie
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/arbol12.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("arbol_a");

create()
{
    ::create();
    AddExit("sur",BOSQUE("arbol08"));
    AddExit("oeste",BOSQUE("arbol11"));
    AddExit("arriba",BOSQUE("copa12"));
    AddItem(PNJ("zorro"), REFRESH_DESTRUCT, 1);
}

