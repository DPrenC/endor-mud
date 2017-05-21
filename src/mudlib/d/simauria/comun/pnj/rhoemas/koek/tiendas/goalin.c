/***************************************************************************************
 ARCHIVO:	goalin.c
 AUTOR:		[z] Zomax
 FECHA:		22-04-2003
 COMENTARIOS:	Goalin el sastre.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <combat.h>

inherit NPC;
#include RHOEDANYO

public string ftunica()
{
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (quest && member(quest,"tunica"))
	{
		if (quest["tunica",0]==0) quest+=(["tunica":1]);
		if (quest["tunica",0]==1)
		{
			return W("Goalin te dice: Pues si, podría conseguirte una túnica "
			"como la que necesitan en el templo pero el caso es que para que "
			"Kaleband no se diera cuenta hay que hacerla de los mismos materiales "
			"y eso no es tan fácil de conseguir. Para empezar el patrón necesito "
			"seda de muy buena calidad, élfica a ser posible. Si me vas trayendo "
			"lo que te pida quizás pueda hacerte una exactamente igual...\n\nGoalin "
			"dice para sus adentros: un auténtico reto... con esto mi reputación "
			"subirá como la espuma.\n\n Goalin te dice: ¿a qué esperas? ¡ves a "
			"por la seda!.\n");
		}
		else if (quest["tunica",0]>1 && quest["tunica",0]<5)
		{
			return W("Goalin te dice: Necesito la seda, tráemela en cuanto puedas "
			"o no podré empezar el patrón.\n");
		}
		else if (quest["tunica",0]>4 && quest["tunica",0]<8)
		{
			return W("Goalin te dice: Ahora me hace falta algo de tinte para "
			"conseguir la misma tonalidad que la original, de color púrpura, recuerda. "
			"Ves a ver si encuentas algún pintor que te deje de esos que usan en polvo, "
			"son los mejores.\n");
		}
		else if (quest["tunica",0]>7 && quest["tunica",0]<12)
		{
			return W("Goalin te dice: Nunca ví un hilo tan fino de oro, no se "
			"cómo lo harás pero me lo tienes que conseguir.\n");
		}
		else if (quest["tunica",0]>11 && quest["tunica",0]<13)
		{
			return W("Goalin te dice: La túnica está casi terminada... mientras... ¿puedes "
			"encontrar a los pequeños bandidos que robaron mis botones?.\n");
		}
	}
	else return "Goalin se encoge de hombros.\n";
}

public string fseda()
{
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (quest && member(quest,"tunica"))
	{
		if (quest["tunica",0]>=1 && quest["tunica",0]<5)
			return W("Goalin te dice: El único lugar donde se me ocurre que pueda haber "
			"el tipo de seda que necesito es Atbalnin, los elfos suelen tener ese tipo de "
			"cosas...\n");
		else if (quest["tunica",0]>4 && quest["tunica",0]<13)
			return W("Goalin te dice: Si, la guardo a buen recaudo, no te preocupes y "
			"traemé lo que falta.\n");
		else return "Goalin se encoge de hombros.\n";
	}
	else return "Goalin se encoge de hombros.\n";
}

public string ftinte()
{
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (quest && member(quest,"tunica"))
	{
		if (quest["tunica",0]>4 && quest["tunica",0]<8)
			return W("Goalin te dice: Necesito el tinte en polvo color púrpura, sin eso "
			"no puedo seguir, se darían cuenta de que no es la misma túnica. Busca un "
			"pintor, ellos suelen tener lo que necesitas.\n");
		else if (quest["tunica",0]>7 && quest["tunica",0]<13)
			return W("Goalin te dice: Ya me lo diste, ¿recuerdas? de hecho la túnica ya "
			"está tintada, ha quedado muy bien.\n");
		else return "Goalin se encoge de hombros.\n";
	}
	else return "Goalin se encoge de hombros.\n";
}

public string fhilo()
{
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (quest && member(quest,"tunica"))
	{
		if (quest["tunica",0]>7 && quest["tunica",0]<12)
			return W("Goalin te dice: Busca donde sea pero necesito el hilo de oro más "
			"fino que puedas encontrar, más incluso, pero no creo que ningún orfebre te "
			"pueda estirar tanto el hilo, esto parece cosa de magia.\n");
		else return "Goalin se encoge de hombros.\n";
	}
	else return "Goalin se encoge de hombros.\n";
}


public string fbotones()
{
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (quest && member(quest,"tunica"))
	{
		if (quest["tunica",0]>11 && quest["tunica",0]<13)
			return W("Goalin te dice: Solo puedo decirte que eran kenders, al principio "
			"me parecieron niños normales pero eran kenders, seguro... tienen predilección "
			"por los botones...\n");
		else return "Goalin se encoge de hombros.\n";
	}
	else return "Goalin se encoge de hombros.\n";

}

create(){
  ::create();
  SetStandard("Goalin el sastre","humano",13,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Goalin");
  SetIds(({"humano","goalin","Goalin","sastre"}));
  SetShort("Goalin el sastre");
  Set(P_CANT_LURE,1);
  SetLong(W("Goalin es el sastre de Koek, un chaval más bien joven con el "
  	"pelo más largo de lo normal y la ropa llena de alfileres que va "
  	"enganchando mientras trabaja. Tiene un poco de barba justo al final "
  	"de la barbilla y unos ademanes de lo más curiosos.\n"));

  AddSubDetail(({"barba"}),"Parece que hace poco se empezó a dejar barba.\n");
  AddSubDetail(({"alfileres"}),W("Los tiene por toda la ropa pero parece que "
  	"está acostumbrado, no se pincha.\n"));
  AddQuestion(({"sastreria","sastrería"}),W("Goalin te dice: Abrí este negocio "
  	"hace poco. La verdad es que tengo grandes expectativas puestas en él, aquí "
  	"la gente tiene un sentido de la moda más bien anticuado, necesitan alguien "
  	"como yo urgentemente.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
  	"Goalin te dice: Es un pueblo bastante normal pero se nota que no se han dedicado mucho "
  	"a cuidarse las ropas.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
  	"Goalin te dice: He oído rumores, pero como soy nuevo en Koek no tengo ni idea de dónde está.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W("Goalin te dice: Fue mi primer "
  	"cliente, la verdad es que necesitaban con urgencia túnicas nuevas. Aunque las "
  	"cosas no me vayan muy bien en el pueblo siempre tendré el Templo como cliente, "
  	"eso fue lo que me decidió para instalar aquí la sastrería.\n"),1);
  AddQuestion(({"tunica","túnica","tunica ceremonial","túnica ceremonial"}),SF(ftunica),1);
  AddQuestion(({"seda","seda elfica","seda élfica"}),SF(fseda),1);
  AddQuestion(({"tinte","tinte púrpura","tinte purpura"}),SF(ftinte),1);
  AddQuestion(({"hilo","hilo de oro","fino hilo de oro"}),SF(fhilo),1);
  AddQuestion(({"botones","botones de mithril"}),SF(fbotones),1);
  AddQuestion(({"horario","abierto","cerrado","abrir","cerrar"}),W("Goalin te dice: Abro "
  	"la sastrería de 8 a 22.\n"),1);
}

init(){
  ::init();

  add_action("fdar","dar");
}


public int fdar(string str)
{
	string que,quien;
	object goalin=TO;
	object seda=present("seda élfica",TP);
	object tinte=present("tinte púrpura",TP);
	object tinte_azul=present("tinte azul",TP);
	object hilo=present("fino hilo de oro",TP);
	object botones=present("botones de mithril",TP);
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (!str) return 0;
	else lower_case(str);

	if (sscanf(str,"%s a %s", que, quien) != 2) return 0;
	else if (!goalin || !living(goalin) || !goalin->id(quien)) return 0;
	else if (quest && member(quest,"tunica"))
	{
		if (seda && quest["tunica",0]==4)
		{
			quest+=(["tunica":5]);
			write(W("Goalin te dice: Vaya... al final conseguiste encontrar la seda... sinceramente "
			"pensaba que no lo conseguirías, bueno pues con esto puedo empezar el patrón, pero para "
			"lograr el color púrpura intenso de la túnica original necesito tinte en polvo, del que "
			"usan los pintores.\n"));
			seda->remove();
			return 1;
		}
		else if (tinte && quest["tunica",0]==7)
		{
			quest+=(["tunica":8]);
			write(W("Goalin te dice: ¡Por Xaenetia!, ¿dónde has conseguido este color tan intenso?, "
			"¡es casi mejor que el original, que empezaba a desteñir!. Muy bien muy bien, con esto "
			"empezaré a tintar la tela. Hay un problema más, lo creas o no... he estado revisando "
			"los retales que quedaron de la túnica con Draego y el hilo que usaron en los bordados "
			"es de oro puro, pero misteriosamente fino. No conozco ningún lugar donde dobleguen "
			"así el oro, es demasiado fino, demasiado, parece hecho por arte de magia.\n"));
			tinte->remove();
			return 1;
		}
		else if (tinte_azul && quest["tunica",0]>= 6 && quest["tunica",0]<8)
		{
			write(W("Goalin te dice: No, este color no puede ser, la túnica original era de color "
			"púrpura, tienes que darme tinte púrpura.\n"));
			return 1;
		}
		else if (hilo && quest["tunica",0]==11)
		{
			quest+=(["tunica":12]);
			write(W("Goalin te dice: ¡Esto es inaudito!, ¿qué orfebre te ha estirado así el oro? "
			"¡es un auténtico maestro!, no importa, ya me lo dirás más tarde, ahora al trabajo... "
			"con esto ya casi hemos terminado, solo tienes que hacerme un favor, esta vez personal, "
			"verás, el otro día pasaron por aquí unos kenders y me robaron casi todos los botones "
			"que tenía para la sastrería... se ve que les gustan esas cosas... el caso es que "
			"los que tengo son los justos para terminar los puños de la túnica y necesitaré más "
			"para mis otros encargos... ¿podrías encontrar a esos pequeños bandidos y recuperar "
			"algunos botones?, mientras acabaré la túnica...\n"));
			hilo->remove();
			return 1;
		}
		else if (botones && quest["tunica",0]==12)
		{
			quest+=(["tunica":13]);
			botones->remove();
			write(W("Goalin te dice: ¡Muchas gracias!, La túnica ya está, toma, he hecho todo "
			"lo que ha estado en mi mano pero aunque no es de buena educación decir algo así... "
			"¡es una obra de arte!, ¡soy un verdadero génio!.\nGoalin te da una túnica.\n"));
			clone_object(RHOEVAR("koek/varios/tunica"))->move(TP,M_NOCHECK);
			return 1;
		}
	}
}
