/*
DESCRIPCION  : arbol en un bosquecillo del parque newbie
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/arbol06.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("arbol_b");

create()
{
    ::create();
    AddExit("norte",BOSQUE("arbol10"));
    AddExit("este",BOSQUE("arbol07"));
    AddExit("oeste",BOSQUE("pradera10"));
    AddExit("sur",BOSQUE("pradera07"));
    AddExit("arriba",BOSQUE("copa06"));
}

