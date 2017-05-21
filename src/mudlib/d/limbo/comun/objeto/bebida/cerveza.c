/*
DESCRIPCION  : una cerveza
FICHERO      : /d/limbo/comun/objeto/bebida/cerveza.c
MODIFICACION : 22-09-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

inherit DRINK;
#include <properties.h>  //por el GENDER_FEMALE

create() {
    ::create();
    Set_Drink_Name("cerveza");
    SetLong("Es una botella de cerveza añeja.\n");
    SetFoodMsg1("Ahhhh... entra suavemente.");
    SetFoodMsg2("se bebe una botella de cerveza.");
    SetFoodAlc(10);
    SetFoodHeal(15);
    Set_Vessel_Name("botella");
    Set_Vessel_Value(10);
    Set_Vessel_Weight(500);
    Set_Vessel_Volume(200);     /* botella pequenya */
    Set_Vessel_Gender(GENDER_FEMALE);
    AddId(({"cerveza","botella de cerveza"}));
    Set(P_NOSELL,1);
}
