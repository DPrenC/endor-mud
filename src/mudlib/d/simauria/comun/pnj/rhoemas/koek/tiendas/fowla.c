/***************************************************************************************
 ARCHIVO:	Fowla.c
 AUTOR:		[z] Zomax
 FECHA:		14-12-2001
 COMENTARIOS:	Fowla, la pitonisa.
 MODIFICACION:	21-03-2003 Añado cosas para el quest de Draego.
 		17-04-2003 Mas cosas para lo mismo...
 		20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

public string fhermana(void)
{
	mapping quest;
	quest=TP->QueryAttribute("DraegoQuest");

	if(quest && member(quest,"copa") && quest["copa",0] && quest["copa",0]<7)
	{

		return W("Fowla te dice: Tendrás que buscarla por tu cuenta. Hace mucho "
		"que le perdí la pista a Shiran. Mis poderes no funcionan con mi hermana "
		"porque es muy poderosa, casi tanto como yo. Quizás en los archivos del "
		"pueblo te sepan decir algo.\n");
	}
	else return W("Fowla te dice: Yo no tengo hermana, y aunque tuviera una no te lo "
		"diria. Umm... ya me has sacado malos recuerdos. Vete o te maldigo.\n");
}

create(){
  ::create();
  SetStandard("Fowla la pitonisa","humano",10,GENERO_FEMENINO);
  SetWhimpy(0);
  SetAlign(50);
  SetAggressive(0);
  SetHands(({({"mano derecha",0,10}),({"mano izquierda",0,10})}));

  SetName("Fowla");
  SetIds(({"humana","fowla","Fowla","pitonisa"}));
  Set(P_CANT_LURE,1);
  SetShort("la pitonisa Fowla");
  SetLong(W("Fowla es una pitonisa. Tiene una larga melena rubia que le tapa "
  	"la cara con mucha frencuencia mientras se concentra en sus sesiones de "
  	"espiritismo. Tiene fama de leer la buenaventura a los viajeros que pasan "
  	"por aquí por un pequeño precio. Mejor no te cruces en su camino o te "
  	"maldecirá.\n"));

  AddSubDetail(({"melena","pelo"}),W("Da algo de miedo, tiene el pelo como un "
  	"estropajo.\n"));
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Fowla te dice: Koek está bien... atrae a mucha gente de fuera.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Fowla te dice: El bosque de Cylin es un lugar perfecto para recoger ingredientes y "
	"meditar, pero sólo la gente con un don especial, como yo, podemos ir "
	"sin peligro. Tú no durarías ni dos segundos. Pregunta a Froeker.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W("Fowla te dice: El templo de Seri-Solderteg "
  	"es la residencia de los monjes, y donde se entrenan y rinden culto a su "
  	"Diosa. Personalmente no entiendo ese tipo de sumisión.\n"),1);
  AddQuestion(({"consulta"}),W("Por una módica cantidad de dinero te paso consulta. "
  	"Fowla te dice: Escribe 'lista' para elegir entre las consultas disponibles.\n"),1);
  AddQuestion(({"hermana","shiran","Shiran"}),SF(fhermana),1);

  InitChats(5,({"Fowla empieza a contar todo lo que ha ganado hoy con una sonrisa pícara.\n",
  		"Fowla dice: Veo algo en tu aura... deberias pedir una consulta.\n",
		"Fowla dice: Soy la mejor pitonisa del pueblo... incluso aunque hubiera más.\n",
		"Fowla dice: Estoy perfeccionando mis técnicas de adivinación.\n",
		"Fowla dice: ¿Nunca has perdido algo? Yo soy la persona que buscas.\n",
		"Fowla dice: Por un módico precio... doy felicidad a la gente.\nSiesque... en el "
		"fondo soy un pedazo de pan. Me tendrían que valorar más.\n",
		"Fowla dice: ¿No tienes curiosidad por algo? pide consulta, escribe <consulta>.\n"}));
  InitAChats(5,({"Fowla grita: [52m ¡Que los fantasmas del valle caigan sobre ti¡, ¡maltido![0m.\n"}));
}
