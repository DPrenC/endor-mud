/*
DESCRIPCION  : una botella de agua
FICHERO      : /d/limbo/comun/objeto/bebida/agua.c
MODIFICACION : 22-09-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

inherit DRINK;
#include <properties.h>  //por el GENDER_FEMALE

create() {
    ::create();
    Set_Drink_Name("agua");
    SetLong("Es una botella de agua.\n");
    SetFoodMsg1("Es refrescante.");
    SetFoodMsg2("se bebe una botella de agua.");
    SetFoodAlc(0);
    SetFoodHeal(5);
    Set_Vessel_Name("botella");
    Set_Vessel_Value(10);
    Set_Vessel_Weight(500);
    Set_Vessel_Volume(200);     /* botella pequenya */
    Set_Vessel_Gender(GENDER_FEMALE);
    AddId(({"agua","botella de agua"}));
    Set(P_NOSELL,1);
}
