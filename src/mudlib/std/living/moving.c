/**
 * SIMAURIA '/std/living/moving.c'
 */

#include <properties.h>
#include <moving.h>
#include <rooms.h>
#include <door.h>
#include <sounds.h>

//--------------------------------------------------------------------------

inherit "/std/thing/moving";

//--------------------------------------------------------------------------

public int QueryStunned();                 // std/living/body
public int SetQuieroHuir(int i);           // std/living/body

public void CallOut(mixed fun, int delay, mixed arg1);
                                           // std/living/heart
public int RemoveCallout(mixed fun);       // std/living/heart

//[Nyh] las siguientes tres las meti yo (las dir son copiadas)
public int QueryLevel();        	   // std/living/description
public int QueryGuildLevel();        	   // ??std/living/description??
public int QueryDex();           	   // std/living/stats
public object *QueryEnemies();		   // std/living/combat
public int Fighting();			   // std/living/combat
public int AddXP(int xp);		   // std/?

#ifdef USE_HBHOOK
mixed SetHBHook(mixed data);               // std/living/heart
mixed QueryHBHook();                       // std/living/heart
#endif

//--------------------------------------------------------------------------

private nosave string lastexit;
private nosave int lastenvc;
private nosave int wimpy_move;

//--------------------------------------------------------------------------

public varargs int GoAway(int wimpygo) {
  mapping m;
  string *exits;
  int i, s, t;
  object lastenv;

  //dtell("nyh",sprintf("%O->GoAway(%O)\n",capitalize(TO->QueryName()), wimpygo));

  exits = ({});

  if( lastenv = environment() )  m = (mapping) environment()->QueryExits();
  if( !m || !sizeof( m ) )  return 0;
  exits = m_indices(m);
  wimpy_move = wimpygo;

  // Cambios para que el pnj no se de con las puertas a no ser que este cegato.
  exits -= filter(exits, (:   $2[$1, EXIT_DOOR]
                           && $2[$1, EXIT_DOOR]->QueryDoorState() == DOOR_CLOSED
                           && TO->CanSee():), m);

  if (   lastexit
      && member(exits, lastexit) >= 0
      && random(7) < (5-lastenvc)
      && command("ir " + lastexit)
     )
   {
    if (environment() == lastenv) lastenvc++;
    else lastenvc = 0;
    return 1;
   }

  m = (mapping) environment()->QueryExitsData();
  s = sizeof(exits);
  for (i = random(s), t = s; t--; i = (i + 1) % s) {
    if (command("ir " + exits[i])) {
      lastexit = exits[i];
      if (environment() == lastenv) lastenvc++;
      else lastenvc = 0;
      return 1;
    }
  }

  lastexit = 0;
  lastenvc = 0;
  return 0;
}

//--------------------------------------------------------------------------
// Nyh añade el int flags, no son flags apilables (al menos no de momento)
//flags en moving.h
public varargs void Whimpy(int flags) {
  int xp;

  SetQuieroHuir(0);
//  xp = QueryLevel()*2;
// [Nyh] a sugerencia de algunos players cambio el nivel de jugador por el nivel de gremio
  xp = QueryGuildLevel()*2;

  if ((flags & (WHIMPY_HB | WHIMPY_FORCE)) ) {
    if (QueryStunned()) {
      TO->catch_msg("No puedes huir estando aturdido.\n");
      return;
    }
    if (!GoAway(1)){ //if goa
      tell_object (TO,"Tus pies intentan huir contigo... pero no encuentran una salida.\n");
      if (!(flags & WHIMPY_FORCE)) {
        TO->catch_msg("Pierdes "+xp/2+" puntos de experiencia intentando huir.\n");
        AddXP(-xp/2);
      }
    }
    else {//else goa
      tell_object (TO, "Huyes del combate.\n");
      play_sound(TP, SND_SUCESOS("huir"));
      if (!(flags & WHIMPY_FORCE)) {
        TO->catch_msg("Pierdes "+xp+" puntos de experiencia por cobarde.\n");
        AddXP(-xp);
      }
    }
  }
  else {
    object *enemies;
    int stun, i, num;
    if ((enemies=QueryEnemies()) && (i=sizeof(enemies))) {
      num=0;
      for(;i--;) num+=enemies[i]->QueryDex();
      num=(i=(num-QueryDex())<25)?25:(i>90)?90:i;
      if (stun = QueryStunned()) {//if stun
        if ((random(100) > 30+stun*10) && !(random(100) > num)) i=0;
        else i=1;
      } //stun
      else { //else stun
        if (random(100)>num) i=1;
        else i=0;
      }
      if (i) { //if i
        if (!GoAway(1)){ //if goa
          tell_object (TO,"Tus pies intentan huir contigo... pero no encuentran una salida.\n"
    			  "Pierdes "+xp/2+" puntos de experiencia intentando huir.\n");
          AddXP(-xp/2);
        }
        else {//else goa
          play_sound(TP, SND_SUCESOS("huir"));
          tell_object (TO, "Huyes del combate.\nPierdes "+xp+" puntos de experiencia por cobarde.\n");
          AddXP(-xp);
        }
      } //cierro if i
      else {//else i
        tell_object (TO, "No consigues zafarte del combate.\n");
        tell_object (TO, "Pierdes "+xp/2+" puntos de experiencia intentando huir.\n");
        TO->AddXP(-xp/2);
      } //fin else i
    } //fin if enemies
    else { //if !enemies
      TO->catch_msg("Nadie te esta atacando.\n");
    }
  }
}

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Move
//--------------------------------------------------------------------------

// Tell the living that it entered the room (some NPCs might fubarily
// depend on this).

public varargs int move(mixed dest, int method, mixed extra) {
  int err;
  object env;

#ifdef USE_HBHOOK
  mixed hook;
#endif
//  dtell("nyh",sprintf("%O->move(%O, %O, %O)\n",capitalize(TO->QueryName()), dest, method, extra));
    if ( !wimpy_move && (method==M_GO || method==M_SILENT) )
    {
        if ( QueryStunned() ) return ME_NO_LEAVE;
        if ( environment() && Fighting() )
        {
            TO->catch_msg("¿Por qué no pruebas a HUIR?.\n");
            return ME_NO_LEAVE;
        }
    }

#ifdef USE_HBHOOK
  hook = QueryHBHook(); SetHBHook(0);
#endif

  wimpy_move  = 0;
  env = environment();
  err = moving::move(dest, method, extra);
  if(ME_OK != err) {
    if(err == ME_TOO_HEAVY)
      TO->catch_msg("Tienes demasiado peso para entrar en esa habitación.\n");
    if(err == ME_TOO_BIG)
      TO->catch_msg("Tienes demasiado volumen para entrar en esa habitación.\n");
    if(err == ME_TOO_MANY)
      TO->catch_msg("Hay demasiadas cosas en esa habitación como para que puedas entrar.\n");
#ifdef USE_HBHOOK
    if (hook) SetHBHook(hook);
#endif
    return err;
  }

  switch(method) {
  case M_SPECIAL:
  case M_TELEPORT:
    if (pointerp(extra) && sizeof(extra) > 2) extra = extra[2];
    if (stringp(extra)) TO->catch_msg(extra +".\n");
  case M_GO:
    TO->LookAfterMove(method, extra);
  }

  if (TO && interactive()) {
    TO->SetHomeTmp(object_name(environment(TO)));
  }

  return ME_OK;
}

//--------------------------------------------------------------------------

public int remove () {
  destruct (TO);
  //if (interactive()) TO->catch_msg("ADIOS.. ¡¡esperamos que vuelvas pronto!! :)\n");
  return 1;
}

//--------------------------------------------------------------------------
