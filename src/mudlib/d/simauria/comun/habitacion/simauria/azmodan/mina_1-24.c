/***********************************************************/
//	"mina_1-24"
//	Mina abandonada
//	11-12-01 : Creación -> Kodex
//	11-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


int piedra = 1;

int mirar_cmd(string str)
{

if (str == "suelo")
	{
	switch (piedra)
		{
		case 0: tell_object(TP,"El suelo es de tierra rocosa.\n"); tell_room(environment(TP),capitalize(TP->QueryRealName()) + " mira suelo.\n",({TP})); break;
		case 1: tell_object(TP,"Ves una piedra preciosa en el suelo.\n"); tell_room(environment(TP),capitalize(TP->QueryRealName()) + " mira suelo.\n",({TP})); break;
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
SetIntShort("la primera planta de la mina");
SetIntLong(W("La oscuridad te envuelve, estás en lo más profundo de este nivel"
" de la mina. Es difícil recordar el camino de vuelta al exterior entre tantos "
"pasillos y conductos, pero aún te quedan fuerzas. Ves que la mina se oscurece "
"más hacia el noroeste. El suelo esta lleno de escombros.\n"));
AddDetail(({"escombros"}),"Deben haberse desprendido al extraer mineral.\n");
AddExit("noroeste",MINA_AZMODAN("mina_1-26"));
AddExit("suroeste",MINA_AZMODAN("mina_1-20"));
AddExit("sudeste",MINA_AZMODAN("mina_1-21"));
		switch(random(3))
		{
		case 0 .. 1: AddItem(NPC_AZMODAN("orco"),REFRESH_DESTRUCT,1);break;
		case 2: AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1); AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1); break;
		default: break;
		}

}

aviso()
{
	if (piedra)
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