/*
DESCRIPCION  : una botella de vino
FICHERO      : /d/limbo/comun/objeto/bebida/agua.c
MODIFICACION : 22-09-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

inherit DRINK;
#include <properties.h>  //por el GENDER_FEMALE

create() {
    ::create();
    Set_Drink_Name("vino peleon");
    SetLong("Es una botella de vino peleon.\n");
    SetFoodMsg1("Ahhhh... rasca un poco pero calienta el cuerpo.");
    SetFoodMsg2("bebe una botella entera de vino");
    SetFoodAlc(15);
    SetFoodHeal(20);
    Set_Vessel_Name("botella");
    Set_Vessel_Value(10);
    Set_Vessel_Weight(500);
    Set_Vessel_Volume(200);     /* botella pequenya */
    Set_Vessel_Gender(GENDER_FEMALE);
    AddId(({"vino","botella de vino","vino peleon"}));
    Set(P_NOSELL,1);
}
