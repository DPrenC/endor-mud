/*
DESCRIPCION  : arbol en un bosquecillo del parque newbie
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/arbol05.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("arbol_a");

create()
{
    ::create();
    AddExit("sur",BOSQUE("pradera04"));
    AddExit("oeste",BOSQUE("pradera08"));
    AddExit("norte",BOSQUE("arbol08"));
    AddExit("arriba",BOSQUE("copa05"));
    AddItem(PNJ("conejo"), REFRESH_DESTRUCT, 1);
}

