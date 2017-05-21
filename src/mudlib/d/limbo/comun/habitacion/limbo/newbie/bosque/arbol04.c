/*
DESCRIPCION  : arbol en un bosquecillo del parque newbie
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/arbol04.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("arbol_a");

create()
{
    ::create();
    AddExit("norte",BOSQUE("pradera06"));
    AddExit("este",BOSQUE("pradera02"));
    AddExit("oeste",BOSQUE("arbol03"));
    AddExit("sur",BOSQUE("arbol01"));
    AddExit("arriba",BOSQUE("copa04"));
    AddItem(PNJ("zorro"), REFRESH_DESTRUCT, 1);
}

