/*
DESCRIPCION  : pradera
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/pradera07.c
MODIFICACION : 08-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("pradera_a");

create()
{
    ::create();
    AddExit("sur",BOSQUE("pradera02"));
    AddExit("norte",BOSQUE("arbol06"));
    AddExit("este",BOSQUE("pradera08"));
    AddExit("oeste",BOSQUE("pradera06"));
    AddItem(PNJ("rana"), REFRESH_DESTRUCT, 1);
}

