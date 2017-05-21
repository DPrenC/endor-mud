/****************************************************************************
Fichero: botas_lujosas.c
Autor: Ratwor
Fecha: 17/04/2008
Descripción: Unas botas lujosas.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create()
{
    ::create();
    SetStandard(AT_BOTAS, 1, P_SIZE_LARGE, M_CUERO);
    SetShort("unas lujosas botas");
    SetLong("Se trata de unas botas altas de cuero bien curtido, adornadas por "
    "brillantes hebillas plateadas, que contrastan con la brillante piel negra.\n");
    SetIds(({"botas", "botas lujosas", "lujosas botas"}));
    Set(P_GENDER, GENDER_FEMALE);
    Set(P_NUMBER, NUMBER_PLURAL);
    SetValue(2300);
}
