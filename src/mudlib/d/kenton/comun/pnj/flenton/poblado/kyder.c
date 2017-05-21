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
		return W("Kyder te dice: Vaya, �y has hecho este largo camino para preguntarme "
		"sobre algo tan antiguo?. La verdad es que nunca me gust�... lo hered� de mi "
		"padre, el mejor ladr�n que Koek ha visto. �l dec�a que val�a una fortuna pero "
		"la verdad es que es imposible venderlo porque enseguida se dar�an cuenta los "
		"maestros del templo y entonces s� que tendr�a problemas serios... no veas "
		"lo que pegan esas fieras... la �nica y �ltima vez que entr� al templo a robar "
		"sal� muy escarmentado. El caso es que siempre lo llevaba encima... hasta ese "
		"d�a. Curiosamente se me cay� en la biblioteca del templo, �te lo puedes creer?, "
		"todo este tiempo que lo llevan buscando y lo tienen en sus narices... bueno, "
		"en sus pi�s, pero se lo tienen merecido por ser tan antip�ticos... El caso es "
		"que como ya me han llegado rumores de que has sido buen"+AO+" con mis aprendices "
		"te dir� donde est�: justo en la biblioteca hay una gran estanter�a, detr�s de "
		"ella hay un hueco donde me escond� malherido, all� debe estar. Para "
		"mover la estanteria busca un ladrillo suelto cerca de ella.\n\nEn fin, eso es todo "
		"lo que pod�a decirte, espero que te sirva de ayuda... y �recuerda!, �si ves a mis "
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
  SetShort("Kyder el ladr�n");
  SetLong(W("Briek es un humano, un maestro ladr�n vestido de negro que intenta "
  	"aprender todo lo que puede en Kenton. Su larga figura te parece de lo m�s "
  	"extra�a para su edad, como si fuera de goma. Parece muy �gil, quiz�s por "
  	"eso es un reconocido ladr�n de Koek\n"));
  AddQuestion(({"lemas","briek","rakon","dwyer","aprendices"}),W("Kyder te dice: "
  	"�Vaya!, �As� que conoces a mis chavales!, �Qu� tal lo est�n haciendo?.\n"),1);
  AddQuestion(({"koek","rhoemas","Koek","Rhoemas"}),W("Kyder te dice: �C�mo has sabido "
  	"que soy de all�?, veo que mi fama me precede...\n"),1);

  AddQuestion(({"manuscrito"}),SF(fmanuscrito),1);
}
