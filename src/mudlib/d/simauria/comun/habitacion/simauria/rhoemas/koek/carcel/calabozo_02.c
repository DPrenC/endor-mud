/***************************************************************************************
 ARCHIVO:	calabozo_02.c
 AUTOR:		[z] Zomax
 FECHA:		01-12-2001
 COMENTARIOS:	Calabozo 2 de la cárcel de Koek
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit SIM_ROOM;

mixed carcel;
string comando;
mapping amor;

create () {
  ::create();

  SetLocate("Koek");
  SetIntShort("el calabozo nº2 de la cárcel");
  SetIntLong(W("Estás en el calabozo nº2 de la cárcel de Koek. Es un sitio "
  	"oscuro y un poco húmedo que mas o menos consta de cuatro paredes de ladrillos "
  	"y en una de ellas una puerta de metal bien cerrada.\n"));

  AddDetail(({"pared","paredes","ladrillo","ladrillos"}),W("Las paredes están hechas de "
  	"ladrillos muy sólidos pese a la humedad.\n"));
  AddDetail(({"puerta","puerta de metal"}),W("Es una gran puerta de metal, parece que "
  	"de hierro o acero. Está cerrada, cómo no.\n"));

  AddItem(RHOEPNJ("koek/carcel/syrnam"),1,1);

  AddRoomCmd("abrir","fabrir");
  AddRoomCmd("embestir","fembestir");
  AddRoomCmd("cavar","fcavar");
  AddRoomCmd("ligar","fligar");
  AddRoomCmd("ligarse","fligar");
  AddRoomCmd("cortejar","fligar");
  AddRoomCmd("enamorar","fligar");
  AddRoomCmd("engatusar","fligar");
  amor=([]);
}

int fsalir(object preso)
{
	carcel=RHOEHAB("koek/carcel/centro");
	amor -= ([TP->QueryRealName():0]);
	tell_object(TP,"[56mUff... sientes que el sacrificio ha valido la pena. Rapidamente haces lo que te ha dicho Syrnam y consigues salir.[0m\n");
	tell_room(TO,W(CATP+" hace lo que Syrnam le ha dicho al oído y se marcha.\n"),({TP}));
	tell_room(carcel,W(CATP+" sale del calabozo nº2.\n"),({TP}));
	TP->move(carcel,M_SILENT);
	TP->LookAfterMove();
	return 1;
}

int fligar(string strg)
{
	string verb,str,art;
	object novia;
	verb=query_verb();
        if (verb=="ligar")
        {
        	if(!strg || sscanf(strg,"con %s", str) != 1)
        	{
        		write(W("¿"+capitalize(verb)+" con <quién>?\n"));
        		return 1;
        	}
        }
        if (verb!="ligar" && (!strg || (sscanf(strg,"a %s", str) != 1)))
        {
        	write(W("¿"+capitalize(verb)+" a <quién>?\n"));
        	return 1;
        }
	else
	{
		if(verb=="ligar") art="con";
		else art="a";
		if (str=="syrnam" || str=="Syrnam" || str=="borracha" || str=="humana")
		{
			if (!amor[TP->QueryRealName(),0])
  			{
  				amor += ([TP->QueryRealName():0]);
  			}
			novia=present("syrnam");
			if (novia)
			{
				if (living(novia))
				{
					int veces;
					veces=amor[TP->QueryRealName(),0];
 					veces++;
 					amor[TP->QueryRealName(),0]=veces;
					write(W("Intentas "+verb+" "+art+" Syrnam.\n"));
					say(W(CATP+" intenta "+verb+" "+art+" Syrnam.\n"),TP);
 					switch(amor[TP->QueryRealName(),0])
					{
						case 1: tell_room(TO,"Syrnam se sonroja.\n");
							tell_room(TO,"Tienes el estómago revuelto ante la escenita.\n",({TP}));
							tell_object(TP,W("Te sientes maread"+AO+".\n"));
							return 1;
							break;
						case 2: tell_room(TO,W("Syrnam le coge la mano a "+CATP+".\n"),({TP}));
							tell_object(TP,"Syrnam te coge la mano.\n");
							tell_room(TO,W("Notas como "+CATP+" se está poniendo verde, parece maread"+AO+".\n"),({TP}));
							tell_object(TP,W("Te sientes muy, muy maread"+AO+".\n"));
							return 1;
							break;
						case 3: tell_room(TO,W("Syrnam empieza a tocar a "+CATP+".\n"),({TP}));
							tell_object(TP,"Syrnam empieza a tocarte.\n");
							tell_room(TO,"Estás apunto de vomitar, pero te controlas.\n",({TP}));
							tell_object(TP,"Te sientes morir por momentos.\n");
							return 1;
							break;
						case 4: tell_room(TO,"Syrnam dice: ¿Que me case contigo? SIIIIIIIII.\n");
							tell_room(TO,W("Te desatascas los oídos porque no crees que sea verdad lo que "+CATP+" acaba de hacer.\n"),({TP}));
							tell_object(TP,"Tienes ganas de ver a Asthar...\n");
							return 1;
							break;
						case 5: tell_object(TP,"Syrnam te dice al oído como salir de aquí para que hagas los preparativos de la boda.\n");
							tell_room(TO,W("Syrnam le dice al oído a "+CATP+" cómo salir de aquí y así prepare la boda.\n"),({TP}));
							tell_room(TO,W("Empiezas a comprender lo que pretendía "+CATP+".\n"),({TP}));
							if(TP->QueryGender()==2)
							{
								tell_object(TP,"Parece que a Syrnam no le importe que seas chica... debe estar demasiado borracha. Por supuesto no se lo piensas advertir... no sea que la lies.\n");
								tell_room(TO,W("Parece que a Syrnam no le importe que "+CATP+" sea tambien chica, o quizás está tan borracha o tan ilusionada que le da igual. Tu por si acaso no se lo vas a recordar, que aún te queda por pasar un tiempo en su misma celda.\n"),({TP}));
							}
							fsalir(TP);
							return 1;
							break;
						default:tell_room(TO,W("Syrnam ignora a "+CATP+".\n"),({TP}));
							tell_object(TP,"Syrnam te ignora.\n");
							return 1;
							break;
					}
				}
				else
				{
					write(W("¿Pero tu estás bien? ¡Necrófil"+AO+"!\n"));
					say(W(CATP+" está intentando "+verb+" "+art+" el cadaver de Syrnam. "
					"A saber que pensará hacerle...\n"),TP);
					return 1;
				}
			}
			else
			{
				write("Um... no ves a Syrnam por aquí...\n");
				return 1;
			}
		}
		else
		{
			write(W("No encuentras nada llamado "+str+" que puedas "+verb+".\n"));
			return 1;
		}
	}
return 0;
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
