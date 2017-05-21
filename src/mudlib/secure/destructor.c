/* /secure/destructor
**
** Find and destruct old objects.
** The object is called by the GD via master::quota_demon() and ::daily_jobs(),
** but may be used directly by arches as well.
**
**   02-Mar-95 [mateese]
**   03-Mar-95 [mateese] Made destruction less aggressive.
*/

#include "/secure/config.h"
#include "/secure/wizlevels.h"
#include <door.h>

#define LOGFILE  "GAME_LOG"
#define SAVEFILE "/secure/save/.destructor"

#define DELAY 1

/*------------------------------------------------------------------------*/

int last_run;

/*------------------------------------------------------------------------*/

static int age;

/*------------------------------------------------------------------------*/

create() {
  seteuid(getuid(TO));

  if (-1 != member(object_name(TO), '#')) {
    log_file (LOGFILE,
 ctime(time())+": destructor: Illegal attempt!\n"
 "  this:        "+object_name(TO)+" ["+getuid(TO)+"]\n"
 "  previous:    "+(PO ? object_name(PO)+" ["+getuid(PO)+"]" : "<none>")+"\n"
 "  player:      "+(TP ? object_name(TP)+" ["+getuid(TP)+"]" : "<none>")+"\n"
 "  interactive: "+(TI ? object_name(TI)+" ["+getuid(TI)+"]" : "<none>")+"\n\n"
             );
    destruct (TO);
    return;
  }
}

/*------------------------------------------------------------------------*/
start_dragon(int arg)

// Start the destruction of unused objects.
// arg <= 0: min age of objects to keep is derived from the time of the
//           last run.
// arg >  0: min age of objects to keep is computed as 'arg-1' hours.

{
  if ((     PO != find_object(MASTER)
        || getuid(TO) != ROOTID
        || -1 != member(object_name(TO), '#')
      )
      && (!TI || !IS_ARCH(TI))
     ) {
    log_file (LOGFILE,
 ctime(time())+": destructor:start_dragon(): Illegal attempt!\n"
 "  this:        "+object_name(TO)+" ["+getuid(TO)+"]\n"
 "  previous:    "+(PO ? object_name(PO)+" ["+getuid(PO)+"]" : "<none>")+"\n"
 "  player:      "+(TP ? object_name(TP)+" ["+getuid(TP)+"]" : "<none>")+"\n"
 "  interactive: "+(TI ? object_name(TI)+" ["+getuid(TI)+"]" : "<none>")+"\n\n"
             );
    destruct (TO);
    return;
  }

  last_run = 0;
  if (arg <= 0)
  {
    restore_object(SAVEFILE);
    if (time() - last_run >= 3600)
      age = 3;
    else if (time() - last_run >= 1800)
      age = 2;
    else
      age = 1;
  }
  else
    age = arg-1;
  last_run = time();
  save_object(SAVEFILE);

  log_file(LOGFILE, ctime()+" destructor started for age "+age+"\n");
  do_destruct(0);
}

/*------------------------------------------------------------------------
** Destruct objects until noone is left to destruct.
** If exec_costs run out, schedule a call_out().
*/

static do_destruct(int count) {
  object o, n, rc;
  string name;
  int gotone, isclone;
  int stime;
  mixed tmp;

  while (remove_call_out("do_destruct") >= 0) /* skip */ ;

  // The destruction process will reload objects/blueprints destructed
  // earlier, so they mustn't be considered again.
  // Also, young objects are not to be considered.
  stime = time()-age*3600;

  do {
    gotone = 0;
    for (o = debug_info(2); o; o = n)
    {
      if (get_eval_cost() < 5000)
      {
        log_file(LOGFILE
                , ctime()+" destructor: "+count+" objects destructed so far.\n"
                );
        call_out("do_destruct", DELAY, count);
        return;
      }
      n = debug_info(2,o);
      name = object_name(o);
      if (   name[0..6] == "/secure"
          || interactive(o)
          || query_once_interactive(o)
          || o == TO
          || environment(o)
          || program_time(o) >= stime
         )
        continue;

      isclone = (0 <= member(name, '#'));

      catch(o->clean_up(2));
      rc = 1;
      // si son puertas lo que se intenta eliminar, comprobamos si se puede o no:
      if (o && isclone && member(inherit_list(o), DOOR_PATH ".c") >= 0 && o->CantRemove()) continue;
      if (o && (!first_inventory(o) || isclone))
        catch(rc = call_resolved(&tmp, o, "remove"));
      if (o && !rc && (!first_inventory(o) || isclone))
        destruct(o);
      if (!o) {
        count++;
        gotone = 1;
      }
    }
  } while (gotone);
  log_file(LOGFILE, ctime()+" destructor: "+count+" objects destructed.\n");
  destruct(TO);
}

/*========================================================================*/
