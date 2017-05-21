/***************************************************************************************
 ARCHIVO:	calabozo_03.c
 AUTOR:		[z] Zomax
 FECHA:		02-12-2001
 COMENTARIOS:	Calabozo 3 de la c�rcel de Koek
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
  SetIntShort("el calabozo n�3 de la c�rcel");
  SetIntLong(W("Est�s en el calabozo n�3 de la c�rcel de Koek. Es un sitio "
  	"oscuro y un poco h�medo que mas o menos consta de cuatro paredes de ladrillos "
  	"y en una de ellas una puerta de metal bien cerrada. Parece que compartes la "
  	"celda con m�s presos. Hay una peque�a ventanita para que podais respirar que da "
  	"a la calle.\n"));

  AddDetail(({"pared","paredes","ladrillo","ladrillos"}),W("Las paredes est�n hechas de "
  	"ladrillos muy s�lidos pese a la humedad.\n"));
  AddDetail(({"puerta","puerta de metal"}),W("Es una gran puerta de metal, parece que "
  	"de hierro o acero. Est� cerrada, c�mo no.\n"));
  AddDetail(({"ventana","ventanita"}),W("Nunca podr�s salir por ah�, pero entra aire "
  	"fresco y ves la calle. Incluso pordr�as lanzar algo por aqu� para golpear a "
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
	if (str=="puerta" || str=="puerta de metal" || str=="puerta metalica" || str=="puerta met�lica")
	{
		write("Ni en el m�s bonito de tus sue�os podr�s abrir esta puerta.\n");
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
			"carrerilla que este habit�culo te proporciona y... "
			"BOOOOOOOOOOOOOOOOOOOMMMMMMM.\n"));
			say(W(CATP+" se dispone a embestir la puerta... coge la poca "
			"carrerilla que este habit�culo le proporciona y... "
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
			"carrerilla que este habit�culo te proporciona y... "
			"BOOOOOOOOOOOOOOOOOOOMMMMMMM un golpe seco en tu cuerpo te "
			"deja hecho polvo... te encuentras mal.\n"));
			say(W(CATP+" se dispone a embestir la puerta... coge la poca "
			"carrerilla que este habit�culo le proporciona y... "
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
		write("�No querr�s dejar esto hecho una porqueria, no?\n");
		return 1;
	}
	if (str=="jabon" || str=="jab�n" || str=="pastilla" || str=="pastilla de jabon" || str=="pastilla de jab�n")
	{
		if (present(str,TP))
		{
			if (present(str,TO))
			{
				write("Tiras otra pastilla de jab�n al suelo... todo sigue igual.\n");
				say(W(CATP+" tira otra pastilla de jab�n al suelo... todo sigue igual.\n"),TP);
				present(str,TP)->move(TO,M_SILENT);
				return 1;
			}
			else
			{
				int i;
				fcuantos();
				switch(numpres)
				{
					case 1: write(W("Tiras una pastilla de jab�n al suelo. "+
						npres[0]+" se levanta corriendo del suelo, se pega "
						"contra la pared y te mira con temor.\n"));
						say(W(CATP+" tira una pastilla de jab�n al suelo. "+
						npres[0]+" se levanta corriendo del suelo, se pega "
						"contra la pared y le mira con temor.\n"),TP);
						break;
					case 2: write(W("Tiras una pastilla de jab�n al suelo. "+
						npres[0]+" y "+npres[1]+" se levantan corriendo "
						"del suelo, se pegan contra la pared y te miran con "
						"temor.\n"));
						say(W(CATP+" tira una pastilla de jab�n al suelo. "+
						npres[0]+" y "+npres[1]+" se levantan corriendo del "
						"suelo, se pegan contra la pared y le miran con temor.\n"),TP);
						break;
					case 3: write(W("Tiras una pastilla de jab�n al suelo. "+
						npres[0]+", "+npres[1]+" y "+npres[2]+" se levantan "
						"corriendo del suelo, se pegan contra la pared y te "
						"miran con temor.\n"));
						say(W(CATP+" tira una pastilla de jab�n al suelo. "+
						npres[0]+", "+npres[1]+" y "+npres[2]+" se levantan "
						"corriendo del suelo, se pegan contra la pared y "
						"le miran con temor.\n"),TP);
						break;
					case 4: write(W("Tiras una pastilla de jab�n al suelo. "+
						npres[0]+", "+npres[1]+", "+npres[2]+" y "+npres[3]+" se "
						"levantan corriendo del suelo, se pegan contra la pared y te "
						"miran con temor.\n"));
						say(W(CATP+" tira una pastilla de jab�n al suelo. "+
						npres[0]+", "+npres[1]+", "+npres[2]+" y "+npres[3]+" se "
						"levantan corriendo del suelo, se pegan contra la pared y "
						"le miran con temor.\n"),TP);
						break;
					default:case 0:	write("Tiras una pastilla de jab�n al suelo.\n");
						say(W(CATP+" tira una pastilla de jab�n al suelo.\n"),TP);
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
		write("La avaricia en la c�rcel no es buena compa�era.\n");
		return 1;
	}
	if (str=="jabon" || str=="jab�n" || str=="pastilla" || str=="pastilla de jabon" || str=="pastilla de jab�n")
	{
		if (present(str,TO))
		{
			present(str,TO)->move(TP,M_SILENT);
			if (present(str,TO))
			{
				write("Coges una pastilla de jab�n del suelo... todo sigue igual.\n");
				say(W(CATP+" coge una pastilla de jab�n del suelo... todo sigue igual.\n"),TP);
				return 1;
			}
			else
			{
				int i;
				fcuantos();
				switch(numpres)
				{
					case 1: write(W("Coges una pastilla de jab�n del suelo. "+
						npres[0]+" se queda m�s tranquilo y se tumba en el suelo a descansar.\n"));
						say(W(CATP+" coge una pastilla de jab�n del suelo. "+
						npres[0]+" se queda m�s tranquilo y se tumba en el suelo a descansar.\n"),TP);
						break;
					case 2: write(W("Coges una pastilla de jab�n del suelo. "+
						npres[0]+" y "+npres[1]+" se quedan m�s tranquilos, "
						"ya no tienen esa cara de terror y se tumban en el suelo a descansar.\n"));
						say(W(CATP+" coge una pastilla de jab�n del suelo. "+
						npres[0]+" y "+npres[1]+" ya no tienen esa cara de "
						"terror y se tumban en el suelo a descansar.\n"),TP);
						break;
					case 3: write(W("Coges una pastilla de jab�n del suelo. "+
						npres[0]+", "+npres[1]+" y "+npres[2]+" se quedan m�s tranquilos, "
						"ya no tienen esa cara de terror y se tumban en el suelo a descansar.\n"));
						say(W(CATP+" coge una pastilla de jab�n del suelo. "+
						npres[0]+", "+npres[1]+" y "+npres[2]+" ya no tienen esa cara de "
						"terror y se tumban en el suelo a descansar.\n"),TP);
						break;
					case 4: write(W("Coges una pastilla de jab�n del suelo. "+
						npres[0]+", "+npres[1]+", "+npres[2]+" y "+npres[3]+" se quedan m�s tranquilos, "
						"ya no tienen esa cara de terror y se tumban en el suelo a descansar.\n"));
						say(W(CATP+" coge una pastilla de jab�n del suelo. "+
						npres[0]+", "+npres[1]+", "+npres[2]+" y "+npres[3]+" ya no "
						"tienen esa cara de terror y se tumban en el suelo a descansar.\n"),TP);
						break;
					default:case 0:	write("Coges una pastilla de jab�n al suelo.\n");
						say(W(CATP+" coge una pastilla de jab�n al suelo.\n"),TP);
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
        	write("�Lanzar <qu�> por <d�nde>?\n");
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
        				write("Lanzas el jab�n por la ventana... pero todo sigue igual.\n");
        				say(W(CATP+" lanza el jab�n por la ventana... pero todo sigue igual.\n"),TP);
        				return 1;
        			}
        			else
        			{
        				fcuantos();
        				carcel=(RHOEHAB("koek/carcel/centro"));
					switch(numpres)
					{
						case 1: write(W("[56mLanzas el jab�n por la ventana... de repente "+npres[0]+" se "
							"pone a llorar de alegr�a y te da las las gracias de todo coraz�n. "
							"Parece que la pastilla de jab�n creaba un ambiente muy tenso y le ten�a "
							"atemorizado. "+npres[0]+" est� tan agradecido que te dice c�mo salir de aqu�, "
							"y sin dudarlo un segundo lo pones en pr�ctica.[0m\n"));
							say(W(CATP+" lanza el jab�n por la ventana... de repente "+npres[0]+" se "
							"pone a llorar de alegr�a y le da las las gracias de todo coraz�n. "
							"Parece que la pastilla de jab�n creaba un ambiente muy tenso y le ten�a "
							"atemorizado. Est� tan agradecido que le dice a "+CATP+" c�mo salir de "
							"aqu�. "+CATP+" no duda un segundo, hace lo que le ha dicho "+npres[0]+" y se va.\n"),TP);
							TP->move(carcel,M_SILENT);
							TP->LookAfterMove();
							tell_room(carcel,W(CATP+" sale del calabozo n�3.\n"),({TP}));
							break;
						case 2: write(W("[56mLanzas el jab�n por la ventana... de repente "+npres[0]+" y "+npres[1]+" se "
							"ponen a llorar de alegr�a y te dan las las gracias de todo coraz�n. "
							"Parece que la pastilla de jab�n creaba un ambiente muy tenso y les ten�a "
							"atemorizados. Est�n tan agradecidos que te dicen c�mo salir de aqu�, y sin "
							"dudarlo un segundo lo pones en pr�ctica.[0m\n"));
							say(W(CATP+" lanza el jab�n por la ventana... de repente "+npres[0]+" y "+npres[1]+" se "
							"ponen a llorar de alegr�a y le dan las las gracias de todo coraz�n. "
							"Parece que la pastilla de jab�n creaba un ambiente muy tenso y les ten�a "
							"atemorizados. Est�n tan agradecidos que le dicen a "+CATP+" c�mo salir de "
							"aqu�. "+CATP+" no duda un segundo, hace lo que le han dicho y se va.\n"),TP);
							TP->move(carcel,M_SILENT);
							TP->LookAfterMove();
							tell_room(carcel,W(CATP+" sale del calabozo n�3.\n"),({TP}));
							break;
						case 3: write(W("[56mLanzas el jab�n por la ventana... de repente "+npres[0]+", "+npres[1]+
							" y "+npres[2]+" se ponen a llorar de alegr�a y te dan las las gracias de todo coraz�n. "
							"Parece que la pastilla de jab�n creaba un ambiente muy tenso y les ten�a "
							"atemorizados. Est�n tan agradecidos que te dicen c�mo salir de aqu�, y sin "
							"dudarlo un segundo lo pones en pr�ctica.[0m\n"));
							say(W(CATP+" lanza el jab�n por la ventana... de repente "+npres[0]+", "+npres[1]+
							" y "+npres[2]+" se ponen a llorar de alegr�a y le dan las las gracias de todo coraz�n. "
							"Parece que la pastilla de jab�n creaba un ambiente muy tenso y les ten�a "
							"atemorizados. Est�n tan agradecidos que le dicen a "+CATP+" c�mo salir de "
							"aqu�. "+CATP+" no duda un segundo, hace lo que le han dicho y se va.\n"),TP);
							TP->move(carcel,M_SILENT);
							TP->LookAfterMove();
							tell_room(carcel,W(CATP+" sale del calabozo n�3.\n"),({TP}));
							break;
						case 4: write(W("[56mLanzas el jab�n por la ventana... de repente "+npres[0]+", "+npres[1]+", "+npres[2]+
							" y "+npres[3]+" se ponen a llorar de alegr�a y te dan las las gracias de todo coraz�n. "
							"Parece que la pastilla de jab�n creaba un ambiente muy tenso y les ten�a "
							"atemorizados. Est�n tan agradecidos que te dicen c�mo salir de aqu�, y sin "
							"dudarlo un segundo lo pones en pr�ctica.[0m\n"));
							say(W(CATP+" lanza el jab�n por la ventana... de repente "+npres[0]+", "+npres[1]+", "+npres[2]+
							" y "+npres[3]+" se ponen a llorar de alegr�a y le dan las las gracias de todo coraz�n. "
							"Parece que la pastilla de jab�n creaba un ambiente muy tenso y les ten�a "
							"atemorizados. Est�n tan agradecidos que le dicen a "+CATP+" c�mo salir de "
							"aqu�. "+CATP+" no duda un segundo, hace lo que le han dicho y se va.\n"),TP);
							TP->move(carcel,M_SILENT);
							TP->LookAfterMove();
							tell_room(carcel,W(CATP+" sale del calabozo n�3.\n"),({TP}));
							break;
						default:case 0:	write("Lanzas una pastilla de jab�n por la ventana.\n");
							say(W(CATP+" lanza una pastilla de jab�n por la ventana.\n"),TP);
							break;
					}
					return 1;
				}
        		}
        		else
        		{
        			write("Mejor que no lances eso, no lo podr�as recuperar.\n");
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
		write("�Cavar <d�nde>?\n");
		return 1;
	}
	if(str=="suelo")
	{
		write("El suelo de este calabozo est� demasiado bien conservado para cavar.\n");
		return 1;
	}
}