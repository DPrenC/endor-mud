/***********************************************************/
//	"mina_3-03"
//	Mina abandonada, fuente(barril)
//	15-12-01 : Creación -> Kodex
//	15-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


int beber_cmd(string str)
{

if (!str) return notify_fail("Beber qué??\n"),0;
if (str == "agua" || str == "agua de barril" || str == "de barril")
	{
	if (TP->QueryDrink() >= TP->QueryMaxDrink())
   		{
    		write("No puedes beber nada más.\n");
    		say(capitalize(TP->QueryRealName())+" intenta beber del barril, pero no puede.\n");
    		return 1;
   		}
  	else
  		{
  		TP->SetDrink(TP->QueryDrink()+4);
		say(capitalize(TP->QueryName())+" bebe algo del agua del barril y se lleva las manos a la garganta.\n");
		write("Bebes un poco de agua del barril.\nEl agua sabe asquerosa! además sientes pesadumbre.\n");
		TP->AddTP(-6);
 		return 1;	
		}
	}
else
	return notify_fail("No encuentras " + str + " para beber.\n"),0;

	
}

create() {
::create();
SetIntShort("la tercera planta de la mina");
SetIntLong(W("Estás en una zona del tercer de la mina donde los orcos "
"han estado trabajando, han dejado los picos en un lado y ves varios "
"montones de piedras. Tambien ves un barril a un lado.\n"));
AddDetail(({"pico","picos"}),
"Los orcos han debido dejarlos ahí para seguir trabajando luego, crees que "
"es mejor dejarlos donde están.\n");
AddDetail(({"barril"}),"Tiene agua, pero es de un color muy extraño...\n");
AddExit("sur",MINA_AZMODAN("mina_3-01"));
AddExit("oeste",MINA_AZMODAN("mina_3-02"));
AddExit("este",MINA_AZMODAN("mina_3-04"));
if (random(100) < 50)
	{
		switch(random(2))
		{
		case 0: AddItem(NPC_AZMODAN("shaman"),REFRESH_DESTRUCT,1); break;
		case 1: AddItem(NPC_AZMODAN("uruk"),REFRESH_DESTRUCT,1); break;
		default: break;
		}
	}

}

init()
{

::init();
add_action("beber_cmd","beber");
	
}
