/** SIMAURIA '/obj/vial.c'
 *  =======================
 *  Un vial de magia y vida.
 */

#include <properties.h>
#include <health.h>

inherit DRINK;

create() {
    ::create();
    Set_Drink_Name("regeneración");
    SetLong("Es un vial de regeneración.\n");
    SetFoodMsg1("Notas como te vas regenerando en cuerpo y mente.");
    SetFoodMsg2("se bebe un vial.");
    SetFoodHeal(100);
    SetIsVial(SP|HP);
    Set_Vessel_Name("vial");
    Set_Vessel_Value(300);
    Set_Vessel_Weight(350);
    Set_Vessel_Volume(330);
    Set_Vessel_Gender(GENDER_MALE);
    AddId("vial");
}
