/***************************************************************************************
 ARCHIVO:	barin.c
 AUTOR:		[z] Zomax
 FECHA:		18-04-2003
 COMENTARIOS:	Barin, el basurero
 MODIFICACIÓN:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 		11-05-2003 Corregido Typo.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Barin el basurero","humano",10,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Barin");
  SetIds(({"humano","barin","Barin","basurero"}));
  SetShort("Barin el basurero");
  SetLong(W("Barin es el basurero del pueblo. Es un hombre un tanto mayor con la piel "
  	"seca y dura que se ocupa de mantener Koek limpio. Los habitantes de Koek le "
  	"suelen dar sus cosas viejas e inservibles y él se ocupa de destruirlas "
  	"de forma ecológica. No parece muy fuerte pero es muy trabajador.\n"));
  AddQuestion(({"basura"}),W("Barin te dice: Dame lo que quieras tirar y me ocuparé de "
  	"que no te moleste más.\n"),1);
  InitChats(5,({"Barin dice: ¡Basurero!, ¡El basurero!.\n",
  		"Barin dice: Si quieres deshacerte de algo dámelo y no lo volverás a ver.\n",
		"Barin dice: ¿Algo pesado en tus bolsillos que no quieras tener? Dámelo.\n",
		"Barin dice: Recojo cosas inservibles para reciclarlas. Dame lo que no quieras.\n"}));
  InitAChats(5,({"Barin grita: [52m ¡Guardias! ¡Guardias![0m.\n"}));
}

init(){
  ::init();

  add_action("fdar","dar");
}

public int fdar(string str)
{
	string cosa,quien, desc;
	object ob;


	if (str) lower_case(str);
	else return 0;
	if (sscanf(str,"%s a %s", cosa,quien) != 2) return 0;
	if (!ob = present(cosa,TP)) return 0;
	else if (TO->id(quien))
	{
		desc = (ob->QueryShort() || ob->QueryName());
       if (ob->QueryEquipped() == TP || ob->QueryEquipped() == TP)
		{
		  return notify_fail("No puedes dar cosas ni puestas ni empuñadas.\n",
		                     NOTIFY_NOT_VALID);
       }
		if (living(ob))
       {
         write("Barin te dice: Pero bueno... ¿Te crees que voy a tirar " +
               desc + " a la basura?\n");
         say("Barin le dice a " + CAP(TNAME) + ": Pero "
             "bueno. ¿Te crees que voy a tirar " + desc + " a la basura?\n");
         return 1;
       }
       write(W("Le das "+ desc +" a Barin que lo guarda enseguida en la basura.\n"));
		say(W(CATP+" le da "+present(cosa,TP)->QueryShort()+" a Barin que lo guarda enseguida en la basura.\n"),TP);
		present(cosa,TP)->remove();
		return 1;
	}
    return 0;
}

public void notify_enter(mixed from,int method,mixed extra)
{
  if (!PO) return;
  call_out("borrar_objeto",1,PO);
}

void borrar_objeto(object ob)
{
  string desc;
  if (!ob) return;
  desc = (ob->QueryShort() || ob->QueryName());
  if (living(ob))
  {
    write("Barin te dice: Pero bueno... ¿Te crees que voy a tirar " +
             desc + " a la basura?\n");
    say("Barin le dice a " + CATP + ": Pero "
           "bueno. ¿Te crees que voy a tirar " + desc + " a la basura?\n"),TP;
    tell_room(environment(),"Barin suelta " + desc + ".\n");
    ob->move(environment());
    return;
  }
  tell_room(environment(),"Barin guarda " + desc + "en la basura.\n");
  if (ob) destruct(ob);
}
