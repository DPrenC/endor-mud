/*   vino.c
     Creado por : Blackrider
     Fecha 2-11-97
*/

inherit DRINK;
inherit FOOD;

create() {
::create();
SetShort("vino");
SetLong("Es un vino tinto con denominacion de origen.\n");
AddId("vino");
SetFoodMsg1("GLUPPP.... hip.... hipp.....");
Set_Vessel_Name("botella");
Set_Vessel_Volume(200);
Set_Vessel_Gender(1);
Set_Drink_Name("vino");
SetFoodSoak(15);
SetWeight(150);
SetFoodAlc(20);
SetValue(5);
}
