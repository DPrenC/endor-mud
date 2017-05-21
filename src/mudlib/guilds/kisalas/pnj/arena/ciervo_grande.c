/****************************************************************************
Fichero: ciervo_grande.c
Autor: Riberales
Fecha: 28/02/2006
Descripción: Un ciervo adulto.
****************************************************************************/


#include <properties.h>
#include <damage.h>
#include "path.h"

inherit ANIMAL_BASE;

create()
{
    ::create();
    SetStandard("un ciervo","ciervo",11+random(3),GENDER_MALE);
    SetShort("un ciervo");
    SetLong("Es un ciervo ya adulto, por la longitud de su cornamenta. Su "
            "piel es de un marrón oscuro, con algunas manchas algo más claras "
            "en su lomo.\n");

    SetIds(({"ciervo"}));

    SetHands(({({"la cornamenta",DT_PIERCE,4})}));
    SetGoChance(30);

    InitChats(3,({"El ciervo te mira curioso.\n"}));
}
