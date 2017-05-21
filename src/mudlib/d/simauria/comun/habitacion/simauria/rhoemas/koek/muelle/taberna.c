/***************************************************************************************
 ARCHIVO:	taberna.c
 AUTOR:		[z] Zomax
 FECHA:		19-12-2001
 COMENTARIOS:	Taberna del hogar del pescador
 ***************************************************************************************/

#include "path.h"

inherit PUB;
#include RHOEPRESO

create () {
 ::create();

  SetIndoors(1);
  SetIntBright(40);
  SetLocate("Koek");
  SetIntShort("el hogar del pescador");
  SetIntSmell("Huele a pescado, ron y pescadores.\n");
  SetIntNoise("No oyes nada extraño.\n");
  SetIntLong(W("Estás en el hogar del pescador. Este es un sitio de reunión para "
  	"los pescadores del pueblo, una taberna, muy concurrida. Aquí los pescadores "
  	"se reúnen para contar historias fantásticas que sólo un verdadero pescador "
  	"consigue exagerar manteniendo una inexplicable credibilidad.\n"));

  AddDetail(({"suelo"}),"El suelo, hecho de tablones de madera que cruje a tu paso.\n");
  AddDetail(({"trofeos","trofeo"}),W("Son trofeos de pesca de los socios del hogar. Aquí "
  	"se muestran para regocijo de sus dueños.\n"));
  AddDetail(({"pared","paredes"}),"Están llenas de trofeos de pesca.\n");
  AddDetail(({"techo"}),W("El techo es un simple conjunto de tablones de "
 	"madera.\n"));

  carcel=(RHOEHAB("koek/calles/folker_06"));
  AddExit("norte",RHOEHAB("koek/calles/folker_06"));
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");

  AddItem(RHOEPNJ("koek/muelle/acian"),1,1);
  AddItem(RHOEPNJ("koek/muelle/frorewan"),1,1);
  AddItem(RHOEPNJ("koek/muelle/severaw"),1,1);

  AddFood("pescado asado","un plato de",5,10,0,0);
  AddFood("pescado frito","un plato de",5,15,0,0);
  AddDrink("ron","una jarra de",10,10,5,0);
  AddDrink("vino","un vaso de",10,10,5,0);
  AddDrink("whisky","un vaso de",15,15,7,0);
  AddDrink("aguardiente","un vaso de",20,20,10,0);
}

int QueryEntrarPatrullero()
{
	return 1;
}