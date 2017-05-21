/****************************************************************************
Fichero: botas_cuero.c
Autor: Ratwor
Fecha: 14/05/2010
Descripción: unas botas de cuero normales.
****************************************************************************/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
    ::create();
    SetStandard(AT_BOOTS,1, P_SIZE_MEDIUM, M_CUERO);
    SetShort("unas botas de cuero");
    SetLong(
    "Son unas botas de cuero del tipo mas corriente. Tienen una gruesa suela y "
    "cubren casi hasta la rodilla. No poseen adornos ni son un trabajo muy fino, "
    "pero cumplen bien su cometido.\n");

    AddId("botas");
    AddAdjective(({"de", "cuero"}));
    Set(P_NUMBER,NUMBER_PLURAL);
    Set(P_GENDER,GENDER_FEMALE);
    SetWeight(500);
}