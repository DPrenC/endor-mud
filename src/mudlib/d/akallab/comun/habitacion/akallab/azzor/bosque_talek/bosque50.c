/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque50.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddExit("norte",BOSQUE_TALEK("bosque54"));
    AddExit("oeste",BOSQUE_TALEK("camino13"));
    AddExit("sur",BOSQUE_TALEK("bosque44"));
    AddExit("este",BOSQUE_TALEK("bosque51"));
}
