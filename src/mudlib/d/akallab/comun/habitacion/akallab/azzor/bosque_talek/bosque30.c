/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque30.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_TALEK("camino01"));
    AddExit("oeste",BOSQUE_TALEK("bosque29"));
    AddExit("suroeste",BOSQUE_TALEK("bosque24"));
}
