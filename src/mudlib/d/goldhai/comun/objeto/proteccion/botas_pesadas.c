/****************************************************************************
Fichero: botas_pesadas.c
Autor: Ratwor
Fecha: 17/04/2008
Descripción: Unas botas pesadas
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create()
{
    ::create();
    SetStandard(AT_BOTAS, 3, P_SIZE_LARGE, M_CUERO);
    SetShort("unas pesadas botas");
    SetLong("Unas botas de gruesa suela, taraceadas con gruesos remaches. La piel es "
    "firme y resistente. Se ajustan con pesadas hebillas. Un calzado perfecto para "
    "moverse por terrenos abruptos e irregulares.\n");
    SetValue(1000);
    SetIds(({"botas", "pesadas botas", "botas pesadas"}));
    Set(P_GENDER, GENDER_FEMALE);
    Set(P_NUMBER, NUMBER_PLURAL);
}
