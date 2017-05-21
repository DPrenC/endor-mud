/***************************************************************************************
 ARCHIVO:	cuadra.c
 AUTOR:		[z] Zomax
 FECHA:		24-12-2001	�Feliz Nochebuena!
 COMENTARIOS:	Las cuadras de la granja
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;
#include RHOEPRESO

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(50);
  SetLocate("Koek");
  SetIntShort("las cuadras");
  SetIntSmell("Huele a caballos... �por qu� ser�?.\n");
  SetIntLong(W("Est�s en el interior de las cuadras de Koek. Este es el lugar de "
  	"descanso y crianza de los caballos. Puedes ver varios tablones de madera "
  	"separando en varios cub�culos todo el lugar. En cada uno hay lugar para "
  	"un caballo. Ves tambi�n un abrevadero que pasa por todos y algo de heno "
  	"para que coman.\n"));
  AddDetail(({"tablones","cub�culos","cubiculos","recinto","recintos"}),W("Los "
  	"tablones de madera separan toda la caballeriza en varios recintos "
  	"individuales en los que hay espacio para alojar un caballo.\n"));
  AddDetail(({"abrevadero"}),W("Un ingenioso sistema de canales permite que todos "
  	"los caballos tengan cerca un poco de agua para beber.\n"));
  AddDetail(({"heno"}),W("Hay un poco de heno en cada lugar donde se aloja a un "
  	"caballo.\n"));
  carcel=(RHOEHAB("koek/granja/camino_00"));
  AddExit("este",RHOEHAB("koek/granja/camino_00"));
  AddItem(RHOEPNJ("koek/granja/caballo"),1,1+random(5));
  AddItem(RHOEPNJ("koek/granja/yegua"),1,1+random(5));
  AddItem(RHOEPNJ("koek/granja/potro"),1,1+random(3));
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
		write(W("No necesitas para nada el heno. Est� pisado por los caballos "
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
