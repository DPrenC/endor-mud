/***************************************************************************************
 ARCHIVO:	geagan.c
 AUTOR:		[z] Zomax
 FECHA:		24-10-2001
 COMENTARIOS:	Geagan, el hijo del panadero.
 MODIFICACI�N:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("el joven Geagan","humano",12,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Geagan");
  SetIds(({"humano","geagan","Geagan","joven"}));
  SetShort("el joven Geagan");
  SetLong(W("Geagan es un muchacho muy robusto, sin duda por ayudar "
  	"a su padre en la panader�a. Tiene los brazos como el hierro "
  	"de cargar sacos de harina y cubos con agua. A�n as� tiene "
  	"una mirada amable que parece haber heredado de su madre. En "
  	"la cara le asoma un proyecto de barba que le hace parecer un "
  	"poco m�s mayor de lo que es.\n"));
  AddSubDetail(({"brazo","brazos"}),W("Sus brazos son dos aut�nticas "
  	"joyas de la anatom�a.\n"));
  AddSubDetail(({"barba"}),W("Bueno... si a eso se le puede llamar barba... "
  	"si... algo tiene.\n"));

  AddQuestion(({"panaderia","panader�a","horno"}),W("Geagan te dice: La panader�a de mi "
  	"padre la hered� de mi abuelo, y alg�n d�a la heredar� yo. Espero "
  	"poder llevarla con la misma eficacia que mis padres, por eso trabajo duro.\n"),1);
  AddQuestion(({"padre",",papa","pap�","jens","Jens"}),W("Geagan te dice: Mi padre, el "
  	"panadero, se llama Jens. Es el mejor padre que pod�a tener, y "
  	"nunca me ha tratado injustamente. Si yo le ayudo no es solo "
  	"porque tenga que hacerlo, sino porque disfruto aprendiendo el "
  	"oficio con �l. Es muy paciente y ense�a muy bien.\n"),1);
  AddQuestion(({"madre","mama","mam�","jynad","Jynad"}),W("Geagan te dice: Mi madre es "
  	"Jynad. Ella se encarga de la venta del pan, porque se le da muy "
  	"bien eso de hablar con la gente. Es muy lista, y creo que empieza "
  	"a sospechar cosas de mi. Pero si no me ha dicho nada es que le "
  	"parece bien, as� que no me preocupo.\n"),1);
  AddQuestion(({"adwel","Adwel"}),W("Geagan se sonrroja por momentos...\n"
  	"Geagan te dice: �Por qu� me preguntas sobre ella?... ya dec�a yo... a estas "
  	"alturas debe saberlo todo Koek. Pues... como explicarlo... esto... "
  	"Adwel es la hija del carnicero. Desde que �ramos peque�os jug�bamos "
  	"juntos, hasta que hace alg�n tiempo nos dimos cuenta de que est�bamos "
  	"enamorados. Quiero casarme con ella cuando pueda mantener a mi futura "
  	"familia. Es la chica m�s bonita e inteligente del lugar... es todo para mi.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Geagan te dice: Koek es el mejor lugar para vivir. Yo nac� aqu�, y aqu� he encontrado "
	"lo m�s importante de mi vida; mis padres, y bueno... algo m�s...\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Geagan te dice: No me gusta ese sitio... dicen que hay gente que entra en �l y nunca "
	"vuelve... quiz�s por eso el templo cierra su entrada. Tiene algo misterioso.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W("Geagan te dice: El templo es un lugar "
  	"enorme, y para mantener a todos sus monjes nos compran mucho pan. M�s de "
	"una vez me ha tocado ir a llev�rselo, as� que algo lo he visto. La verdad "
	"es que por dentro es muy bonito.\n"),1);
  AddQuestion(({"pan","hogaza","hogaza de pan","panes","hogazas de pan"}),W("Geagan te dice: El "
  	"pan que hace mi adre es famoso, solo espero poder hacerlo igual de bien "
  	"o incluso mejor cuando herede la panader�a, supongo que es el mejor regalo "
  	"que les podr�a hacer.\n"),1);
  InitChats(10,({"Geagan se ajusta las botas.\n",
  		 "Geagan mira con disimulo.\n",
		 "Geagan se rasca la barbilla.\n",
		 "Geagan silba.\n"}));
  InitAChats(10,({"[54mGeagan dice: ��C�mo te atreves?![0m\n"}));
}
