/***************************************************************************************
 ARCHIVO:	gallinero.c
 AUTOR:		[z] Zomax
 FECHA:		24-12-2001	�Feliz Nochebuena!
 COMENTARIOS:	El gallinero de la granja
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;
#include RHOEPRESO

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(50);
  SetLocate("Koek");
  SetIntShort("el gallinero");
  SetIntSmell("Huele a gallinas.\n");
  SetIntLong(W("Este es el gallinero. Lo normal es que est� lleno de gallinas "
  	"nerviosas picoteando el suelo con gran ansiedad. Hay un peque�o abrevadero "
  	"para que beban.\n"));
  AddDetail(({"abrevadero"}),W("Un ingenioso sistema de canales permite que todas "
  	"las gallinas tengan cerca un poco de agua para beber.\n"));
  carcel=(RHOEHAB("koek/granja/camino_00"));
  AddExit("oeste",RHOEHAB("koek/granja/camino_00"));
  AddItem(RHOEPNJ("koek/granja/gallina"),1,5+random(7));
  AddItem(RHOEPNJ("koek/granja/gallo"),1,1);
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
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

int QueryEntrarPatrullero()
{
	return 1;
}
