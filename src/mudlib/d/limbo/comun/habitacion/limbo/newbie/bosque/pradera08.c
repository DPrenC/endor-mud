/*
DESCRIPCION  : pradera
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/pradera08.c
MODIFICACION : 08-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("pradera_b");

create()
{
    ::create();
    AddExit("sur",BOSQUE("pradera03"));
    AddExit("norte",BOSQUE("arbol07"));
    AddExit("este",BOSQUE("arbol05"));
    AddExit("oeste",BOSQUE("pradera07"));
}

