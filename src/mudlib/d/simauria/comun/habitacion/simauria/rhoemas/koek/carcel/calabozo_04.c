/***************************************************************************************
 ARCHIVO:	calabozo_04.c
 AUTOR:		[z] Zomax
 FECHA:		02-12-2001
 COMENTARIOS:	Calabozo 4 de la cárcel de Koek
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit SIM_ROOM;

mixed celda,carcel;

create () {
  ::create();

  SetLocate("Koek");
  SetIntShort("el calabozo nº4 de la cárcel");
  SetIntLong(W("Estás en el calabozo nº4 de la cárcel de Koek. Es un sitio "
  	"oscuro y un poco húmedo que mas o menos consta de cuatro paredes de ladrillos "
  	"y en una de ellas una puerta de metal bien cerrada. Parece que aquí la "
  	"humedad es incluso más fuerte que en los otros calabozos.\n"));

  AddDetail(({"pared","paredes","ladrillo","ladrillos"}),W("Las paredes están hechas de "
  	"ladrillos muy sólidos pese a la humedad.\n"));
  AddDetail(({"puerta","puerta de metal"}),W("Es una gran puerta de metal, parece que "
  	"de hierro o acero. Está cerrada, cómo no.\n"));
  AddDetail(({"suelo"}),W("¡Vaya!, parece que el suelo se ha deteriorado debido a la "
  	"humedad!\n"));

  AddRoomCmd("abrir","fabrir");
  AddRoomCmd("embestir","fembestir");
  AddRoomCmd("cavar","fcavar");
}

int fabrir(string str)
{
	if (str=="puerta" || str=="puerta de metal" || str=="puerta metalica" || str=="puerta metálica")
	{
		write("Ni en el más bonito de tus sueños podrás abrir esta puerta.\n");
		return 1;
	}
return 0;
}

int fembestir(string str)
{
	if (str=="puerta" || str=="puerta de metal" || str=="puerta metalica" || str=="puerta metálica")
	{
		carcel=find_object(RHOEHAB("koek/carcel/centro"));
		if (TP->QueryHP()<=50)
		{
			object brecha;
			write(W("Te dispones a embestir la puerta... coges la poca "
			"carrerilla que este habitáculo te proporciona y... "
			"BOOOOOOOOOOOOOOOOOOOMMMMMMM.\n"));
			say(W(CATP+" se dispone a embestir la puerta... coge la poca "
			"carrerilla que este habitáculo le proporciona y... "
			"BOOOOOOOOOOOOOOOOOOOMMMMMMM.\n"),TP);
			if (carcel)
			{
				tell_room(carcel,W("Oyes un golpe seco en la puerta "
				"de uno de los calabozos.\n"),({TP}));
			}
			brecha=clone_object(RHOEVAR("koek/carcel/brecha"));
			brecha->move(TP,M_NOCHECK);
		}
		else
		{
			TP->AddHP(-50);
			write(W("Te dispones a embestir la puerta... coges la poca "
			"carrerilla que este habitáculo te proporciona y... "
			"BOOOOOOOOOOOOOOOOOOOMMMMMMM un golpe seco en tu cuerpo te "
			"deja hecho polvo... te encuentras mal.\n"));
			say(W(CATP+" se dispone a embestir la puerta... coge la poca "
			"carrerilla que este habitáculo le proporciona y... "
			"BOOOOOOOOOOOOOOOOOOOMMMMMMM un golpe seco en su cuerpo le "
			"deja hecho polvo... tiene mala pinta.\n"),TP);
			if (carcel)
			{
				tell_room(carcel,W("Oyes un golpe seco en la puerta "
				"de uno de los calabozos.\n"),({TP}));
			}
		}
		return 1;
	}
return 0;
}

int fcavar(string str)
{
	if(!str)
	{
		write("¿Cavar <dónde>?\n");
		return 1;
	}
	if(str=="suelo")
	{
		switch(random(4))
		{
			case 0: celda=(RHOEHAB("koek/carcel/calabozo_00")); break;
			case 1: celda=(RHOEHAB("koek/carcel/calabozo_01")); break;
			case 2: celda=(RHOEHAB("koek/carcel/calabozo_02")); break;
			case 3: celda=(RHOEHAB("koek/carcel/calabozo_03")); break;
			default:celda=(RHOEHAB("koek/carcel/calabozo_00")); break;
		}
		write(W("[56mEmpiezas a cavar lentamente con las manos. La humedad ha "
		"hecho casi todo el trabajo y prácticamente estás jugando a hacer castillos "
		"con la arena. Apareces en otro sitio.[0m\n"));
		tell_room(TO,W(CATP+" se pone a cavar con las manos en el suelo. La humedad ha "
		"hecho casi todo el trabajo y parece que esté haciendo castillos de arena "
		"en lugar de fugándose. "+CATP+" se va.\n"),({TP}));
		TP->move(celda,M_SILENT);
		TP->LookAfterMove();
		tell_room(celda,W("Oyes unos ruidos extraños... de repente "+CATP+" "
		"aparece de un agujero que inmediatamente se tapa debido a  un pequeño "
		"colapso de tierra.\n"),({TP}));
		return 1;
	}
return 0;
}