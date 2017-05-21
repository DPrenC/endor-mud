/** SIMAURIA '/obj/vialv.c'
 *  =======================
 *  Un vial de vida
 */

#include <properties.h>
#include <health.h>

inherit DRINK;

create() {
    ::create();
    Set_Drink_Name("vida");
    SetLong("Es un vial de regeneración de vida.\n");
    SetFoodMsg1("A medida que lo bebes vas sintiendo como se curan tus heridas.");
    SetFoodMsg2("se bebe un vial.");
    SetFoodHeal(50);
    SetIsVial(HP);
    Set_Vessel_Name("vial");
    Set_Vessel_Value(150);
    Set_Vessel_Weight(350);
    Set_Vessel_Volume(330);
    Set_Vessel_Gender(GENDER_MALE);
    AddId(({"vial","vial de vida"}));
}
