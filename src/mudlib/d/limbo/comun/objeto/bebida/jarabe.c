/*
DESCRIPCION  : un jarabe curativo
FICHERO      : /d/limbo/comun/objeto/bebida/jarabe.c
MODIFICACION : 01-10-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

inherit DRINK;
#include <properties.h>  //por el GENDER_FEMALE

create() {
    ::create();
    Set_Drink_Name("jarabe curativo");
    SetLong("Esta botella contiene un jarabe rojizo de efectos curativos.\n");
    SetFoodMsg1("Puajj... es muy amargo, pero hace que tu cuerpo se recupere.");
    SetFoodMsg2("se bebe una botella entera de jarabe curativo.");
    SetFoodAlc(0);
    SetFoodHeal(15);
    Set_Vessel_Name("botella");
    Set_Vessel_Value(10);
    Set_Vessel_Weight(2000);
    Set_Vessel_Volume(200);
    Set_Vessel_Gender(GENDER_FEMALE);
    AddId(({"jarabe","jarabe curativo","botella de jarabe"}));
    Set(P_NOSELL,1);
}
