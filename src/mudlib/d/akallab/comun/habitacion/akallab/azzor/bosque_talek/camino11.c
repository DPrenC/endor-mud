/*
DESCRIPCION  : camino a traves del bosque de Talek
FICHERO      : camino11.c
MODIFICACION : 13-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_TALEK("camino");

create()
{
    ::create();
   SetIntLong("Te encuentras en un camino de tierra que recorre el bosque "
        "de Talek. El bosque se extiende a tu alrededor mostrando una gran "
        "vitalidad y esplendor. El camino continúa hacia el noroeste y hacia "
        "el sur, donde llega al importante Camino del Este.\n");
    AddExit("este",BOSQUE_TALEK("bosque38"));
    AddExit("noroeste",BOSQUE_TALEK("camino12"));
    AddExit("sur",BOSQUE_TALEK("camino07"));
}
