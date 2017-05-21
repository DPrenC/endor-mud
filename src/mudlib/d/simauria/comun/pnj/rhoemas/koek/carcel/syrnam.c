/***************************************************************************************
 ARCHIVO:	syrnam.c
 AUTOR:		[z] Zomax
 FECHA:		01-12-2001
 COMENTARIOS:	Syrnam, la borracha presa
 MODIFICACION:  09-04-2003 Añado preguntas y funciones para la Quest de Draego.
                20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <moving.h>
#include <properties.h>

inherit NPC;

public string fhermana(void)
{
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (quest && member(quest,"copa") && quest["copa",0]==4)
	{
		quest+=(["copa":5]);
		return W("Syrnam te dice: ¿Quién? No se de quién hablas...\n\nLe cuentas cómo "
		"has conseguido leer los archivos del conserje y que sabes que ella es "
		"en realidad Shiran, la hermana de Fowla.\n\nSyrnam dice: Ohh... de acuerdo, "
		"sí, soy yo, me cambié el nombre en una apuesta ¡pero oye, gané una noche "
		"de barra libre en la taberna!, ¡valió la pena!. Ahora que sabes mi pequeño "
		"secreto dime, ¿qué puedo hacer por tí para que no se lo cuentes a nadie?.\n");
	}
	return "Syrnam te dice: ¿Quién? ¿De qué hablas?... hic... bueno sigamos, ¿quieres una copita?\n";
}

public string fzafiro(void)
{
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (quest && member(quest,"copa") && quest["copa",0]==5)
	{
		quest+=(["copa":6]);
		clone_object(RHOEVAR("koek/carcel/zafiro"))->move(TP,M_NOCHECK);
		return W("Syrnam te dice: Vale te lo doy... pero que sepas que es en pago por tu "
		"silencio... hic...\nSyrnam se mete el dedo en la boca hasta lo más profundo "
		"y oyes un chasquido... parece que tenía el zafiro incrustado en la dentadura "
		"entre dos de los pocos dientes que aún conserva. Es un buen método para que "
		"un borracho no pierda las cosas pero por tu parte estás apunto de morir de "
		"angustia... y lo peor de todo... te lo acaba de dar...\n");
	}
	return "Syrnam se encoge de hombros.\n";
}

create(){
  ::create();
  SetStandard("Syrnam, la borracha","humano",10,GENERO_FEMENINO);
  SetWhimpy(0);
  SetAlign(150);
  SetAggressive(0);
  SetName("Syrnam");
  SetIds(({"humana","syrnam","Syrnam","borracha","presa"}));
  SetShort("Syrnam la borracha");
  SetLong(W("Syrnam es la borracha del pueblo... es una mujer mayor con la cara "
  	"completamente arrugada y llena de granos que parece que puede romper todos "
  	"los espejos en 100km a la redonda. Tiene las manos retorcidas y las uñas "
  	"negras y largas que no dejan nunca de sostener su botella. Quizás siendo "
  	"amable saques algo en claro.\n"));
  AddSubDetail(({"grano","granos"}),W("Parece que vayan a explotarte en la cara cuando "
  	"los miras. Tienes ganas de devolver.\n"));
  AddSubDetail(({"mano","manos"}),"Más que manos parecen garras.\n");
  AddSubDetail(({"botella"}),W("Tiene una botella incrustada en la mano para siempre. "
  	"forma ya parte de ella.\n"));
  AddQuestion(({"novio","pareja","marido","esposo"}),W("Syrnam te dice: Uis... que picarón... "
  	"No... no tengo de eso... ¿es que te ofreces?\nSyrnam te guiña un ojo y "
  	"un escalofrío recorre tu espalda.\n"),1);
  AddQuestion(({"fowla"}),W("Syrnam te dice: Esa vieja bruja... no me hables más de ella.\nSyrnam pega "
  	"un largo trago de la botella que tiene pegada a su mano.\n"),1);
  AddQuestion(({"shiran","hermana","Shiran"}),SF(fhermana),1);
  AddQuestion(({"zafiro","joya"}),SF(fzafiro),1);
  AddQuestion(({"fuga","salir","carcel","fugarse","calabozo","salida"}),W("Syrnam te dice: Um... ¡hic!... me conozco "
  	"cada palmo de la cárcel... ¡hic!... cada secreto... ¡hic!...la verdad es "
  	"que paso más tiempo aquí que en la calle... ¡hic!... se está muy bien... "
  	"¡hic!... La verdad es que me conozco todos los secretos...¡hic!.\n"),1);
  InitChats(10,({"Syrnam se tambalea mientras te mira.\n",
  		 "Syrnam dice: Hola pichurrín... ¿quieres ser mi pareja?.\n",
		 "Syrnam dice: Todo lo que necesito es... amor... bueno, y otra botella.\n",
		 "Syrnam se queda un segundo pensativa y después pega un largo trago.\n"}));
  InitAChats(10,"[51m¡Así no lograrás conquistar mi corazón! ¡Sé más sútil!.[0m\n");
}

