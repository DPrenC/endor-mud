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
    Set_Drink_Name("zumo de naranja");
    SetLong("Esta botella contiene zumo de naranja exprimido recientemente.\n");
    SetFoodMsg1("Ahhhh... es dulce y refrescante.");
    SetFoodMsg2("se bebe una botella entera de zumo de naranja.");
    SetFoodAlc(0);
    SetFoodHeal(10);
    Set_Vessel_Name("botella");
    Set_Vessel_Value(10);
    Set_Vessel_Weight(500);
    Set_Vessel_Volume(200);
    Set_Vessel_Gender(GENDER_FEMALE);
    AddId(({"zumo","zumo de naranja","botella de zumo"}));
    Set(P_NOSELL,1);
}
