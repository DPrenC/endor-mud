/***************************************************************************************
 ARCHIVO:	casa_06.c
 AUTOR:		[k] Korsario
 FECHA:		28-02-1998
 COMENTARIOS:	Casa de un kender
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit ROOM;

create(){
  ::create();

  SetIndoors(1);
  SetIntBright(80);
  SetLocate("flenton");
  SetIntNoise("Escuchas el rumor de la calle.\n");
  SetIntSmell("Huele a moho y a polvo.\n");

  SetIntShort("una casa de la calle Kendarg");
  SetIntLong("Entras a una destartalada casa. Las maderas del suelo crujen "
  	"al pisar. Hay una cama deshecha al fondo y una mesa rota en medio. Las "
  	"paredes están cubiertas de telas de araña. El suelo esta cubierto de "
  	"platos rotos y restos de madera. Al fondo hay una ventana que da a la "
  	"parte trasera.\n");

  AddDetail(({"pared"}),"Está sucia y recubierta de telas de araña.\n");
  AddDetail(({"telas de araña"}),"Cubren todas las paredes, parecen abandonadas.\n");
  AddDetail(({"ventana"}),"Es una pequeña ventana que da a la parte trasera de la casa.\n");
  AddDetail(({"mesa"}),"está en muy mal estádo, tiene una pata rota.\n");
  AddDetail(({"cama"}),"Es una cama pequeña de madera, está totalmente deshecha.\n");
  AddDetail(({"suelo","abajo"}),"El suelo está lleno de platos rotos y restos de madera.\n");
  AddDetail(({"techo","arriba"}),"El techo está sucio y lleno de telarañas.\n");
  AddDetail(({"tela de araña","telas de araña"}),"Hay telas de araña por todas "
  	"partes. Parece que hace tiempo que no limpian.\n");
  AddDetail(({"platos"}),"El suelo está lleno de platos rotos.\n");
  AddDetail(({"restos","restos de madera"}),"El suelo está lleno de restos de madera.\n");

  AddRoomCmd("saltar","fsaltar");

  AddExit("norte",FLENHAB+"calles/kendarg_03");
}

int fsaltar(string str)
{
	if (str=="por la ventana" || str=="por ventana")
	{
		if(TP->QuerySize()==1)
		{
			write("Consigues pasar a traves de la pequeña ventana y saltas "
				"al exterior.\n");
			say(CATP+" sale por la ventana de atrás.\n",TP);
			TP->move(FLENHAB+"calles/callejon_01",M_GO);
			say(CATP+" salta desde la ventana de la casa.\n",TP);
			return 1;
		}
		else
		{
			write("La ventana es demasiado pequeña para que puedas pasar "
				"por ella.\n");
			say(CATP+" intenta saltar por la ventana, pero no puede porque "
				"es demasiad"+AO+" grande.\n",TP);
			return 1;
		}
	}
	else
	{
		write("¿Saltar por <dónde>?\n");
		return 1;
	}
}