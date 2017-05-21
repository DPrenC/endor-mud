/*
DESCRIPCION  : Messur el viejo herbolario que ha perdido el amuleto (quest)
FICHERO      : /d/akallab/comun/quest/amuleto/messur.c
MODIFICACION : 13-02-99 [Angor@Simauria]Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <properties.h> //por el PSIZE
#include <living.h>     //por el GENDER
#include <config.h>     //por el QUESTMASTER
#include <colours.h>
#include <messages.h>
inherit NPC;
inherit "/lib/money";


int tieneDinero(int n);

create() {
  ::create();
 SetName("Messur");
  SetShort("Messur, el herbolario");
  SetLong(
     "Messur es un orco muy anciano de carater ausente. Los pequenyos "
       "anteojos que lleva para compensar su ya mermada vision se deslizan "
       "una y otra vez por su nariz y el se pasa el dia subiendoselos de "
       "nuevo. Presta mas atencion a las hierbas que esta clasificando o "
       "a las diversas pociones que prepara que a los clientes que acuden "
       "a su local. Parece preocupado.\n");

  SetRace("orco");
  SetGender(GENDER_MALE);
  SetWeight(55000);
  SetGoChance(0);
  SetAlign(-100);
  SetAC(1);
  SetMaxHP(100);
  SetHP(100);
  SetLevel(6);
  SetStr(10);
  SetDex(4);
  SetCon(10);
  SetInt(5);
  SetIds(({"messur","Messur","herbolario","viejo","orco"}));

  InitChats(15,({
    "Messur se sube los pequenyos anteojos de nuevo.\n",
    "Messur pregunta a su ayudante: Seguro que no has visto mi amuleto?\n",
    "Messur te pregunta: Has visto mi amuleto? Lo he perdido y no se donde esta. "
    "Si alguien me ayudara alguna vez...'\n",
    "Messur rebusca entre unas cajas y luego se encoje de hombros.\n",
    "El viejo Messur te observa por un momento y luego vuelve a su trabajo.\n",
   }) );

  AddQuestion(({"amuleto","colgante"}),
    "\nMessur te dice: Ahh... mi querido amuleto... He perdido mi "
      "amuleto de la suerte y no soy capaz de encontrarlo. He rebuscado "
      "en toda la tienda y no aparece. No es que tenga gran valor, pero "
      "llevo toda la vida con el y estaria dispuesto a recompensar a quien "
      "lo recupere. Seguramente debi perderlo el otro dia cuando fui al "
      "bosque a recoger hierbas.\n");

  AddQuestion(({"bosque"}),
    "\nSuelo ir al bosque que hay al nordeste del valle a recoger distintas "
      "hierbas para mis pociones. Supongo que es alli donde debi perder mi "
      "amuleto de la suerte.\n");

  AddQuestion(({"pociones","hierbas"}),
    "\nSi quieres, se venden en este local.\n");

  AddQuestion(({"recompensa"}),
    "\nSi recuperas mi amuleto te dare varias pociones curativas como "
      "recompensa, lo prometo. Quiero recuperar mi amuleto cuanto antes.\n");

}

init() {
  ::init();
  add_action("dar_cmd","dar");
}


int dar_cmd(string str) {
object from, ob, ob2, lista;
int num;
string a, b, Quests;

 from=TP;
 if (!from || !str) return 0;
 if ((sscanf(str,"%s a herbolario",a)==1)||
     (sscanf(str,"%s a messur",a)==1)||
     (sscanf(str,"%s a Messur",a)==1))
     {
     ob  =  present(a,TP);
     if (!ob) return notify_fail("Tu no tienes "+a+".\n",NOTIFY_NOT_VALID)&&0;

     if (member(ob->QueryIds(),"amu_quest_05")!=-1)
        {
        ob->remove();
        write("El viejo Messur se sube los anteojos y mira ensimismado lo "
                "que le acabas de dar. Luego te abraza efusivamente y dice: "
                "Muchas gracias por recuperar mi querido amuleto. Donde lo "
                "encontraste? Seguro que el algun rincon del bosque...\nTras "
                "ponerse de nuevo el amuleto en el cuello, Messur te dice: lo "
                "prometido es deuda. Toma tu recompensa.\nMessur te da dos "
                "pociones curativas.\n");
        tell_room(TO, ({ MSG_SEE, "Messur le da dos pociones a "+NOMBRE+" como recompensa por su ayuda.\n" }), ({ TP }));
        ob2=clone_object(POCION("pocion_curativa"));
        ob2->move(TP);
        ob2=clone_object(POCION("pocion_curativa"));
        ob2->move(TP);

        Quests=from->QueryQuests();
        if (!Quests) Quests="hallo";
        if (sscanf(Quests,"%smuleto_perdido_messu%s",a,b)!=2)
           {
           write("\nAcabas de resolver el quest del amuleto perdido de Messur.\n\n");
           QUESTMASTER->InformSolution("El viejo herbolario Messur ha recuperado su amuleto "
                "perdido gracias a "+NOMBRE);
           QUESTMASTER->SetPlayerQuest("amuleto_perdido_messur",TP);
           }
        }
     else
        {
        ob->Remove();
        write("El viejo Messur se sube los anteojos y mira ensimismado lo "
                "que le acabas de dar. Luego te dice: Gracias por el regalo.\n ");
        }

     return 1;
     }
  return 0;
}

