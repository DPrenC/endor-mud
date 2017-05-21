/*
DESCRIPCION   : botas de cuero peque�as
FICHERO       : botas_cuero_p.c
CREACION      : 10-11-01 [Bomber]
MODIFICACION  :
*/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
    ::create();
    SetStandard(AT_BOOTS,1, P_SIZE_SMALL, M_CUERO);
    SetShort("unas botas de cuero peque�as");
    SetLong(
    "Son unas botas peque�as de cuero del tipo mas corriente. Tienen una gruesa suela y "
    "cubren casi hasta la rodilla. No poseen adornos ni son un trabajo muy fino, "
    "pero cumplen bien su cometido.\n");
    SetWeight(300);
    AddId("botas");
    AddAdjective(({"de", "cuero", "peque�as"}));
    Set(P_NUMBER,NUMBER_PLURAL);
    Set(P_GENDER, GENDER_FEMALE);
}