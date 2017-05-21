/*
DESCRIPCION  : pradera
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/pradera05.c
MODIFICACION : 08-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("pradera_a");

create()
{
    ::create();
    AddExit("sur",BOSQUE("arbol03"));
    AddExit("norte",BOSQUE("pradera09"));
    AddExit("este",BOSQUE("pradera06"));
    AddExit("oeste",BOSQUE("senda"));
    AddItem(PNJ("rana"), REFRESH_DESTRUCT, 1);
}

