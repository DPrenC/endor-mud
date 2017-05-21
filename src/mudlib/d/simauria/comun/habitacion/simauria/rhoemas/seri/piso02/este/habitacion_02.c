/***************************************************************************************
 ARCHIVO:	habitacion_02.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Habitaci�n este 02
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

int armario;

string farmario()
{
	if (armario) return W("Es un gran armario de madera casi nuevo muy "
		"resistente y elaborado. No parece que tenga cerrojos ni nada. "
		"Est� abierto, pero no ves nada en su interior.\n");
	else return W("Es un gran armario de madera casi nuevo muy resistente "
		"y elaborado. No ves que tenga ning�n tipo de cerrojo, pero est� cerrado.\n");
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
  SetIntShort("una habitaci�n");
  SetIntLong(W("Curioseas por la habitaci�n de un maestro. Esta habitaci�n est� "
  	"algo m�s cuidada que las de los fieles de menor rango, con uno bonito "
  	"armario en perfectas condiciones y una cama con una mesita al lado. La "
  	"cama incluso parece de mucha mejor calidad que las que hab�as visto hasta "
  	"el momento. Adem�s hay una peque�a alfombra de lana pura en el suelo "
  	"para no pasar fr�o cuando se levanta descalzo.\n"));
  AddDetail(({"armario"}),SF(farmario));
  AddDetail(({"cabecera","cama","colch�n","colchon"}),W("Hay una robusta cama de "
  	"madera con un colch�n de muy buena calidad muy pesado, por cierto.\n"));
  AddDetail(({"suelo"}),W("El suelo es de roca gris. Est� muy limpio y algo fr�o. Quiz�s "
  	"por eso el due�o ha puesto una alfombra, para mitigar el fr�o por las ma�anas.\n"));
  AddDetail(({"techo"}),W("El techo est� hecho del mismo tipo de roca que el suelo, "
  	"una gris no muy atractiva, pero sin duda resistente.\n"));
  AddDetail(({"tapiz","tapices"}),W("Son unos tapices muy bonitos t�picos de la regi�n. "
  	"Est�n tejidos en lana de muy buena calidad y muy coloridos. Representan escenas "
  	"de la vida cotidiana en el templo.\n"));
  AddDetail(({"pared","paredes"}),W("Las paredes est�n hechas de roca gris. Hay varios "
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
		write(W("No puedes coger los tapices, est�n colgados demasiado alto "
			"y no llegas.\n"));
		return 1;
	}
	else if (str=="cama")
	{
		write(W("La cama es muy pesada, est� hecha de madera maciza, as� que "
			"es imposible que puedas cogerla.\n"));
		return 1;
	}
	else if (str=="colchon" || str=="colch�n")
	{
		write(W("El colch�n es de tan buena calidad que pesa demasiado para "
			"que lo lleves por el templo. �Y si te atacan por invadir su "
			"intimidad?.\n"));
		return 1;
	}
	else if (str=="alfombra")
	{
		write(W("Una pata de la cama la pilla de lleno bajo ella. La cama pesa "
			"demasiado incluso para que la muevas, as� que como s�lo hay dos "
			"opciones: llevarte s�lo un trozo de alfombra o dejarla optas "
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
		write("Seguramente pesar� incluso m�s que t�, as� que ni lo sue�es.\n");
		return 1;
	}
}

int fabrir(string str)
{
	if (str=="armario")
	{
		if (armario)
		{
			write("El armario ya est� abierto.\n");
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
