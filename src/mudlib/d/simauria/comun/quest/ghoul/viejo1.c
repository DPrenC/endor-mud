/* Viejo para la plaza de Nandor
   (c) Nemesis 1997
   Pnj esencial para el quest del ghoul
   De momento esta en la plaza del pueblo,
   pero en breve (cuando dejemos de estar
   en pruebas) estara en el Ayuntamiento

   [woo] He quitado el remove.. que daba un error siempre
         que alguien hacia el quest y he puesto acentos
   [Nem] Yo te mato, Woo... en fin, arreglao lo del remove
         de manera DEFINITIVA
   [Nem] "Arreglado" un bug por el que sí se podían tener
         varias cabezas.
   [Nem] Castellanizado. (Oct'02)
   [Nem] Ahora hará una pequeña comprobación antes de dar
         el quest por resuelto.

   13-06-03 [Nem] Convertido a SetStandard(), incluyendo lo de GC_LUCHADOR
                   porque al fin y al cabo fue guerrero en su día.
   14-07-04 [kastwey: modificado para que acepte la cabeza, y añadido
          un call_out para que reaccione al segundo de dársela, y aparezca antes el mensaje de:
          le das una cabeza de ghoul a Gulkas, que la frase del quest resuelto y demás.
16/01/2005: [kastwey]: retoco algo de código y pongo para que solo hable del quest a los que no lo tienen hechos
y que también, además de resopnder solo a las preguntas de un player, distinga entre quien lo tenga hecho y quien no.
*/

#include "path.h"
#include <gremios.h>
#include <skills.h>
#include <properties.h>
#include <size.h>
#include <combat.h>

inherit NPC;

string preguntar_quest();
string preguntar_criatura();
string dialogo();

create()
{
    ::create();
    SetStandard("Gulkas","humano",([GC_LUCHADOR: 13]),GENDER_MALE);
    SetShort("Gulkas");
    SetLong(
    "Es un anciano de cara amable, bigote blanco y boina calada. Te da la sensación "
    "de que es un poco rudo, pero buena persona. Quizá le puedas preguntar sobre algun "
    "gremio, ya que lleva colgada en el cuello una antigua insignia.\n");
    AddId(({"anciano", "viejo"}));
    SetAds(({"un","afable","simpatico","rudo"}));
  AddQuestion(({"gremios","gremio"}),
    "Gulkas dice: 'Son poderosas asociaciones. Si quieres ser algo en la vida debes "
    "unirte a uno de ellos. Están distribuidos por todo el mundo. En mis tiempos "
    "yo pertenecía al de Guerreros, pero ahora ya valgo para poco.'\n",1);
    AddQuestion(({"problema", "ayuda", "quest", "maldicion", "maldición"}),
    SF(preguntar_quest),1);
    AddQuestion(({"criatura","criatura malefica","criatura maléfica"}),SF(preguntar_criatura),1);
    AddQuestion(({"guerreros", "gremio de guerreros"}),
    "Gulkas te dice: ' Si lo que quieres es una vida dedicada a la guerra y cubrirte "
    "de gloria en las batallas, los guerreros son sin duda tu gremio.\n Aquí en "
    "Nandor tienes el cuartel general del gremio, donde puedes obtener más "
    "información.'\n", 1);
    InitChats(4, ({ SF(dialogo) }) );
    InitAChats(10,({
    "Gulkas gruñe: '¡Qué juventud! ¡En mis tiempos te ibas a enterar! ¡Gamberro!'\n",
    "Gulkas grita: ¡no sabes con quien te estás metiendo!\n"}));
    SetCitizenship("nandor");
}

void destroy_cabeza()
{
  object cab;
  if (cab=present("k_beza")) cab->remove();
  if (cab) destruct(cab);
}


void notify_enter(mixed from,int method,mixed extra)
{
  object p;
  p = PO;
  call_out("comprueba_cabeza",1,p);
}

void comprueba_cabeza(object p)
{
  if (member(p->QueryIds(),"k_beza") >= 0)
  {
    if(p->QueryOwner() != TP->QueryRealName())
    // Si el poseedor de la cabeza no es su propietario (se la ha robado seguro
    // porque ya se añadió una acción para que solo se le pudiese dar la cabeza a gulkas).
    {
      tell_object(TP,
        "Gulkas mira la cabeza de imitación que le has traído, te echa una mirada de odio y la tira lejos...\n");
      say("Gulkas mira la cabeza de imitación que le ha traído " + TP->QueryName() + ", le echa una mirada de odio y la tira lejos...\n",TP);
      write_file(LOGS"GHOULCHEATERS",ctime(time())+TP->QueryRealName()+" ["+
        TP->QueryLevel()+"]   Ha intentado hacer trampas robándole la cabeza del ghoul a "+p->QueryOwner()+".\n");
      destroy_cabeza();
      tell_object(TP,W("Un trueno resuena sobre tu cabeza y te cae un rallo. "
        "Parece que los dioses están enfadados por algo...\n"));
      TP->Defend (TP->QueryHP() - 1, DT_ELECTRO, DEFEND_F_NOLIV);
      return;
    }
    else if(p->QueryOwner() != p->QueryGhoulKiller())
    // El GhoulKiller lo ha matado, y el listillo del Owner se la cortó...
    // Mal asunto...
    {
      tell_object(TP,
        "Gulkas mira la cabeza de imitación que le has traído, te echa una mirada de odio y la tira lejos...\n");
      say(W("Gulkas mira la cabeza de imitación que le ha traído " + capitalize(TP->QueryName()) + ", le echa una mirada de odio y la tira lejos...\n"),TP);
      write_file (LOGS"GHOULCHEATERS",ctime(time())+TP->QueryRealName()+" ["+
        TP->QueryLevel()+"]   Ha intentado hacer trampas con ayuda de "+p->QueryGhoulKiller()+".\n");
      call_out("destroy_cabeza",1);
      if (p->QueryGhoulKiller() && find_object(lower_case(p->QueryGhoulKiller())))
      {
        tell_object(find_object(lower_case(p->QueryGhoulKiller())),"Un trueno resuena sobre tu cabeza y te cae\
          un rayo. Parece que los Dioses están enfadados por algo.\n");
        find_object(lower_case(p->QueryGhoulKiller()))->Defend (TP->QueryHP() - 1, DT_ELECTRO, DEFEND_F_NOLIV);
      }
      return;
    }
    if (QUESTMASTER->QueryQuestSolved("kill_ghoul", TP))
    {
      tell_object(TP,W("Gulkas mira la cabeza que le has dado y con cara seria te dice: " + capitalize(TP->QueryName()) + ". Todos sabemos que ya me trajiste la cabeza del ghoul como prueba de que habías acabado con él. No se a qué vienes con la cabeza de otro.\n"));
      say(W("Gulkas le dice algo a " + capitalize(TP->QueryName()) + ".\n"),TP);
      tell_room(environment(),"Gulkas tira lejos la cabeza.\n");
      write_file (LOGS "GHOULKILLERS",ctime(time())+TP->QueryRealName()+" ["+
        TP->QueryLevel()+"]   Ha matado al ghoul de Nandor otra vez.\n");
      destroy_cabeza();
    }
    else
    // no lo tiene resuelto, así que se le pone como tal
    {
      QUESTMASTER->SetPlayerQuest("kill_ghoul",TP);
      tell_object(TP,"Gulcas mira la cabeza que le has dado y exclama con alegría: ¡Mil gracias! ¡Nandor nunca te olvidará!\n");
      QUESTMASTER->InformSolution("¡¡Nandor estará eternamente agradecida a "+TP->QueryName()+"!!\n");
      destroy_cabeza();
      tell_object(TP,"¡Has liberado Nandor de la horrible maldición! Felicidades!\n");
      write_file (LOGS "GHOULQUEST",ctime(time())+" "+TP->QueryRealName()+" ["+
      TP->QueryLevel()+"]   Ha matado al ghoul de Nandor.\n");
      (TP->QueryGender()==2?TP->SetTitle("la liberadora de Nandor"):TP->SetTitle("el liberador de Nandor"));
      write_file (LOGS "GHOULKILLERS",ctime(time())+TP->QueryRealName()+" ["+
        TP->QueryLevel()+"]   Ha matado al ghoul de Nandor.\n");
    }
  }
}

string preguntar_quest()
{
	if (QUESTMASTER->QueryQuestSolved("kill_ghoul",TP))
	// lo tiene hecho así que le dirá otra cosa.
	{
		return W("Oh " + capitalize(TP->QueryName()) + ". Desde que acabaste con la criatura maléfica, Nandor vuelve a estar en paz. Te estaré eternamente agradecido.\n");
	}
	else
	{
		return W("Gulkas dice: '¡Oh! ¡¿Tú podrías ayudarnos?! El cementerio está poseído "
      "por una criatura maléfica que profana las tumbas y se come a nuestros muertos!\n");
  }
}

string preguntar_criatura()
{
	if (QUESTMASTER->QueryQuestSolved("kill_ghoul",TP))
	{
		// lo tiene hecho, as´ique responderá otra cosa
		return "Antes de que nos libraras de ella, la criatura maléfica rondaba por el cementerio de nandor, profanando nuestras tumbas y molestando a las pobres almas que descansan en éllas.\n";
	}
	else
	// no lo tiene hecho
	{
		return "Gulkas dice: 'Es una especie de muerto viviente. Quizá "
		       "deberías proveerte de armas de plata o algo así. Supongo que "
		       "con el material adecuado podrías decirle a un herrero que te "
		       "fabricase una. De todas maneras, si consigues matarlo, traeme "
		       "una prueba de tu hazaña. Tu valor sera recordado por todos... "
		       "siempre.'\n";
  }
}
string dialogo()
{
	if (!environment()) return "";
    foreach(object ob:all_inventory(environment()))
    {
        if (query_once_interactive(ob) && !QUESTMASTER->QueryQuestSolved("kill_ghoul", ob))
        {
            tell_object(ob,
                        "Gulkas dice: '¡Qué horrible maldición ha caído sobre nuestra pobre villa!\n¡Ojalá alguien nos ayudara!\n");
        }
    }
    return "";
}

public int QueryIsGulkas() { return 1; }
