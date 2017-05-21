/****************************************************************************
Fichero: pajaro.c
Autor: Ratwor
Fecha: 14/09/2007
Descripción: Un pajarillo que revolotea por el bosque.
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("un pájaro", "ave", d2(), GENDER_MALE);
    AddId(({"pajaro", "pájaro", "jilguero", "ave", "animal", "pajarillo", "pajarito"}));
    SetShort("un curioso pájaro");
    SetLong("Un pequeño jilguero que vuela en busca de comida.\n");
    SetHands(({({"el pico", TD_PENETRACION,0})}));
    InitChats(6,({"El pájaro te mira y... ¡¡SE TE CAGA ENCIMA!!\n",
        "El pájaro vuela y se posa un par de metros más alejado de tí.\n",
	    "El pájaro empieza a piar alegremente.\n"}));
    SetGoChance(100);
    SetMsgOut("se va volando");
    SetMsgIn("viene volando");
}


