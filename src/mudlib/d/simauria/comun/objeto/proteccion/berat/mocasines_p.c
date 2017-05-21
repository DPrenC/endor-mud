/****************************************************************************
Fichero: mocasines_p.c
Autor: Ratwor
Fecha: 14/05/2010
Descripci�n: unos mocasines de talla peque�a
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_BOTAS, 1, P_SIZE_SMALL, M_CUERO);
    SetShort("unos mocasines peque�os");
    SetLong("Son unos peque�os mocasines de cuero blando, muy c�modos y flexibles.\n");
    SetWeight(300);
    SetIds(({"mocasines", "zapatos"}));
    AddAdjective(({"de", "cuero", "peque�os", "blando"}));
    Set(P_GENDER, GENDER_MALE);
    Set(P_NUMBER, NUMBER_PLURAL); 
}
