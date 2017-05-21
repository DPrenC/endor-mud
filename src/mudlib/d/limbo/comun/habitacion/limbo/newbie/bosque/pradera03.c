/*
DESCRIPCION  : pradera
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/pradera03.c
MODIFICACION : 08-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("pradera_a");

create()
{
    ::create();
    AddExit("sur",BOSQUE("pradera01"));
    AddExit("norte",BOSQUE("pradera08"));
    AddExit("este",BOSQUE("pradera04"));
    AddExit("oeste",BOSQUE("pradera02"));
    AddItem(PNJ("rana"), REFRESH_DESTRUCT, 1);
}

