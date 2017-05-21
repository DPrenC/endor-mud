/**
 * SIMAURIA '/std/thing/moving.c'
 */

#include <config.h>
#include <moving.h>
#include <properties.h>
#include <messages.h>

public mixed Query(string pn);
public mixed Set(string pn, mixed arg);

//--- global variables ------------------------------------------------------

private static object *pFollowers;
private mixed pNoFollow, pNoGet, pNoDrop, pNoGive;

//--- object following ------------------------------------------------------

public object *QueryFollowers()         { return pFollowers||({}); }
public varargs object *SetFollowers(object *fs, int modosigue)
{
  if (sizeof(fs))
  {
    map_objects(fs, "Set", P_IS_FOLLOWER, modosigue||FOLLOW_ALWAYS);
    map_objects(fs, "Set", P_IS_FOLLOWING, TO);
  }
  return pFollowers = sizeof(fs) ? fs : 0;
}

public varargs object *AddFollower(object f, int modosigue) {
  if (TO == f) raise_error("Llamado 'AddFollower()' sobre sí mismo.\n");
  if (f)
  {
    f->Set(P_IS_FOLLOWER, modosigue || FOLLOW_ALWAYS);
    f->Set(P_IS_FOLLOWING, TO);
  }
  return pFollowers ?
    (member(pFollowers, f) < 0 ? pFollowers += ({ f }) : pFollowers)
    : pFollowers = ({ f });
}

// Esto no debe devolver 0, pues eso representaria q la funcion no ha hecho
// nada o q no existe...
public int RemoveFollower(object ob)
{
    if (!pFollowers || !sizeof(pFollowers) || !sizeof(pFollowers -= ({ ob })))
    {
        pFollowers = 0;
    }
    if (ob && ob->Query(P_IS_FOLLOWING) == TO)
    {
		ob->Set(P_IS_FOLLOWER, 0);
    	ob->Set(P_IS_FOLLOWING, 0);
    	return 1;
    }
    return -1;
}

//--- follow, give, get and drop preventation -------------------------------

public mixed QueryNoFollow()    { return pNoFollow; }
public mixed QueryNoDrop()      { return pNoDrop; }
public mixed QueryNoGet()       { return pNoGet || query_once_interactive(TO); }
public mixed QueryNoTake()      { return QueryNoGet(); }
public mixed QueryNoGive()      { return pNoGive; }

public mixed SetNoFollow(mixed i) { return pNoFollow = i; }
public mixed SetNoDrop(mixed i)   { return pNoDrop = i; }
public mixed SetNoGet(mixed i)    { return pNoGet = i; }
public mixed SetNoTake(mixed i)   { return SetNoGet(i); }
public mixed SetNoGive(mixed i)   { return pNoGive = i; }

//---------------------------------------------------------------------------
// int move(string|object dest, void|int method, void|mixed extra)
//
// Move this object into <dest> using given <method> (default is M_SILENT).
// <extra> may contain additional information for the preventation and
// notification.
// Return ME_OK if the move was successful, else an error code.
// Before moving this object, the old environment will be asked for permission
// by:
//
//   old_env->prevent_leave(dest, method, extra)
//
// which may return a code != 0 if leaving is not allowed (this code will then
// be returned by move()).
// Second, the new environment will be asked with:
//
//   new_env->allow_enter(method, extra)
//
// which may return a code != ME_OK if entering is not allowed. If an object
// does not define a allow_enter() function, then moving objects into it will
// not be allowed because a return value of 0 is the standard ME_NO_ENTER
// error code.
// After a successful move, the old environment and the new one will be notifed
// by:
//
//   old_env->notify_leave(new_env, method, extra)
//   new_env->notify_enter(old_env, method, extra)
//
// The notification functions can then give out moving messages or update
// light and weight etc.
// If all this has been performed, all followers (if any) will also be notifed
// of the move.
//---------------------------------------------------------------------------

public varargs int move(mixed dest, int method, mixed extra) {
  mixed err1, err2;
  object oldenv;

  switch(method) {
    case M_GET:
      if (pNoGet) return ME_NO_GET;
      break;
    case M_DROP:
      if (pNoDrop) return ME_NO_DROP;
      break;
    case M_GIVE:
      if (pNoGive) return ME_NO_GIVE;
      break;
  }
  oldenv = environment();
  if(M_NOCHECK != method) { // In all other cases ask for permissions.

    // Ask if we perhaps are not allowed to leave the current environment.
    // We do not want to catch an error because we have not yet moved the
    // object and so no inconsistency can occur. Just let the error happen
    // so we can fix it. We still can escape with a M_NOCHECK move
    // if we are a player (and somebody helps us).

    if(environment() && (err1 = (int)environment()->prevent_leave(dest, method, extra)))
      return err1;

    // Check for permission to enter the new environment. We also do not
    // need to catch an error for the same we reason we did not when asking
    // for permission to leave. Just let the error happen.

    if((err1 = (int)dest->allow_enter(method, extra)) != ME_OK)
      return err1 || ME_NO_ENTER;

    if(!TO) return ME_DESTRUCTED_SELF; // Have we been destructed?
  }

  // if we come to this point everything seams to be o.k. for moving.
  // We also do not want to catch an error for the same reasons as
  // above. Just let it happen.

  move_object(TO, dest);
  //Nyh esto es pa el esconderse...
  TO->ResetSeenBy();
  // We now want to notify the environments of the successful move so they
  // can update the weight etc. The problem here is that an error will
  // lead into inconsistency. Especially when notifying the old env we
  // still want to give the new env the chance to update. Therefore we
  // catch possible errors and send a error message.

  err1 = 0;
#if 0
  if(oldenv && dest != oldenv
  && (err1 = catch(oldenv->notify_leave(dest, method, extra))))
    MASTER->runtime_error("Error on calling " + to_string(oldenv) +
                          "->notify_leave(): " + err1,
                          __FILE__, object_name(), __LINE__);

  if(dest != oldenv
  && (err2 = catch(dest->notify_enter(oldenv, method, extra))))
    MASTER->runtime_error("Error on calling " + to_string(dest) +
                          "->notify_enter(): " + err2,
                          __FILE__, object_name(), __LINE__);

  if (err1 || err2)
    return ME_CAUGHT_ERR;
#else

  if (oldenv) oldenv->notify_leave(dest, method, extra);
  dest->notify_enter(oldenv, method, extra);
#endif

  // Now tell all our followers about it. Take care of recursions by using
  // an increment/decrement counter.
  if (pFollowers)
  {
    pNoFollow++;
    filter_objects(pFollowers, "follow", oldenv, dest, method, extra);
    pNoFollow--;
  }

  return ME_OK;
}

//--- deja de seguir --------------------------------------------------------
// si se le da ob solo deja de seguir a ob.
// si no se da ob, deja de seguir a quien sea.
public varargs int ResetFollow(object ob)
{
    if (!ob) ob = Query(P_IS_FOLLOWING);
    if (!ob || !ob->RemoveFollower(TO))
    {
		Set(P_IS_FOLLOWER, 0);
    	Set(P_IS_FOLLOWING, 0);
    }
    return 1;
}

//--- object following ------------------------------------------------------
//[Nyh] la modifico un poco
// This sigue a Prev...
public void follow(mixed from, mixed dest, int method, mixed extra) {
  int st;

  if (pNoFollow || environment(PO) == environment()) return;

  if (  (Query(P_IS_FOLLOWING) && Query(P_IS_FOLLOWING)!=PO)
      || environment() != from // Si no estabas junto a el, no le sigues
     )
  {
  	ResetFollow(PO);
  	return;
  }
  switch (Query(P_IS_FOLLOWER))
  { //pongo un case por si luego aumenta
   	case FOLLOW_NO:     ResetFollow(PO); break;
  	case FOLLOW_ALWAYS:
  	    // compruebo si This no es un living y si el method es M_SPECIAL
  	    // en cuyo caso el extra se modifica.
  	    if (method == M_SPECIAL && !living(TO) && pointerp(extra))
  	    {
  	      if (sizeof(extra) > 0 && extra[0] != "")
  	      {
  	        extra[0] = " se va siguiendo a " + CAP(NNAME(PO));
  	      }
  	      if (sizeof(extra) > 1 && extra[1] != "")
  	      {
  	        extra[1] = "llega en pos de " + CAP(NNAME(PO));
  	      }
  	    }

  	    move(dest, method, extra);
  	    break;
  	case FOLLOW_NORMAL:
  	    if (!(method==M_TELEPORT || method==M_SPECIAL))
		{
		    if (living(TO) && TO->QueryTP() < 1)
		    {
		      TO->catch_msg("Estás demasiado cansad" + TO->QueryGenderEndString() + " para "
		                    "seguir a " + PO->QueryName() + ".\n");
		      if (living(PO))
		      {
		        tell_object(PO, TO->QueryName() + " está demasiado cansad" + TO->QueryGenderEndString() +
		        " para seguirte.\n");
		      }
		      return;
		    }
		    else if (living(TO) && (st = TO->QueryStatus()) == STATUS_SLEEPING || st == STATUS_RESTING)
		    // mientras se duerme o se descansa no puedes seguir a nadie
		    {
		      TO->catch_msg("Dejas que " + PO->QueryName() + " continúe su camino "
		                    "mientras sigues " + (st == STATUS_RESTING ? "descansando " :
		                                          "durmiendo ") + " tranquilamente.\n");
           if (living(PO))
           {
             tell_object(PO, "Dejas atrás a " + TO->QueryName() + ", que continúa " +
                         (st == STATUS_RESTING ? "descansando " : "durmiendo ") +
                         " tranquilamente.\n");
           }
           return;
         }

		    if (living(TO)) TO->AddTP(-1);
		    move(dest, method, extra);
		}
		else
		{
			if (living(TO)) TO->catch_msg("No puedes seguir a "+PO->QueryName()+" allí.\nDejas de seguir a "+PO->QueryName()+".\n");
			if (living(PO)) tell_object(PO,""+TO->QueryName()+" no te puede seguir hasta aquí.\n"+TO->QueryName()+" ha dejado de seguirte.\n");
			ResetFollow(PO);
		}
		break;
	default: move(dest, method, extra); //por defecto te mueve
  }
}

//---------------------------------------------------------------------------
// Cleanup handling:
//
// ref < 0: our environment calls us to clean up.
//   In each contained object call 'clean_up(-1)'. If after that no object
//   remains, self destruct, else return 1.
// ref = 0: we are a clone, or a blueprint with replaced program.
//   Selfdestruct if we have no environment(). On selfdestruct, call
//   'remove()' in contained objects, even on nested inventories.
// ref = 1: we are a swapped and/or unreferenced blueprint.
//   Do not selfdestruct if we have an environment.
//   Else call 'clean_up(-1)' in each contained object. If no object remains
//   after that, self destruct.
// ref > 1: we are a non-swapped blueprint in use.
//   Try again later.
// Objects carried by once interactive objects (players) aren't cleaned up.

public int clean_up(int ref) {
  mixed rc;
  if ((call_resolved(&rc, TO, "Query", P_CLEAN_UP) && !rc)
      || (environment() && query_once_interactive(environment()))
     )
    return 1;
  switch(ref) {
    case 0:
      if (environment()) return 1;
      filter_objects(deep_inventory(), "remove");
      break;
    case 1:
      if (environment()) return 1;
      /* FALL THROUGH */
    case -1:
      filter_objects(all_inventory(), "clean_up", -1);
      if (first_inventory()) return 1;
      break;
    default:
      return 1;
  }
  TO->remove();
  return TO && 1;
}
