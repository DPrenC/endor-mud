/***************************************************************************************
 ARCHIVO:	geagan.c
 AUTOR:		[z] Zomax
 FECHA:		24-10-2001
 COMENTARIOS:	Geagan, el hijo del panadero.
 MODIFICACIÓN:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
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
  	"a su padre en la panadería. Tiene los brazos como el hierro "
  	"de cargar sacos de harina y cubos con agua. Aún así tiene "
  	"una mirada amable que parece haber heredado de su madre. En "
  	"la cara le asoma un proyecto de barba que le hace parecer un "
  	"poco más mayor de lo que es.\n"));
  AddSubDetail(({"brazo","brazos"}),W("Sus brazos son dos auténticas "
  	"joyas de la anatomía.\n"));
  AddSubDetail(({"barba"}),W("Bueno... si a eso se le puede llamar barba... "
  	"si... algo tiene.\n"));

  AddQuestion(({"panaderia","panadería","horno"}),W("Geagan te dice: La panadería de mi "
  	"padre la heredó de mi abuelo, y algún día la heredaré yo. Espero "
  	"poder llevarla con la misma eficacia que mis padres, por eso trabajo duro.\n"),1);
  AddQuestion(({"padre",",papa","papá","jens","Jens"}),W("Geagan te dice: Mi padre, el "
  	"panadero, se llama Jens. Es el mejor padre que podía tener, y "
  	"nunca me ha tratado injustamente. Si yo le ayudo no es solo "
  	"porque tenga que hacerlo, sino porque disfruto aprendiendo el "
  	"oficio con él. Es muy paciente y enseña muy bien.\n"),1);
  AddQuestion(({"madre","mama","mamá","jynad","Jynad"}),W("Geagan te dice: Mi madre es "
  	"Jynad. Ella se encarga de la venta del pan, porque se le da muy "
  	"bien eso de hablar con la gente. Es muy lista, y creo que empieza "
  	"a sospechar cosas de mi. Pero si no me ha dicho nada es que le "
  	"parece bien, así que no me preocupo.\n"),1);
  AddQuestion(({"adwel","Adwel"}),W("Geagan se sonrroja por momentos...\n"
  	"Geagan te dice: ¿Por qué me preguntas sobre ella?... ya decía yo... a estas "
  	"alturas debe saberlo todo Koek. Pues... como explicarlo... esto... "
  	"Adwel es la hija del carnicero. Desde que éramos pequeños jugábamos "
  	"juntos, hasta que hace algún tiempo nos dimos cuenta de que estábamos "
  	"enamorados. Quiero casarme con ella cuando pueda mantener a mi futura "
  	"familia. Es la chica más bonita e inteligente del lugar... es todo para mi.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Geagan te dice: Koek es el mejor lugar para vivir. Yo nací aquí, y aquí he encontrado "
	"lo más importante de mi vida; mis padres, y bueno... algo más...\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Geagan te dice: No me gusta ese sitio... dicen que hay gente que entra en él y nunca "
	"vuelve... quizás por eso el templo cierra su entrada. Tiene algo misterioso.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W("Geagan te dice: El templo es un lugar "
  	"enorme, y para mantener a todos sus monjes nos compran mucho pan. Más de "
	"una vez me ha tocado ir a llevárselo, así que algo lo he visto. La verdad "
	"es que por dentro es muy bonito.\n"),1);
  AddQuestion(({"pan","hogaza","hogaza de pan","panes","hogazas de pan"}),W("Geagan te dice: El "
  	"pan que hace mi adre es famoso, solo espero poder hacerlo igual de bien "
  	"o incluso mejor cuando herede la panadería, supongo que es el mejor regalo "
  	"que les podría hacer.\n"),1);
  InitChats(10,({"Geagan se ajusta las botas.\n",
  		 "Geagan mira con disimulo.\n",
		 "Geagan se rasca la barbilla.\n",
		 "Geagan silba.\n"}));
  InitAChats(10,({"[54mGeagan dice: ¡¿Cómo te atreves?![0m\n"}));
}
