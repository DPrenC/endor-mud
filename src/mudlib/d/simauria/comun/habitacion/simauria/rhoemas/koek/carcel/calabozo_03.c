/***************************************************************************************
 ARCHIVO:	calabozo_03.c
 AUTOR:		[z] Zomax
 FECHA:		02-12-2001
 COMENTARIOS:	Calabozo 3 de la cárcel de Koek
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit SIM_ROOM;

mixed carcel;
int numpres,jabon;
string *npres;
object *preso;

create () {
  ::create();

  SetLocate("Koek");
  SetIntShort("el calabozo nº3 de la cárcel");
  SetIntLong(W("Estás en el calabozo nº3 de la cárcel de Koek. Es un sitio "
  	"oscuro y un poco húmedo que mas o menos consta de cuatro paredes de ladrillos "
  	"y en una de ellas una puerta de metal bien cerrada. Parece que compartes la "
  	"celda con más presos. Hay una pequeña ventanita para que podais respirar que da "
  	"a la calle.\n"));

  AddDetail(({"pared","paredes","ladrillo","ladrillos"}),W("Las paredes están hechas de "
  	"ladrillos muy sólidos pese a la humedad.\n"));
  AddDetail(({"puerta","puerta de metal"}),W("Es una gran puerta de metal, parece que "
  	"de hierro o acero. Está cerrada, cómo no.\n"));
  AddDetail(({"ventana","ventanita"}),W("Nunca podrás salir por ahí, pero entra aire "
  	"fresco y ves la calle. Incluso pordrías lanzar algo por aquí para golpear a "
  	"alguien de fuera.\n"));

  AddItem(RHOEVAR("koek/carcel/jabon"),REFRESH_REMOVE,1);
  AddItem(RHOEPNJ("koek/carcel/dwyer"),REFRESH_DESTRUCT,1);
  AddItem(RHOEPNJ("koek/carcel/rakon"),REFRESH_DESTRUCT,1);
  AddItem(RHOEPNJ("koek/carcel/briek"),REFRESH_DESTRUCT,1);
  AddItem(RHOEPNJ("koek/carcel/lemas"),REFRESH_DESTRUCT,1);

  AddRoomCmd("abrir","fabrir");
  AddRoomCmd("cavar","fcavar");
  AddRoomCmd("coger","fcoger");
  AddRoomCmd("tirar","ftirar");
  AddRoomCmd("recoger","fcoger");
  AddRoomCmd("lanzar","flanzar");
  AddRoomCmd("embestir","fembestir");

  numpres=0;
  jabon=1;
}

int QueryJabon()
{
	return jabon;
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

int fcuantos()
{
	int j,k;
	k=0;
	numpres=0;
	preso=allocate(4);
	npres=allocate(4);
	preso[0]=present("briek");
	preso[1]=present("dwyer");
	preso[2]=present("lemas");
	preso[3]=present("rakon");
	for(j=0;j<sizeof(preso);j++)
	{
		if(living(preso[j]))
		{
			npres[k]=capitalize(preso[j]->QueryRealName());
			k++;
		}
	}
	for(j=0;j<sizeof(npres);j++)
	{
		if (npres[j])
		numpres++;
	}
	return numpres;
}

int ftirar(string str)
{
	if (str=="todo")
	{
		write("¿No querrás dejar esto hecho una porqueria, no?\n");
		return 1;
	}
	if (str=="jabon" || str=="jabón" || str=="pastilla" || str=="pastilla de jabon" || str=="pastilla de jabón")
	{
		if (present(str,TP))
		{
			if (present(str,TO))
			{
				write("Tiras otra pastilla de jabón al suelo... todo sigue igual.\n");
				say(W(CATP+" tira otra pastilla de jabón al suelo... todo sigue igual.\n"),TP);
				present(str,TP)->move(TO,M_SILENT);
				return 1;
			}
			else
			{
				int i;
				fcuantos();
				switch(numpres)
				{
					case 1: write(W("Tiras una pastilla de jabón al suelo. "+
						npres[0]+" se levanta corriendo del suelo, se pega "
						"contra la pared y te mira con temor.\n"));
						say(W(CATP+" tira una pastilla de jabón al suelo. "+
						npres[0]+" se levanta corriendo del suelo, se pega "
						"contra la pared y le mira con temor.\n"),TP);
						break;
					case 2: write(W("Tiras una pastilla de jabón al suelo. "+
						npres[0]+" y "+npres[1]+" se levantan corriendo "
						"del suelo, se pegan contra la pared y te miran con "
						"temor.\n"));
						say(W(CATP+" tira una pastilla de jabón al suelo. "+
						npres[0]+" y "+npres[1]+" se levantan corriendo del "
						"suelo, se pegan contra la pared y le miran con temor.\n"),TP);
						break;
					case 3: write(W("Tiras una pastilla de jabón al suelo. "+
						npres[0]+", "+npres[1]+" y "+npres[2]+" se levantan "
						"corriendo del suelo, se pegan contra la pared y te "
						"miran con temor.\n"));
						say(W(CATP+" tira una pastilla de jabón al suelo. "+
						npres[0]+", "+npres[1]+" y "+npres[2]+" se levantan "
						"corriendo del suelo, se pegan contra la pared y "
						"le miran con temor.\n"),TP);
						break;
					case 4: write(W("Tiras una pastilla de jabón al suelo. "+
						npres[0]+", "+npres[1]+", "+npres[2]+" y "+npres[3]+" se "
						"levantan corriendo del suelo, se pegan contra la pared y te "
						"miran con temor.\n"));
						say(W(CATP+" tira una pastilla de jabón al suelo. "+
						npres[0]+", "+npres[1]+", "+npres[2]+" y "+npres[3]+" se "
						"levantan corriendo del suelo, se pegan contra la pared y "
						"le miran con temor.\n"),TP);
						break;
					default:case 0:	write("Tiras una pastilla de jabón al suelo.\n");
						say(W(CATP+" tira una pastilla de jabón al suelo.\n"),TP);
						break;
				}
				present(str,TP)->move(TO,M_SILENT);
				jabon=1;
				return 1;
			}
		}
	}
return 0;
}

int fcoger(string str)
{
	if (str=="todo")
	{
		write("La avaricia en la cárcel no es buena compañera.\n");
		return 1;
	}
	if (str=="jabon" || str=="jabón" || str=="pastilla" || str=="pastilla de jabon" || str=="pastilla de jabón")
	{
		if (present(str,TO))
		{
			present(str,TO)->move(TP,M_SILENT);
			if (present(str,TO))
			{
				write("Coges una pastilla de jabón del suelo... todo sigue igual.\n");
				say(W(CATP+" coge una pastilla de jabón del suelo... todo sigue igual.\n"),TP);
				return 1;
			}
			else
			{
				int i;
				fcuantos();
				switch(numpres)
				{
					case 1: write(W("Coges una pastilla de jabón del suelo. "+
						npres[0]+" se queda más tranquilo y se tumba en el suelo a descansar.\n"));
						say(W(CATP+" coge una pastilla de jabón del suelo. "+
						npres[0]+" se queda más tranquilo y se tumba en el suelo a descansar.\n"),TP);
						break;
					case 2: write(W("Coges una pastilla de jabón del suelo. "+
						npres[0]+" y "+npres[1]+" se quedan más tranquilos, "
						"ya no tienen esa cara de terror y se tumban en el suelo a descansar.\n"));
						say(W(CATP+" coge una pastilla de jabón del suelo. "+
						npres[0]+" y "+npres[1]+" ya no tienen esa cara de "
						"terror y se tumban en el suelo a descansar.\n"),TP);
						break;
					case 3: write(W("Coges una pastilla de jabón del suelo. "+
						npres[0]+", "+npres[1]+" y "+npres[2]+" se quedan más tranquilos, "
						"ya no tienen esa cara de terror y se tumban en el suelo a descansar.\n"));
						say(W(CATP+" coge una pastilla de jabón del suelo. "+
						npres[0]+", "+npres[1]+" y "+npres[2]+" ya no tienen esa cara de "
						"terror y se tumban en el suelo a descansar.\n"),TP);
						break;
					case 4: write(W("Coges una pastilla de jabón del suelo. "+
						npres[0]+", "+npres[1]+", "+npres[2]+" y "+npres[3]+" se quedan más tranquilos, "
						"ya no tienen esa cara de terror y se tumban en el suelo a descansar.\n"));
						say(W(CATP+" coge una pastilla de jabón del suelo. "+
						npres[0]+", "+npres[1]+", "+npres[2]+" y "+npres[3]+" ya no "
						"tienen esa cara de terror y se tumban en el suelo a descansar.\n"),TP);
						break;
					default:case 0:	write("Coges una pastilla de jabón al suelo.\n");
						say(W(CATP+" coge una pastilla de jabón al suelo.\n"),TP);
						break;
				}
				jabon=0;
				if (numpres)
				{
					for (i=0;i<numpres;i++)
					{
						if(present(npres[i]))
						{
							if(living(present(npres[i])))
							{
								present(npres[i])->init();
							}
						}
					}
				}
				return 1;
			}
		}
	}
return 0;
}

int flanzar(string str)
{
	string cosa1, cosa2;
        if (!str || (sscanf(str,"%s por %s", cosa1, cosa2) != 2))
        {
        	write("¿Lanzar <qué> por <dónde>?\n");
        	return 1;
        }
        else
        {
        	if (present(cosa1,TP))
        	{
        		if ((present(cosa1,TP))==(present("jabon",TP)))
        		{
        			present("jabon",TP)->remove();
        			if(present("jabon",TO))
        			{
        				write("Lanzas el jabón por la ventana... pero todo sigue igual.\n");
        				say(W(CATP+" lanza el jabón por la ventana... pero todo sigue igual.\n"),TP);
        				return 1;
        			}
        			else
        			{
        				fcuantos();
        				carcel=(RHOEHAB("koek/carcel/centro"));
					switch(numpres)
					{
						case 1: write(W("[56mLanzas el jabón por la ventana... de repente "+npres[0]+" se "
							"pone a llorar de alegría y te da las las gracias de todo corazón. "
							"Parece que la pastilla de jabón creaba un ambiente muy tenso y le tenía "
							"atemorizado. "+npres[0]+" está tan agradecido que te dice cómo salir de aquí, "
							"y sin dudarlo un segundo lo pones en práctica.[0m\n"));
							say(W(CATP+" lanza el jabón por la ventana... de repente "+npres[0]+" se "
							"pone a llorar de alegría y le da las las gracias de todo corazón. "
							"Parece que la pastilla de jabón creaba un ambiente muy tenso y le tenía "
							"atemorizado. Está tan agradecido que le dice a "+CATP+" cómo salir de "
							"aquí. "+CATP+" no duda un segundo, hace lo que le ha dicho "+npres[0]+" y se va.\n"),TP);
							TP->move(carcel,M_SILENT);
							TP->LookAfterMove();
							tell_room(carcel,W(CATP+" sale del calabozo nº3.\n"),({TP}));
							break;
						case 2: write(W("[56mLanzas el jabón por la ventana... de repente "+npres[0]+" y "+npres[1]+" se "
							"ponen a llorar de alegría y te dan las las gracias de todo corazón. "
							"Parece que la pastilla de jabón creaba un ambiente muy tenso y les tenía "
							"atemorizados. Están tan agradecidos que te dicen cómo salir de aquí, y sin "
							"dudarlo un segundo lo pones en práctica.[0m\n"));
							say(W(CATP+" lanza el jabón por la ventana... de repente "+npres[0]+" y "+npres[1]+" se "
							"ponen a llorar de alegría y le dan las las gracias de todo corazón. "
							"Parece que la pastilla de jabón creaba un ambiente muy tenso y les tenía "
							"atemorizados. Están tan agradecidos que le dicen a "+CATP+" cómo salir de "
							"aquí. "+CATP+" no duda un segundo, hace lo que le han dicho y se va.\n"),TP);
							TP->move(carcel,M_SILENT);
							TP->LookAfterMove();
							tell_room(carcel,W(CATP+" sale del calabozo nº3.\n"),({TP}));
							break;
						case 3: write(W("[56mLanzas el jabón por la ventana... de repente "+npres[0]+", "+npres[1]+
							" y "+npres[2]+" se ponen a llorar de alegría y te dan las las gracias de todo corazón. "
							"Parece que la pastilla de jabón creaba un ambiente muy tenso y les tenía "
							"atemorizados. Están tan agradecidos que te dicen cómo salir de aquí, y sin "
							"dudarlo un segundo lo pones en práctica.[0m\n"));
							say(W(CATP+" lanza el jabón por la ventana... de repente "+npres[0]+", "+npres[1]+
							" y "+npres[2]+" se ponen a llorar de alegría y le dan las las gracias de todo corazón. "
							"Parece que la pastilla de jabón creaba un ambiente muy tenso y les tenía "
							"atemorizados. Están tan agradecidos que le dicen a "+CATP+" cómo salir de "
							"aquí. "+CATP+" no duda un segundo, hace lo que le han dicho y se va.\n"),TP);
							TP->move(carcel,M_SILENT);
							TP->LookAfterMove();
							tell_room(carcel,W(CATP+" sale del calabozo nº3.\n"),({TP}));
							break;
						case 4: write(W("[56mLanzas el jabón por la ventana... de repente "+npres[0]+", "+npres[1]+", "+npres[2]+
							" y "+npres[3]+" se ponen a llorar de alegría y te dan las las gracias de todo corazón. "
							"Parece que la pastilla de jabón creaba un ambiente muy tenso y les tenía "
							"atemorizados. Están tan agradecidos que te dicen cómo salir de aquí, y sin "
							"dudarlo un segundo lo pones en práctica.[0m\n"));
							say(W(CATP+" lanza el jabón por la ventana... de repente "+npres[0]+", "+npres[1]+", "+npres[2]+
							" y "+npres[3]+" se ponen a llorar de alegría y le dan las las gracias de todo corazón. "
							"Parece que la pastilla de jabón creaba un ambiente muy tenso y les tenía "
							"atemorizados. Están tan agradecidos que le dicen a "+CATP+" cómo salir de "
							"aquí. "+CATP+" no duda un segundo, hace lo que le han dicho y se va.\n"),TP);
							TP->move(carcel,M_SILENT);
							TP->LookAfterMove();
							tell_room(carcel,W(CATP+" sale del calabozo nº3.\n"),({TP}));
							break;
						default:case 0:	write("Lanzas una pastilla de jabón por la ventana.\n");
							say(W(CATP+" lanza una pastilla de jabón por la ventana.\n"),TP);
							break;
					}
					return 1;
				}
        		}
        		else
        		{
        			write("Mejor que no lances eso, no lo podrías recuperar.\n");
        			return 1;
        		}
        	}
        	else
        	{
        		write(W("No tienes "+cosa1+" que lanzar.\n"));
        		return 1;
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
}