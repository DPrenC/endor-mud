/*
DESCRIPCION  : troll a la entrada del edificio de suministros
FICHERO      : /d/limbo/comun/pnj/troll.c
MODIFICACION : 20-09-98 [Angor@Siamuria] Creacion.
               10-10-99 [Woo] Toqueteado...
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <config.h>     //por el QUESTMASTER
#include <messages.h>

inherit NPC;

#define AO      (TP->QueryGenderEndString())
#define NOMBRE  (capitalize(TP->QueryName()))

create() {
  ::create();
 SetStandard("Nuk","troll",20,GENDER_MALE);
  SetShort("Nuk el troll");
  SetLong(
"Nuk es un troll joven y algo inexperto. Por su vestimenta, poco frecuente en "
"un troll, sabes que es uno de los siervos de los dioses en la isla Limbo. "
"Está sentado en los escalones que conducen al edificio de los siervos y por "
"sus gestos dirias que esta preocupado. Tal vez deberias preguntarle acerca de su "
"problema para saber que le pasa. Quizás puedas ayudarle.\n");

  SetIds(({"troll","siervo","Nuk","nuk"}));
  SetAds(({"un","siervo","joven","inexperto"}));
  SetAlign(-200);
  SetAC(3);
  SetNoGet("Nuk te dice: 'No molestes, no ves que tengo problemas'.\n");
  SetAggressive(0);

  AddQuestion(({"angor"}),
  "Angor es un dios que suele trabajar en esta isla. No es un mal tipo aunque "
  "tiene sus pequeñas manias. Hoy no lo he visto aun por aquí.\n");

  AddQuestion(({"lio","problema","preocupacion"}),
"Sabes, tengo un grave problema que no se como solucionar. Ayer por la noche, el "
"propio Asthar me encargo que cuidara el templo ya que el celador habitual, "
"estaba de viaje. Era una gran oportunidad para demostrar mi valia, pero como la "
"noche avanzaba y no pasaba nada, decidí ir un rato a pescar a la playa de "
"Levante. Hace un rato me he dado cuenta de que pescando debi perder las llaves "
"del templo de Asthar. Como se entere me mata, pero ahora anda por aquí y no "
"puedo dejar mi puesto e ir a buscarlas. No se que hacer...\n");

  AddQuestion(({"playa","playa de levante","playa de Levante","playa levante"}),
"La playa de Levante es el lugar donde fui a pescar y por tanto allí debi perder "
"las llaves del templo. La playa se encuentra al nordeste de la isla Limbo.\n");

  AddQuestion(({"llaves","llaves del templo"}),
"Las llaves del templo son tres llaves de tamaño mediano hechas de plata. Cada "
"una tiene incrustada en su cabeza una gema de gran valor y las tres se hallan "
"engarzadas en una argolla de oro.\n");
Set(P_CANT_FIGHT,1);
Set(P_CANT_STEAL,1);
}

init() {
  ::init();
  //add_action("matar_cmd","matar");
  add_action("dar_cmd", "dar");
}

int matar_cmd(string str){
  object who;
  int hp;

  who=TP;
  if (present(str, environment(who)) != TO) return 0;

  who->StopHunting(TO);

  write(
   "Golpeas a Nuk en la cabeza, pero el troll sigue absorto en sus problemas y no "
   "reacciona. Repites el golpe y ocurre lo mismo. No merece la pena seguir atacando "
   "a un troll que no tiene intención de luchar y además es lo suficientemente "
   "resistente como para que tu te agotes antes de llegar a hacerle un daño grave.\n");

   tell_room(environment(TP), ({ MSG_SEE,
  NOMBRE+" ataca a Nuk, pero este ni reacciona ni parece haber recibido mucho "
  "danyo. "+NOMBRE+" ataca de nuevo y Nuk, mas preocupado de sus problemas que de otra "
  "cosa tampoco reacciona. "+NOMBRE+" desiste de un ataque inútil.\n"}), ({ TP }));

  return 1;
}

int dar_cmd(string str) {
 object from, key;
 string a, b, Quests;
 from=TP;
 if (!from || !str) return 0;
 if ((sscanf(str,"%s a troll",a)==1)||
     (sscanf(str,"%s a Nuk",a)==1)||
     (sscanf(str,"%s a nuk",a)==1)) {
    object ob;
    ob  =  present(a,TP);
    if (!ob || !call_other(ob,"id","llaves_templo")) return 0;

    write("Nuk mira las llaves del templo que le acabas de dar y sin poder contenerse te "
          "abraza con fuerza al tiempo que exclama sollozando: 'Gracias "+NOMBRE+", gracias. "
          "Me has salvado y no se como agradecertelo...'. Nuk corre hacia el templo para "
          "devolver las llaves, volviendo poco después. Piensas en como vas a quitarte de "
          "encima el olor después del largo achuchón que te ha dado este troll...\n");

   tell_room(environment(TP), ({ MSG_SEE,
   NOMBRE+" da unas llaves a Nuk y éste, agradecido y sollozante le proporciona un "
  "largo y agradecido achuchón. Nuk corre hacia el templo, volviendo poco después.\n"}), ({ TP }));

    ob->remove();
    Quests=from->QueryQuests();
    if (!Quests) Quests="hallo";
    if (sscanf(Quests,"%slaves_templo_Astha%s",a,b)!=2) {
    write("Acabas de resolver el quest de las llaves del templo de Asthar.\n");
    QUESTMASTER->InformSolution("Nuk ha recuperado las llaves del templo de Asthar gracias a "+NOMBRE);
    QUESTMASTER->SetPlayerQuest("llaves_templo_Asthar",TP);
    }
    return 1;
   }
   return 0;
}
