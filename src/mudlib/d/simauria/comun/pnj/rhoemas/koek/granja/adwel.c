/***************************************************************************************
 ARCHIVO:	adwel.c
 AUTOR:		[z] Zomax
 FECHA:		23-10-2001
 COMENTARIOS:	Adwel, la hija de los carniceros.
 MODIFICACI�N:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("la joven Adwel","humano",10,GENERO_FEMENINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Adwel");
  SetIds(({"humana","adwel","Adwel","joven"}));
  SetShort("la joven Adwel");
  SetLong(W("Adwel es la hija de Galonor y Mireba, los carniceros del pueblo. "
  	"Una muchacha de mirada penetrante que notas como te examina al fijarla "
  	"en ti. Tiene una preciosa y larga melena rojiza que refleja los rayos "
  	"del sol con m�s intensidad que un espejo. Parece descentrada, como si "
  	"estuviera pensando en algo o en alguien.\n"));
  AddSubDetail(({"pelo","melena"}),W("Es hija de Galonor, sin duda, ese pelo "
  	"rojo como el infierno es �nico. Tambi�n ves que tiene algo de paja entre "
  	"el pelo, como si hubiera estado retozando por ah�.\n"));
  AddSubDetail(({"paja","ramitas","ramita","ramita de paja","ramitas de paja"}),W("Tiene "
  	"el pelo lleno y el resto del cuerpo tambi�n.\n"));

  AddQuestion(({"carniceria"}),W("Adwel te dice: Es el negocio de mis padres, aunque a mi no "
  	"me gusta mucho, porque me encantan los animales. La verdad es que desde "
  	"que era peque�a no he participado mucho en las tareas de aqu� por eso. "
  	"Desde que naci� Broe me quedo m�s tranquila, porque �l se ocupar� del "
  	"negocio en el futuro y yo no me sentir� tan culpable.\n"),1);
  AddQuestion(({"hermano","broe","Broe"}),W("Adwel te dice: Broe es mi hermanito peque�o. Apenas "
  	"sabe decir alguna palabra, pero se le ve un ni�o muy avispado, siempre "
  	"que le ense�amos algo lo recuerda enseguida. Me hac�a mucha ilusi�n tener "
  	"un hermano. Estoy deseando que crezca y pueda hablar con �l de todas las cosas.\n"),1);
  AddQuestion(({"padre","galonor","Galonor"}),W("Adwel te dice: Mi padre es Galonor, el carnicero "
  	"del pueblo. Es un buen padre, aunque anda siempre algo distra�do, pero es "
  	"porque trabaja mucho. Cuando no trabaja suele estar en casa descansando de "
  	"la dura jornada, y es entonces cuando puedo hablar con �l un poco, antes "
  	"de que caiga rendido de sue�o.\n"),1);
  AddQuestion(({"madre","mireba","Mireba"}),W("Adwel te dice: Mireba es mi madre. Cuando era "
  	"peque�a me sol�a contar cuentos de elfos y enanos antes de dormirme, para "
  	"que tuviera buenos sue�os. Ahora est� muy ocupada con broe y el trabajo, "
  	"pero a�n as� me suele contar a�n alg�n cuento aprovechando que tambi�n "
  	"se los cuenta a Broe.\n"),1);
  AddQuestion(({"geagan","Geagan"}),W("Adwel se pone colorada, m�s a�n que su "
  	"pelo, si cabe...\nAdwel te dice: Geagan... es el chico m�s maravilloso del mundo... "
  	"es el hijo del panadero, y desde que �ramos unos ni�os est�bamos siempre "
  	"juntos, hasta que nos dimos cuenta de que nos quer�amos. Desde entonces, "
  	"aunque parezca raro, nos vemos mucho, pero no tanto como antes, porque nos "
  	"da un poco de verg�enza. Pero yo pienso que su madre sabe algo, porque se "
  	"sonrie cuando nos cruzamos con ella, y antes no lo hac�a.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Adwel te dice: Koek es todo lo que conozco. La verdad es que nunca he salido de aqu�, pero "
	"tampoco lo siento, porque este sitio es muy bonito.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Adwel te dice: El bosque da mucho miedo, sobre todo por la noche... no te acerques a �l.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W("Adwel te dice: El templo de Seri-Solderteg "
  	"es la residencia de los monjes, y donde se entrenan y rinden culto a su "
  	"Diosa. Es un lugar muy tranquilo donde casi nunca se oye nada.\n"),1);
  InitChats(10,({"Adwel se quita algo de paja del pelo con disimulo.\n",
  		 "Adwel mira el techo.\n",
		 "Adwel se est� poniendo roja.\n",
		 "Adwel silba.\n"}));
  InitAChats(10,({"[36mAdwel dice: ��Pero que haces?![0m\n"}));
}
