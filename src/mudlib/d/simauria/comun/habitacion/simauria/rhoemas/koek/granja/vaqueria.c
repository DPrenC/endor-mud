/***************************************************************************************
 ARCHIVO:	vaqueria.c
 AUTOR:		[z] Zomax
 FECHA:		24-12-2001	�Feliz Nochebuena!
 COMENTARIOS:	La vaquer�a de la granja
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;
#include RHOEPRESO

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(50);
  SetLocate("Koek");
  SetIntShort("la vaquer�a");
  SetIntSmell("Huele a vacas. L�gico, por otra parte.\n");
  SetIntLong(W("Est�s en el interior de la vaquer�a de Koek. Aqu� cuidan a las "
  	"vacas y las mantienen a salvo para que den buena leche. Hay unos peque�os "
  	"canales que llevan agua del abrevadero central a uno peque�o por cada "
  	"vaca. Tambi�n hay un poco de heno por cada vaca, para que se alimenten.\n"));
  AddDetail(({"abrevadero central","canales","abrevadero"}),W("Un ingenioso "
  	"sistema de canales permite que todas las vacas tengan cerca un poco de "
  	"agua para beber.\n"));
  AddDetail(({"heno"}),W("Hay un poco de heno en cada lugar donde se aloja a una "
  	"vaca.\n"));
  carcel=(RHOEHAB("koek/granja/camino_01"));
  AddExit("este",RHOEHAB("koek/granja/camino_01"));
  AddItem(RHOEPNJ("koek/granja/vaca"),REFRESH_DESTRUCT,1+random(8));
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
		write(W("�No se te ocurrir� beber del abrevadero, no? A saber "
			"que enfermedades podr�as coger.\n"));
		return 1;
	}
return 0;
}


int fcoger(string str)
{
	if (str=="heno")
	{
		write(W("No necesitas para nada el heno. Est� pisado por las vacas "
			"y no podr�as com�rtelo sin sufrir alg�n tipo de intoxicaci�n. "
			"Decides no cogerlo.\n"));
		return 1;
	}
return 0;
}

int QueryEntrarPatrullero()
{
	return 1;
}
