/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque06.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("oeste",BOSQUE_TALEK("bosque05"));
    AddExit("sudeste",BOSQUE_TALEK("bosque01"));
}
