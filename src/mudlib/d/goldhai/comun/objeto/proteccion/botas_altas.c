/****************************************************************************
Fichero: botas_altas.c
Autor: Ratwor
Fecha: 17/04/2008
Descripci�n: Unas botas altas.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create()
{
    ::create();
    SetStandard(AT_BOTAS, 1, P_SIZE_LARGE, M_CUERO);
    SetShort("unas botas altas");
    SetLong("Se trata de unas botas de ca�a alta, como las que utiliza la caballer�a"
    ". Est�n realizadas en lustroso cuero negro.\n");
    SetIds(({"botas", "botas altas"}));
    Set(P_GENDER, GENDER_FEMALE);
    Set(P_NUMBER, NUMBER_PLURAL);
    SetValue(1400);
}
