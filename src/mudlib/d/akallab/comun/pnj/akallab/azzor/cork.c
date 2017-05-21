/****************************************************************************
Fichero: cork.c
Autor: Riberales
Creaci�n: 06/12/05
Descripci�n: Un orco pa repoblar Azzor.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <guild.h>

inherit NPC;

public create()
{
    ::create();

    seteuid(getuid());

    SetStandard("cork","orco",([GC_NINGUNO:75+random(5)]),GENDER_MALE);
    SetShort("cork el negro");
    SetLong("Corck es un orco de gran embergadura, amante del mar y sus "
            "criaturas, y que durante mucho tiempo viaj� con el conocido "
            "Manak por las aguas, desde Azzor hasta las mism�simas tierras "
            "de los humanos, buscando un comercio pac�fico. Su pelaje es muy "
            "oscuro, raz�n por la cual recibe el apelativo de 'el negro'.\n");

    SetIds(({"corck","Corck","el negro","negro","orco","marino","marinero"}));

    SetGoChance(35);
    AddWalkZones(({AZ_PUERTO(""),AZ_CIUDAD("")}));

    AddItem("/obj/money",REFRESH_REMOVE,([P_MONEY:(["plata":random(11),
                                          "oro":random(15)])]));

    InitChats(3,({"Corck suspira melanc�lico.\n"}));

    InitAChats(3,({"Cork el negro gru�e.\n"}));

}
