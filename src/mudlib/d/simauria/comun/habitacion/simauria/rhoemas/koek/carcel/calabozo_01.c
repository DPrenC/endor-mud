/***************************************************************************************
 ARCHIVO:	calabozo_01.c
 AUTOR:		[z] Zomax
 FECHA:		01-12-2001
 COMENTARIOS:	Calabozo 1 de la c�rcel de Koek
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit SIM_ROOM;

mixed carcel;
object carcelero;

create () {
  ::create();

  SetLocate("Koek");
  SetIntShort("el calabozo n�1 de la c�rcel");
  SetIntLong(W("Est�s en el calabozo n�1 de la c�rcel de Koek. Es un sitio "
  	"oscuro y un poco h�medo que mas o menos consta de cuatro paredes de ladrillos "
  	"y en una de ellas una puerta de metal bien cerrada.\n"));

  AddDetail(({"pared","paredes","ladrillo","ladrillos"}),W("Las paredes est�n hechas de "
  	"ladrillos muy s�lidos pese a la humedad.\n"));
  AddDetail(({"puerta","puerta de metal"}),W("Es una gran puerta de metal, parece que "
  	"de hierro o acero. Est� cerrada, c�mo no.\n"));

  AddRoomCmd("abrir","fabrir");
  AddRoomCmd("cavar","fcavar");
  AddRoomCmd("forzar","fforzar");
  AddRoomCmd("embestir","fembestir");

}

int fabrir(string str)
{
	if (str=="puerta" || str=="puerta de metal" || str=="puerta metalica" || str=="puerta met�lica")
	{
		write("Ni en el m�s bonito de tus sue�os podr�s abrir esta puerta.\n");
		return 1;
	}
return 0;
}

int fforzar(string str)
{
	if (str=="puerta" || str=="puerta de metal" || str=="puerta metalica" || str=="puerta met�lica")
	{
		carcel=(RHOEHAB("koek/carcel/centro"));
		write("[56mVaya!, Parece que la puerta era defectuosa![0m\n");
		say(W(CATP+" le hace algo a la puerta y de repente se abre.\n"),TP);
		tell_object(TP,"Te marchas antes de que pase algo.\n");
		tell_room(TO,W(CATP+" se marcha.\n"),({TP}));
		TP->move(carcel,M_SILENT);
		TP->LookAfterMove();
		tell_room(carcel,W(CATP+" sale del calabozo n�1.\n"),({TP}));
		tell_room(TO,"La puerta se cierra de repente.\n",({TP}));
		return 1;
	}
return 0;
}

int fembestir(string str)
{
	if (str=="puerta" || str=="puerta de metal" || str=="puerta metalica" || str=="puerta met�lica")
	{
		carcel=find_object(RHOEHAB("koek/carcel/centro"));
		if (TP->QueryHP()<=50)
		{
			object brecha;
			write(W("Te dispones a embestir la puerta... coges la poca "
			"carrerilla que este habit�culo te proporciona y.... "
			"BOOOOOOOOOOOOOOOOOOOMMMMMMM.\n"));
			say(W(CATP+" se dispone a embestir la puerta... coge la poca "
			"carrerilla que este habit�culo le proporciona y.... "
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
			"carrerilla que este habit�culo te proporciona y.... "
			"BOOOOOOOOOOOOOOOOOOOMMMMMMM un golpe seco en tu cuerpo te "
			"deja hecho polvo... te encuentras mal.\n"));
			say(W(CATP+" se dispone a embestir la puerta... coge la poca "
			"carrerilla que este habit�culo le proporciona y.... "
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
		write("�Cavar <d�nde>?\n");
		return 1;
	}
	if(str=="suelo")
	{
		write("El suelo de este calabozo est� demasiado bien conservado para cavar.\n");
		return 1;
	}
return 0;
}
