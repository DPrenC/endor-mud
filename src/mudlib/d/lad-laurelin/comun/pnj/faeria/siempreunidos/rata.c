/***
Fichero: rata.c
Autor: kastwey@simauria
Descripción: rata para las celdas de siempreunidos.
Retocado del fichero de angor, de la mina de novatos de limbo.
Creación: 07/12/2004
***/

#include "path.h"
#include <combat.h>
#include <properties.h>
#include <gremios.h>


inherit NPC;

create() {
    ::create();

    SetStandard("una rata", "rata", ([ GC_TORPE: 2]), GENDER_FEMALE);
    SetShort("una rata enorme");
    SetLong(
        "Es una enorme rata de pelaje negro y con una larga cola. Sus dientes son muy\n"
        "afilados y sus ojos brillan con un gesto amenazador.\n");
    SetIds(({"rata", "bicho"}));
    SetAds(({"una", "enorme", "asquerosa", "peluda"}));
    SetSize(P_SIZE_SMALL);
    SetHands(({ ({"mordisco", TD_PENETRACION, 3})}));
    InitChats(8, ({
     "La rata da vueltas a tu alrededor.\n",
     "La rata se te intenta subir a los tobillos.\n",
     "La rata te mira con gesto amenazador.\n",
     "La rata parece MUUUUY hambrienta.\n",
     "La rata te enseña sus dientes amarillos.\n",
    }));
}
