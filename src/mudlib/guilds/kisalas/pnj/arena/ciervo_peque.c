/****************************************************************************
Fichero: ciervo_peque.c
Autor: Riberales
Fecha: 28/02/2006
Descripci�n: Un ciervo cachorro.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <damage.h>

inherit ANIMAL_BASE;

create()
{
    ::create();
    SetStandard("un ciervo","ciervo",6+random(3),GENDER_MALE);
    SetShort("un peque�o ciervo");
    SetLong("Se trata de un cachorro de ciervo. Su cornamenta a�n est� "
            "form�ndose, y su piel es de un color canela. Continuamente est� "
            "movi�ndose de un lugar para otro.\n");

    SetIds(({"peque�o ciervo","pequenyo ciervo","ciervo","cervatillo"}));

    SetHands(({({"la cornamenta",DT_PIERCE,3})}));
    SetGoChance(30);

    InitChats(3,({"El cervatillo se pone a dar saltos.\n"}));
}
