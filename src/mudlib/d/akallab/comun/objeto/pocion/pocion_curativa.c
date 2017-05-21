/*
DESCRIPCION  : una pocion curativa de la curandera
FICHERO      : /d/akallab/comun/objeto/bebida/pocion_curativa.c
MODIFICACION : 20-02-99 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

inherit DRINK;
#include "path.h"

#include <properties.h>  //por el GENDER_FEMALE

create() {
    ::create();
    Set_Drink_Name("una pocion curativa");
    SetLong(
    "Esta botella contiene una poderosa pocion curativa hecha a base de hierbas "
      "medicinales. Su olor y color no son muy atractivos, pero funciona.\n");

    SetFoodMsg1("Puajj... es muy amarga, pero hace que tu cuerpo se recupere.");
    SetFoodMsg2("se bebe una botella entera de pocion curativa.");
    SetFoodAlc(0);
    SetFoodHeal(30);
    Set_Vessel_Name("botella");
    Set_Vessel_Value(10);
    Set_Vessel_Weight(750);
    Set_Vessel_Volume(500);
    Set_Vessel_Gender(GENDER_FEMALE);
    AddId(({"pocion","pocion curativa","botella pocion"}));
}
