/***************************************************************************************
 ARCHIVO:	habitacion_03.c
 AUTOR:		[z] Zomax
 FECHA:		04-01-2002
 COMENTARIOS:	Habitaci�n oeste 03
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

int espejo;

string fespejo()
{
	if (espejo) return (W("En una de las paredes hay colgado un gran espejo enmarcado "
		"en madera tallada. Es muy bonito y est� en perfectas condiciones. Reflejado "
		"en el puedes ver tu imagen:\n\n")+TP->QueryLong());
	else if (!espejo) return "Es un espejo muy bonito, o lo era, porque est� roto.\n";
}

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, planta baja, ala oeste");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntSmell(W("Huele a incienso y otras hierbas que se queman en ofrendas por "
  	"todo el templo.\n"));
  SetIntShort("una habitaci�n");
  SetIntLong(W("Est�s en una habitaci�n muy simple, pr�cticamente cuatro paredes "
  	"techo y suelo. En uno de los lados hay una cama de madera, algo vieja y "
  	"carcomida. En otra pared ves un gran espejo colgado.\n"));
  AddDetail(({"cama","colch�n","colchon"}),W("Hay una cama muy b�sica hecha de "
  	"madera en no muy buen estado. El colch�n es de paja.\n"));
  AddDetail(({"espejo"}),SF(fespejo));
  AddDetail(({"suelo"}),"El suelo es de roca gris. Est� muy limpio y algo fr�o.\n");
  AddDetail(({"techo"}),W("El techo est� hecho del mismo tipo de roca que el suelo, "
  	"una gris no muy atractiva, pero sin duda resistente.\n"));
  AddDetail(({"pared","paredes"}),W("Las paredes est�n hechas de roca gris. En una de "
  	"ellas puedes ver un gran espejo colgado.\n"));
  AddRoomCmd("coger","fcoger");
  AddRoomCmd("romper","fromper");
  espejo=1;
  AddExit("sur",RHOEHAB("seri/piso00/oeste/pasillo_02"));
  if (!random(2)) AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1);
}

reset(){
  ::reset();
  espejo=1;
}

int fromper(string str)
{
	if (str=="espejo" && espejo)
	{
		write(W("A�n sabiendo que romper el espejo puede suponer muy mala "
			"suerte lo rompes. L�stima, era muy bonito.\n"));
		say(W(CATP+" rompe el espejo que hay colgado en la pared. Esperas que "
			"no sea supersticioso.\n"),TP);
		espejo=0;
		return 1;
	}
	else if (str=="espejo" && !espejo)
	{
		write(W("El espejo ya est� roto. �Para qu� romperlo m�s a�n?, te podr�as "
			"cortar, as� que no haces nada.\n"));
		return 1;
	}
	else
	{
		write("Romper <qu�>?\n");
		return 1;
	}
}

int fcoger(string str)
{
	if (str=="espejo")
	{
		write(W("El espejo es demasiado grande y est� muy bien sujeto a la "
			"pared. No puedes cogerlo.\n"));
		return 1;
	}
	else if (str=="cama")
	{
		write(W("No puedes coger la cama, a�n siendo bastante simple es demasiado "
			"pesada para llevarla.\n"));
		return 1;
	}
}
