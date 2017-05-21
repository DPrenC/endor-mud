/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque65.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
[maler@simauria] meto a forlafil, tio d equest
--------------------------------------------------------------------------------
*/

#include "path.h"
#define QPROY(x) "/guilds/hechiceros/quest/proyectilelectrico/"+x
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
    AddItem(QPROY("forlafil"),REFRESH_DESTRUCT);
    AddExit("norte",BOSQUE_TALEK("bosque69"));
    AddExit("oeste",BOSQUE_TALEK("bosque64"));
    AddExit("este",BOSQUE_TALEK("camino18"));
}
