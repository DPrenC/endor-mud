/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque07.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("sur",BOSQUE_TALEK("bosque01"));
    AddExit("este",BOSQUE_TALEK("bosque08"));
    AddExit("nordeste",BOSQUE_TALEK("bosque17"));
}
