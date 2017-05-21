/***************************************************************************************
 ARCHIVO:	habitacion_02.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Habitación este 02
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

int armario;

string farmario()
{
	if (armario) return W("Es un gran armario de madera casi nuevo muy "
		"resistente y elaborado. No parece que tenga cerrojos ni nada. "
		"Está abierto, pero no ves nada en su interior.\n");
	else return W("Es un gran armario de madera casi nuevo muy resistente "
		"y elaborado. No ves que tenga ningún tipo de cerrojo, pero está cerrado.\n");
}

reset(){
  ::reset();
  armario=0;
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
  SetIntLong(W("Curioseas por la habitación de un maestro. Esta habitación está "
  	"algo más cuidada que las de los fieles de menor rango, con uno bonito "
  	"armario en perfectas condiciones y una cama con una mesita al lado. La "
  	"cama incluso parece de mucha mejor calidad que las que habías visto hasta "
  	"el momento. Además hay una pequeña alfombra de lana pura en el suelo "
  	"para no pasar frío cuando se levanta descalzo.\n"));
  AddDetail(({"armario"}),SF(farmario));
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
  AddExit("este",RHOEHAB("seri/piso02/este/pasillo_07"));
  if (!random(2)) AddItem(RHOEPNJ("seri/maestro"),REFRESH_DESTRUCT,1);
  armario=0;
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
	else if (str=="mesa" || str=="mesita")
	{
		write("No debes, no quieres y no puedes.\n");
		return 1;
	}
	else if (str=="armario")
	{
		write("Seguramente pesará incluso más que tú, así que ni lo sueñes.\n");
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
