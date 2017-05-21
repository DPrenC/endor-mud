/***************************************************************************************
 ARCHIVO:	habitacion_03.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Habitación este 03
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

int armario,espejo;

string farmario()
{
	if (armario) return W("Es un gran armario de madera casi nuevo muy "
		"resistente y elaborado. No parece que tenga cerrojos ni nada. "
		"Está abierto, pero no ves nada en su interior.\n");
	else return W("Es un gran armario de madera casi nuevo muy resistente "
		"y elaborado. No ves que tenga ningún tipo de cerrojo, pero está cerrado.\n");
}

string fespejo()
{
	if (espejo) return (W("En una de las paredes hay colgado un gran espejo enmarcado "
		"en madera tallada muy elaborado. Es muy bonito y está en perfectas condiciones. Reflejado "
		"en el puedes ver tu imagen:\n\n")+TP->QueryLong());
	else if (!espejo) return "Es un espejo muy bonito, o lo era, porque está roto.\n";
}

reset(){
  ::reset();
  armario=0;
  espejo=1;
}

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, segundo piso, ala este");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntSmell(W("Huele a incienso y otras hierbas que se queman en ofrendas por "
  	"todo el templo.\n"));
  SetIntShort("una habitación");
  SetIntLong(W("Te encuentras en una de las habitaciones de los maestros, en "
  	"concreto una muy bien equipada. Puedes ver un enorme armario al lado de "
  	"una cama enorme y de aspecto muy cómodo. A los piés hay una alfombra "
  	"muy útil en los fríos inviernos de Rhoemas y un espejo colgado en la "
  	"pared al lado de unos bonitos tapices.\n"));
  AddDetail(({"armario"}),SF(farmario));
  AddDetail(({"espejo"}),SF(fespejo));
  AddDetail(({"cabecera","cama","colchón","colchon"}),W("Hay una robusta cama de "
  	"madera con un colchón de muy buena calidad muy pesado, por cierto.\n"));
  AddDetail(({"suelo"}),W("El suelo es de roca gris. Está muy limpio y algo frío. Quizás "
  	"por eso el dueño ha puesto una alfombra, para mitigar el frío por las mañanas.\n"));
  AddDetail(({"techo"}),W("El techo está hecho del mismo tipo de roca que el suelo, "
  	"una gris no muy atractiva, pero sin duda resistente.\n"));
  AddDetail(({"tapiz","tapices"}),W("Son unos tapices muy bonitos típicos de la región. "
  	"Están tejidos en lana de muy buena calidad y muy coloridos. Representan escenas "
  	"de la vida cotidiana en el templo.\n"));
  AddDetail(({"pared","paredes"}),W("Las paredes están hechas de roca gris. Hay varios "
  	"tapices que les dan algo de vida.\n"));
  AddRoomCmd("abrir","fabrir");
  AddRoomCmd("cerrar","fcerrar");
  AddRoomCmd("coger","fcoger");
  AddRoomCmd("romper","fromper");
  AddExit("sur",RHOEHAB("seri/piso02/este/pasillo_04"));
  if (!random(2)) AddItem(RHOEPNJ("seri/maestro"),REFRESH_DESTRUCT,1);
  armario=0;
}

int fromper(string str)
{
	if (str=="espejo" && espejo)
	{
		write(W("Aún sabiendo que romper el espejo puede suponer muy mala "
			"suerte lo rompes. Lástima, era muy bonito.\n"));
		say(W(CATP+" rompe el espejo que hay colgado en la pared. Esperas que "
			"no sea supersticioso.\n"),TP);
		espejo=0;
		return 1;
	}
	else if (str=="espejo" && !espejo)
	{
		write(W("El espejo ya está roto. ¿Para qué romperlo más aún?, te podrías "
			"cortar, así que no haces nada.\n"));
		return 1;
	}
	else
	{
		write("Romper <qué>?\n");
		return 1;
	}
}

int fcoger(string str)
{
	if (str=="tapiz" || str=="tapices")
	{
		write(W("No puedes coger los tapices, están colgados demasiado alto "
			"y no llegas.\n"));
		return 1;
	}
	else if (str=="cama")
	{
		write(W("La cama es muy pesada, está hecha de madera maciza, así que "
			"es imposible que puedas cogerla.\n"));
		return 1;
	}
	else if (str=="colchon" || str=="colchón")
	{
		write(W("El colchón es de tan buena calidad que pesa demasiado para "
			"que lo lleves por el templo. ¿Y si te atacan por invadir su "
			"intimidad?.\n"));
		return 1;
	}
	else if (str=="alfombra")
	{
		write(W("Una pata de la cama la pilla de lleno bajo ella. La cama pesa "
			"demasiado incluso para que la muevas, así que como sólo hay dos "
			"opciones: llevarte sólo un trozo de alfombra o dejarla optas "
			"por dejarla.\n"));
		return 1;
	}
	else if (str=="armario")
	{
		write("Seguramente pesará incluso más que tú, así que ni lo sueñes.\n");
		return 1;
	}
	else if (str=="espejo")
	{
		write(W("El espejo es demasiado grande y está muy bien sujeto a la "
			"pared. No puedes cogerlo.\n"));
		return 1;
	}
}

int fabrir(string str)
{
	if (str=="armario")
	{
		if (armario)
		{
			write("El armario ya está abierto.\n");
			return 1;
		}
		else
		{
			write("Abres el armario.\n");
			say(W(CATP+" abre el armario.\n"),TP);
			armario=1;
			return 1;
		}
	}
}

int fcerrar(string str)
{
	if (str=="armario")
	{
		if (armario)
		{
			write("Cierras el armario.\n");
			say(W(CATP+" cierra el armario.\n"),TP);
			armario=0;
			return 1;
		}
		else
		{
			write("El armario ya estaba cerrado.\n");
			return 1;
		}
	}
}
