/*
DESCRIPCION : un cerrojo (standard). Continene la mecanica basica para
              mantener algo cerrado (closed) o cerrado con llave (locked)
FICHERO     : /std/lock
MODIFICACION:
  10-Jun-93  [Mateese]
  10-Aug-94  [Mateese] Added some utility functions.
  2000-03-11 [Angor]   - Primera traduccion
                       - modificadas varias funciones
                       - comentadas las llamadas a strip_article
*/

#include <config.h>
#include <properties.h>
#include <lock.h>
#include <search.h>
#include <classes.h>
#include <messages.h>

//------------------------------------------------------------------------------

public varargs mixed Query(string name); // from /std/base
public varargs string Short(string what);    // from /std/thing/description

//------------------------------------------------------------------------------

private string *pKeyIds;
private mixed pKeyCode;
private int pState;
private int pPickchance = 100;

//------------------------------------------------------------------------------

public string *SetKeyIds (mixed id) {
  if (id)
    TO->AddClassAdj(CA_LOCKABLE);
  else
    TO->RemoveClassAdj(CA_LOCKABLE);
  pKeyIds = id ? (pointerp(id) ? id : ({ id })) : 0;
  if (pKeyIds)
  {
    pKeyIds -= ({ "", 0 });
    if (!sizeof(pKeyIds))
      pKeyIds = 0;
  }
  return pKeyIds;
}
public string *QueryKeyIds () { return pKeyIds; }

//[a] modificada
public int SetLockState (int state) {
  mixed texte;
  if (TO->QueryGender()==GENDER_FEMALE)
       //texte = ({ "open", "closed", ({ "locked", "closed" }) });
       texte = ({ "abierta", "cerrada", ({ "locked", "closed" }) });
  else texte = ({ "abierto", "cerrado", ({ "locked", "closed" }) });
  TO->RemoveAdjective(texte[pState]);
  TO->AddAdjective(texte[state]);
  return pState = state;
}
public int QueryLockState ()        { return pState; }

//[a] modificada
public string LockStateText()
{
if (TO->QueryGender()==GENDER_FEMALE)
   return ({ "abierta", "cerrada", "cerrada con llave" })[QueryLockState()];
else
   return ({ "abierto", "cerrado", "cerrado con llave" })[QueryLockState()];
  //return ({ "open", "closed", "locked" })[QueryLockState()];
}

public mixed SetKeyCode (mixed c) { return pKeyCode = c; }
public mixed QueryKeyCode () { return pKeyCode; }

public int SetPickChance (int i) { return pPickchance = i; }
public int QueryPickChance () { return pPickchance; }

/*-------------------------------------------------------------------------*/
// Filter stub for _filter_key().
// Return true if the <idstr> matches for <key>.

static int _filter_keyids (string idstr, object key) {
  return (int) key->id(idstr);
}

/*-------------------------------------------------------------------------*/
// int ValidKey (object key)
//
// Return true if the <key> has one of the defined pKeyIds.

public int ValidKey (object key) {
  return sizeof(filter (pKeyIds, SF(_filter_keyids), key)) != 0;
}

/*-------------------------------------------------------------------------*/
// mixed TurnLock (int unlock, object key, void | mixed keycode)
//
// Lock (unlock == 0) or unlock (unlock != 1) this lock with the
// given <key> using the given <keycode>.
// The keycode defaults to that of the key.
// If this function changes the state of the lock, it does this
// by calling SetLockState().
// Results:
//   0 = LOCK_OK      : locking successful
//       LOCK_NOCHANGE: lock was already (un)locked.
//       LOCK_NOTLOCK : lock is not lockable (i.e.: is open)
//       LOCK_KEYWRONG: key doesn't fit
//       LOCK_KEYDENY : key denies operation
//       <string>     : Denial message from the key.

public varargs mixed TurnLock (int unlock, object key, mixed keycode) {
  mixed rc;
  int state;
  state = unlock ? LOCK_CLOSED : LOCK_LOCKED;
  if (!pKeyIds || pState == LOCK_OPEN)
    return LOCK_NOTLOCK;
  if (!keycode) keycode = (mixed) key->Query(P_KEYCODE);
  if (pKeyCode != keycode || !ValidKey(key))
    return LOCK_KEYWRONG;
  if (!(rc = key->Query(unlock ? P_NOUNLOCK : P_NOLOCK))) {
    if (pState == state)
      return LOCK_NOCHANGE;
    SetLockState (state);
  }
  else if (!stringp(rc))
    rc = LOCK_KEYDENY;
  return rc;
}

/*-------------------------------------------------------------------------*/
// object *FindKey (mixed key)
//
// Search in the players inventory for objects which match <key> and are
// valid keys according to pKeyIds.
// Result:
//   An array of the found valid key objects, empty if no key fit.
//   0 if 'key' could not be found at all.

public object *FindKey (mixed key) {
  object *rc;
  rc = (object *) TP->Search(key, SEARCH_INV);
  return sizeof(rc) ? filter (rc, SF(ValidKey)) : 0;
}

/*-------------------------------------------------------------------------*/
// int | object* ParseArgs (string arg, int mandatory, int where)
//
// Parse a commandline for a '<thing>' or '<thing> with <key>' pattern
// and validize that '<thing>' is this object (search according to <where>).
// If '<key>' is specified, all matching keys in the players are selected,
// else all keys.
// In <mandatory> mode, the player must have a (matching) key.
//
// Results:
//         0: An error occured. An approbiate notify_fail() has been issued.
//   <array>: Valid keys found (may be empty).

public varargs mixed ParseArgs (string arg, int mandatory, int where) {
  string what, skey;
  mixed keys;
  int i;

  if (!arg || !environment() || (mandatory && !pKeyIds)) return 0;

  if (!mandatory){ //mandatory is 0
    if (sscanf (arg, "%s con %s", what, skey) == 2){
      arg = what;
      if (pKeyIds) {
        keys = FindKey (skey);
        if (!sizeof(keys)) {
          if (!keys)
            notify_fail("No tienes '"+skey+"'.\n", NOTIFY_NOT_VALID);
          else
            notify_fail("La "+skey+" no encaja en la cerradura.\n", NOTIFY_NOT_VALID);
          return 0;
        }
      }
      else keys = ({});
    }
    else if (pKeyIds)
      keys = FindKey(pKeyIds) || ({});
    else
      keys = ({});
  }
  else {//mandatory is 1
    if (sscanf (arg, "%s con %s", what, skey) == 2) arg = what;
    else skey = "llave";

    keys = FindKey (skey);
    if (!sizeof(keys)) {
      if (!keys)
        notify_fail ("No tienes '"+skey+"'.\n", NOTIFY_NOT_VALID);
      else
        notify_fail ("La "+skey+" no encaja en la cerradura.\n", NOTIFY_NOT_VALID);
      return 0;
    }
  }

  if (!arg || TP->Search (arg, where|SEARCH_OBJECT|WizSearch()) != TO) {
    if (!arg) arg = capitalize(query_verb())+" que?";
    else {
      arg = "No ves "+arg+" aqui.";
      if ((i = (int)TP->CantSee()) < 0) arg += " Esta demasiado oscuro.";
      else if (i > 0)                   arg += " Hay demasiada luz.";
    }
    return notify_fail (arg+"\n", NOTIFY_NOT_OBJ);
  }
  return keys;
}

/*-------------------------------------------------------------------------*/
// int TryLocking (object *keys, int unlock)
//
// Try to lock (<unlock> == 0) or to unlock (<unlock> != 0) the lock
// with one of the given <keys>.
// Except for key-denial-messages, no own messages are issued.
//
// Results:
//   <int>: The index of the successfully used key.
//      -1: Failure.

public varargs int TryLocking (object *keys, int unlock) {
  int i;
  mixed rc;
  for (i = 0; i < sizeof(keys); i++) {
    rc = TurnLock (unlock, keys[i]);
    if (stringp(rc)) write (rc);
    else if (rc == LOCK_OK) break;
  }
  if (i >= sizeof(keys)) return -1;
  return i;
}

/*-------------------------------------------------------------------------*/

public string ModifyInvShort (string text) {
  if (QueryLockState() != LOCK_OPEN)
    return text;
  if (text[0] != 'a')
    return text+" (abierto)";
  //return "an open "+strip_article(text);
  return "un "+text+" abierto";
}

public string ModifyLong (string text) {
  return text+"Está "+LockStateText()+".\n";
}

/*-------------------------------------------------------------------------*/

public init () {
  add_action ("fopen", "abrir");
  add_action ("fopen", "cerrar");
  add_action ("flock", "lock"); //[a] provisional
  add_action ("flock", "unlock"); //[a] provisional
}

/*-------------------------------------------------------------------------*/
public varargs int DoActionFor (int action, int type, object *keys, int kix)
//[a] 2000-03-11 modificada

// Do an appropriate user-notifying action for an operation of the lock.
// <action> and <type> denote the operation, <keys> is the keys array in use,
// <kix> the index of the used key.
//
// Valid actions are:
//   LOCK_DO_OPEN, LOCK_DO_CLOSE, LOCK_DO_LOCK, LOCK_DO_UNLOCK
//
// Valid types are:
//   LOCK_ACT_NOKEY   : the player has no keys.
//   LOCK_ACT_WRONGKEY: the player has no matching key.
//   LOCK_ACT_LOCK    : the object is (un)locked with <keys>[<kix>].
//   LOCK_ACT_OPEN    : the object is opened/closed.
//   LOCK_ACT_ALREADY : No actions need to be performed.
//
// Result is the return code:
//   1: Abort action with 1
//   0: Abort action with 0
//  -1: Continue action.

{
  int rc;
  string sh, verb;

  //sh = strip_article(Query(P_SHORT));
  sh = Query(P_SHORT);

  switch (type) {
	case LOCK_ACT_NOKEY:
      if (action == LOCK_DO_OPEN || action == LOCK_DO_CLOSE)
        write(capitalize(sh)+" está cerrad"+TO->QueryGenderEndString()+".\n");
      else
        write("No tienes la llave.\n");
      rc = 1;
      break;

    case LOCK_ACT_WRONGKEY:
      if (action == LOCK_DO_LOCK)
        verb = "cerrar con llave";
      else
        verb = "abrir con llave";
      write(
"Fallas al intentar "+verb+" "+sh+". "
+(sizeof(keys) > 1 ? "Ninguna de tus llaves encaja" : "La llave no encaja") + ".\n"
                  );
      rc = 1;
      break;

    case LOCK_ACT_LOCK:
      if (action == LOCK_DO_LOCK)
        verb = "cierra";
      else
        verb = "abre";
      write(capitalize(verb)+"s con llave "+sh+" con "
            +keys[kix]->Short()+".\n");
      tell_room(environment(TP), ({MSG_SEE, capitalize((string)TP->QueryName())+" "+verb+" con llave "
           +Short()+" con "+(string)keys[kix]->Short()+".\n"
          , "Oyes un chasquido.\n"}), ({ TP })
          );
      rc = -1;
      break;

    case LOCK_ACT_OPEN:
      if (action == LOCK_DO_OPEN)
        verb = "abre";
      else
        verb = "cierra";
      write(capitalize(verb)+"s "+sh+".\n");
      tell_room(environment(TP), ({ MSG_SEE, capitalize((string)TP->QueryName())+" "+verb+" "+Short()+".\n" }), ({ TP }));
      rc = 1;
      break;

    case LOCK_ACT_ALREADY:
      switch(action) {
      case LOCK_DO_LOCK:
        write("Ya esta cerrado con llave.\n");
        break;
      case LOCK_DO_UNLOCK:
        write("Ya esta abierto con llave.\n");
        break;
      case LOCK_DO_OPEN:
        write("Ya esta abierto.\n");
        break;
      default:
        write("Ya esta cerrado.\n");
      }
      rc = 1;
      break;
  }

  return rc;
}

/*-------------------------------------------------------------------------
** Commands "open" and "close"
**
**   "open <object>"
**      Opens the lock. If it is locked, and the player has the right key,
**      it is unlocked first.
**   "open <object> with <key>":
**      Opens the lock. If it is locked, and the player specified the
**      right key, it is unlocked first.
**   "close <object>"
**   "close <object> with <key>"
**      Closes the lock.
**
** <where> determines where the object is searched. Default is SEARCH_ENV_INV.
*/

public varargs int fopen (string str, int where) {
  object *keys;
  mixed rc;
  string sh;
  int i;

  if (!(rc = ParseArgs (str, 0, where))) return 0;
  keys = rc;

  //if (query_verb() == "open") {
  if (query_verb() == "abrir") {
    switch (QueryLockState()) {
      case LOCK_LOCKED:
        if (!sizeof(keys)) {
          rc = DoActionFor(LOCK_DO_OPEN, LOCK_ACT_NOKEY);
          if (rc >= 0) return rc;
        }
        if ((i = TryLocking (keys, 1)) < 0) {
          rc = DoActionFor(LOCK_DO_OPEN, LOCK_ACT_WRONGKEY);
          if (rc >= 0) return rc;
        }
        rc = DoActionFor(LOCK_DO_OPEN, LOCK_ACT_LOCK, keys, i);
        SetLockState(LOCK_CLOSED);
        if (rc >= 0) return rc;
        /* FALL THROUGH */

      case LOCK_CLOSED:
        rc = DoActionFor(LOCK_DO_OPEN, LOCK_ACT_OPEN);
        SetLockState (LOCK_OPEN);
        if (rc >= 0) return rc;
        break;

      case LOCK_OPEN:
        rc = DoActionFor(LOCK_DO_OPEN, LOCK_ACT_ALREADY);
        if (rc >= 0) return rc;
        break;
    }
  }
  else { /* close */
    switch (QueryLockState()) {
      case LOCK_OPEN:
        rc = DoActionFor(LOCK_DO_CLOSE, LOCK_ACT_OPEN);
        SetLockState (LOCK_CLOSED);
        if (rc >= 0) return rc;
        break;

      case LOCK_LOCKED:
      case LOCK_CLOSED:
        rc = DoActionFor(LOCK_DO_CLOSE, LOCK_ACT_ALREADY);
        if (rc >= 0) return rc;
        break;
    }
  }

  return 1;
}

/*-------------------------------------------------------------------------
** Commands "lock" and "unlock"
**
**   "lock <object>"
**      Locks the lock if the player has the right key.
**      If it is open, it is closed first.
**   "lock <object> with <key>"
**      Locks the lock if the player has specified the right key.
**      If it is open, it is closed first.
**   "unlock <object>"
**      Unlocks the lock if the player has the right key.
**   "unlock <object> with <key>"
**      Unlocks the lock if the player has specified the right key.
**
** <where> determines where the object is searched. Default is SEARCH_ENV_INV.
*/

public varargs int flock (string str, int where) {
  string sh;
  object *keys;
  mixed rc;
  int i;

  // This notify_fail() is for nil arg-strings, and attempts
  // to (un)lock a lockless object.

  //[a] (?) que hacía sólo el notify_fail?
  //notify_fail(capitalize(query_verb())+" que?\n", NOTIFY_NOT_OBJ);
  if (!str) notify_fail(capitalize(query_verb())+" que?\n", NOTIFY_NOT_OBJ);

  if (!(rc = ParseArgs (str, 1, where))) return 0;
  keys = rc;

  if (query_verb() == "lock")
    {
    switch (QueryLockState()) {
      case LOCK_OPEN:
        rc = DoActionFor(LOCK_DO_LOCK, LOCK_ACT_OPEN);
        SetLockState(LOCK_CLOSED);
        if (rc >= 0) return rc;
        /* FALL THROUGH */

      case LOCK_CLOSED:
        if (!sizeof(keys)) {
          rc = DoActionFor(LOCK_DO_LOCK, LOCK_ACT_NOKEY);
          if (rc >= 0) return rc;
        }
        if ((i = TryLocking (keys, 0)) < 0) {
          rc = DoActionFor(LOCK_DO_LOCK, LOCK_ACT_WRONGKEY);
          if (rc >= 0) return rc;
        }
        rc = DoActionFor(LOCK_DO_LOCK, LOCK_ACT_LOCK, keys, i);
        SetLockState (LOCK_LOCKED);
        if (rc >= 0) return rc;
        break;

      case LOCK_LOCKED:
        rc = DoActionFor(LOCK_DO_LOCK, LOCK_ACT_ALREADY);
        if (rc >= 0) return rc;
        break;
    }
  }
  else {  /* "unlock" */
    switch (QueryLockState()) {
      case LOCK_LOCKED:
        if (!sizeof(keys)) {
          rc = DoActionFor(LOCK_DO_UNLOCK, LOCK_ACT_NOKEY);
          if (rc >= 0) return rc;
        }
        if ((i = TryLocking (keys, 1)) < 0) {
          rc = DoActionFor(LOCK_DO_UNLOCK, LOCK_ACT_WRONGKEY);
          if (rc >= 0) return rc;
        }
        rc = DoActionFor(LOCK_DO_UNLOCK, LOCK_ACT_LOCK, keys, i);
        SetLockState (LOCK_CLOSED);
        if (rc >= 0) return rc;
        break;

      case LOCK_CLOSED:
      case LOCK_OPEN:
        rc = DoActionFor(LOCK_DO_UNLOCK, LOCK_ACT_ALREADY);
        if (rc >= 0) return rc;
        break;
    }
  }

  return 1;
}

/*-------------------------------------------------------------------------*/

//[a] ahora mira el genero
public void create ()
{
if (TO->QueryGender()==GENDER_FEMALE) TO->AddAdjective("abierta");
else TO->AddAdjective("cerrada");
}

/*************************************************************************/
