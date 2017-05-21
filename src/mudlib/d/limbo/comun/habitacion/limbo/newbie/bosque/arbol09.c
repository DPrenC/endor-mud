/*
DESCRIPCION  : arbol en un bosquecillo del parque newbie
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/arbol00.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("arbol_b");

create()
{
    ::create();
    AddExit("sur",BOSQUE("pradera09"));
    AddExit("este",BOSQUE("pradera11"));
    AddExit("arriba",BOSQUE("copa09"));
    AddItem(PNJ("serpiente"), REFRESH_DESTRUCT, 1);
}

