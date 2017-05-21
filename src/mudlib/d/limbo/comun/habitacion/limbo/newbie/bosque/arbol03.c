/*
DESCRIPCION  : arbol en un bosquecillo del parque newbie
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/arbol03.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("arbol_b");

create()
{
    ::create();
    AddExit("norte",BOSQUE("pradera05"));
    AddExit("este",BOSQUE("arbol04"));
    AddExit("sur",BOSQUE("arbol00"));
    AddExit("arriba",BOSQUE("copa03"));
}

