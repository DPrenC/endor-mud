/****************************************************************************
Fichero: ciervo_peque.c
Autor: Riberales
Fecha: 28/02/2006
Descripción: Un ciervo cachorro.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <damage.h>

inherit ANIMAL_BASE;

create()
{
    ::create();
    SetStandard("un ciervo","ciervo",6+random(3),GENDER_MALE);
    SetShort("un pequeño ciervo");
    SetLong("Se trata de un cachorro de ciervo. Su cornamenta aún está "
            "formándose, y su piel es de un color canela. Continuamente está "
            "moviéndose de un lugar para otro.\n");

    SetIds(({"pequeño ciervo","pequenyo ciervo","ciervo","cervatillo"}));

    SetHands(({({"la cornamenta",DT_PIERCE,3})}));
    SetGoChance(30);

    InitChats(3,({"El cervatillo se pone a dar saltos.\n"}));
}
