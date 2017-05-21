/*
DESCRIPCION  : pradera
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/pradera10.c
MODIFICACION : 08-08-98 [Angor@Simauria] Creacion
               23-10-98 [Izet@Simauria] Arreglada la salida hacia
                                         el norte (ver mas abajo).
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("pradera_a");

create()
{
    ::create();
    AddExit("sur",BOSQUE("pradera06"));
    AddExit("norte",BOSQUE("pradera11"));
    AddExit("este",BOSQUE("arbol06"));
    AddExit("oeste",BOSQUE("pradera09"));
    AddItem(PNJ("oveja"), REFRESH_DESTRUCT, 1);
}

