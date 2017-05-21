/***
Fichero: comadreja.c
Autor: kastwey@simauria
Descripci�n: Una comadreja para el bosque de Siempreunidos.
Creaci�n: 18/12/2004
***/

#include "path.h"
#include <gremios.h>

inherit NPC;

create()
{
    ::create();
   SetStandard("una comadreja","comadreja",([GC_TORPE:2]),2);
    SetLong("Es una comadreja. Tiene una cabeza peque�a y pelo pardo rojizo. Sus patas son cortas, aunque sabes que estos animales son ligeros y vivaces como los que m�s.\n");
    SetWhimpy(QueryHP());
    InitChats(6,({"La comadreja te mira con ojos inquietos.\n",
    "La comadreja comienza a moverse a tu alrededor.\n",
    "La comadreja te olisquea curiosa.\n"}));
}