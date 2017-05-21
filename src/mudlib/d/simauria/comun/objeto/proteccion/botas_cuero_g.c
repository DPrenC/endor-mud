/*
DESCRIPCION   : botas de cuero grandes
FICHERO       : botas_cuero_g.c
CREACION      : 10-11-01 [Bomber]
MODIFICACION  :
*/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
    ::create();
    SetStandard(AT_BOOTS,1, P_SIZE_LARGE, M_CUERO);
    SetShort("unas botas de cuero grandes");
    SetLong(
    "Son unas botas grandes de cuero del tipo mas corriente. Tienen una gruesa suela y "
    "cubren casi hasta la rodilla. No poseen adornos ni son un trabajo muy fino, "
    "pero cumplen bien su cometido.\n");
    SetWeight(700);
    AddId("botas");
    AddAdjective(({"de", "cuero", "grandes"}));
    Set(P_NUMBER,NUMBER_PLURAL);
    Set(P_GENDER,GENDER_FEMALE);
}