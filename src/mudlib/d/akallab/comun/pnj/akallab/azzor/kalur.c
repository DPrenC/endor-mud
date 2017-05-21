/****************************************************************************
Fichero: kalur.c
Autor: Riberales
Creación: 06/12/05
Descripción: Otro orco más pa repoblar Azzor, el simplón xD.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <guild.h>

inherit NPC;

public create()
{
    ::create();

    seteuid(getuid());

    SetStandard("Kalur","orco",([GC_NINGUNO:69]),GENDER_MALE);
    SetShort("Kalur el ingenuo");
    SetLong("Kalur es un orco de buen parecer, pero que no cumple los rasgos "
            "típicos de los marineros. Es alto, pero no muy musculoso, y en "
            "su cara observas la ingenuidad de un orco inexperto en las "
            "labores marinas.\n");

    SetIds(({"orco","ingenuo","kalur","Kalur","marino","marinero"}));

    SetGoChance(35);
    AddWalkZones(AZ_PUERTO(""));

    AddItem("/obj/money",REFRESH_REMOVE,([P_MONEY:(["plata":2+random(8),
                                                    "oro":4+random(7)])]));

    AddItem("/obj/armas/cuchillo",REFRESH_REMOVE,([
            P_SHORT: "un arpón",
            P_LONG: "Se trata de un instrumento muy utilizado en las "
                    "actividades marinas. Principalmente se usa para pescar, "
                    "aunque también puede servir de arma.\n",
            P_IDS: ({"arpon","arpón","arma"}),
            P_WC: 8]),
            SF(wieldme));


    InitChats(4,({
              "Kalur murmura: Hum, ¿dónde se habrán metido todos mis "
              "compañeros?\n","Kalur dice: Qué raro, me dijo el capitán que "
              "fuera a por un arpón por si nos topábamos con  piratas, pero "
              "ya no están.\n","Kalur mira hacia el mar buscando su "
            "barco.\n"}));

}

