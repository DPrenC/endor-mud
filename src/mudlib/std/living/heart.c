/* SIMAURIA '/std/living/heart.c'
   ==============================
   [m] Mateese@nightfall
   [w] Woo

   09-08-94 [m] Modificacion de este archivo.
   17-12-96 [w] Revisado para el nuevo mud (ningun cambio).
*/


#include <living.h>

#define NETDEAD  (!TO || (!interactive(TO) && query_once_interactive(TO)))
#define MY_HEART ((1<<HEART_FORCE)|(1<<HEART_HEAL)|(1<<HEART_COMBAT)|(1<<HEART_CALLOUT)|\
(1<<HEART_MOVING)|(1<<HEART_USER))

public void ValidizeHeart(); // forward
public void scheduleNext();  // forward
public object QueryHbObj();  // forward

private static int cookies = 0;  /* Allocated user slots */
private static int userSet = 0;  /* Allow 32 users for the heart */

private static mixed *callouts;
// Relative indices in callouts:
#define CALLOUT_TIME 0 // Scheduled runtime
#define CALLOUT_FUN  1 // Function/closure to be called
#define CALLOUT_ARGS 2 // Array of args

#define CALLOUT_SIZE 3 // Number of indices per callout-entry


//--------------------------------------------------------------------------

#ifdef USE_HBHOOK

// Heartbeat-Hook stuff
static object pHookobj;
static mixed  pHookfun;
static int    pHooktval;
private static int hookcount;

#endif

//--------------------------------------------------------------------------

public int QueryHeart ()    { return userSet; }
public int SetHeart (int i) {
  userSet = i;
  ValidizeHeart();
  return userSet;
}

public int set_heart(int i) { return set_heart_beat(i); }
public int turn_heart_beat(int i) { return set_heart_beat(i); }

public int QueryHeartUser ()    { return cookies | MY_HEART; }
public int SetHeartUser (int i) {
  cookies = i | MY_HEART;
  ValidizeHeart();
  return cookies;
}

public mixed QueryCallouts() { return callouts; }

//--------------------------------------------------------------------------

// Grant <user> to get the heart beat.

public void GetHeart (int user) {
  userSet |= (1 << user) & (cookies | MY_HEART);
#ifdef USE_HBHOOK
  if ((!NETDEAD && userSet) || QueryHbObj()) set_heart_beat(1);
#else
  if (!NETDEAD && userSet) set_heart_beat(1);
#endif
  if (user != HEART_CALLOUT) scheduleNext();
}

// <user> doesn't need the heart anymore.

public void DropHeart (int user) {
  if (    user != HEART_FORCE
       && (userSet & (1 << user))
       && !(userSet ^= (1 << user))
#ifdef USE_HBHOOK
       && !QueryHbObj()
#endif
     )
    set_heart_beat(0);
  if (user != HEART_CALLOUT) scheduleNext();
}

// Check if a certain <user> uses the heart.

public int CheckHeart (int user) {
  return userSet & (1 << user);
}

// Restart the heart properly

public void ValidizeHeart () {
#ifdef USE_HBHOOK
  if ((!userSet) && !QueryHbObj())
#else
  if (!userSet)
#endif
    set_heart_beat(0);
  else set_heart_beat(1);
  scheduleNext();
}

//--------------------------------------------------------------------------
// Allocate a user slot for the heart

public int GetUser () {
  int i;

  if (!cookies)
    cookies = MY_HEART;

  for (i = 0; i < 32; i++)
    if (!((1 << i) & cookies))
    {
      cookies |= (1 << i);
      return i;
    }
  return -1;
}

// Release a user slot of the heart

public void DropUser (int user) {
  int i;

  DropHeart(user);
  if (cookies & (1 << user))
    cookies ^= (1 << user);
}

// Check if a certain <user> has a slot of the heart.

public int CheckUser (int user) {
  return cookies & (1 << user);
}

//---------------------------------------------------------------------------
public varargs int CheckHBfun (mixed files)
{
  if (!files)
    files = ({ });
  else if (stringp(files))
    files = ({ files });
  files += ({ "/std/living" });
  if (-1 == member(files, function_exists("heart_beat", TO)))
  {
    GetHeart(HEART_USER);
    return 1;
  }
  DropHeart(HEART_USER);
  return 0;
}

//--------------------------------------------------------------------------
// Schedule the next callout

public void scheduleNext ()
{
  int delay;

  while(remove_call_out("DoCallout") >= 0);
  if (!sizeof(callouts))
  {
    DropHeart(HEART_CALLOUT);
    return;
  }

  delay = callouts[CALLOUT_TIME] - time();
  if (!NETDEAD && (delay < HEART_DELAY || (QueryHeart()&~(1<<HEART_CALLOUT))))
  {
    GetHeart(HEART_CALLOUT);
  }
  else
  {
    DropHeart(HEART_CALLOUT);
    call_out("DoCallout", delay);
  }
}


// Register a new callout.
public void CallOut( mixed fun, int delay, varargs mixed * args)
{
  int runtime;
  int i, low, top, ix;

  runtime = time() + delay;

  if (!sizeof(callouts))
  {
    callouts = ({ runtime, fun, args });
    scheduleNext();
  }
  else if (runtime <= callouts[CALLOUT_TIME])
  {
    callouts = ({ runtime, fun, args }) + callouts;
    scheduleNext();
  }
  else if (runtime >= callouts[<(CALLOUT_SIZE-CALLOUT_TIME)])
  {
    callouts = callouts + ({ runtime, fun, args });
  }
  else
  {
    low = 0;
    top = sizeof(callouts) / CALLOUT_SIZE - 1;
    while (top >= low)
    {
      i = (top+low)/2;
      ix = i * CALLOUT_SIZE;
      if (runtime == callouts[ix+CALLOUT_TIME])
      {
        low = i;
        break;
      }
      if (runtime > callouts[ix+CALLOUT_TIME])
        low = i+1;
      else
        top = i-1;
    }
    low = low * CALLOUT_SIZE;
    callouts = callouts[0..low-1] + ({ runtime, fun, args }) + callouts[low..];
    if (!low)
      scheduleNext();
  }
}

// Find a callout by name.

public int FindCallout ( mixed fun )
{
  int runtime;
  int i;

  if (!sizeof(callouts))
    return -1;

  for (i = 0; i < sizeof(callouts); i += CALLOUT_SIZE)
    if (callouts[i+CALLOUT_FUN] == fun)
    {
      runtime = callouts[i+CALLOUT_TIME]-time();
      return runtime >= 0 ? runtime : 0;
    }
  return -1;
}

// Remove a callout by name.

public int RemoveCallout ( mixed fun )
{
  int runtime;
  int i;

  if (!sizeof(callouts))
    return -1;

  for (i = 0; i < sizeof(callouts); i += CALLOUT_SIZE)
    if (callouts[i+CALLOUT_FUN] == fun)
    {
      runtime = callouts[i+CALLOUT_TIME]-time();
      callouts[i..i+CALLOUT_SIZE-1] = ({});
      if (!i)
        scheduleNext();
      return runtime >= 0 ? runtime : 0;
    }
  return -1;
}

// Perform one or more registered callouts

public void DoCallout ()
{
  int i;
  mixed *todo;

  for (i = 0; i < sizeof(callouts); i += CALLOUT_SIZE)
    if (callouts[i+CALLOUT_TIME] > time())
      break;

  if (i)
  {
    todo = callouts[0..i-1];
    callouts = callouts[i..];
  }

  scheduleNext();

  for (i = 0; i < sizeof(todo); i += CALLOUT_SIZE)
  {
    if (closurep(todo[i+CALLOUT_FUN]))
      apply(todo[i+CALLOUT_FUN], todo[i+CALLOUT_ARGS]);
    else
      apply(SF(call_other), TO, todo[i+CALLOUT_FUN], todo[i+CALLOUT_ARGS]);
  }
}

//--------------------------------------------------------------------------

#ifdef USE_HBHOOK
public object QueryHbObj()         { return pHookobj; }
public object SetHbObj(object obj) {
  pHookobj = obj;
  ValidizeHeart();
  return pHookobj;
}

public mixed QueryHbFun() { return pHookfun; }
public mixed SetHbFun(mixed fun) {
  if ((pHookfun = fun) && closurep(pHookfun))
    SetHbObj(to_object(pHookfun));
  else if (!pHookfun)
    SetHbObj(0);
  ValidizeHeart();
  return pHookfun;
}

public int QueryHbInterval()    { return pHooktval; }
public int SetHbInterval(int i) { return pHooktval = i; }

public varargs void InitHBHook (int tval, mixed fun, object obj)
{
  SetHbInterval(tval < 1 ? 150 : tval);
  SetHbObj(obj || PO);
  SetHbFun(fun || "player_hb_hook");
}

public mixed * QueryHBHook() {
  object obj;
  obj = QueryHbObj();
  return obj && ({ QueryHbInterval(), QueryHbFun(), obj });
}

public varargs mixed SetHBHook (mixed tval, string fun, object obj) {
  if (tval && !pointerp(tval))
  {
    log_file("COMPAT", sprintf("%O: %O->%s(non-array)\n", TO, PO, "SetHBHook"));
    return InitHBHook(tval, fun, obj);
  }
  if (!tval)
  {
    SetHbObj(0);
    SetHbInterval(0);
    SetHbFun(0);
  }
  else
  {
    SetHbInterval(tval[0]);
    SetHbObj(tval[2]);
    SetHbFun(tval[1]);
  }
  return QueryHBHook();
}

public void ResetHBHook () {
  log_file("COMPAT", sprintf("%O: %O->%s(non-array)\n", TO, PO, "ResetHBHook"));
  SetHBHook(0);
}

#endif

//--------------------------------------------------------------------------

public void heart_beat ()
{
  object obj;
  mixed  fun;

#ifdef USE_HBHOOK
  if ((obj = QueryHbObj()) && --hookcount <= 0)
  {
    hookcount = QueryHbInterval();
    fun = QueryHbFun();
    if (stringp(fun))
      call_other(obj, fun);
    else
      funcall(fun);
  }
#endif
  if (CheckHeart(HEART_CALLOUT) || sizeof(callouts))
    DoCallout();
}

/*==========================================================================*/
