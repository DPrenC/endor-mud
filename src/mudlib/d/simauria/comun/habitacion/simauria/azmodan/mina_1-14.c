/***********************************************************/
//	"mina_1-14"
//	Mina abandonada
//	11-12-01 : Creaci�n -> Kodex
//	11-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


int piedra = 1;

int mirar_cmd(string str)
{

if (str == "basura")
	{
	switch (piedra)
		{
		case 0: tell_object(TP,"S�lo ves un mont�n de basura.\n"); tell_room(environment(TP),capitalize(TP->QueryRealName()) + " mira candelabro.\n",({TP})); break;
		case 1: tell_object(TP,"Puedes ver una piedra preciosa entre la basura.\n"); tell_room(environment(TP),capitalize(TP->QueryRealName()) + " mira candelabro.\n",({TP})); break;
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
SetIntLong(W("Est�s en un espacio algo m�s abierto que los angostos"
" pasillos que forman esta mina, ves varios carros de mineral vac�os"
" colocados unos encima de otros. Esta deb�a ser la parte donde se "
"almacenaba el mineral extra�do, ahora parece un gran vertedero de basura.\n"));
AddDetail(({"carros","carro","carros de mineral"}),"Est�n totalmente vac�os y muy oxidados.\n");
AddExit("este",MINA_AZMODAN("mina_1-15"));
AddExit("sur",MINA_AZMODAN("mina_1-10"));
AddExit("norte",MINA_AZMODAN("mina_1-19"));
		switch(random(3))
		{
		case 0 .. 1: AddItem(NPC_AZMODAN("orco"),REFRESH_DESTRUCT,1);break;
		case 2: AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1); AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1); break;
		default: break;
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