/*
DESCRIPCION  : camino a traves del bosque de Talek
FICHERO      : camino19.c
MODIFICACION : 13-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_TALEK("camino");

create()
{
    ::create();
   SetIntLong("Continúas avanzando a través del bosque de Talek por un "
        "camino de tierra. El camino continúa hacia el sudeste en una "
        "dirección y hacia el norte en otra. Observas que, comparada con "
        "otras, en esta zona del bosque predominan los grandes árboles, en "
        "especial robles, y escasean los matorrales bajos.\n");
    AddDetail(({"árboles","arboles","robles"}),"A tu alrededor se alzan "
        "multitud de altos robles.\n");
    AddExit("norte",BOSQUE_TALEK("camino20"));
    AddExit("suroeste",BOSQUE_TALEK("camino18"));
    AddExit("oeste",BOSQUE_TALEK("bosque70"));
    AddExit("este",BOSQUE_TALEK("bosque71"));
}
