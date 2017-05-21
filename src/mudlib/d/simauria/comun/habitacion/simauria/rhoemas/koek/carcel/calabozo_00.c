/***************************************************************************************
 ARCHIVO:	calabozo_00.c
 AUTOR:		[z] Zomax
 FECHA:		01-12-2001
 COMENTARIOS:	Calabozo 0 de la cárcel de Koek
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit SIM_ROOM;

object carcelero,carcel;
mapping gritar;

create () {
  ::create();

  SetLocate("Koek");
  SetIntShort("el calabozo nº0 de la cárcel");
  SetIntLong(W("Estás en el calabozo nº0 de la cárcel de Koek. Es un sitio "
  	"oscuro y un poco húmedo que mas o menos consta de cuatro paredes de ladrillos "
  	"y en una de ellas una puerta de metal bien cerrada.\n"));

  AddDetail(({"pared","paredes","ladrillo","ladrillos"}),W("Las paredes están hechas de "
  	"ladrillos muy sólidos pese a la humedad.\n"));
  AddDetail(({"puerta","puerta de metal"}),W("Es una gran puerta de metal, parece que "
  	"de hierro o acero. Está cerrada, cómo no.\n"));

  AddRoomCmd("abrir","fabrir");
  AddRoomCmd("embestir","fembestir");
  AddRoomCmd("gritar","fgritar");
  AddRoomCmd("cavar","fcavar");

  gritar = ([]);
}

int fabrir(string str)
{
	if (str=="puerta" || str=="puerta de metal" || str=="puerta metalica" || str=="puerta metálica")
	{
		write("Ni en el más bonito de tus sueños podrás abrir esta puerta.\n");
		say(W(CATP+" intenta abrir la puerta... pero no puede.\n"),TP);
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
			"carrerilla que este habitáculo te proporciona y.... "
			"BOOOOOOOOOOOOOOOOOOOMMMMMMM.\n"));
			say(W(CATP+" se dispone a embestir la puerta... coge la poca "
			"carrerilla que este habitáculo le proporciona y.... "
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
			"carrerilla que este habitáculo te proporciona y.... "
			"BOOOOOOOOOOOOOOOOOOOMMMMMMM un golpe seco en tu cuerpo te "
			"deja hecho polvo... te encuentras mal.\n"));
			say(W(CATP+" se dispone a embestir la puerta... coge la poca "
			"carrerilla que este habitáculo le proporciona y.... "
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

int fgritar(string str)
{
	string cosa1;
        if (!str || (sscanf(str,"a %s", cosa1) != 1))
        {
        	write("¿Gritar a <quién>?\n");
        	return 1;
        }
        else
        {
        	if (!gritar[TP->QueryRealName(),0])
  		{
  			gritar += ([TP->QueryRealName():0]);
  		}
  		if(cosa1=="carcelero")
		{
			say(W(CATP+" le grita al carcelero.\n"),TP);
			carcel=find_object(RHOEHAB("koek/carcel/centro"));
			if(carcel)
			{
				tell_room(carcel,W("Oyes los gritos de "+CATP+" desde "
				"uno de los calabozos.\n"),({TP}));
				carcelero=present("carcelero",carcel);
			}
			if(living(carcelero) || (!living(carcelero) && !carcel))
			{
 				int grito;
 				grito=gritar[TP->QueryRealName(),0];
 				grito++;
 				gritar[TP->QueryRealName(),0]=grito;
				if (gritar[TP->QueryRealName(),0]>=5)
				{
					if (!carcel) carcelero=clone_object(RHOEPNJ("koek/carcel/carcelero"));
					carcelero->move(TO,M_SILENT);
					tell_room(TO,"El carcelero llega desesperado.\n");
					tell_room(RHOEHAB("koek/carcel/centro"),W("El carcelero se va hacia uno de los "
					"calabozos desesperado ante tanto jaleo.\n"));
					write(W("[56mEl carcelero dice: ¿Es que "
					"no vas a parar nunca de gritar? anda, "
					"vete de aquí que me vas a provocar "
					"un motín.[0m\n"));
					say(W("El carcelero le dice a "+CATP+": "
					"¿Es que no vas a parar nunca de gitar? "
					"anda, vete de aquí que me vas a provocar "
					"un motín.\n"),TP);
					gritar -= ([TP->QueryRealName():0]);
					TP->move(RHOEHAB("koek/carcel/centro"),M_SILENT);
					TP->LookAfterMove();
					if (!carcel) carcelero->remove();
					else carcelero->move(RHOEHAB("koek/carcel/centro"),M_SILENT);
					tell_room(TO,W(CATP+" se marcha.\n"),({TP}));
					tell_room(RHOEHAB("koek/carcel/centro"),W(CATP+" sale del calabozo nº0.\n"),({TP}));
					tell_room(TO,"El carcelero vuelve a su sitio.\n",({TP}));
					tell_room(RHOEHAB("koek/carcel/centro"),W("El carcelero vuelve tras soltar a "+CATP+".\n"),({TP}));
					tell_object(TP,"El carcelero vuelve a su puesto más tranquilo.\n");
					return 1;
				}
				else
				{
					write("El carcelero te ignora.\n");
					say(W("El carcelero ignora a "+CATP+".\n"),
					TP);
					return 1;
				}
			}
			else
			{
				write("Gritas... no hay respuesta.\n");
				say(W(CATP+" grita... no hay respuesta.\n"),
				TP);
				return 1;
			}
		}
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
		write("El suelo de este calabozo está demasiado bien conservado para cavar.\n");
		return 1;
	}
return 0;
}
