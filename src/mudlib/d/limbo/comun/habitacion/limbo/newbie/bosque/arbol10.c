/*
DESCRIPCION  : arbol en un bosquecillo del parque newbie
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/arbol10.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("arbol_a");

create()
{
    ::create();
    AddExit("sur",BOSQUE("arbol06"));
    AddExit("oeste",BOSQUE("pradera11"));
    AddExit("este",BOSQUE("arbol11"));
    AddExit("arriba",BOSQUE("copa10"));
    AddItem(PNJ("conejo"), REFRESH_DESTRUCT, 1);
}

