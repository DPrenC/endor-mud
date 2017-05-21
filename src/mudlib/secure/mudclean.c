/* SIMAURIA '/secure/mudclean.c'
   =============================
   [w] Woo@simauria

   25-12-97 [w] Traducido y adaptado a Simauria.
*/


#include "/secure/config.h"
#include "/secure/wizlevels.h"

#define LOGFILE  "GAME_LOG"
#define SAVEFILE "/secure/save/.mudclean"

#define MODEST 1

//#define DEBUG 1

#ifdef DEBUG
#define DTELL(a) dtell("woo", a)
#else
#define DTELL(a)
#endif


int last_run;


static string  modest;   // "" if not modest, "modest " if modest
static int     idcode;   // code to tag the objects already visited

static int state;        // State of the destructor:
#define STATE_NONE   0   //   Destructor is not working.
#define STATE_START  1   //   Destructor has just been started.
#define STATE_START2 2   //   Destructor is initialized.
#define STATE_GATHER 3   //   Destructor is gathering interesting objects.
#define STATE_CLEAN  4   //   Destruct the gathered objects.
#define STATE_GC     5   //   Schedule the garbage_collection().
#define STATE_END    6   //   Destructor done.

static int age;  // Max. age of the objects to destruct

static mixed * objs;       // Array of array of objs
#define NUMOBJS  2000      // Number of objects per array.
static int     numobj;     // Number of objects to consider.
static int     numsecobj;  // Number of /secure-objects.
static int     numinter;   // Number of interactive objects.
static int     numyoung;   // Number of too-young objects.
static int     numupdate;  // Number of objects to update.

static int     numcarr;    // Number of carried objects.
static int     numvic;     // Number of objects near a player.
static int     numhold;    // Number of objects holding a player.
static int     numnegl;    // Number of objects neglecting destruction.
static int     numdest;    // Number of objects destructed.
static int     numrun;     // Number of runs needed.
static int     numhb;      // Number of heartbeats needed.

static object  lastobj;    // Last object considered in gather()
static int     diddest;    // Flag if clean() did destruct an object.
static int     lastix;     // Index of next object to consider in clean()

/*------------------------------------------------------------------------*/

create() {
  seteuid(getuid(TO));

  if (-1 != member(object_name(TO), '#')
   || object_name(TO)+".c" != __FILE__
     ) {
    log_file (LOGFILE,
 ctime(time())+": mudclean: Illegal attempt!\n"
 "  this:        "+object_name(TO)+" ["+getuid(TO)+"]\n"
 "  previous:    "+(PO ? object_name(PO)+" ["+getuid(PO)+"]" : "<none>")+"\n"
 "  player:      "+(TP ? object_name(TP)+" ["+getuid(TP)+"]" : "<none>")+"\n"
 "  interactive: "+(TI ? object_name(TI)+" ["+getuid(TI)+"]" : "<none>")+"\n\n"
             );
    destruct (TO);
    return;
  }
#ifdef MODEST
  modest =  "modest ";
#else
  modest = "";
#endif
  state = STATE_NONE;
}

/*------------------------------------------------------------------------*/
start_dragon(int arg)

// Start the destruction of unused objects.
// arg <= 0: min age of objects to keep is derived from the time of the
//           last run.
// arg >  0: min age of objects to keep is computed as 'arg-1' hours.

{
  int tmp;
  if ((     PO != find_object(MASTER)
        || getuid(TO) != ROOTID
        || -1 != member(object_name(TO), '#')
	|| object_name(TO)+".c" != __FILE__
      )
      && (!TI || !IS_ARCH(TI))
     ) {
    log_file (LOGFILE,
 ctime(time())+": mudclean:start_dragon(): Illegal attempt!\n"
 "  this:        "+object_name(TO)+" ["+getuid(TO)+"]\n"
 "  previous:    "+(PO ? object_name(PO)+" ["+getuid(PO)+"]" : "<none>")+"\n"
 "  player:      "+(TP ? object_name(TP)+" ["+getuid(TP)+"]" : "<none>")+"\n"
 "  interactive: "+(TI ? object_name(TI)+" ["+getuid(TI)+"]" : "<none>")+"\n\n"
             );
    destruct (TO);
    return;
  }

  if (state)
  {
    log_file (LOGFILE,
 ctime(time())+": mudclean:start_dragon(): Already working!\n"
 "  this:        "+object_name(TO)+" ["+getuid(TO)+"]\n"
 "  previous:    "+(PO ? object_name(PO)+" ["+getuid(PO)+"]" : "<none>")+"\n"
 "  player:      "+(TP ? object_name(TP)+" ["+getuid(TP)+"]" : "<none>")+"\n"
 "  interactive: "+(TI ? object_name(TI)+" ["+getuid(TI)+"]" : "<none>")+"\n\n"
             );
    return;
  }

  last_run = 0;
  if (arg <= 0)
  {
    restore_object(SAVEFILE);
    if (time() - last_run >= 3600)
      tmp = 6;
    else if (time() - last_run >= 1800)
      tmp = 4;
    else
      tmp = 2;
  }
  else
    tmp = arg-1;
  last_run = time();
  save_object(SAVEFILE);

  log_file(LOGFILE, ctime()+" "+modest+"mudclean started for age "+tmp+"\n");
  age = time() - tmp*3600;
  state = STATE_START;
  idcode = time();
  set_heart_beat(1);
}

static void shout (string msg)
{
  filter(users(), SF(tell_object), msg);
}

static object setobj (int index, object obj)

// Set object <obj> into objs[] at <index>.
// Index may be <numobjs>, thus extending the array.

{
  int arr, ix;

  arr = index / NUMOBJS;
  ix = index % NUMOBJS;
  if (arr == sizeof(objs))
    objs += ({ allocate(NUMOBJS) });
  objs[arr][ix] = obj;
  if (index >= numobj)
    numobj = index+1;
  return obj;
}

static object getobj (int index)

// Get object <obj> from objs[] at <index> and return it.

{
  return objs[index / NUMOBJS][index % NUMOBJS];
}

static int gather()

// Collect all cleanable objects in objs[].
// Return 1 if no more objects are to be collected.
// The functions judges just on object name, age and interactivity,
// but ignores inventory relations and similar.

{
  int mincost, fage;
  object o;
  string name;

  // Stop at max(50%, 100) eval cost left.
  mincost = get_eval_cost() / 20;
  if (mincost < 100)
    mincost = 100;

  for ( o = debug_info(2)
      ; o && get_eval_cost() >= mincost
      ; o = debug_info(2, o)
      )
  {
    name = to_string(o);
    // Netdead things in the void are garbage.
    if (interactive(o) || (query_once_interactive(o) && environment(o)))
    {
      DTELL("Gather: "+to_string(o)+" is interactive.\n");
      numinter++;
      if (interactive(o) && o->Query("mudclean_id") != idcode)
      {
/*
        tell_object(o,
"Una de las sombras se acerca a ti y te observa detenidamente y sin mediar\n"
 "palabra te sonrie y se aleja por el lado opuesto al que vino.\n\n"
                   );
*/
	o->Set("mudclean_id", idcode);
      }
    }
    else if (name[0..6] == "/secure" || o == TO)
    {
      numsecobj++;
      DTELL("Gather: "+to_string(o)+" is secure.\n");
    }
    else
    {
      setobj(numobj, o);
      DTELL("Gather: "+to_string(o)+" gathered.\n");
    }
  }

  lastobj = o;
  return !o;
}

static int clean()

// Destruct all cleanable objects in objs[].
// Return 1 if no more objects are to be destructed.

{
  int mincost;
  object o, e;
  int isclone, rc;
  mixed tmp;

  // Stop at max(5%, 100) eval cost left.
  mincost = get_eval_cost() / 20;
  if (mincost < 100)
    mincost = 100;

  for (; lastix < numobj && get_eval_cost() >= mincost; lastix++)
  {
    o = getobj(lastix);
    if (!o)
    {
	/* Maybe it's a side effect of our actions, maybe someone else
	 * destructed it - anyway, it's gone.
	 */
      continue;
    }

    setobj(lastix, 0);

    if (!clonep(o)
     && file_size(to_string(o)+".c") > 0
     && file_date(to_string(o)+".c") > program_time(o)
       )
    {
      numupdate++;
      DTELL("Clean: "+to_string(o)+" gets updated.\n");
    }
    else if (program_time(o) > age)
    {
      numyoung++;
      DTELL("Clean: "+to_string(o)+" is too young.\n");
      continue;
    }
#ifdef MODEST
#if 0
    else if (!query_once_interactive(o) || interactive(o) || environment(o))
    {
      numnegl++;
      DTELL("Clean modest: "+to_string(o)+" no interactive in the void.\n");
      continue;
    }
#endif
#endif

    e = environment(o);
    if (e)
    {
      // Don't destruct objects carried by players.
      for ( ; e && !query_once_interactive(e); e = environment(e));
      if (e)
      {
        DTELL(to_string(o)+" carried.\n");
        numcarr++;
        continue;
      }

      // Don't destruct objects in the vicinity of players.
      if (sizeof(filter( all_inventory(environment(o))
                             , SF(interactive))))
      {
        DTELL(to_string(o)+" around player.\n");
        numvic++;
        continue;
      }
    }

    // Don't destruct objects containing players.
    if ("/room/netdeath" == to_string(o)
    ||  sizeof(filter(deep_inventory(o), SF(query_once_interactive))))
    {
      DTELL(to_string(o)+" contains player.\n");
      numhold++;
      continue;
    }

    isclone = (0 <= member(to_string(o), '#'));

    DTELL("Destructing "+to_string(o)+".\n");

    catch(o->clean_up(2));
    rc = 1;
#ifndef MODEST
    if (o /* && (!first_inventory(o) || isclone) */)
      catch(rc = call_resolved(&tmp, o, "remove", -1));
    // Netdead things in the void are garbage, too.
    // The gather() run won't pass us true interactives, so we
    // don't need to check for that.
    if (o && (!rc || (!environment(o) && query_once_interactive(o)))
          /* && (!first_inventory(o) || isclone) */
       )
      destruct(o);
#endif
    if (!o)
    {
      numdest++;
      diddest = 1;
    }
    else
      numnegl++;
  }

  rc = (lastix >= numobj && !diddest);
  if (lastix >= numobj)
  {
    numrun++;
    if (diddest)
    {
      diddest = 0;
      lastix = 0;
    }
  }

  return rc;
}

void heart_beat()

// Main state machine of the destructor.

{
  string errmsg;
  int    tmp;

  errmsg = 0;

  switch(state)
  {
    case STATE_NONE:
      errmsg = "Heartbeat in state NONE.";
      break;

    case STATE_START:
/*
      shout(
"El cielo se enrrojece de pronto y una luz cegadora se abre paso entre las\n"
"nubes... La luz se atenua y consigues vislumbrar una Sombra.\n"
"La Sombra grita: OHH NOOO!!! Mi mundo esta lleno de basura!!\n"
"La Sombra recorre el mundo de un extremo a otro gritando horrorizada.\n\n"
           );
*/
      garbage_collection(); /* gives us some more memory to work in */
      objs = ({});
      numobj = 0;
      numsecobj = 0;
      numinter = 0;
      state = STATE_START2;
      break;

    case STATE_START2:
/*
      shout(
"La Sombra se detiene y pronuncia unas palabras que no logras entender. De\n"
"pronto miles de sombras aparecen de todos lados y bajan a ras de suelo.\n"
"La Sombra grita: No os movais si no quereis morir a manos de mis huestes.\n\n"
           );
*/
      state = STATE_GATHER;
      /* FALLTHROUGH */
    case STATE_GATHER:
      if (gather())
      {
        state = numobj ? STATE_CLEAN : STATE_GC;
        numcarr = 0;
        numvic = 0;
        numhold = 0;
        numnegl = 0;
        numdest = 0;
        numrun = 0;
        numhb = 0;
        numupdate = 0;
	numyoung = 0;

        diddest = 0;
        lastix = 0;

        tmp = numsecobj+numinter+numobj;
        log_file(LOGFILE,
ctime()+" "+modest+"mudclean: "+numobj+" of "+tmp+" objects gathered.\n"
 "  "+numsecobj+" game objs, "+numinter+" interactives.\n");
      }
      break;

    case STATE_CLEAN:
      numhb++;
/*
      if (numhb % 2 && (numhb / 2) < 2)
      {
        shout(
({ "Escuchas gritos de terror provenientes de todos lados y puedes observar como\n"
 "algunas sombras retornan al cielo cargadas de objetos.\n\n"
 })[numhb/2]
             );
      }
 */
      if (clean())
      {
        state = STATE_GC;
        log_file(LOGFILE,
 ctime()+" "+modest+"mudclean: "+numdest+"("+numupdate+") objects destructed ("
        +numrun+" runs, "+numhb+" hbs).\n"
 "  "+(numcarr+numvic+numhold+numnegl+numyoung)+" left: "
     +numyoung+" too young, "+numcarr+" carried, "+numvic+" near pl, "
     +numhold+" around pl, "+numnegl+" persistant.\n"
                );
      }
      break;

    case STATE_GC:
//      shout("Por unos instantes la confusion gobierna este mundo.\n");
      objs = 0; /* so the GC can reclaim this memory as well */
      garbage_collection();
      state = STATE_END;
      break;

    case STATE_END:
/*
      shout(
"Finalmente las huestes de la Sombra retornan a las alturas.\n"
"La Sombra grita: Jajajaja.. Mi Mundo ya esta vacio de gentes y objetos\n"
"inservibles, por lo tanto ahora me voy pero.. volvere!!\n"
"La Sombra desaparece mientras el cielo recobra su color normal.\n"
           );
*/
      set_heart_beat(0);
      destruct(TO);
      break;

    default:
      errmsg = "Illegal state "+state+".\n";
      break;
  }

  if (errmsg)
  {
    log_file (LOGFILE,
 ctime(time())+": "+modest+"mudclean:heart_beat(): "+errmsg+"\n"
 "  this:        "+object_name(TO)+" ["+getuid(TO)+"]\n"
 "  previous:    "+(PO ? object_name(PO)+" ["+getuid(PO)+"]" : "<none>")+"\n"
 "  player:      "+(TP ? object_name(TP)+" ["+getuid(TP)+"]" : "<none>")+"\n"
 "  interactive: "+(TI ? object_name(TI)+" ["+getuid(TI)+"]" : "<none>")+"\n"
 "  Dragon destructed.\n\n"
             );
    set_heart_beat(0);
    destruct(TO);
  }
}

