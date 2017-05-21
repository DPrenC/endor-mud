/*
DESCRIPCION  : pradera
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/pradera04.c
MODIFICACION : 08-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("pradera_b");

create()
{
    ::create();
    AddExit("sur",BOSQUE("pradera00"));
    AddExit("norte",BOSQUE("arbol05"));
    AddExit("este",BOSQUE("entrada"));
    AddExit("oeste",BOSQUE("pradera03"));
}

