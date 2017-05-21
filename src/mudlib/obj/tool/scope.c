/* LPC-Scope
**
** Monitors continously several .err-Files and shows the diffs to the owner.
** Idea by Ergberg.
**
**   01-Sep-92 [m]
**   05-Apr-94 [m] Can't be used by NPCs any longer.
**   02-May-94 [t] Bugfixes.
**   19-Apr-95 [m] No longer autoloading for mortals.
**   23-Oct-95 [m] QueryAutoObject() called by autosave stumbled over the
**                 missing TI (noted by Loco).
**
**  [m] Mateese, Biontic Magics & Darkness
**  [t] Thragor
*/

#include <config.h>
#include <properties.h>
#include <news.h>
#include <wizlevels.h>

#include "/obj/lib/stddefs.h"

#include "/obj/lib/string.h"
inherit STR;

inherit "/std/thing";

/*-------------------------------------------------------------------------*/

#define REVTAG   "951023"
#define VERSION  2
#define REVISION 1
#define VER_REV  VERSION+"."+REVISION

#define USAGE(con,txt) if (con) return notify_fail(txt) && 0;else
#define FAIL(msg) return (notify_fail(msg) && 0)

/*-------------------------------------------------------------------------*/

mixed *scopes; /* AList of scopes, key is shorthandname */
#define S_KEY  0
#define S_DATA 1
#define SC_FILE   0
#define SC_SCOPED 1
#define SC_SIZE   2
int interval;
int scopeon;

/*-------------------------------------------------------------------------
*/
update_scopes (int justcleanup);

private int load_scope(int i) {
  string err, user;
  if (!clonep()) return 0;
  if (!TP) return 0;
  user = getuid(TP);
  if (!restore_object("/players/"+user+"/.scope")) {
    if (!i)
      write("Scope loading failed. Reason:\n"+err+"\n");
    return 1;
  }
  while (remove_call_out("_check_scopes") != -1);
  if (!i)
    write("Scope settings loaded.\n");
  if (!pointerp(scopes) || sizeof(scopes) != 2) {
    scopes = ({({}),({})});
    interval = 5;
    scopes = insert_alist ("debug", ({ "/nova.debug.log", 1, 0 }), scopes);
    scopes = insert_alist ("parse", ({ "/parse.log", 1, 0 }), scopes);
    scopes = insert_alist ("std", ({ "/log/std.err", 1, 0 }), scopes);
    scopeon = 1;
  }
  update_scopes(0);
  scopes = order_alist(scopes);
  call_out ("_check_scopes", interval);
  return 1;
}
private int save_scope(int i) {
  string err, user;
  if (!clonep() || !TP) return 0;
  user = getuid(TP);
  if (err = catch(save_object("/players/"+user+"/.scope"))) {
    if (!i)
      write("Saving failed. Reason:\n"+err+"\n");
    return 1;
  }
  if (!i)
    write("Scope settings saved.\n");
  return 1;
}

create() {
  string name, foo;

  thing::create();
  if (!clonep()) return;

  seteuid(getuid());
  SetShort ("a scope");
  Set(P_NOBUY,1);
  Set(P_NOSELL,1);
  SetNoDrop(1);
  SetNoGive(1);
  SetLong (
 " -- LPC-Scope "+VER_REV+" ["+REVTAG+"] --\n"
 "This tool monitors the various error files and prints the differences to\n"
 "you. The commands is 'scope'. Give '?' as parameter for help.\n"
          );
  AddId ("scope");
  SetReadMsg (
 "A small sign reads:\n"
 " LPC-Scope -- v "+VER_REV+" ["+REVTAG+"]\n"
 "  Biontic Magics & Darkness\n"
          );
  SetInfo ("LPC-Scope "+VER_REV+" ["+REVTAG+"] by Mateese");
  scopes = ({({}),({})});
  interval = 5;
  scopes = insert_alist ("debug", ({ "/nova.debug.log", 1, 0 }), scopes);
  scopes = insert_alist ("parse", ({ "/parse.log", 1, 0 }), scopes);
  scopes = insert_alist ("std", ({ "/log/std.err", 1, 0 }), scopes);
  scopes = order_alist(scopes);
  update_scopes(0);
  scopeon = 1;
  call_out ("_check_scopes", interval);
}

id(str) {
  if (!PL || !PL_WLEVEL) return 0;
  return thing::id(str);
}

remove(mixed arg) {
  save_scope(1);
  return ::remove();
}

/*-------------------------------------------------------------------------
** check_owner() checks if the right player is trying to use us.
*/

check_owner(int no_ipl) {
  return (no_ipl || (IPL && IPL == PL)) && PL_WLEVEL && PL == environment(ME);
}

/*-------------------------------------------------------------------------
** Create or evaluate the autoload-data.
*/

SetAutoObject (mixed *args) {
  int autoinit;

  if (intp(args)) {
    load_scope(1);
    if (args != VERSION)
      write ("The Scope has been improved since your last visit here!\n");
    return;
  }

  if (!pointerp(args) || sizeof(args) < 3) {
    write ("Can't initialize the Scope.\n");
    return;
  }

  if (args[0] != VERSION)
    write ("The Scope has been improved since your last visit here!\n");

  if (sizeof(args) > 3)
    write ("The Scope couldn't understand all the init-data.\n");
  start_stop(args[1]);
  scopes = order_alist( args[2] );
  update_scopes(0);
  return;
}


QueryAutoObject () { if(!check_owner(1)) return 0; return VERSION; }

/*-------------------------------------------------------------------------
** Check the euid of TP against ours.
** If we have none, try to set it to this_players().
** If this fails, the player can't use us, our euid is reset and tried
** to be set to the players one.
*/

varargs int check_euid (int silently, object pl) {
  if (!pl) pl = PL;
  if (!pl || !living(pl)) return 0;
  if (!PO || geteuid(PO) != geteuid(ME)) {
    if (!silently) write ("Sorry, this scope is not yours.\n");
    return 0;
  }

  if (!geteuid(ME) && !seteuid(geteuid(pl))) {
    if (!silently) write ("Sorry, this scope is not yours.\n");
    return 0;
  }

  if (!geteuid(ME) || geteuid(ME) != geteuid(pl)) {
    seteuid(0);
    if (!seteuid(geteuid(pl))) {
      if (!silently) write ("You have no right to do that!\n");
      return 0;
    }
  }
  return 1;
}

/*-------------------------------------------------------------------------
** Update the sizes in the current scopes, or just remove illegal entries.
*/

update_scopes (int justcleanup) {
  int i, s;
  for (i = 0; i < sizeof(scopes[S_KEY]); i++) {
    s = file_size(scopes[S_DATA][i][SC_FILE]);
//      if (s < 0) {
// I think we should keep files in the list, even if they don't exist,
// Thragor, 03may94
      if (s==-2) {
        scopes = order_alist(remove_alist(scopes[S_KEY][i], scopes));
        i = -1;
      }
      else if (!justcleanup) scopes[S_DATA][i][SC_SIZE] = s;
  }
}

/*-------------------------------------------------------------------------
** msg() displays a message to the owner of this scope (not to players)
** Inserted by Thragor
*/

private void msg(string txt)
{
 if (environment()&&IS_LEARNER(environment()))
  tell_object(environment(),txt);
}

/*-------------------------------------------------------------------------
** Add and decode our commands.
*/

init() {
  int s;
  string f;
//  if (!check_owner()) return 0;
  thing::init();
/*  add_action ("read"      , "inspect"); */
  add_action ("_dispatch" , "", 1);
}

int _dispatch(string arg) {
  string verb, foo;
#if 0
  if ((verb = query_verb()) == "scope") {
    if (!arg) verb = 0;
    else if (sscanf (arg, "%s %s", verb, arg) < 2) verb = arg, arg = 0;
  }
#else
  verb = query_verb();
#endif
//  check_euid(1); // Seems to break the scope
  if (verb && verb != "" && function_exists("f"+verb, ME))
    return (int) call_other(ME, "f"+verb, arg);
  return 0;
}

/*-------------------------------------------------------------------------
** Check all given files, print diff, and recall.
*/

#define MAX_TXT_LEN 5000

_check_scopes() {
  int i, s;
  string str, txt;
  mixed *data;

  while (remove_call_out("_check_scopes") != -1);
  if (scopeon)
    call_out ("_check_scopes", interval);
  for (i = 0; i < sizeof(scopes[S_KEY]); i++) {
    if (!scopes[S_DATA][i][SC_SCOPED]) continue;
    data = scopes[S_DATA][i];
    s = file_size(data[SC_FILE]);
    if (s < 0 || s <= data[SC_SIZE])
    {
     if (s<0) s = 0;
     scopes[S_DATA][i][SC_SIZE] = s;
     continue;
    }
    str = data[SC_FILE]+" : "+stime(time(), SD_DATE | SD_TIME);
    str = ladjust ("--- "+str, 75, "-")+"\n";
    while (s-data[SC_SIZE] >= MAX_TXT_LEN) {
      str =  str
            +read_bytes(data[SC_FILE], data[SC_SIZE], MAX_TXT_LEN);
      msg(str);
      str = "";
      data[SC_SIZE] += MAX_TXT_LEN;
    }
    str =  str
          +read_bytes (data[SC_FILE], data[SC_SIZE], s-data[SC_SIZE])
          +mkstr (75, "--")+"\n";
    msg(str);
    scopes[S_DATA][i][SC_SIZE] = s;
  }
}

/*-------------------------------------------------------------------------
** Start/Stop overall scoping.
*/

start_stop (int start) {
  if (start && !scopeon) {
    update_scopes(0);
    call_out ("_check_scopes", interval);
  }
  if (!start && scopeon) remove_call_out ("_check_scopes");
  scopeon = start;
}

/*-------------------------------------------------------------------------
** Command 'scope'
*/

int fscope (string arg) {
  string *args;
  int i, newint;
  mixed *data;

  if (!check_owner()) return 0;
  USAGE (arg == "?",
 "scope\n"
 "  Lists all important data about the scopes.\n"
 "scope <name> <filename>\n"
 "  Set a scope on <filename> under <name> and start it.\n"
 "scope <name> [on | off]\n"
 "  Start/stop scoping on <name> ('on' is default).\n"
 "scope <name> remove\n"
 "  Remove the scope <name>.\n"
 "scope on | off\n"
 "  Start/stop all scoping.\n"
 "scope <int>\n"
 "  Set the scope interval to <int> seconds.\n"
 "scope save\n"
 "  Save the scope settings into ~/.scope.o\n"
 "scope load\n"
 "  Load the scope settings from ~/.scope.o\n"
        );

  update_scopes(1);

  if (!arg) {
    write ("LPC-Scope "+VER_REV+" ["+REVTAG+"]\n");
    if (sizeof(scopes[S_KEY])) {
      for (i = 0; i < sizeof(scopes[S_KEY]); i++) {
        data = scopes[S_DATA][i];
        write ("  "+ladjust(scopes[S_KEY][i], 10)
               +(data[SC_SCOPED]?" + ":" - ")
               + data[SC_FILE]
               +"\n"
              );
      }
    }
    else write ("  No scope set.\n");
    write ("Interval: "+interval+" sec.\n");
    write ("Overall scoping: "+(scopeon?"On":"Off")+"\n");
    return 1;
  }

  args = explode(arg, " ");
  if (sizeof(args) > 2) FAIL("Too much arguments.\n");
  if (sizeof(args) < 2) {
    if (args[0] == "save") {
      return save_scope(0);
    }
    if (args[0] == "load") {
      return load_scope(0);
    }
    if (args[0] == "on") {
      start_stop(1); write ("Overall scoping: On.\n");
      save_scope(1);
      return 1;
    }
    if (args[0] == "off") {
      start_stop(0); write ("Overall scoping: Off.\n");
      save_scope(1);
      return 1;
    }
    if (sscanf(args[i], "%d", newint) && ""+newint == args[i]) {
      interval = newint;
      save_scope(1); // Save scope quiet
      write ("Interval: "+interval+" sec.\n");
      return 1;
    }
    args += ({ "on" });
  }
  data = assoc (args[0], scopes);
  if ((i = member(({ "on", "off", "remove" }), args[1])) != -1) {
    if (!data) FAIL ("No scope on '"+args[0]+"' set.\n");
    switch (i) {
      case 0: data[SC_SCOPED] = 1;
              data[SC_SIZE] = file_size(data[SC_FILE]);
              scopes = order_alist(insert_alist (args[0], data, scopes));
	      save_scope(1); // Save scope quiet
              write ("Scoping on '"+data[SC_FILE]+"' activated.\n");
              break;
      case 1: data[SC_SCOPED] = 0;
              scopes = order_alist(insert_alist (args[0], data, scopes));
	      save_scope(1); // Save scope quiet
              write ("Scoping on '"+data[SC_FILE]+"' deactivated.\n");
              break;
      case 2: scopes = order_alist(remove_alist (args[0], scopes));
	      save_scope(1); // Save scope quiet
              write ("Scope on '"+data[SC_FILE]+"' removed.\n");
              break;
    }
    return 1;
  }

  if (!geteuid(ME))
    write ("Warning: This scope has no euid. You possibly can't do that.\n");

  if (data)
    write ("Warning: Overriding old scope '"+args[0]+"' on "
           +data[SC_FILE]+"\n"
          );
  args[1] = (string) PL->get_path(args[1]);
//  if ((i = file_size(args[1])) < 0)
//    FAIL(args[1]+" is a dir or not existing.\n");
  if ((i = file_size(args[1])) == -2)
    FAIL(args[1]+" is a dir.\n");
  data = ({ args[1], 1, i });
  scopes = order_alist(insert_alist (args[0], data, scopes));
  save_scope(1); // Save scope quiet
  write ("Scope '"+args[0]+"' on '"+args[1]+"' set and activated.\n");
  return 1;
}

/*************************************************************************/
