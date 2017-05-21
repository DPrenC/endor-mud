/****************************************************************************
Fichero: gran_escudo.c
Autor: Ratwor
Fecha: 04/12/2007
Descripción: Un escudo para los guardias del castillo
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
    "la superficie curva para desviar los golpes enemigos. Con él se puede cubrir el "
    "torso y los muslos ofreciéndo una considerable protección.\n");
    AddId(({"gran escudo", "escudo", "gran", "armadura"}));
    Set(P_GENDER, GENDER_MALE);
    SetWeight(5500);
}
