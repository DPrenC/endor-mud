/****************************************************************************
Fichero: baston_lujoso.c
Autor: Ratwor
Fecha: 17/04/2008
Descripción: un bastón lujoso.
****************************************************************************/

#include "./path.h"
#include <combat.h>
#include <properties.h>
inherit WEAPON;

create() {
    ::create();
    SetStandard(WT_VARA,2,P_SIZE_MEDIUM,M_MADERA);
    SetIds(({"baston","bastón","bastón lujoso", "lujoso bastón"}));
    SetShort("un lujoso bastón");
    SetLong("Es un bastón con la caña realizada en una pulida madera de ébano y con "
    "la empuñadura en forma de cabeza de león forjado en oro macizo.\n");
    SetWeight(1000);
    SetNumberHands(1);
    SetValue(QueryValue()*10);
    Set(P_GENDER, GENDER_MALE);
}
