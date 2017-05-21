/*
DESCRIPCION  : pradera
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/pradera02.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("pradera_b");

create()
{
    ::create();
    AddExit("sur",BOSQUE("arbol02"));
    AddExit("norte",BOSQUE("pradera07"));
    AddExit("este",BOSQUE("pradera03"));
    AddExit("oeste",BOSQUE("arbol04"));
}

