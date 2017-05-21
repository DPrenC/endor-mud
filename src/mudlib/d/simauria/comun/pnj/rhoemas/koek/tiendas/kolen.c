/***************************************************************************************
 ARCHIVO:	kolen.c
 AUTOR:		[z] Zomax
 FECHA:		14-12-2001
 COMENTARIOS:	Kolen, el herrero.
 MODIFICACIÓN:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 		28-04-2003 Añado AddQuestions y funciones para un quest.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

public string fpunyal(void)
{
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (quest && member(quest,"punyal"))
	{
		if (quest["punyal",0]==0)
		{
			quest+=(["punyal":1]);
			return W("Kolen te dice: Si, podría forjarte un puñal idéntico "
			"pero no es barato que digamos, ¿sabes?, si hicieras algo por "
			"mi... algo como facilitarme cierto material... más concretamente "
			"una pieza de metal rectangular de dos palmos de larga, uno de "
			"ancha y dos dedos de gruesa de mithril para forjar a partir de "
			"eso la espada de mi vida. Si me traes eso el puñal es tuyo, "
			"es muy fácil de forjar. Tengo entendido que los pescadores "
			"de la taberna pescaron hace tiempo algo que podría ser lo que "
			"busco, por si te sirve de algo.\n");
		}
		else return "Kolen se encoge de hombros.\n";
	}
	else return "Kolen se encoge de hombros.\n";
}

create(){
  ::create();
  SetStandard("Kolen el herrero","humano",15,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Kolen");
  SetIds(({"humano","kolen","Kolen"}));
  Set(P_CANT_LURE,1);
  SetShort("Kolen el herrero");
  SetLong(W("Kolen es el herrero del pueblo. Es un humano de mediana edad muy "
  	"robusto y de mirada solitaria. Tiene unos brazos anchos como los pilares "
  	"del templo y una espalda que parece un orco de lo ancha que es.\n"));

  AddSubDetail(({"brazo","brazos"}),"Eso son brazos y lo demás tonterías.\n");
  AddSubDetail(({"espalda"}),"Mas que una espalda parecen dos personas juntas.\n");
  AddQuestion(({"herreria","herrería"}),W("Kolen te dice: La herrería está muy bien, pero me "
  	"ocupa todo el tiempo... aún no he podido encontrar a mi media naranja.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Kolen te dice: Koek es un lugar estupendo para hacer negocios.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Kolen te dice: Um... no trae nada bueno... aléjate de él.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W("Kolen te dice: El templo de Seri-Solderteg "
  	"es la residencia de los monjes, y donde se entrenan y rinden culto a su "
  	"Diosa. Gracias a él tengo el negocio repleto siempre. Recibo encargos de "
  	"todos.\n"),1);
  AddQuestion(({"encargo","encargos"}),W("Kolen te dice: Se puede decir que todas las cosas de metal "
  	"que hay en este valle las he fabricado yo, modestia aparte.\n"),1);
  AddQuestion(({"puñal","punyal","puñal ceremonial","punyal ceremonial"}),SF(fpunyal),1);
  AddItem(RHOEARM("koek/varios/delantal"),REFRESH_REMOVE,SF(wearme));
}
