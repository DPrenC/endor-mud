/****************************************************************************
Fichero: kalur.c
Autor: Riberales
Creaci�n: 06/12/05
Descripci�n: Otro orco m�s pa repoblar Azzor, el simpl�n xD.
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
            "t�picos de los marineros. Es alto, pero no muy musculoso, y en "
            "su cara observas la ingenuidad de un orco inexperto en las "
            "labores marinas.\n");

    SetIds(({"orco","ingenuo","kalur","Kalur","marino","marinero"}));

    SetGoChance(35);
    AddWalkZones(AZ_PUERTO(""));

    AddItem("/obj/money",REFRESH_REMOVE,([P_MONEY:(["plata":2+random(8),
                                                    "oro":4+random(7)])]));

    AddItem("/obj/armas/cuchillo",REFRESH_REMOVE,([
            P_SHORT: "un arp�n",
            P_LONG: "Se trata de un instrumento muy utilizado en las "
                    "actividades marinas. Principalmente se usa para pescar, "
                    "aunque tambi�n puede servir de arma.\n",
            P_IDS: ({"arpon","arp�n","arma"}),
            P_WC: 8]),
            SF(wieldme));


    InitChats(4,({
              "Kalur murmura: Hum, �d�nde se habr�n metido todos mis "
              "compa�eros?\n","Kalur dice: Qu� raro, me dijo el capit�n que "
              "fuera a por un arp�n por si nos top�bamos con  piratas, pero "
              "ya no est�n.\n","Kalur mira hacia el mar buscando su "
            "barco.\n"}));

}

