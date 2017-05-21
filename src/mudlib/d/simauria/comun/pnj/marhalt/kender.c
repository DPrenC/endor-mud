/* Un jodio kender para la posada de Nandor.
 *
 * (c) Nemesis 1997.
 * Revisado por Nemesis para que no fuera demasiado basto.
 * Modificaciones:
 *   Jul'2001 [n] Repasado para que hiciera lo que debe.
 *                Ahora responde a un mogollón de comandos de maneras
 *                diversas, que era lo que se pretendía. Aún así, hay
 *                cosas que no funcionan, pero estoy en ello...
 *   NO FUNCIONAN:
 *      why_did() (No entra)
 *	say_hi() (No entra)
 *	gives() (va sólo un poco)
 *      follow() (ni entra)
 *      second_life() (no va)
 *
 */

#include <properties.h>
#include <moving.h>
#include <rooms.h>
#include <equipment.h>
#include <npc.h>
#include <messages.h>

inherit NPC;

object harry;

create() {
  string *chats, *achats, *funs, *type, *match;
  ::create();
  chats = ({
 "Al dice: '¿Qué haces por aquí?'\n"
,"Al dice: '¡Mira, un mono de tres cabezas!'\n"
,"Al dice: 'No me gusta el invierno.'\n"
,"Al dice: 'No me gusta la nieve.'\n"
,"Al dice: 'No me gusta la lluvia.'\n"
,"Al dice: '¿Cómo te llamas?'\n"
,"Al dice: '¿Has visto algo interesante por ahí?'\n"
,"Al dice: 'Mmmm... ¡Llevas un montón de cosas interesantes! ¿Me das alguna?'\n"
,"Al sonríe.\n"
,"Al ve algo brillante en el suelo y lo recoge.\n"
          });
  achats = ({
 "Al dice: '¡No me pegues!'\n"
,"Al dice: '¡Ay! ¡Eso duele!'\n"
,"Al dice: '¡Ayudadme!'\n"
,"Al dice: '¡Abusón! ¡Métete con uno de tu tamaño!'\n"
,"Al dice: '¡Auch!'\n"
,"Al dice: '¡Odio a los que pegan a los pequeños!'\n"
,"Al dice: '¡Bastardo!'\n"
,"Al dice: '¡Mala bestia!'\n"
           });
/*  funs = ({ "why_did", 0     , 0          , 0      , 0
          , "smiles"  , "say_hi" , "test_say", 0
          , "follow" , "gives"
         });
*/
  funs = ({ "why_did", "why_did", "why_did", "why_did", "why_did"
          , "smiles"  , "say_hi" , "test_say", 0
          , "follow" , "gives"
         });
  type = ({ "vende", "ataca a", "se convierte"     , "coge", "tira"
          , "sonríe"  , "llega", "dice:"   , "te dice:"
          , "se va en dirección" , "te"
         });
  match = ({ ""     , ""       , "en una estatua.", ""      , ""
           , ""     , "del"    , ""         , ""
           , ""       , "da"
          });

  SetStandard("al","kender",11,GENDER_MALE);
  SetShort("Al el kender");
    SetGoChance(5);
  InitChats(2, chats);
  SetAttribute("MagicDefense",6);
  InitAChats(20,chats);
  InitMatch(funs,
           type,
		   match);
  CallOut("pick_any_obj", random(200)+1);
  CallOut("drop_any_obj", random(400)+1);
}

#if 0
heart_beat() {
  ::heart_beat();
  if (random(100) <= 20) pick_any_obj();
  if (random(100) <= 10) drop_any_obj();
}
#endif

// Parece que rula
pick_any_obj() {
  object ob, *inv;
  mixed rc;
  string sh;

  if (!environment(TO)) return;

  if (PO == TO)
  {
    while(RemoveCallout("pick_any_obj") >= 0);
    CallOut("pick_any_obj", random(200)+1);
  }

  inv = all_inventory(environment(TO));
  inv -= ({ TO })+filter(inv, SF(interactive));
  if (!sizeof(inv))
    return;
  ob = inv[0];
  sh = ob->Short() || "algo";
  rc = DropTake("coger", ob);
  if (!ob)
    return;
  if (!sizeof(rc)) {
    tell_room(environment(TP), ({ MSG_SEE, capitalize(QueryName())+" intenta coger "+sh+" pero no le gusta.\n"}), ({ TP }));
    return;
  }

  command("equipar "+sh);

}

// Creo que rula
valid_drop_item(object ob)
{
  return ob->QueryCreator()!=object_name(TO);
}

// Rula, o eso parece...
drop_any_obj() {
  string sh;
  object ob, *inv;
  mixed rc;

  if (!environment(TO))
    return;

  if (PO == TO)
  {
    while(RemoveCallout("drop_any_obj") >= 0);
    CallOut("drop_any_obj", random(400)+1);
  }

  if (!sizeof(inv = filter(all_inventory(),SF(valid_drop_item))))
    return;

  ob = inv[0];
  sh = ob->Short() || "algo";
  rc = DropTake("tirar", ob, PUTGET_REALLY);
  if (!ob)
    return;
  if (!sizeof(rc)) {
    tell_room(environment(TP), ({ MSG_SEE, capitalize(QueryName())+" va a tirar "+sh+" pero le parece algo curioso y se lo queda.\n"}), ({ TP }));
    return;
  }
}

// No va
why_did(str) {
  string who, what;
  if (strlen(str) && str[<1] == '\n')
    str = str[0..<2];
  sscanf(str, "%s %s", who, what);
  if(who == "al" || who == "Al") return;
  if (sscanf(str, "%s vende %s.", who, what) == 2)
    notify("Al dice: ¿Por qué vendes " + what + "? ¡Yo lo quería!\n");
  if (sscanf(str, "%s ataca a %s.", who, what) == 2)
    notify("Al dice: ¿Por qué " + who + " ataca a " + what + "?\n");
  if (sscanf(str, "%s se convierte en una estatua.", who) == 1)
    notify("Al dice: ¿Por qué " + who + " abandonó el mundo?\n");
  if (sscanf(str, "%s coge %s.", who, what) == 2)
    notify("Al dice: ¿Por qué " + who + " cogió " + what + "? ¡Lo quería coger yo!\n");
  if (sscanf(str, "%s tira %s.", who, what) == 2)
    notify("Al dice: ¿Por qué " + who + " dejó " + what + " ? ¡Es taaan curioso!\n");
}

notify2(str) {
  if (!(TP)) {return;}
  if (environment(TP))
    tell_room(environment(TP), str, ({ TP }));
  write(str);
}

notify(str) {
  call_out("notify2", 1, str);
}

// Va bien
smiles(str) {
  string who, what;
  sscanf(str, "%s %s", who, what);
  if(who == "al" || who == "Al") return;
  if (sscanf(str, "%s sonríe", who) == 1 && who != "Al")
    notify("Al sonríe con cara de felicidad.\n");
}

// No va
say_hi(str) {
  string who, what;
  if (strlen(str) && str[<1] == '\n')
    str = str[0..<2];
  if (sscanf(str, "%s llega del%s", who, what) == 2)
    notify( "Al dice: '¡Hola, " + who + ", encantado de verte!'\n");
}

// Va de PM
test_say(str) {
  string a, b, message;

  sscanf(str, "%s %s", a, b);
  if(a == "al" || a == "Al") return;
  if (strlen(str) && str[<1] == '\n')
    str = str[0..<2];
  if (!sscanf(str, "%s dice: '%s'", a, b) == 2) return;
  str = b;

  if (str == "hola" || str == "holas" || str == "hola a todos")
    message = "Al dice: '¡Encantado de verte!'\n";

  if ( (str == "callate") || (str == "cállate"))
    message = "Al dice: '¿Por qué quieres que me calle?'\n";

  if (sscanf(str, "%squedate aqui%s", a, b) == 2 ||
      sscanf(str, "%squédate aquí%s", a, b) == 2 ||
      sscanf(str, "%squedate aquí%s", a, b) == 2 ||
      sscanf(str, "%squédate aqui%s", a, b) == 2 ||
      sscanf(str, "%sno me sigas%s", a, b) == 2 ||
      sscanf(str, "%spierdete%s", a, b) == 2 ||
      sscanf(str, "%spiérdete%s", a, b) == 2)
    message = "Al dice: 'Vale, no te pongas así.'\n";

  if (!message)  message = "Al dice: '¿¿¿Qué significa: '" + str + "'???'\n";

  notify(message);
}

// No tira
follow(str) {
  string who, where;
  if (strlen(str) && str[<1] == '\n')
    str = str[0..<2];
  if (sscanf(str, "%s se va en dirección %s.", who, where) == 2)
  {
    notify(who+"\n");
    notify(where+"\n");
    call_out("_follow", 0, where);
  }
}

_follow(where) { command_me (where); }

// Va, aunque sea un poco...
gives(str) {
  string who, what, whom, tmp;
  int rand;
  object obj, next_obj;

  if (strlen(str) && str[<1] == '\n')
    str = str[0..<2];
  if(sscanf(str, "%s te da %s.", who, what) != 2) return;

  if(
     what == "vodka" || what == "ginebra" ||
     what == "cerveza" || what == "una botella" ||
     (sscanf(what, "una botella %s.", tmp) == 1) // el sscanf no va
    ) {
       notify(who+"\n");
       notify(what+"\n");
    switch(random(4)) {
    case 0:
      if (random(10) > 6) {
        notify("Al baja la cabeza y dice: 'Supongo que ahora vas a matarme...'\n");
        DropTake("tirar", "todo");
        command_me("sur");
      }
      break;
    case 1:
      notify("Al dice: '¡Muchas gracias! ¡Me lo beberé ahora mismo!'\n");
      command_me("beber " + what);
      break;
    case 2:
	// Rula...
	  notify("Al dice: '¡Puaj! ¡Qué asco! ¡Es de garrafón!'\n");
	  DropTake("tirar", what);
      break;
    case 3:
      notify("Al dice: 'Gracias, pero ya tengo bebida.'\n");
      GivePut("dar", what, lower_case(who));
      break;
    }
  }
  else if (sscanf(what, "el cadáver de %s.", tmp) == 1)
  {
    notify("Al dice: '¡Hey, entierra tus propios muertos, capullo!'\n");
    GivePut("dar", "cadáver a", lower_case(who));
  }
  else notify("Al dice: 'Muchas gracias, ¡esto sí es interesante!'\n");
}

// Curiosamente, no parece ir...
second_life() {
  object *inv;

  inv = filter_objects(all_inventory(TO), "id", "botella");
  if (sizeof(inv)) {
    filter_objects(inv, "remove");
    notify(
        "Al caer el cuerpo de Al, oyes un ruido de cristales rotos.\n");
  }
  return 0;
}

init()
{
 ::init();
 add_action("ask_about","ask");
}
