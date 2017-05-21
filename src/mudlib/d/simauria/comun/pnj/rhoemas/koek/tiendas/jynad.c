/***************************************************************************************
 ARCHIVO:	jynad.c
 AUTOR:		[z] Zomax
 FECHA:		25-10-2001
 COMENTARIOS:	Jynad, la panadera.
 MODIFICACI�N:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Jynad la panadera","humano",10,GENERO_FEMENINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Jynad");
  SetIds(({"humana","jynad","Jynad","panadera"}));
  Set(P_CANT_LURE,1);
  SetShort("Jynad la panadera");
  SetLong(W("Jynad es una humana de aspecto agradable que como buena "
  	"comerciante sabe ganarse a sus clientes con una sonrisa nada "
  	"m�s entran a su tienda. Tiene una larga melena casta�a y ojos "
  	"verdes como los campos de trigo en primavera. Desde luego no es "
  	"joven, pero sin duda aparenta muchos menos a�os de los que se "
  	"supone que debe tener.\n"));

  AddSubDetail(({"melena","pelo"}),"Tiene una bonita melena casta�a.\n");
  AddSubDetail(({"ojo","ojos"}),W("Preciosos. Son los ojos m�s verdes y "
  	"cristalinos que has visto en tu vida.\n"));
  AddQuestion(({"panaderia","panader�a","horno"}),W("Jynad te dice: Mi marido hered� "
  	"el negocio de sus padres, es una panader�a muy bonita, y adem�s "
  	"tiene mucha fama en toda la regi�n. Yo le ayudo desde que nos "
  	"casamos, y mi hijo desde que sabe andar... creo que el secreto "
  	"de que funcione tan bien es que todos aportamos lo que podemos al negocio.\n"),1);
  AddQuestion(({"hijo","geagan","Geagan"}),W("Jynad te dice: Geagan es el hijo que toda "
  	"madre desear�a tener, es fuerte como un toro, pero a la vez sereno "
  	"y muy trabajador. Desde siempre ha ayudado en las tareas de la "
  	"panaderia y nunca se ha cansado. Pero mucho me temo que ya le "
  	"falte poco... se est� haciendo mayor y le veo como mira a Adwel, "
  	"la hija del carnicero... y ella tampoco est� normal cuando le "
  	"mira a �l... pero no me importa mucho, porque creo que es una "
  	"buena chica y ser�a una esposa perfecta para mi hijo.\n"),1);
  AddQuestion(({"marido","esposo","jens","Jens"}),W("Jynad te dice: Jens es mi marido. "
  	"Trabaja en el horno todo el d�a y es muy buena persona. la verdad "
  	"es que no creo que hubiera encontrado a alguien igual aunque estuviera "
  	"a�n busc�ndole. Desde que nos conocimos no ha habido un d�a en el "
  	"que no hemos sido felices.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Jynad te dice: Koek es un sitio maravilloso, lleno de comerciantes y campos y agua... "
	"es uno de los pueblos m�s pr�speros de la zona. Espero que sea as� para "
	"siempre.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Jynad te dice: Solo te dir� una cosa del bosque... ni se te ocurra entrar... se "
	"cuentan historias terribles de ese bosque. Si quieres saber m�s "
	"preg�ntale a Froeker, el pescador.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W(
	"Jynad te dice: El templo de Seri-Solderteg es algo misterioso... pero nos mantiene "
	"a todos atrayendo a visitantes que nos compran de todo, as� que no me "
	"hago muchas preguntas sobre �l. Me basta con saber que si no estuviera "
	"ninguno de nosostros estar�amos aqu�.\n"),1);
  AddQuestion(({"pan","hogaza","hogaza de pan","panes","hogazas de pan"}),W(
	"Jynad te dice: El pan de mi marido es el mejor de la regi�n. La verdad es que lo hace "
	"con mucho detenimiento usando siempre los mejores ingredientes, y como "
	"ayudaba a sus padres desde peque�o no le falta nada de pr�ctica.\n"),1);
  AddQuestion(({"adwel","Adwel"}),W("Jynad te dice: Es una muchacha muy bonita, la hija del "
  	"carnicero. Creo que mi hijo y ella se ven a escondidas, porque se "
  	"miran de la misma forma que nos mir�bamos mi marido y yo. Pero me "
  	"gusta como futura esposa de Geagan, as� que lo veo muy bien.\n"),1);
  AddQuestion(({"horario","abierto","cerrado","abrir","cerrar"}),W("Jynad te dice: "
	"Abrimos de 8 a 20 ininterrumpidamente.\n"),1);
  AddItem(RHOEARM("koek/varios/delantal"),REFRESH_REMOVE,SF(wearme));
}
