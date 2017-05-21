/** SIMAURIA '/obj/vialm.c'
 *  =======================
 *  Un vial de magia.
 */

#include <properties.h>
#include <health.h>

inherit DRINK;

create() {
    ::create();
    Set_Drink_Name("magia");
    SetLong("Es un vial de regeneración de magia.\n");
    SetFoodMsg1("Notas como tu energía espiritual se va regenerando.");
    SetFoodMsg2("se bebe un vial.");
    SetFoodHeal(50);
    SetIsVial(SP);
    Set_Vessel_Name("vial");
    Set_Vessel_Value(150);
    Set_Vessel_Weight(350);
    Set_Vessel_Volume(330);
    Set_Vessel_Gender(GENDER_MALE);
    AddId(({"vial","vial de magia"}));
}
