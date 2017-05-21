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
  	"paredes est�n cubiertas de telas de ara�a. El suelo esta cubierto de "
  	"platos rotos y restos de madera. Al fondo hay una ventana que da a la "
  	"parte trasera.\n");

  AddDetail(({"pared"}),"Est� sucia y recubierta de telas de ara�a.\n");
  AddDetail(({"telas de ara�a"}),"Cubren todas las paredes, parecen abandonadas.\n");
  AddDetail(({"ventana"}),"Es una peque�a ventana que da a la parte trasera de la casa.\n");
  AddDetail(({"mesa"}),"est� en muy mal est�do, tiene una pata rota.\n");
  AddDetail(({"cama"}),"Es una cama peque�a de madera, est� totalmente deshecha.\n");
  AddDetail(({"suelo","abajo"}),"El suelo est� lleno de platos rotos y restos de madera.\n");
  AddDetail(({"techo","arriba"}),"El techo est� sucio y lleno de telara�as.\n");
  AddDetail(({"tela de ara�a","telas de ara�a"}),"Hay telas de ara�a por todas "
  	"partes. Parece que hace tiempo que no limpian.\n");
  AddDetail(({"platos"}),"El suelo est� lleno de platos rotos.\n");
  AddDetail(({"restos","restos de madera"}),"El suelo est� lleno de restos de madera.\n");

  AddRoomCmd("saltar","fsaltar");

  AddExit("norte",FLENHAB+"calles/kendarg_03");
}

int fsaltar(string str)
{
	if (str=="por la ventana" || str=="por ventana")
	{
		if(TP->QuerySize()==1)
		{
			write("Consigues pasar a traves de la peque�a ventana y saltas "
				"al exterior.\n");
			say(CATP+" sale por la ventana de atr�s.\n",TP);
			TP->move(FLENHAB+"calles/callejon_01",M_GO);
			say(CATP+" salta desde la ventana de la casa.\n",TP);
			return 1;
		}
		else
		{
			write("La ventana es demasiado peque�a para que puedas pasar "
				"por ella.\n");
			say(CATP+" intenta saltar por la ventana, pero no puede porque "
				"es demasiad"+AO+" grande.\n",TP);
			return 1;
		}
	}
	else
	{
		write("�Saltar por <d�nde>?\n");
		return 1;
	}
}