/****************************************************************************
Fichero: espada_1mano.c
Autor: Ratwor
Fecha: 30/03/2008
Descripción: Una espada de una mano.
****************************************************************************/



#include <properties.h>
#include <combat.h>
inherit WEAPON;
create()
{
    ::create();
    SetStandard(WT_ESPADA, 10, P_SIZE_LARGE, M_ACERO);
    SetShort("una espada larga");
    SetLong("Es una potente espada larga de una mano, la cual es algo más ancha de "
    "lo que le correspondería para este tipo de arma.\n La hoja de acero, de un lijero "
    "tono negro azulado, mide cerca de un metro, con filos rectos y punta redondeada. "
    "El peso del arma es notablemente superior, aunque el diseño de su empuñadura "
    "equilibra el arma para una mayor manejabilidad.\n");
    AddId(({"espada larga", "larga", "arma", "espada", "espada de una mano",
        "espada una mano"}));
    Set(P_GENDER, GENDER_FEMALE);
    SetWeight(5000);
    SetNumberHands(1);
}
