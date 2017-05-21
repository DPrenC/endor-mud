/*
DESCRIPCION  : arbol en un bosquecillo del parque newbie
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/arbol07.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("arbol_a");

create()
{
    ::create();
    AddExit("norte",BOSQUE("arbol11"));
    AddExit("este",BOSQUE("arbol08"));
    AddExit("oeste",BOSQUE("arbol06"));
    AddExit("sur",BOSQUE("pradera08"));
    AddExit("arriba",BOSQUE("copa07"));
    AddItem(PNJ("pato"), REFRESH_DESTRUCT, 1);
}

