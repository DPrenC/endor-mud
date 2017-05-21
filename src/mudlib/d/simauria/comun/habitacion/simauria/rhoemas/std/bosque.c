/***************************************************************************************
 ARCHIVO:	bosque.c
 AUTOR:		[z] Zomax
 FECHA:		15-11-2001
 COMENTARIOS:	Bosque Standard.
 MODIFICACION:  24-04-2003 Repaso de c�digo.
 		11-05-2003 Hago los mappings del mismo tama�o para el nuevo driver.
 ***************************************************************************************/

#include <magia.h>
#include "path.h"
#include <moving.h>
#include <properties.h>

inherit SIM_ROOM;

mapping map;
int existe,clonar,rama;

public int fcoger(string str)
{
	object cosa;
	switch(clonar)
	{
		case 1: if (str=="hierba" || str=="hierbas")
			{
				if (existe)
				{
					cosa=clone_object(RHOEVAR("cylin/hierba"));
					cosa->move(TP,M_SILENT);
					write(W("Sin dejar de mirar hacia todas partes "
					"y con mucho sigilo coges una hierba.\n"));
					say(W(CATP+
					" coge una hierba con mucho cuidado.\n"),TP);
					existe=0;
					return 1;
				}
				else
				{
					write("Parece que alguien se te ha adelantado, prueba m�s tarde.\n");
					return 1;
				}
			}
			break;
		case 2: if (str=="nido" || str=="nidos")
			{
				if (existe)
				{
					cosa=clone_object(RHOEVAR("cylin/nido"));
					cosa->move(TP,M_SILENT);
					write(W("Coges con cuidado el �nico nido que hay "
					"a tu alcance.\n"));
					say(W(CATP+
					" coge un nido de un �rbol.\n"),TP);
					existe=0;
					return 1;
				}
				else
				{
					write(W("Parece que alguien se ha llevado ya el �nico "
					"nido accesible desde el suelo, prueba m�s tarde.\n"));
					return 1;
				}
			}
			break;
		case 3: if (str=="roca" || str=="rocas" || str=="roca afilada" || str=="rocas afiladas")
			{
				if (existe)
				{
					cosa=clone_object(RHOEVAR("cylin/roca"));
					cosa->move(TP,M_SILENT);
					write(W("Coges una roca del tama�o de un pu�o del "
					"suelo con cuidado de no cortarte.\n"));
					say(W(CATP+
					" coge una roca del suelo.\n"),TP);
					existe=0;
					return 1;
				}
				else
				{
					write(W("Parece que alguien se ha llevado la �nica "
					"roca de un tama�o que se puede llevar sin problemas, "
					"prueba m�s tarde.\n"));
					return 1;
				}
			}
			break;
		case 4: if (str=="musgo")
			{
				if (existe)
				{
					cosa=clone_object(RHOEVAR("cylin/musgo"));
					cosa->move(TP,M_SILENT);
					write("Coges un poco de musgo.\n");
					say(W(CATP+
					" coge un poco de musgo.\n"),TP);
					existe=0;
					return 1;
				}
				else
				{
					write(W("Parece que alguien se ha llevado el "
					"musgo que quedaba en buen estado, quiz�s m�s "
					"tarde consigas algo.\n"));
					return 1;
				}
			}
			break;
		case 5: if (str=="pelo" || str=="pelo enredado")
			{
				if (existe)
				{
					cosa=clone_object(RHOEVAR("cylin/pelo"));
					cosa->move(TP,M_SILENT);
					write("Coges un poco de pelo.\n");
					say(W(CATP+
					" coge un poco de pelo.\n"),TP);
					existe=0;
					return 1;
				}
				else
				{
					write("Parece que alguien se te ha adelantado, prueba m�s tarde.\n");
					return 1;
				}
			}
			break;
		case 6: if (str=="tocon" || str=="toc�n")
			{
				write(W("�No puedes cogerlo, est� demasiado "
				"sujeto al suelo.\n"));
				return 1;
			}
			break;
		case 7: if (str=="cesped" || str=="c�sped")
			{
				if (existe)
				{
					cosa=clone_object(RHOEVAR("cylin/cesped"));
					cosa->move(TP,M_SILENT);
					write("Te agachas y coges un poco de c�sped.\n");
					say(W(CATP+
					" coge un poco de c�sped.\n"),TP);
					existe=0;
					return 1;
				}
				else
				{
					write(W("Parece que alguien ha cogido el "
					"poco c�sped que quedaba sano.\n"));
					return 1;
				}
			}
			break;
		case 8: if (str=="marcas" || str=="zarpazo" || str=="zarpazos")
			{
				write("�C�mo vas a poder coger eso?\n");
				return 1;
			}
			break;
		case 9: if (str=="restos" || str=="resto" || str=="animal" || str=="esqueleto")
			{
				if (existe)
				{
					cosa=clone_object(RHOEVAR("cylin/esqueleto"));
					cosa->move(TP,M_SILENT);
					write("Coges el esqueleto de un animal.\n");
					say(W(CATP+
					" coge el esqueleto de un animal.\n"),TP);
					existe=0;
					return 1;
				}
				else
				{
					write("Parece que alguien se ha llevado practicamente todo el esqueleto, prueba m�s tarde.\n");
					return 1;
				}
			}
			break;
		case 10:if (str=="niebla" || str=="bruma")
			{
				write(W("Empiezas a delirar... �es que de donde vienes "
				"se puede coger la "+str+"?\n"));
				return 1;
			}
			break;
		default:break;
	}
	switch(CHRONOS->QueryEstacion())
	{
		case 1: if (str=="nieve")
			{
				cosa=clone_object(RHOEVAR("cylin/nieve"));
				cosa->move(TP,M_SILENT);
				write("Coges algo de nieve del suelo.\n");
				say(W(CATP+
				" coge un poco de nieve.\n"),TP);
				return 1;
			}
			break;
		case 2: if (str=="brote" || str=="brotes")
			{
				write("�No querr�s ayudar a la deforestaci�n, no?\n");
				return 1;
			}
			break;
		case 3: if (str=="hoja" || str=="hojas")
			{
				write("�No querr�s ayudar a la deforestaci�n, no?\n");
				return 1;
			}
			break;
		case 4: if (str=="hoja" || str=="hojas")
			{
				cosa=clone_object(RHOEVAR("cylin/hoja"));
				cosa->move(TP,M_SILENT);
				write("Coges una hoja ca�da del suelo.\n");
				say(W(CATP+
				" coge una hoja ca�da del suelo.\n"),TP);
				return 1;
			}
			break;
		default:break;
	}
	if (str=="rama" || str=="ramas")
	{
		if (rama==1)
		{
			cosa=clone_object(RHOEVAR("cylin/rama"));
			cosa->move(TP,M_SILENT);
			write("Coges una rama ca�da del suelo.\n");
			say(W(CATP+
			" coge una rama ca�da del suelo.\n"),TP);
			rama=0;
			return 1;
		}
		else
		{
			write(W("Parece que hay ramas de un tama�o que "
			"puedas coger. Tendr�s que esperar a que caiga alguna.\n"));
			return 1;
		}
	}
	else if (str=="arbol" || str=="�rbol" || str=="arboles" || str=="�rboles")
	{
		write(W("Este bosque empieza a afectarte... ���De verdad crees que puedes "
		"coger un �rbol???\n"));
		return 1;
	}
}

public int fanimales()
{
	 switch(random(20))
 	{
 		case 0: AddItem(RHOEPNJ("cylin/animales"),REFRESH_REMOVE); break;
 		case 2: AddItem(RHOEPNJ("cylin/animales"),REFRESH_REMOVE); break;
 		case 4: AddItem(RHOEPNJ("cylin/animales"),REFRESH_REMOVE); break;
 		case 6: AddItem(RHOEPNJ("cylin/animales"),REFRESH_REMOVE); break;
 		case 8: AddItem(RHOEPNJ("cylin/animales"),REFRESH_REMOVE); break;
 		case 10:AddItem(RHOEPNJ("cylin/animales"),REFRESH_REMOVE); break;
 		case 12:AddItem(RHOEPNJ("cylin/animales"),REFRESH_REMOVE); break;
 		case 14:AddItem(RHOEPNJ("cylin/animales"),REFRESH_REMOVE); break;
 		case 16:AddItem(RHOEPNJ("cylin/animales"),REFRESH_REMOVE); break;
 		case 18:AddItem(RHOEPNJ("cylin/animales"),REFRESH_REMOVE); break;
 		default: break;
 	}
 	return 1;
}

public int fhuir(string str)
{
	if (TP->QueryCombatDelay())
	{
		write(W("No puedes huir. Est�s inmovilizad"+AO+".\n"));
		say(W(CATP+" mira a su alrededor con p�nico en los ojos. Parece que "
		"quiere huir, pero est� inmovilizad"+AO+".\n"),TP);
		return 1;
	}
}

create () {
  ::create();

  SetIndoors(0);
  existe=random(2);
  rama=random(4);
  Set(P_TPORT,0);
  map = ([]);
  map += ([neu:des;sme;noi;dde;nde]);
  map += ([inv:des;sme;noi;dde;0]);
  map += ([pri:des;sme;noi;dde;0]);
  map += ([ver:des;sme;noi;dde;0]);
  map += ([oto:des;sme;noi;dde;0]);
  AddRoomCmd("huir","fhuir");
  map[neu,sme]="No hueles nada en especial.\n";
  map[inv,sme]="Tienes la nariz tan fr�a que no hueles nada.\n";
  map[pri,sme]="Las plantas de toda la zona aromatizan el ambiente.\n";
  map[ver,sme]="Aspiras el aire... demasiado caliente para tu gusto.\n";
  map[oto,sme]="El olor a tierra mojada invade el ambiente.\n";

  map[neu,noi]="Te concentras... No oyes nada en especial.\n";
  map[inv,noi]="Oyes los silbidos del aire g�lido al chocar con tus orejas.\n";
  map[pri,noi]="Apenas oyes el sonido del viento acariciando cuanto toca.\n";
  map[ver,noi]="El aire est� tan parado que no oyes nada en absoluto.\n";
  map[oto,noi]="Oyes el sonido del viento que empieza a soplar con algo de fuerza y tus "+
  	      "pasos sobre las hojas ca�das en el suelo.\n";
  switch(random(10))
  {
 	case 0: /********************* DESCRIPCIONES ****************************/
 		map[neu,des]="Este es el tenebroso bosque de Cylin, demasiado "+
 		"peligroso para que ning�n habitante de Koek se adentre en �l. "+
 		"Hay varias ramas por el suelo y hierbas por todas partes que "+
 		"hacen dificil caminar por este lugar. ";
 		map[inv,des]="La nieve cubre las esquel�ticas ramas de los �rboles "+
 		"y el suelo dejando todo completamente blanco.\n";
 		map[pri,des]="Las ramas de los �rboles estan rebrotando y ya empiezan "+
 		"o coger un tono mas verde.\n";
 		map[ver,des]="Los �rboles tienen las ramas m�s frondosas que has visto "+
 		"en la vida, casi no dejan pasar el sol.\n";
 		map[oto,des]="Los �rboles ya han empezado a dejar caer sus hojas, la "+
 		"mayor�a de color rojizo y amarillo, y hacen del suelo una manta de colores.\n";
 		/*********************** NOMBRE DETALLES ************************/
 		map[neu,nde]=({"hierba","hierbas"});
 		clonar=1;
		/******************** DESCRIPCION DETALLES **********************/
		map[neu,dde]="Hay hierbas muy raras por todas partes";
		map[inv,dde]=", semienterradas en la nieve, que entorpecen m�s a�n el camino.\n";
 		map[pri,dde]=" que empiezan a despertar tras el duro invierno.\n";
 		map[ver,dde]=" frondosas gracias a las buenas temperaturas.\n";
 		map[oto,dde]=" balanceadas por el fuerte viento.\n";
 		break;
  	case 1: /********************* DESCRIPCIONES ****************************/
 		map[neu,des]="Est�s en el bosque de Cylin, al norte de Koek. Aqu� "+
 		"los �rboles tienen formas extra�as que recuerdan a los mounstruos "+
 		"de los cuentos que sol�as oir de ni�o. Las ramas de los �rboles, a "+
 		"pesar de ser tan extra�as, acogen alg�n que otro nido. ";
 		map[inv,des]="La nieve del invierno lo ha cubierto pr�cticamente todo "+
 		"a su paso.\n";
 		map[pri,des]="Las amenazadores formas se suavizan algo con los brotes "+
 		"de primavera.\n";
 		map[ver,des]="Las grandes hojas de los �rboles hacen del bosque una "+
 		"zona en penumbra.\n";
 		map[oto,des]="Sin casi hojas en los �rboles el ambiente es m�s aterrador "+
 		"si cabe.\n";
 		/*********************** NOMBRE DETALLES ************************/
 		map[neu,nde]=({"nido","nidos"});
 		clonar=2;
		/******************** DESCRIPCION DETALLES **********************/
		map[neu,dde]="Hay varios nidos en los �rboles ";
		map[inv,dde]="que han sido cubiertos por la nieve en su mayor parte.\n";
 		map[pri,dde]="que est�n siendo reparados durante esta �poca.\n";
 		map[ver,dde]="en perfecto estado.\n";
 		map[oto,dde]="que se est�n rompiendo debido al viento.\n";
 		break;
 	case 2: /********************* DESCRIPCIONES ****************************/
 		map[neu,des]="Este es el bosque de Cylin, un lugar donde ni los m�s "+
 		"valientes de Koek se aventuran a ir aunque les prometan grandes "+
 		"tesoros. En el suelo hay varias rocas afiladas que hacen pensar que "+
 		"aqu� una ca�da es algo m�s que eso. ";
 		map[inv,des]="Adem�s la nieve las oculta con gran picaresca.\n";
 		map[pri,des]="Incluso en la fr�a roca surgen brotes.\n";
 		map[ver,des]="Pese a que casi no llega el sol a esta parte del bosque, "+
 		"hace mucho calor.\n";
 		map[oto,des]="Adem�s las lluvias dejan el suelo muy irregular, lo que "+
 		"no facilita la estabilidad.\n";
 		/*********************** NOMBRE DETALLES ************************/
 		map[neu,nde]=({"roca","rocas","roca afilada","rocas afiladas"});
 		clonar=3;
		/******************** DESCRIPCION DETALLES **********************/
		map[neu,dde]="Hay unas rocas muy afiladas en el suelo ";
		map[inv,dde]="casi ocultas por la nieve.\n";
 		map[pri,dde]="que te hacen caminar con m�s cuidado.\n";
 		map[ver,dde]="que te hacen caminar con m�s cuidado.\n";
 		map[oto,dde]="casi ocultas bajo las hojas.\n";
 		break;
 	case 3: /********************* DESCRIPCIONES ****************************/
 		map[neu,des]="Est�s en un bosque oscuro y tenebroso que te hiela "+
 		"la sangre. Los �rboles aqu� no son m�s que figuras retorcidas que "+
 		"llenan de p�nico a quienes los observan, y el musgo no hace sino "+
 		"aumentar la ansiedad, ya que forma extra�as formas que parece que "+
 		"te observan. ";
 		map[inv,des]="Ahora est� todo cubierto de nieve, pero eso no te hace "+
 		"sentir mejor.\n";
 		map[pri,des]="A pesar de los brotes de la primavera, esto no te parece "+
 		"un lugar tan bonito como para quedarte m�s tiempo.\n";
 		map[ver,des]="Adem�s el calor acent�a las ganas de salir de aqui que tienes.\n";
 		map[oto,des]="Adem�s la lluvia ha dejado todo h�medo y fr�o, lo cual no "+
 		"hace de este sitio el lugar ideal para estar a estas horas.\n";
 		/*********************** NOMBRE DETALLES ************************/
 		map[neu,nde]=({"musgo"});
 		clonar=4;
		/******************** DESCRIPCION DETALLES **********************/
		map[neu,dde]="El musgo lo invade todo";
		map[inv,dde]=", aunque ahora casi no lo ves, oculto bajo la nieve.\n";
 		map[pri,dde]=", haciendo el paisaje un poco m�s verde.\n";
 		map[ver,dde]=", pero con este calor parece un poco seco.\n";
 		map[oto,dde]=" y est� muy crecido gracias a las lluvias del oto�o.\n";
 		break;
 	case 4:/********************* DESCRIPCIONES ****************************/
 		map[neu,des]="Paseas por el bosque de Cylin, al norte de Koek. Parece "+
 		"un lugar sacado del m�s oscuro de los relatos que oyes por las tabernas "+
 		"por las que sueles pasar en tus viajes, lo cierto es que nunca nadie "+
 		"se habia atevido a llegar t�n lejos como lo haces tu, por lo menos nadie "+
 		"que est� vivo ahora. Ves restos de pelo enredado en los �rboles. ";
 		map[inv,des]="La nieve lo cubre todo.\n";
 		map[pri,des]="A�n con la llegada de la primavera esto no parece m�s acogedor.\n";
 		map[ver,des]="Hace mucho calor, a pesar de que las hojas tapan el sol.\n";
 		map[oto,des]="Est� todo muy mojado, sin duda por las lluvias.\n";
 		/*********************** NOMBRE DETALLES ************************/
 		map[neu,nde]=({"pelo","pelo enredado"});
 		clonar=5;
		/******************** DESCRIPCION DETALLES **********************/
		map[neu,dde]="Ves pelo de alg�n tipo de criatura enredado en los �rboles ";
		map[inv,dde]="un poco oculto bajo algo de nieve.\n";
 		map[pri,dde]="que contrasta con los brotes de al lado.\n";
 		map[ver,dde]="sin duda de un animal peligroso.\n";
 		map[oto,dde]="mojado por las lluvias.\n";
 		break;
 	case 5: /********************* DESCRIPCIONES ****************************/
 		map[neu,des]="Est�s en las entra�as del bosque de Cylin, un lugar oscuro "+
 		"y sombr�o por el que pocos se atreven a andar. A la vista est� que no "+
 		"encontrar�s nada bueno por estos lares. Hay un viejo toc�n rodeado "+
 		"por los �rboles, ";
 		map[inv,des]="cubierto de nieve por encima.\n";
 		map[pri,des]="con algunos t�midos brotes saliendo de �l.\n";
 		map[ver,des]="algo reseco.\n";
 		map[oto,des]="empapado por la lluvia.\n";
 		/*********************** NOMBRE DETALLES ************************/
 		map[neu,nde]=({"tocon","toc�n"}); //No, no es un Maler, mirad el diccionario.
 		clonar=6;
		/******************** DESCRIPCION DETALLES **********************/
		map[neu,dde]="Un viejo y abandonado toc�n ";
		map[inv,dde]="cubierto casi completamente por la nieve.\n";
 		map[pri,dde]="con algunos brotes a su alrededor, pero que no crees que renazca.\n";
 		map[ver,dde]="bastante reseco.\n";
 		map[oto,dde]="completamente mojado por la lluvia.\n";
 		break;
 	case 6: /********************* DESCRIPCIONES ****************************/
 		map[neu,des]="Est�s en peque�o claro del bosque. Desde aqu� sientes "+
 		"unas amenazadoras miradas que vienen de lo profundo de la vegetaci�n "+
 		"y notas como tu coraz�n se acelera. Hay un poco de c�sped que ha podido "+
 		"conseguir aqu� algo de sol para crecer";
 		map[inv,des]=", pero ahora est� cubierto por la nieve, aunque en alguna zona "+
 		"todav�a se puede ver.\n";
 		map[pri,des]=" y que empieza a rebrotar con fuerza.\n";
 		map[ver,des]=" y gracias al buen tiempo se ve en muy buen estado.\n";
 		map[oto,des]=", aunque las hojas que caen se lo ponen dif�cil.\n";
 		/*********************** NOMBRE DETALLES ************************/
 		map[neu,nde]=({"c�sped","cesped"});
 		clonar=7;
		/******************** DESCRIPCION DETALLES **********************/
		map[neu,dde]="En el suelo hay algo de c�sped";
		map[inv,dde]=" muy quemado por el fr�o y cubierto por la nieve.\n";
 		map[pri,dde]=" que empieza a crecer con fuerza.\n";
 		map[ver,dde]=" en muy buen estado, dando un bonito color verde al lugar.\n";
 		map[oto,dde]=" semienterrado entre las hojas que caen.\n";
 		break;
 	case 7: /********************* DESCRIPCIONES ****************************/
 		map[neu,des]="Este es el bosque de Cylin, famoso por sus innumerables "+
 		"peligros. Hay varias razones por las que no deber�as haber entrado, y "+
 		"ahora que est�s dentro piensas que deber�as haberlas escuchado. En "+
 		"los �rboles puedes ver unas extra�as marcas como si fueran zarpazos hechos "+
 		"por alg�n tipo de criatura, ";
 		map[inv,des]="quiz�s buscando comida durante esta dura �poca.\n";
 		map[pri,des]="puede que marcando su territorio.\n";
 		map[ver,des]="puede que marcando su territorio.\n";
 		map[oto,des]="puede que marcando su territorio.\n";
 		/*********************** NOMBRE DETALLES ************************/
 		map[neu,nde]=({"marcas","zarpazo","zarpazos"});
 		clonar=8;
		/******************** DESCRIPCION DETALLES **********************/
		map[neu,dde]="Unas extra�as marcas que han desgarrado profundamente los �rboles";
		map[inv,dde]=", exponi�ndolos a la nieve y el fr�o intenso.\n";
 		map[pri,dde]=" y que han destrozado muchos de los brotes de primavera.\n";
 		map[ver,dde]=" y que han terminado por resecar algunos de los �rboles.\n";
 		map[oto,dde]=", que ahora son pasto f�cil del mal tiempo.\n";
 		break;
 	case 8: /********************* DESCRIPCIONES ****************************/
 		map[neu,des]="Est�s en un bosque, pero no parece un bosque normal, sino "+
 		"m�s bien un bosque por el que la muerte ronda sin cesar. En el suelo, "+
 		"bastante escondidos, puedes ver los restos de lo que parece fue un animal. "+
 		"Adem�s los �rboles aqu� son enormes, parece que como nadie los ha "+
 		"molestado durante siglos han crecido a sus anchas";
 		map[inv,des]=", aunque ahora, sin hojas, no parecen tan amenazadores.\n";
 		map[pri,des]=" y lo seguiran haciendo mientras siga pasando el tiempo.\n";
 		map[ver,des]=", aunque este calor puede que les afecte.\n";
 		map[oto,des]=" y con estas lluvias, sin duda crecer�n m�s a�n.\n";
 		/*********************** NOMBRE DETALLES ************************/
 		map[neu,nde]=({"restos","resto","animal","esqueleto"});
 		clonar=9;
		/******************** DESCRIPCION DETALLES **********************/
		map[neu,dde]="Unos restos de alg�n tipo de animal, o incluso puede que "+
		"persona, con claros s�ntomas de haber sido la comida de alguien";
		map[inv,dde]=", se ocultan bajo algo de nieve.\n";
 		map[pri,dde]=", dan una sensaci�n aterradora.\n";
 		map[ver,dde]=", te dan ganas de vomitar con este calor.\n";
 		map[oto,dde]=", se descomponen con la humedad.\n";
 		break;
 	case 9: /********************* DESCRIPCIONES ****************************/
 		map[neu,des]="Est�s en un bosque cerrado, tan inmenso e inexplorado "+
 		"que parece que est�s en otro mundo. El ambiente es muy h�medo y "+
 		"una densa niebla hace m�s agobiante el lugar. Parece que la niebla "+
 		"es un invento del propio bosque para perder a los incautos que se "+
 		"adentran en �l y acabar con su vida lentamente";
 		map[inv,des]=" a manos del intenso fr�o.\n";
 		map[pri,des]=" ayudado por la desesperaci�n que produce.\n";
 		map[ver,des]=" asfixi�ndolos con el inmenso calor.\n";
 		map[oto,des]=" ayudado por la incesante lluvia.\n";
 		/*********************** NOMBRE DETALLES ************************/
 		map[neu,nde]=({"niebla","bruma"});
 		clonar=10;
		/******************** DESCRIPCION DETALLES **********************/
		map[neu,dde]="Una espesa niebla se ha apoderado de este trozo del bosque";
		map[inv,dde]=" y hace pr�cticamente imposible ver casi nada.\n";
 		map[pri,dde]=" y hace pr�cticamente imposible ver casi nada.\n";
 		map[ver,dde]=" y hace pr�cticamente imposible ver casi nada.\n";
 		map[oto,dde]=" y hace pr�cticamente imposible ver casi nada.\n";
 		break;
 	default:/********************* DESCRIPCIONES ****************************/
 		map[neu,des]="Este es el tenebroso bosque de Cylin, un lugar del "+
 		"que nunca saldr�s con vida...";
 		break;
  }
}

 init(){
 ::init();
 add_action("fcoger","coger");
 switch (CHRONOS->QueryEstacion())
 {
 	case 1:	SetIntLong(W(to_string(map[neu,des])+to_string(map[inv,des])));
 		SetIntSmell(W(to_string(map[inv,sme])));
 		SetIntNoise(W(to_string(map[inv,noi])));
 		AddDetail((map[neu,nde]),W(to_string(map[neu,dde])+to_string(map[inv,dde])));
 		AddDetail(({"nieve"}),W(
		"El duro invierno del valle de Rhoemas hace que la nieve se amontone "+
		"sin cesar por donde cae, formando todo un manto nevado que cubre "+
		"pr�cticamente todo a su paso.\n"));
		AddDetail(({"rama","ramas"}),W(
		"Las ramas de los �rboles est�n completamente cubiertas de nieve y sin "+
		"ninguna hoja a la vista. Adem�s, el fuerte viento ha hecho caer algunas "+
		"al suelo, que han sido enterradas por la nieve.\n"));
		AddDetail(({"�rbol","�rboles","arbol","arboles"}),W(
		"Aqu� los �rboles est�n completamente cubiertos por la nieve, y hace mucho que "+
		"se quedaron sin hojas debido al viento.\n"));
		AddDetail(({"suelo"}),W(
		"No ves nada mas que la nieve cubriendo cada rinc�n del suelo.\n"));
 		break;

 	case 2:	SetIntLong(W(to_string(map[neu,des])+to_string(map[pri,des])));
 		SetIntSmell(W(to_string(map[pri,sme])));
 		SetIntNoise(W(to_string(map[pri,noi])));
 		AddDetail((map[neu,nde]),W(to_string(map[neu,dde])+to_string(map[pri,dde])));
 		AddDetail(({"brote","brotes"}),W(
		"Hay peque�os brotes verdes por donde quiera que mires.\n"));
		AddDetail(({"rama","ramas"}),W(
		"Las ramas de los �rboles est�n renaciendo tras el largo invierno, y "+
		"ofrecen una curiosa variedad de brotes de diferentes formas.\n"));
		AddDetail(({"�rbol","�rboles","arbol","arboles"}),W(
		"Todos los �rboles empiezan a renacer lentamete y est�n llenos de brotes.\n"));
		AddDetail(({"suelo"}),W(
		"Peque�os brotes verdes dan un toque de colorido al suelo.\n"));
 		break;

 	case 3: SetIntLong(W(to_string(map[neu,des])+to_string(map[ver,des])));
 		SetIntSmell(W(to_string(map[ver,sme])));
 		SetIntNoise(W(to_string(map[ver,noi])));
 		AddDetail((map[neu,nde]),W(to_string(map[neu,dde])+to_string(map[ver,dde])));
 		AddDetail(({"hoja","hojas"}),W(
		"Los �rboles tienen unas hojas impresionantemente grandes que casi "+
		"tapan el cielo.\n"));
		AddDetail(({"rama","ramas"}),W(
		"Las ramas de los �rboles est�n repletas de hojas, y ves el verde "+
		"por donde miras.\n"));
		AddDetail(({"�rbol","�rboles","arbol","arboles"}),W(
		"Este bosque tiene los �rboles m�s frondosos que has visto nunca.\n"));
		AddDetail(({"suelo"}),W(
		"El suelo es negro y h�medo, a pesar del calor.\n"));
 		break;

 	case 4:	SetIntLong(W(to_string(map[neu,des])+to_string(map[oto,des])));
 		SetIntSmell(W(to_string(map[oto,sme])));
 		SetIntNoise(W(to_string(map[oto,noi])));
 		AddDetail((map[neu,nde]),W(to_string(map[neu,dde])+to_string(map[oto,dde])));
 		AddDetail(({"hoja","hojas"}),W(
		"Las frondosas hojas del verano ya se han marchitado, ti�endo de "+
		"amarillo y rojo todo el lugar, y empiezan a caer al suelo formando "+
		"una manta de colores.\n"));
		AddDetail(({"rama","ramas"}),W(
		"Las ramas de los �rboles empiezan a coger tonos m�s c�lidos, "+
		"y algunas empiezan a quedarse sin hojas.\n"));
		AddDetail(({"�rbol","�rboles","arbol","arboles"}),W(
		"Los �rboles est�n empezando a dejar caer las hojas, que ahora son de varios "+
		"colores.\n"));
		AddDetail(({"suelo"}),W(
		"El suelo cruje a cada paso que das. Est� lleno de hojas marchitas.\n"));
		break;

 	default:SetIntLong(W(to_string(map[neu,des])));
 		SetIntSmell(W(to_string(map[neu,sme])));
 		SetIntNoise(W(to_string(map[neu,noi])));
 		AddDetail((map[neu,nde]),W(to_string(map[neu,dde])+".\n"));
 		break;
  }
}

reset(){
  ::reset();
  existe=random(2);
  rama=random(4);
}
