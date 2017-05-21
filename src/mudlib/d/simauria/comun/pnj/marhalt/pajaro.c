/****************************************************************************
Fichero: pajaro.c
Autor: Ratwor
Fecha: 14/09/2007
Descripci�n: Un pajarillo que revolotea por el bosque.
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("un p�jaro", "ave", d2(), GENDER_MALE);
    AddId(({"pajaro", "p�jaro", "jilguero", "ave", "animal", "pajarillo", "pajarito"}));
    SetShort("un curioso p�jaro");
    SetLong("Un peque�o jilguero que vuela en busca de comida.\n");
    SetHands(({({"el pico", TD_PENETRACION,0})}));
    InitChats(6,({"El p�jaro te mira y... ��SE TE CAGA ENCIMA!!\n",
        "El p�jaro vuela y se posa un par de metros m�s alejado de t�.\n",
	    "El p�jaro empieza a piar alegremente.\n"}));
    SetGoChance(100);
    SetMsgOut("se va volando");
    SetMsgIn("viene volando");
}


