/****************************************************************************
Fichero: sandalias_p.c
Autor: Ratwor
Fecha: 14/05/2010
Descripción: unas sandalias de talla pequeña
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_BOTAS, 1, P_SIZE_SMALL, M_CUERO);
    SetShort("unas sandalias pequeñas");
    SetLong("Son unas pequeñas sandalias de cuero, muy cómodas para viajar.\n");
    SetWeight(300);
    SetIds(({"sandalias"}));
    AddAdjective(({"de", "cuero", "pequeñas"}));
    Set(P_GENDER, GENDER_FEMALE);
    Set(P_NUMBER, NUMBER_PLURAL); 
}
