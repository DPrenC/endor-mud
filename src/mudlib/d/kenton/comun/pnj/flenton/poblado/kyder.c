/***************************************************************************************
 ARCHIVO:	kyder.c
 AUTOR:		[z] Zomax
 FECHA:		22-04-2003
 COMENTARIOS:	Kyder el maestro ladron humano.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

public string fmanuscrito()
{
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (quest && member(quest,"libro") && quest["libro",0]==4)
		quest+=(["libro":5]);
	if (quest && member(quest,"libro") && quest["libro",0]==5)
	{
		return W("Kyder te dice: Vaya, ¿y has hecho este largo camino para preguntarme "
		"sobre algo tan antiguo?. La verdad es que nunca me gustó... lo heredé de mi "
		"padre, el mejor ladrón que Koek ha visto. Él decía que valía una fortuna pero "
		"la verdad es que es imposible venderlo porque enseguida se darían cuenta los "
		"maestros del templo y entonces sí que tendría problemas serios... no veas "
		"lo que pegan esas fieras... la única y última vez que entré al templo a robar "
		"salí muy escarmentado. El caso es que siempre lo llevaba encima... hasta ese "
		"día. Curiosamente se me cayó en la biblioteca del templo, ¿te lo puedes creer?, "
		"todo este tiempo que lo llevan buscando y lo tienen en sus narices... bueno, "
		"en sus piés, pero se lo tienen merecido por ser tan antipáticos... El caso es "
		"que como ya me han llegado rumores de que has sido buen"+AO+" con mis aprendices "
		"te diré donde está: justo en la biblioteca hay una gran estantería, detrás de "
		"ella hay un hueco donde me escondí malherido, allí debe estar. Para "
		"mover la estanteria busca un ladrillo suelto cerca de ella.\n\nEn fin, eso es todo "
		"lo que podía decirte, espero que te sirva de ayuda... y ¡recuerda!, ¡si ves a mis "
		"chicos diles que en unas semanitas estoy de vuelta!.\n");
	}
	else return "Kyder se encoge de hombros.\n";
}

create(){
  ::create();
  SetStandard("Kyder","humano",10,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(50);
  SetAggressive(0);
  SetName("Kyder");
  SetIds(({"humano","kyder","Kyder","maestro","ladron"}));
  SetShort("Kyder el ladrón");
  SetLong(W("Briek es un humano, un maestro ladrón vestido de negro que intenta "
  	"aprender todo lo que puede en Kenton. Su larga figura te parece de lo más "
  	"extraña para su edad, como si fuera de goma. Parece muy ágil, quizás por "
  	"eso es un reconocido ladrón de Koek\n"));
  AddQuestion(({"lemas","briek","rakon","dwyer","aprendices"}),W("Kyder te dice: "
  	"¡Vaya!, ¡Así que conoces a mis chavales!, ¿Qué tal lo están haciendo?.\n"),1);
  AddQuestion(({"koek","rhoemas","Koek","Rhoemas"}),W("Kyder te dice: ¿Cómo has sabido "
  	"que soy de allí?, veo que mi fama me precede...\n"),1);

  AddQuestion(({"manuscrito"}),SF(fmanuscrito),1);
}
