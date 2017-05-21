/****************************************************************************
Fichero: gran_escudo.c
Autor: Ratwor
Fecha: 04/12/2007
Descripci�n: Un escudo para los guardias del castillo
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create()
{
    ::create();
    SetStandard(AT_ESCUDO, 4, P_SIZE_GENERIC, M_ACERO);
    SetShort("Un gran escudo");
    SetLong("Es un pesado escudode metal con la parte inferior en forma triangular, y "
    "la superficie curva para desviar los golpes enemigos. Con �l se puede cubrir el "
    "torso y los muslos ofreci�ndo una considerable protecci�n.\n");
    AddId(({"gran escudo", "escudo", "gran", "armadura"}));
    Set(P_GENDER, GENDER_MALE);
    SetWeight(5500);
}
