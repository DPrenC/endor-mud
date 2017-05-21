/***************************************************************************************
 ARCHIVO:	gorgona.c
 AUTOR:		[z] Zomax
 FECHA:		27-11-2001
 COMENTARIOS:	Bosque Cylin, en Koek (Entrada a la guarida de la Gorgona)
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit SIM_ROOM;

string descripcion;
int rama;

int fcoger(string str)
{
	object cosa;
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
				write("¿No querrás ayudar a la deforestación, no?\n");
				return 1;
			}
			break;
		case 3: if (str=="hoja" || str=="hojas")
			{
				write("¿No querrás ayudar a la deforestación, no?\n");
				return 1;
			}
			break;
		case 4: if (str=="hoja" || str=="hojas")
			{
				cosa=clone_object(RHOEVAR("cylin/hoja"));
				cosa->move(TP,M_SILENT);
				write("Coges una hoja caída del suelo.\n");
				say(W(CATP+
				" coge una hoja caída del suelo.\n"),TP);
				return 1;
			}
			break;
		default:break;
	}
	if (str=="hierba" || str=="hierba extraña" || str=="hierba extranya" || str=="hierbas" || str=="hierbas extrañas" || str=="hierbas extranyas")
	{
		write(W("Las hierbas son demasiado fuertes y tupidas como para que "
		"cojas una, están todas enmarañadas.\n"));
		return 1;
	}
	else if (str=="rama" || str=="ramas")
	{
		if (rama==1)
		{
			cosa=clone_object(RHOEVAR("cylin/rama"));
			cosa->move(TP,M_SILENT);
			write("Coges una rama caída del suelo.\n");
			say(W(CATP+
			" coge una rama caída del suelo.\n"),TP);
			rama=0;
			return 1;
		}
		else
		{
			write(W("Parece que hay ramas de un tamaño que "
			"puedas coger. Tendrás que esperar a que caiga alguna.\n"));
			return 1;
		}
	}
	else if (str=="arbol" || str=="árbol" || str=="arboles" || str=="árboles")
	{
		write(W("Este bosque empieza a afectarte... ¿¿¿De verdad crees que puedes "
		"coger un árbol???\n"));
		return 1;
	}
}

int fhuir(string str)
{
	if (TP->QueryCombatDelay())
	{
		write(W("No puedes huir. Estás inmovilizad"+AO+".\n"));
		say(W(CATP+" mira a su alrededor con pánico en los ojos. Parece que "
		"quiere huir, pero está inmovilizad"+AO+".\n"),TP);
		return 1;
	}
}

create () {
 ::create();
 rama=random(4);
 SetLocate("Bosque de Cylin - Gorgona");
 SetIntShort("el bosque de Cylin");
 AddExit("norte",RHOEHAB("cylin/bosque_138"));
 AddExit("abajo",RHOEHAB("cylin/cueva"));
 HideExit("abajo",1);
 AddRoomCmd("huir","fhuir");
 AddRoomCmd("reiniciar","freiniciar");
 SetIndoors(0);
 SetIntBright(10);
 descripcion=("Estás en lo que parece ser el centro del bosque de Cylin. Aquí "
 	     "los árboles son más espesos si cabe y la luz casi no llega a "
 	     "esta altura. Hay una siniestra quietud por este lugar, como si "
 	     "los mismos animales del bosque temieran este sitio y no se "
 	     "acercaran por nada del mundo. Hay muchas hierbas extrañas que "
 	     "cubren la mayor parte del suelo");
 AddDetail(({"hierba","hierba extraña","hierba extranya","hierbas","hierbas extrañas","hierbas extranyas"}),W(
	     "Hay unas hierbas muy muy raras esparcidas pro el suelo... no parece que sean "
	     "autóctonas, más bien parece que hayan sido plantadas adrede. Son muy muy "
	     "tupidas, ideales para tapar algo.\n"));
}

init(){
 ::init();

 add_action("fcoraje","coraje");
 TP->SetWhimpy(-1);
 tell_object(TP,W("Te sientes muy segur"+AO+" de ti mism"+AO+", esta vez no huirás automáticamente.\n"));
 add_action("fcoger","coger");
 switch (CHRONOS->QueryEstacion())
 {
 	case 1:	SetIntLong(W(descripcion+" junto con la nieve.\n"));
 		SetIntSmell("Tienes la nariz tan fría que no hueles nada.\n");
 		SetIntNoise("Oyes los silbidos del aire gélido al chocar con tus orejas.\n");
 		AddDetail(({"nieve"}),W(
		"El duro invierno del valle de Rhoemas hace que la nieve se amontone "+
		"sin cesar por donde cae, formando todo un manto nevado que cubre "+
		"prácticamente todo a su paso.\n"));
		AddDetail(({"rama","ramas"}),W(
		"Las ramas de los árboles están completamente cubiertas de nieve y sin "+
		"ninguna hoja a la vista. Además, el fuerte viento ha hecho caer algunas "+
		"al suelo, que han sido enterradas por la nieve.\n"));
		AddDetail(({"árbol","árboles","arbol","arboles"}),W(
		"Aquí los árboles están completamente cubiertos por la nieve, y hace mucho que "+
		"se quedaron sin hojas debido al viento.\n"));
		AddDetail(({"suelo"}),W(
		"No ves nada mas que la nieve cubriendo cada rincón del suelo.\n"));
 		break;

 	case 2:	SetIntLong(W(descripcion+" y que están rebrotando con mucha fuerza.\n"));
 		SetIntSmell("Las plantas de toda la zona aromatizan el ambiente.\n");
 		SetIntNoise("Apenas oyes el sonido del viento acariciando cuanto toca.\n");
 		AddDetail(({"brote","brotes"}),W(
		"Hay pequeños brotes verdes por donde quiera que mires.\n"));
		AddDetail(({"rama","ramas"}),W(
		"Las ramas de los árboles están renaciendo tras el largo invierno, y "+
		"ofrecen una curiosa variedad de brotes de diferentes formas.\n"));
		AddDetail(({"árbol","árboles","arbol","arboles"}),W(
		"Todos los árboles empiezan a renacer lentamete y están llenos de brotes.\n"));
		AddDetail(({"suelo"}),W(
		"Pequeños brotes verdes dan un toque de colorido al suelo.\n"));
 		break;

 	case 3: SetIntLong(W(descripcion+", pero están empezando a marchitarse del calor.\n"));
 		SetIntSmell("Aspiras el aire... demasiado caliente para tu gusto.\n");
 		SetIntNoise("El aire está tan parado que no oyes nada en absoluto.\n");
 		AddDetail(({"hoja","hojas"}),W(
		"Los árboles tienen unas hojas impresionantemente grandes que casi "+
		"tapan el cielo.\n"));
		AddDetail(({"rama","ramas"}),W(
		"Las ramas de los árboles están repletas de hojas, y ves el verde "+
		"por donde miras.\n"));
		AddDetail(({"árbol","árboles","arbol","arboles"}),W(
		"Este bosque tiene los árboles más frondosos que has visto nunca.\n"));
		AddDetail(({"suelo"}),W(
		"El suelo es negro y húmedo, a pesar del calor.\n"));
 		break;

 	case 4:	SetIntLong(W(descripcion+" y algunas hojas caídas que terminan de taparlo "
 		"por completo.\n"));
 		SetIntSmell("El olor a tierra mojada invade el ambiente.\n");
 		SetIntNoise(W("Oyes el sonido del viento que empieza a soplar con algo "
 				"de fuerza y tus pasos sobre las hojas caídas en el suelo.\n"));
 		AddDetail(({"hoja","hojas"}),W(
		"Las frondosas hojas del verano ya se han marchitado, tiñendo de "+
		"amarillo y rojo todo el lugar, y empiezan a caer al suelo formando "+
		"una manta de colores.\n"));
		AddDetail(({"rama","ramas"}),W(
		"Las ramas de los árboles empiezan a coger tonos más cálidos, "+
		"y algunas empiezan a quedarse sin hojas.\n"));
		AddDetail(({"árbol","árboles","arbol","arboles"}),W(
		"Los árboles están empezando a dejar caer las hojas, que ahora son de varios "+
		"colores.\n"));
		AddDetail(({"suelo"}),W(
		"El suelo cruje a cada paso que das. Está lleno de hojas marchitas.\n"));
		break;
 }
}

reset(){
 ::reset();
 rama=random(4);
}

int fcoraje(int num)
{
	tell_object(TP,"Eres demasiado valiente para estar aquí, no puedes cambiar ahora.\n");
	return 1;
}

int freiniciar(string str)
{
	write("No, no... eso no se hace.\n");
	return 1;
}
