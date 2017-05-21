/*
-------------------------------------------------------------------------------
DESCRIPCION  : Pocion de fortaleza (+1)
FICHERO      : /d/lad-laurelin/comun/objeto/magico/potf.c
MODIFICACION : Alura (4-2-99) muy agradecida a guybrush por su toque final
--------------------------------------------------------------------------------


*/

inherit DRINK;
#include "path.h"
#include <properties.h>  //por el GENDER_MALE

int beb(string str){
if ((str=="pocion")&&(present("pocion roja",TP)))

{
	TP->AddStrBonus(1);
	write("Te siente mas fuerte.\n");
	call_out("bajar_fuerza",200);
	return (::_drink(str));

	}
}

init(){
::init();
add_action("beb","beber");
}

int bajar_fuerza(){
TP->AddStrBonus(-1);
write("Tu fuerza disminuye.\n");
return 1;
}


create() {
    ::create();
    Set_Drink_Name("una pocion");
    SetLong("Es una pocion magica, se ha hecho combinando medicina natural y magia.\n"+
    	    "Te la puedes BEBER.\n");

    SetFoodMsg2("se bebe una pocion de color rojo.");
    SetFoodAlc(0);
    SetFoodHeal(0);
    Set_Vessel_Name("frasco");
    Set_Vessel_Value(30);
    Set_Vessel_Weight(200);
    Set_Vessel_Volume(100);
    Set_Vessel_Gender(GENDER_MALE);
    AddId(({"pocion","pocion roja"}));
}