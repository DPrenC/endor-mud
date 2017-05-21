/*
DESCRIPCION  : pradera
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/pradera11.c
MODIFICACION : 08-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit BOSQUE("pradera_b");

create()
{
    ::create();
    AddExit("sur",BOSQUE("pradera10"));
    AddExit("norte",BOSQUE("c_mina01"));
    AddExit("este",BOSQUE("arbol10"));
    AddExit("oeste",BOSQUE("arbol09"));
}

