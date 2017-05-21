/****************************************************************************
Fichero: botines.c
Autor: Ratwor
Fecha: 17/04/2008
Descripción: Unas suaves botines.
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create()
{
    ::create();
    switch(d2()){
        case 1: SetStandard(AT_BOTAS, 1, P_SIZE_LARGE, M_PIEL); break;
        case 2: SetStandard(AT_BOTAS, 1, P_SIZE_SMALL, M_PIEL); break;
    }

    SetShort("unos suaves botines");
    SetLong("Son unos delicados botines, realizados en fina piel de gamuza. Excelentes "
    "para moverse con sigilo, por cualquier terreno.\n");
    SetValue(2000);
    SetIds(({"botas", "botines", "suaves botines", "botines suaves"}));
    Set(P_GENDER, GENDER_MALE);
    Set(P_NUMBER, NUMBER_PLURAL);
}
