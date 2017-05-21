/*
DESCRIPCION  : pradera
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/pradera00.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("pradera_a");

create()
{
    ::create();
    AddExit("norte",BOSQUE("pradera04"));
    AddExit("oeste",BOSQUE("pradera01"));
    AddItem(PNJ("oveja"), REFRESH_DESTRUCT, 1);
}

