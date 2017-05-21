/****************************************************************************
Fichero: botas_verdosas.c
Autor: Ratwor
Fecha: 18/05/2010
Descripción: unas botas verdosas de talla normal.
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_BOTAS, 3, P_SIZE_LARGE, M_CUERO);
    SetShort("unas botas verdosas");
    SetLong("Son unas flexibles botas de cuero de color verde oliva y de buena "
    "manofactura.\n");
    SetWeight(1000);
    AddId("botas");
    AddAdjective(({"verdosas", "de", "cuero", "verde", "oliva", "color", "flexibles"}));
    Set(P_GENDER, GENDER_FEMALE);
    Set(P_NUMBER, NUMBER_PLURAL); 
}
