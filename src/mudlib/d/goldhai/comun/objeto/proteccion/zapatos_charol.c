/****************************************************************************
Fichero: zapatos_charol.c
Autor: Ratwor
Fecha: 17/04/2008
Descripción: unos zapatos de charol.
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create()
{
    ::create();
    switch(d2()){
        case 1: SetStandard(AT_BOTAS, 1, P_SIZE_MEDIUM, M_PIEL); break;
        case 2: SetStandard(AT_BOTAS, 1, P_SIZE_SMALL, M_PIEL); break;
    }
    SetShort("unos zapatos de charol");
    SetLong("Negros y brillantes como si fueran la superficie de un estanque. Estos "
    "lujosos zapatos están adornados con grandes hebillas doradas y rematados por un "
    "fino trabajo de marroquinería.\n");
    SetIds(({"zapatos", "zapatos de charol", "zapatos negros"}));
    Set(P_GENDER, GENDER_MALE);
    Set(P_NUMBER, NUMBER_PLURAL);
    SetValue(1100);
}
