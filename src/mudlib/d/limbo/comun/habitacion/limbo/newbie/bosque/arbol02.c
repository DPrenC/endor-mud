/*
DESCRIPCION  : arbol en un bosquecillo del parque newbie
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/arbol02.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("arbol_a");

create()
{
    ::create();
    AddExit("norte",BOSQUE("pradera02"));
    AddExit("este",BOSQUE("pradera01"));
    AddExit("oeste",BOSQUE("arbol01"));
    AddExit("arriba",BOSQUE("copa02"));
    AddItem(PNJ("pato"), REFRESH_DESTRUCT, 1);
}

