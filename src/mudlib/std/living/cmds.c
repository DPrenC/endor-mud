/**
 * SIMAURIA '/std/living/cmds.c'
 */

#include <attributes.h>
#include <gremios.h>
#include <skills.h>
#include <actions.h>
#include <messages.h>
#include <config.h> // Para los notify_fail
#include <search.h>
#include "/secure/daemons.h"
#include "/secure/wizlevels.h"

#undef ENV
#define ENV  environment

#define NETDEAD  (!interactive() && query_once_interactive(TO))

// std/living/attributes

public varargs mixed QueryAttr(string aname, int sc);
public varargs mixed SetAttr(string aname, mixed value, int sc);

// std/living/moving
public void Whimpy();

// std/living/body
public int QueryStatusNormal();
public int QueryStatusResting();
public int QueryStatusSleeping();
public int QueryStatusTripped();
public int QueryStatusHelpless();
public int QueryDisabled();
public int QueryParalyzed();

// std/living/description
public string QueryName();
public int QueryGhost();
public int CanSeeObject(object ob);
public varargs mixed Search(mixed what, int mode);
public varargs mixed SearchM(mixed what, int mode, closure pred);

// std/living/combat
public int Fighting();
public int Kill(object ob);

// std/base
public mixed Query(string pn);
public mixed Set(string pn, mixed arg);
//--------------------------------------------------------------------------

protected void delata() {
  object ob;

  ob = this_object();

  if (Query(P_HIDDEN)) {
    Set(P_HIDDEN, 0);
    tell_object(ob,"Sales de entre las sombras.\n");
    tell_room(environment(ob),capitalize(QueryName())+" sale de entre las sombras.\n",({ob}));
    call_other(all_inventory(environment(ob))-({ ob }),"init");
  }
}

/*
Esta funcion se llama desde el master cada vez que un living quiere hacer
una accion...verb es el verbo y arg los argumentos.
Devuelve 0 si puede ejecutar la accion
Devuelve un string si no ejecuta la accion y ese string sera el error
si verb o arg son modificados se modifica la accion que se realiza...
*/
public string CheckAction(string verb, string arg) {
  if (Query(P_HIDDEN) && ACTION_IS_HIDDEN(verb)) delata();

  if (ACTION_IS_NOT(verb)) return 0;

  if (IS_LEARNER(TO) && !(TO->Query(P_NOWIZ))) return 0;

  if (QueryDisabled())
    return "No puedes hacer eso estando inconsciente.\n";
  if (QueryParalyzed())
    return "No puedes hacer eso estando inmovilizado.\n";
  if (QueryStatusSleeping() && !ACTION_IS_SLEEPING(verb))
    return "Estás durmiendo.\n";
  if (QueryStatusResting() && !ACTION_IS_RESTING(verb))
    return "Estás descansando.\n";

  return 0;
}

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
//si flag=0 se esconde
//si flag=1 se esconde DESPUES de un sigilo (gasta menos mana)
//el arr es para ver quien te puede ver, vacio=todos
static varargs int fhide(mixed *arr, int flags) {
object o, ob, *all, *ven, *dejan;
int check, i;

  ob=TP;

  if (ob->HasSkill(HAB_ESCONDERSE) == -1) return notify_fail("No posees la habilidad 'esconderse'.\n");

  if (Fighting()) return notify_fail("No puedes esconderte mientras peleas!\n");
  if (ob->Query(P_HIDDEN)>0 && !flags) {
      write("Sales de tu escondite.\n");
      tell_room(environment(ob),capitalize(ob->QueryName())+" sale de entre las sombras.\n",({ob}));
      ob->Set(P_HIDDEN,0);
      return 1;
  }

  if (flags) i=5; //coste de mana
  else i=2;    //coste de mana
  if ( ob->QuerySP()<i ) return notify_fail("No tienes suficientes puntos de mana.\n");
  ob->AddSP(-i);

  check=ob->UseSkill(HAB_ESCONDERSE,ob->QueryGuildLevel());
  ven = dejan = ({});
  if (check > 0) {
    if (pointerp(arr)) all=filter(arr-({ob}),SF(living));
    else all=filter(all_inventory(environment(ob))-({ob}),SF(living));
    for (i=sizeof(all);i--;) {
      o=all[i];
      if ( (o->QueryInt()+o->QueryLevel())>check ) {
        if (IS_LEARNER(o) || member(o->Query(P_ALLOW_SHADOW)||({}),ob)>-1) {
          dejan += ({o});
//          ob->AddSeenBy(o); //lo pongo luego
        }
        else ven += ({o});
      } //if
    } //for
    if (sizeof(ven)) {
      say(capitalize(ob->QueryName())+" intenta esconderse, pero no lo consigue.\n");
      write(flags?"No consigues volver a esconderte bajo la atenta vigilancia de "+capitalize(ven[random(sizeof(ven))]->QueryName())+".\n"
              :"No consigues esconderte bajo la atenta vigilancia de "+capitalize(ven[random(sizeof(ven))]->QueryName())+".\n");
      ob->Set(P_HIDDEN,0);
      ob->Set(P_SEEN_BY,({}));
    }
    else {
      map(dejan,SF(tell_object),"Permites que disimuladamente "+capitalize(ob->QueryName())+" se esconda entre las sombras.\n");
      write(flags?"Continuas escondido en las sombras.\n":"Te escondes entre las sombras.\n");
      ob->Set(P_HIDDEN,check);
      ob->Set(P_SEEN_BY,dejan);
    }
  }
  else {
     write(flags?"Continuas escondido en las sombras.\n":"Te escondes entre las sombras.\n");
     map(all||({}),SF(tell_object),capitalize(ob->QueryName())+" intenta esconderse entre las sombras, pero no lo consigue.\n");
     ob->Set(P_HIDDEN,0);
     ob->Set(P_SEEN_BY,({}));
  }
  return 1;
}



//--------------------------------------------------------------------------

// Llamada al bind
public int bind(string str) { return BIND->bin_cmd(str); }

//--------------------------------------------------------------------------

public void add_living_cmds () {
  add_action("fhide",  "esconderse");

  add_action("bind","",2);    // [k] Demonio de binarios
}

/****************************************************************************/
