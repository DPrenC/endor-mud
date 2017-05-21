/*
DESCRIPCION  : camino a traves del bosque de Talek
FICHERO      : camino12.c
MODIFICACION : 13-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_TALEK("camino");

create()
{
    ::create();
   SetIntLong("Contin�as avanzando a trav�s del bosque de Talek por un "
        "camino de tierra. El camino contin�a hacia el sudeste en una "
        "direcci�n y hacia el norte en otra. Observas que, comparada con "
        "otras, en esta zona del bosque predominan los grandes �rboles, en "
        "especial robles, y escasean los matorrales bajos.\n");
    AddDetail(({"�rboles","arboles","robles"}),"A tu alrededor se alzan "
        "multitud de altos robles.\n");
    AddExit("este",BOSQUE_TALEK("bosque44"));
    AddExit("oeste",BOSQUE_TALEK("bosque43"));
    AddExit("sudeste",BOSQUE_TALEK("camino11"));
    AddExit("norte",BOSQUE_TALEK("camino13"));
}
