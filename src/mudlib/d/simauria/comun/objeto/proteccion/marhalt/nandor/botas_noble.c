/****************************************************************************
Fichero: botas_noble.c
Autor: Ratwor
Fecha: 28/11/2007
Descripción: parte del equipo del noble del castillo.
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create()
{
    ::create();
    SetStandard(AT_BOTAS, 2, P_SIZE_LARGE, M_CUERO);
    SetShort("unas botas de montar");
    SetLong("Son un par de botas altas de cuero con una lámina de metal que protege la "
    "pantorrilla dotadas de unas pequeñas espuelas.\n");
    AddId(({"botas de montar", "botas", "altas", "montar"}));
    Set(P_GENDER, GENDER_FEMALE);
    Set(P_NUMBER, NUMBER_PLURAL);
    SetWeight(1500);
    SetValue(1000);
}
