/**
 * /obj/npc/guard.c
 *
 * Objeto a heredar para hacer guardias.
 * NOTA: Esto es una PLANTILLA que se añade al NPC base que hayas heredado
 *       Por si solo no es nada!
 * Su funcionamiento es básicamente interceptar los mensajes de combate que
 * recibe el guardia y actuar en consecuencia.
 *
 * 24-04-2008 - [Nyh] Creación
 */

#include <messages.h>

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

public int CanSeeObject(object ob);  // /std/living/perception
public string QueryCitizenship();    // /std/living/description
public varargs string QueryName(mixed m);// /std/living/description

public string QueryShort();          // /std/thing/description

public object *QueryEnemies();       // /std/living/combat
public void AddEnemies(object *e);   // /std/living/combat

public void RegisterMsgFun(string type, mixed funarg); // /std/living/perception

//-----------------------------------------------------------------------------

private mixed pGuardDefendMsg; // string o closure(defended)

//-----------------------------------------------------------------------------

public int QueryIsGuard() { return 1; }

public mixed QueryGuardDefendMsg()      { return pGuardDefendMsg; }
public mixed SetGuardDefendMsg(mixed d) { return pGuardDefendMsg = d; }

//-----------------------------------------------------------------------------

// Si from no existe cojo los enemigos de def
// Si def no existe pero from si pego a from
// Si no hay nada... me piro
// NOTA: Al llegar aqui puede que def ya haya muerto...
public varargs int Guard(object def, object *from) {
  if (!def && !sizeof(from)) return 0;
  
  if (sizeof(from)) { // Pego a from y ale
    from = filter( from
                 , (:   $1
                     && CanSeeObject($1)
                     && ($1->QueryCitizenship() != QueryCitizenship()) :));
  }
  else if (   def
           && present(def)
           && living(def)
           && CanSeeObject(def))
  { // cojo from de def
    from = filter( def->QueryEnemies() - QueryEnemies()
                    , (:   $1
                        && CanSeeObject($1)
                        && ($1->QueryCitizenship() != QueryCitizenship()) :));

  }

  if (sizeof(from)) {
    if (!QueryGuardDefendMsg())
    {
      tell_room(environment(), CAP(QueryName() || QueryShort() || "Alguien") 
            + " grita: ¡No me quedaré de brazos cruzados viendo pelear a " +
            (def->QueryName() || def->QueryShort() || "alguien") + "!\n",
             ({TO}) );
      tell_object(TO, "Gritas: ¡No me quedaré de brazos cruzados viendo pelear a " +
            (def->QueryName() || def->QueryShort() || "alguien") + "!\n");
    }
    else
    {
      if (stringp(QueryGuardDefendMsg())) {
        tell_room(environment(), QueryGuardDefendMsg());
        // ¿Ningun write?
      }
      else funcall(QueryGuardDefendMsg(), def); // y q la closure haga say y write
    }
    AddEnemies(from);
    return 1;
  }
  
  return 0; 
}

//-----------------------------------------------------------------------------

//static para q no me toquen la moral desde fuera
static void _guard_check(mixed msg, object obj) {
// ({ MSG_COMBAT,  COMBAT_TYPE,
//    COMBAT_ATK,  COMBAT_DEF,
//    COMBAT_VERB, COMBAT_WITH, COMBAT_DAM
//    COMBAT_WHAT, COMBAT_HOW })
  object def;
  object *from;
    
  // Si veo al objeto defensor y es de mi pueblo, y no tenemos ya los mismos
  // enemigos, le defiendo
  
  if (!(def = msg[COMBAT_DEF])) return;
  
  if (def == TO) return; // Q si no me auto defiendo, jajaja
  
  if (!CanSeeObject(def)) return;
    
  if (def->QueryCitizenship() != QueryCitizenship()) return;

  if (!sizeof(from = def->QueryEnemies() - QueryEnemies())) return;

  //El call_out es para q no sea instantaneo  
  call_out("Guard", 1, def, from);  
   
}

//-----------------------------------------------------------------------------

create() {
  if (clonep()) RegisterMsgFun(MSG_COMBAT, "_guard_check");
}