/*
DESCRIPCION  : pradera
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/pradera06.c
MODIFICACION : 08-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("pradera_b");

create()
{
    ::create();
    AddExit("sur",BOSQUE("arbol04"));
    AddExit("norte",BOSQUE("pradera10"));
    AddExit("este",BOSQUE("pradera07"));
    AddExit("oeste",BOSQUE("pradera05"));
}

