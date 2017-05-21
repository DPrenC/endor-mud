/****************************************************************************
Fichero: hakor.c
Autor: Riberales
Creaci�n: 06/12/05
Descripci�n: Un orco marino, para repoblar Azzor.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <guild.h>

inherit NPC;

public create()
{
    ::create();
    seteuid(getuid());

    SetStandard("Hakor","orco",([GC_NINGUNO:78+random(6)]),GENDER_MALE);
    SetShort("Hakor el cojo");
    SetLong("SE trata de Hakor, uno de los m�ticos orcos que surcaron por "
            "primera vez el mar de Jadkut. Observas que tiene una peque�a "
            "asimetr�a en las piernas, lo que hace que vaya de aqu� para all� "
            "con una graciosa cojera. Aun as�, dudas que la fuerza y "
            "coraje de anta�o  le hayan abandonado.\n");

    SetIds(({"hakor","Hakor","cojo","el cojo","marino","marinero","orco"}));

    SetMsgIn(({"llega cojeando","Alguien llega"}));
    SetMsgOut(({"se va cojeando","Alguien se va"}));

    SetGoChance(40);
    AddWalkZones(({AZ_PUERTO(""),AZ_CIUDAD("")}));

    InitChats(3,({"Hakor murmura: Si no fuera por esta pierna in�til...\n"}));

    AddItem("/obj/armas/baston",REFRESH_REMOVE,([
            P_SHORT: "Un bast�n",
            P_LONG: "Es un bast�n de madera, bastante r�gido y que sirve para "
                    "poder caminar mejor, entre otras cosas.\n",
            P_IDS: ({"baston","bast�n"}),
        P_NUMBER_HANDS: 1,
        P_MATERIAL: M_MADERA]),
            SF(wieldme));


}
