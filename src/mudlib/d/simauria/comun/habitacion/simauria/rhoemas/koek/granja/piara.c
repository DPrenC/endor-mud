/***************************************************************************************
 ARCHIVO:	piara.c
 AUTOR:		[z] Zomax
 FECHA:		24-12-2001	¡Feliz Nochebuena!
 COMENTARIOS:	La piara de la granja
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;
#include RHOEPRESO

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(50);
  SetLocate("Koek");
  SetIntShort("la piara");
  SetIntSmell("Huele a cerdos. Lógico, por otra parte.\n");
  SetIntLong(W("Estás en el interior de la piara de Koek. Aquí cuidan a los "
  	"cerdos y los mantienen a salvo de los peligros del campo abierto. "
  	"Parece que los tienen muy limpios y cuidados.\n"));
  AddDetail(({"abrevadero central","canales","abrevadero"}),W("Un ingenioso "
  	"sistema de canales permite que todos los cerdos tengan cerca un poco de "
  	"agua para beber.\n"));
  AddDetail(({"heno"}),W("Hay un poco de heno en cada lugar donde se aloja a un "
  	"cerdo.\n"));
  carcel=(RHOEHAB("koek/granja/camino_01"));
  AddExit("oeste",RHOEHAB("koek/granja/camino_01"));
  AddItem(RHOEPNJ("koek/granja/cerdo"),1,1+random(12));
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
  AddRoomCmd("coger","fcoger");
  AddRoomCmd("beber","fbeber");
}

int fbeber(string str)
{
	if (str=="agua")
	{
		write(W("¿No se te ocurrirá beber del abrevadero, no? A saber "
			"que enfermedades podrías coger.\n"));
		return 1;
	}
return 0;
}

	
int fcoger(string str)
{
	if (str=="heno")
	{
		write(W("No necesitas para nada el heno. Está pisado por los cerdos "
			"y no podrías comértelo sin sufrir algún tipo de intoxicación. "
			"Decides no cogerlo.\n"));
		return 1;
	}
return 0;
}

int QueryEntrarPatrullero()
{
	return 1;
}
