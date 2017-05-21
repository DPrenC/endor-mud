/****************************************************************************
Fichero: baston_lujoso.c
Autor: Ratwor
Fecha: 17/04/2008
Descripci�n: un bast�n lujoso.
****************************************************************************/

#include "./path.h"
#include <combat.h>
#include <properties.h>
inherit WEAPON;

create() {
    ::create();
    SetStandard(WT_VARA,2,P_SIZE_MEDIUM,M_MADERA);
    SetIds(({"baston","bast�n","bast�n lujoso", "lujoso bast�n"}));
    SetShort("un lujoso bast�n");
    SetLong("Es un bast�n con la ca�a realizada en una pulida madera de �bano y con "
    "la empu�adura en forma de cabeza de le�n forjado en oro macizo.\n");
    SetWeight(1000);
    SetNumberHands(1);
    SetValue(QueryValue()*10);
    Set(P_GENDER, GENDER_MALE);
}
