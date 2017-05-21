/****************************************************************************
Fichero: mocasines_p.c
Autor: Ratwor
Fecha: 14/05/2010
Descripción: unos mocasines de talla pequeña
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_BOTAS, 1, P_SIZE_SMALL, M_CUERO);
    SetShort("unos mocasines pequeños");
    SetLong("Son unos pequeños mocasines de cuero blando, muy cómodos y flexibles.\n");
    SetWeight(300);
    SetIds(({"mocasines", "zapatos"}));
    AddAdjective(({"de", "cuero", "pequeños", "blando"}));
    Set(P_GENDER, GENDER_MALE);
    Set(P_NUMBER, NUMBER_PLURAL); 
}
