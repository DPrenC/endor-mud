/*
DESCRIPCION  : pradera
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/pradera01.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("pradera_b");

create()
{
    ::create();
    AddExit("norte",BOSQUE("pradera03"));
    AddExit("este",BOSQUE("pradera00"));
    AddExit("oeste",BOSQUE("arbol02"));
}

