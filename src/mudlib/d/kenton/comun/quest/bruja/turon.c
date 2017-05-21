/*
DESCRIPCION : el pescador turón
FICHERO     : /d/kenton/comun/quest/bruja/turon.c
MODIFICACION: 20-9-00 [Maler] Creacion
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <living.h>
#include <combat.h>
inherit NPC;
string QueryLong()
{
string a,b,Quests;
Quests=TP->QueryQuests();

        if (!Quests) Quests="hallo";
		if (sscanf(Quests,"%slariton_quest_bruj%s",a,b)!=2)
		{return "Ves a Turon, un kender un tanto raro, al contrario que los demás"+
		" kenders, lo ves apagado, y triste..., por lo demás es normal..., bajito..., "+
		"algo regordete de cabello rojizo. Supones que tiene algún problema porque no es normal "+
		"ver a un Kender triste.\n";}
		else
		{return "Ves a Turon, el pescador. Después de que le ayudaras parece muy feliz.\n";
		}
}





init() {

  ::init();

  add_action("dar_cmd","dar");

}

int dar_cmd(string str) {

object from;

int num;

string a, b, Quests;
object ob;
from=TP;

if ((sscanf(str,"%s a turon",a)==1)||

		        (sscanf(str,"%s a Turon",a)==1)||

		        (sscanf(str,"%s a pescador",a)==1))

		        {

   if (!from || !str) return 0;

        Quests=from->QueryQuests();

        if (!Quests) Quests="hallo";

        	        ob  =  present(a,TP);

				        if (!ob) return notify_fail("Tu no tienes "+a+".\n",NOTIFY_NOT_VALID)&&0;

if (member(ob->QueryIds(), "quest_bota_bruja")!=-1)

		           {

		           ob->remove();

		   			write("Turón dice: Gracias querido amigo...!!!\n");
		   			write(
	                   "Turón da un salto, te besa en la frente y ves como se pone a amarrar la bota en su caña de pesca. "
	                   "Te quedas pensando si todo ha sido un sueño, pero habrías podido jurar que Turón te había "
					   "prometido dinero. Para que luego te fies de Kenders que se dedican a pescar con botas...!!! "
					   "Por otro lado, piensas y te alegras porque al final ha valido la pena el haber podido ayudar a "
					   "Yasmín..., a Tamara y a Altur...\n");


						if (sscanf(Quests,"%slariton_quest_bruj%s",a,b)!=2)

					           {
								  write("\nAcabas de resolver el quest de la bota perdida de Turon.\n\n");

						           CHMASTER->SendMsg("info", "Turon ha dado con su bota gracias a "+TP->QueryName());
						           QUESTMASTER->SetPlayerQuest("klariton_quest_bruja",TP);
								}


 }
    else

        {


        write(W("Turón te mira, y dice: gracias, pero lo que yo quiero es mi bota, de todas formas "
				"gracias por intentar animarme.\n"));
		return 0;

        }




     return 1;

     }

  return 0;

}
create() {
  ::create();
SetStandard("Turón","kender",10,GENDER_MALE);
SetShort("Turón, el pescador");
SetLong(W(QueryLong()));
SetIds(({"turón","turon","pescador"}));
AddQuestion(({"busqueda","problema","alteracion","preocupacion"}),
   W("Turon reacciona, te mira rápidamente y te dice sin casi respirar:\n"
   "Por favor..., por favor..., POR FAVOOOOR...!!! Ayúdame "
   "a encontrar mi bota, es una bota normal..., una bota... mi bota... "
   "la usaba para pescar..., para pescar peces, claro..., sabes donde "
   "puede estar...???, lo sabes...???, me podrías ayudar a encontrarla...??? "
   "Te recompensaré... si siiiii... te recompensaré muy... muy... ay no...!!! "
   "mucho... mucho dinero... si... dinero si encuentras mi bota...!!!, necesito mi bota para pescar peces...!!!\n"));
AddQuestion(({"bota","Bota"}),
   "Turón dice: Es una bota normal, tiene mi nombre grabado, tiene que estar por aquí.\n");
set_heart_beat(1);
}

private int Es_Pc(object mon)
     {
       if(mon->QueryIsPlayer())
         return 1;
        return 0;
     }
void heart_beat()
{
string a,b,Quests;
int i;
object *npcs;
::heart_beat();
        npcs =
     filter(deep_inventory(environment(TO)),SF(Es_Pc));
        if(sizeof(npcs))
          for(i=0;i<sizeof(npcs);i++)
		  {
Quests=npcs[i]->QueryQuests();

        if (!Quests) Quests="hallo";
		if (sscanf(Quests,"%slariton_quest_bruj%s",a,b)!=2)
{
switch(random(25))
{
case 0:tell_object(npcs[i],"Turón dice: ¿Donde estás?\n");break;
case 1:tell_object(npcs[i],"Turón dice: ¿Has visto mi bota?\n");break;
default:break;
}
}
}
}
