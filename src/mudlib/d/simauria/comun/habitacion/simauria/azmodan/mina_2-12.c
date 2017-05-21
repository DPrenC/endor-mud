/***********************************************************/
//	"mina_2-12"
//	Mina abandonada
//	14-12-01 : Creaci�n -> Kodex
//	14-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");

int piedra = 1;

int mirar_cmd(string str)
{

if (str == "cr�neo" || str == "craneo")
	{
	switch (piedra)
		{
		case 0: tell_object(TP,"El cr�neo est� cubierto de polvo.\n"); tell_room(environment(TP),capitalize(TP->QueryRealName()) + " mira candelabro.\n",({TP})); break;
		case 1: tell_object(TP,"Tiene una piedra preciosa por ojo.\n"); tell_room(environment(TP),capitalize(TP->QueryRealName()) + " mira candelabro.\n",({TP})); break;
		default: break;	
		}
	return 1;
	}
}

int coger_cmd(string str)
{
object ob;

if (str == "piedra" || str == "piedra preciosa")
	{
		if (piedra)
			{
			piedra--;
			write("Coges una brillante piedra preciosa.\n");
			say(capitalize(TP->QueryRealName()) + " coge una brillante piedra preciosa del suelo.\n");
			ob = clone_object(OBJETO_AZMODAN("piedra"));
			ob->move(TP);
			return 1;
			}
	}
}


create() {
::create();
SetIntShort("la segunda planta de la mina");
SetIntLong(W("Est�s en un cruce de corredores. Este cruce tiene un gran mont�n de cr�neos en "
"un lateral, seguramente sean de incautos que alcanzaron este nivel de la mina y fueron cazados "
"por los orcos. No te gustar�a estar en el pellejo de esos pobres infelices.\n"));
AddDetail(({"cr�neos","craneos","monton de cr�neos",
"mont�n de craneos","monton de craneos","mont�n de cr�neos"}),
"Son realmente repugnantes. Uno de ellos te llama la atenci�n\n");
AddExit("noroeste",MINA_AZMODAN("mina_2-17"));
AddExit("suroeste",MINA_AZMODAN("mina_2-08"));
AddExit("este",MINA_AZMODAN("mina_2-13"));
if (random(100) < 50)
	{
		switch(random(3))
		{
		case 0 .. 1: AddItem(NPC_AZMODAN("uruk"),REFRESH_DESTRUCT,1); break;
		case 2: AddItem(NPC_AZMODAN("orco"),REFRESH_DESTRUCT,1); break;
		default: break;
		}
	}

}

aviso()
{
tell_object(TP,"Ves algo brillante.... parece una piedra preciosa en el suelo.\n");	
}


init()
{
::init();
if (TP->QueryRace() == "enano" && piedra)	
	call_out("aviso",1);
add_action("coger_cmd","coger");
add_action("mirar_cmd","mirar");
add_action("mirar_cmd","m");	
}