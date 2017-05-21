/*
DESCRIPCION  : pradera
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/pradera09.c
MODIFICACION : 08-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("pradera_b");

create()
{
    ::create();
    AddExit("sur",BOSQUE("pradera05"));
    AddExit("norte",BOSQUE("arbol09"));
    AddExit("este",BOSQUE("pradera10"));
}

