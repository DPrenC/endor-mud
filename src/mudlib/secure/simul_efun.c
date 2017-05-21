/**
 * secure/simul_efun.c
 *
 * Funciones globalmente accesibles. Se comportan como si fuesen efuns pero
 * no estan directamente implementadas dentro del gamedriver.
 */

#pragma strict_types

#include "/secure/wizlevels.h"
#include <config.h>
#include "/secure/wizlist.h"
#include <strings.h> //Para el TRIM
#include <sounds.h>
#include <messages.h>
#include <files.h> // Para el get_dir

#define CAN_SEE_USERS ({CHRONOS, "/"+QUESTMASTER, "/"+CHANNELMASTER, "/"+MASTER})

#define BACKBONE_WIZINFO_SIZE 6
#define BOOTTIME_INDEX 5

#undef TO
#define TO       efun::this_object()
#undef TI
#define TI       efun::this_interactive()
#undef TP
#define TP       efun::this_player()
#undef PRE
#define PRE      efun::previous_object()
#define LEVEL(x) (int)MASTER->query_wiz_level(x)
#define NAME(x)  capitalize(getuid(x))
#define SRV_PORT 9538


// How much call_out()s are allowed at once?

#define CALL_OUT_WARN 1000  // limit for re-enabling
#define CALL_OUT_MAX  1200  // upper limit

#define MAX_LOG_SIZE 50000

// set the current object to be the previous object so we can do clean
// call_other()s.

#define FAKE_OBJECT set_this_object(PO)

//---------------------------------------------------------------------------
// Submodules. Inherit at this point could be harmful.

#include "/secure/sefun_search.ic"

public void dtell(string whom, string what);
public int query_wiz_level(mixed player);
public nomask varargs int send_server_request(string request, int id, varargs string *extra);
private int _log_file(string file, string txt);

//----------------------------------------------------------------------------
//--- obsolete efuns (have been moved from the GD into this file) ------------
//----------------------------------------------------------------------------

// lare = log and raise error ;)
private void _lare(string x, string y) {
    x = sprintf("[%O] '%s' usada por %O.", ctime(), x, PO);
    _log_file("OUTDATED", x + "\n\t" + y + ".\n");
    raise_error(x + " " + y + ".\n");
}

/* // [Nyh]
 En este momento doy fe que las siguientes funciones no se usan en ninguna
 parte del mud, asi que espero que siga siendo asi por siempre jamas.
*/
public varargs void    add_verb()         { _lare("add_verb()",         "This function is now obsolete"); }
public varargs void    add_xverb()        { _lare("add_xverb()",        "This function is now obsolete"); }
public varargs mapping allocate_mapping() { _lare("allocate_mapping()", "Renamed to 'm_allocate()'");     return ([]); }
public varargs mapping copy_mapping()     { _lare("copy_mapping()",     "Superseeded by 'copy()'.\n");    return ([]); }
public varargs void    efun308()          { _lare("efun308()",          "Renamed to 'set_environment()'"); }
public varargs string  extract()          { _lare("extract()",          "Use str[from..to] instead");     return ""; }
public varargs string  file_name()        { _lare("file_name()",        "Renamed to 'object_name()'");    return ""; }
public varargs mixed*  filter_array()     { _lare("filter_array()",     "Obsoleted by 'filter()'");       return ({}); }
public varargs mapping filter_mapping()   { _lare("filter_mapping()",   "Renamed to 'filter_indices()'"); return ([]); }
public varargs int     m_sizeof()         { _lare("m_sizeof()",         "Old alias for 'sizeof()'");      return 0; }
public varargs mixed*  map_array()        { _lare("map_array()",        "Obsoleted by 'map()'");          return ({}); }
public varargs mapping map_mapping()      { _lare("map_mapping()",      "Renamed to 'map_indices()'");    return ([]); }
public varargs int     mapping_contains() { _lare("mapping_contains()", "Renamed to 'm_contains()'");     return 0; }
public varargs int     member_array()     { _lare("member_array()",     "Superseeded by 'member()'");     return 0; }
public varargs int     query_imp_mud()    { _lare("query_imp_mud()",    "Renamed to 'query_udp_port()'"); return 0; }
public varargs void    set_auto_include_string() { _lare("set_auto_include_string()", "Replaced with driver hook H_AUTO_INCLUDE"); }
public varargs mixed*  slice_array()      { _lare("slice_array()",      "Use arr[from..to] instead");     return ({}); }

public varargs void    add_worth()               { _lare("add_worth()",           "This function is now obsolete"); }
static varargs void    clean_name_living_m()     { _lare("clean_name_living_m()", "This function is now obsolete"); }
public varargs void    set_living_name()         { _lare("set_living_name()",     "This function is now obsolete"); }
public varargs string  version()                 { _lare("version()",             "This function no longer exists. Use __VERSION__ instead"); return __VERSION__; }
public varargs string  query_host_name()         { _lare("query_host_name()",     "This function no longer exists. Use __HOST_NAME__ instead"); return __HOST_NAME__; }
public varargs object* find_clones()             { _lare("find_clones()",         "This function no longer exists. Use clones() instead"); return 0; }

// Write some text into a logfile. If the size of the logfile exceeds
// the maximum logfile size then backup the file an start with a new one.

// Si queremos logear algo que ocurre aqui dentro usamos _log_file para evitar
// que se realice un FAKE_OBJECT
private int _log_file(string file, string txt) {
    if (file[0..4] != LOGPATH) file = LOGPATH + file;
    file = (string)MASTER->make_path_absolute(file);
    if (file_size(file) > MAX_LOG_SIZE) catch(rename(file, file + "." +to_string(time())));
    return write_file(file, txt);
}

public int log_file(string file, string txt) {
  if (file[0..4] != LOGPATH) file = LOGPATH + file;
  file = (string)MASTER->make_path_absolute(file);
  if (file_size(file) > MAX_LOG_SIZE) catch(rename(file, file + "." +to_string(time())));
  FAKE_OBJECT;
  return write_file(file, txt);
}

// Return the creation date of a file. The integer value then can be passed
// to the efun ctime().

public int file_date(string file) {
  mixed *data;
  return sizeof(data = get_dir(file, GETDIR_DATES)) ? data[0] : 0;
}

varargs void wizlist(string name) {
    int i, pos, total_cmd;
    int *cmds;
    mixed *a;
    mixed *b;

    if (!name) {
        name = (string) TP->QueryRealName();
        if (!name) return;
    }
    a = transpose_array(wizlist_info());
    cmds = a[WL_COMMANDS];
    a[WL_COMMANDS] = a[0];
    a[0] = cmds;
    a = order_alist(a);
    cmds = a[0];
    a[0] = a[WL_COMMANDS];
    a[WL_COMMANDS] = cmds;

    if ((pos = member(a[WL_NAME], name)) < 0 && name != "ALL")
        return;
    b = allocate(sizeof(cmds));
    for (i = sizeof(cmds); i;) {
        b[<i] = i;
        total_cmd += cmds[--i];
    }
    a = transpose_array(a + ({b}) );
    if (name != "ALL") {
        if (pos + 18 < sizeof(cmds)) {
            a = a[pos-2..pos+2]+a[<15..];
        } else if (pos < sizeof(cmds) - 13) {
            a = a[pos-2..];
        } else {
            a = a[<15..];
        }
    }

    write("\nWizard top score list\n\n");
    printf("%-15s %5s %3s (%3s) [%8sk, %8s, %8sk, %8s, %8s] %8s %8s %8s %8s %8s\n",
        "User ID","CMDs","%CM","Pos","WCost", "WGCost", "TCost", "TWCost","HBs","COs","ArrayT","MappingT","StructT","Extra");
    if (total_cmd == 0)
        total_cmd = 1;


    for (i = sizeof(a); i--; ) {
        b = a[i];
        printf("%-15s %5d %2d%% (%3d) [%8dk, %8d, %8dk, %8d, %8d] %8d %8d %8d %8d %8d\n",
          b[WL_NAME], b[WL_COMMANDS], b[WL_COMMANDS] * 100 / total_cmd, b[<1],
          b[WL_COST          ] / 1000,
          b[WL_GIGACOST      ],
          b[WL_TOTAL_COST    ] / 1000,
          b[WL_TOTAL_GIGACOST],
          b[WL_HEART_BEATS   ],
          b[WL_CALL_OUT      ],
          b[WL_ARRAY_TOTAL   ],
          b[WL_MAPPING_TOTAL ],
          b[WL_STRUCT_TOTAL  ],
          b[WL_EXTRA         ]
        );
    }
    printf("\nTotal         %7d     (%3d)\n\n", total_cmd, sizeof(cmds));
}

public void dtell(string whom, string what) {
  object ob;
  if (ob = find_object(lower_case(whom))) tell_object(ob, what);
}

//----------------------------------------------------------------------------
// --- end of obsolete functions ---------------------------------------------
//----------------------------------------------------------------------------

void start_simul_efun() {
    mixed *info;

    if ( !(info = get_extra_wizinfo(0)) ) {
        set_extra_wizinfo(0, info = allocate(BACKBONE_WIZINFO_SIZE));
        info[BOOTTIME_INDEX] = time();
    }
}

/* If the simul_efun is reloaded, there is a valid master, but it won't
 * call start_simul_efun()
 */
void create() {
    start_simul_efun();
}

//--- IP name resolving -----------------------------------------------------

public string country(mixed arg) {
  seteuid(getuid()); /* We need it if loading of /lib/country is neccessary */
  return (string) "/lib/country"->country(arg);
}

//--- redefined efuns -------------------------------------------------------


// Sobrecargo get_dir para q no pille el ".svn"
/*
[Nyh] Actualmente hay varias inconsistencias en la efun get_dir.
    - El uso de GETDIR_PATH funciona un poco extraño... incluye de por si el
      names.
      get_dir(string, 16) devuelve get_dir(string, 17) pero
      get_dir(string, 32) devuelve get_dir(string, 0)
    - Si la mascara es solo GETDIR_SIZES siempre sale como si fuese
      GETDIR_SIZES|GETDIR_UNSORTED...
      *** Extraido del archivo de codigo fuente q define esta efun: ***
      * Note: You should use GETDIR_NAMES|GETDIR_UNSORTED to get the entries
      * in the same order as with GETDIR_SIZES and GETDIR_DATES.
      Mantengo este comportamiento en mi sefun añadiendo GETDIR_UNSORTED en
      estos casos (por que si no luego buscareis el "CVS" en un array con otro
      orden
*/
public nomask string *get_dir(string str, varargs mixed *mask) {
    if (!sizeof(mask)) { //Este es el caso facil
        return (mask = efun::get_dir(str))?(mask-=({".svn"})):0;
    }
    else { // Ahora lo jodido...
        int i = mask[0], cvspos, del = 0;
        if (!(mask = efun::get_dir(str, i))) return 0;
        switch (i) {
            case GETDIR_EMPTY:
            case GETDIR_UNSORTED:
                return mask;
            case GETDIR_NAMES: // Estos los pongo aqui por eficiencia.
            case 33: // GETDIR_NAMES|GETDIR_UNSORTED
                return mask -= ({ ".svn" });
            case GETDIR_SIZES:
            case GETDIR_DATES:
            case 6: // GETDIR_SIZES|GETDIR_DATES
                i = i & GETDIR_UNSORTED; // Ver por que hago esto arriba
        }
        if (i&GETDIR_SIZES) del++;
        if (i&GETDIR_DATES) del++;
        if (i&GETDIR_PATH) { // Tenemos un puto path, lo trato como sin names
            del++;           // porque en la efun este se superpone al otro.
            i = i & (~GETDIR_NAMES);
        }
        if (i&GETDIR_NAMES) { // facil, tenemos "CVS"
            del++;
            cvspos = member(mask, ".svn");
        }
        else { // no tenemos nada, llamo a get_dir para ver donde estaria
            cvspos = del * member(efun::get_dir(str, GETDIR_NAMES|(i&GETDIR_UNSORTED)), ".svn");
        }
        if (cvspos >= 0) return mask = mask[..cvspos-1] + mask[cvspos+del..];
        return mask;
    }
    return 0; // imposible llegar aqui, pero bueno...
}


public nomask void destruct(object ob) {
  if (objectp(ob) && interactive(ob) && TP && interactive(TP)) {
//    _log_file("/SIMUL_EFUN",sprintf("PO: %O TP: %O TI: %O llamo a destruct(ob)\n",PO,TP,TI,ob));
    if (    (    (ob->QueryIsPlayer()&&LEVEL(ob))
              >= (TP->QueryIsPlayer()&&LEVEL(TP))
            )
         && ob != TP
       )
    {
      tell_object(ob, "[1m[31m¡"+NAME(TI)+" ha intentado destruirte![0m[39m\n");
      return;
    }
  }
  efun::destruct(ob);

}

public varargs nomask int command(string str, object ob) {
  int rc;

  //dtell("nyh",sprintf("[36mPO: %O TP: %O did command[39m(%O, %O)\n", PO, TP, str, ob));

  FAKE_OBJECT;

  if ( ob && ob != TO) return (int)ob->command_me(str);
  TO->SetCmdData("ThisPlayer", TP);
  // The 'TP->PushCmdData()' is done by the modify_command-hook.
  if ((rc = efun::command(str)) && TP)
    TP->PopCmdData(); // No failure, else the driver hook already popped it.
  return rc;
}

public varargs nomask int notify_fail(mixed msg, int pri) {
  if (TP)
  {
    FAKE_OBJECT;
    TP->NotifyFail(msg, pri);
  }
  return 0;
}

public nomask int transfer(object item, object dest) {
  FAKE_OBJECT;
  return (int) item->move(dest);
}

public nomask void set_this_player(object obj) {
  if (!PRE || (obj != PRE && to_string(PRE)[0..7] != SECUREPATH)) {
    raise_error("Illegal attempt to change TP.\n");
    return;
  }
  FAKE_OBJECT;
  efun::set_this_player(obj);
}

public nomask void set_environment(object item, object dest) {
  if (!PRE || to_string(PRE)[0..7] != SECUREPATH) {
    raise_error("Illegal attempt to use set_environment().\n");
    return;
  }
  FAKE_OBJECT;
  efun::set_environment(item, dest);
}


public nomask mixed remove_interactive(object victim) {
  if (!victim || !interactive(victim))
    return 0;
  if (   (PRE && getuid(PRE) == ROOTID)
      || (TI && LEVEL(TI) >= ARCH_LVL)
      || (TI && victim == TI && TP == TI)
     )
    return efun::remove_interactive(victim);

  catch(_log_file("DESTRUCT", ctime()+": "+capitalize((string)victim->QueryRealName())
+"\n    remove_interactive() by "
+(PRE ? (object_name(PRE)+" ["+getuid(PRE)+"]") : "???")
+"\n"));
  return 0;
}

//----------------------------------------------------------------------------

#define NAS_MIN_LEVEL ARCH_LVL

/**
 * [Nyh] El nuevo comportamiento del espiar sera el siguiente:
 *       Podrás espiar a la vez a tanta gente como quieras (antes no era asi)
 *       Solo podran espiar los wizs (aunque en un futuro nadie descarta que
 *        algún hechizo de adivinacion no permita hacer algo parecido a los
 *        players)
 *       Cuando un wiz espía o deja de espiar TODOS los wizs de igual o mayor
 *        nivel seran notificados. Esto es asi porque el espiar es algo muy
 *        serio y que solo debe de utilizarse cuando sea estrictamente
 *        necesario. Puede que incluso guarde logs de las espias realizadas.
 */

// Si ob == 0 usa ob = TP
// Envia un mensaje msg a todos los que tengan mayor nivel de wiz que ob
public varargs void _supertell(string msg, object ob) {
    int niv = 0;

    if (!ob && !(ob = TP)) niv = 0;
    else niv = LEVEL(ob);

    filter(users(), (: (LEVEL($1)>=$2)?(tell_object($1, $3),1):0 :), niv, msg);
}

public nomask varargs int snoop(object me, object you) {
  int ret = 0;

  if (!TI || !IS_WIZARD(TI)) {
    _supertell(NAME(me)+" ha intentado espiar ilegalmente a a "+NAME(you)+".\n", me);
    _log_file("SNOOP","["+ctime()+"] "+NAME(me)+" ha intentado espiar ilegalmente a a "+NAME(you)+".\n");
    return 0;
  }

  if (!you) {
    // 'me' quiere dejar de espiar
    if (ret = efun::snoop(me)) {
        // Y lo consigue, notificar en consecuencia
        _supertell(NAME(me)+" ha dejado de espiar.\n", me);
    }
    else {
        // Y no lo consigue, notificar en consecuencia
        _supertell(NAME(me)+" ha intentado dejar de espiar pero ha fallado miserablemente.\n", me);
    }
    return ret;
  }

// 'me' quiere espiar a 'you' a ver que pasa...
  switch (ret = efun::snoop(me, you)) {
    case -1: // No se ha realizado la espia porque habría producido un bucle
    case 0: // No se ha producido la espia por algun otro fallo
        _supertell(NAME(me)+" ha intentado espiar a " + NAME(you) +
                   " pero ha fallado miserablemente.\n", me);
        break;
    case 1: // La espia ha comenzado con éxito
        _supertell(NAME(me)+" ha empezado a espiar a "+NAME(you)+".\n", me);
        break;
    default:
        _supertell(NAME(me)+" ha intentando espiar a "+NAME(you)+" y la "
                   "funcion snoop ha devuelto un valor extraño: "+ret+".\n", me);
  }
  return ret;
}

public nomask object query_snoop(object snoopee) {
  object snooper;

  if (   snoopee
      && (snooper = efun::query_snoop(snoopee))
      && (   (TI && geteuid(PRE) == geteuid(TI) && LEVEL(TI) >= LEVEL(snooper))
          || (geteuid(PRE) == geteuid(snoopee) && LEVEL(PRE) >= LEVEL(snooper))
          || (LEVEL(snooper) < NAS_MIN_LEVEL)
         )
    )
    return snooper;
  return 0;
}

//----------------------------------------------------------------------------

// Log shutdowns.

void mighty_shutdown()
{
  efun::shutdown();
}

public nomask void shutdown() {
  object *usr;
  int i;

  if(TP && PRE) {
    catch(_log_file("GAME_LOG", ctime(time()) + " shutdown() on "
                         +__HOST_NAME__+"\n" +
             " previous:    " + object_name(PRE) + " [" + getuid(PRE) + "]\n" +
             " player:      " + object_name(TP)  + " [" + getuid(TP)  + "]\n" +
             " interactive: " + (TI ? getuid(TI) : "(none)") + "\n"));
     send_server_request("shutdown");
     efun::shutdown();
  }
}

//--- simul efuns for general mudlib support --------------------------------

// Return the content of a directory like the efun get_dir() does but also
// extend the filenames with some special identification characters:
// a "/" will be appended to directories and
// a "*" will be appended to files which have been loaded or inherited

string *get_dir_ext(string path) {
  string *strs, file;
  mixed *finfo;
  int i, s;

  finfo = get_dir(path, GETDIR_NAMES | GETDIR_SIZES);
  if(finfo && (s = sizeof(finfo))) {
    strs = (string*)MASTER->full_path_array(path, TP ? getuid(TP) : 0);
    path = sizeof(strs) ? "/" + implode(strs[0..<2], "/") + "/" : "/";
    strs = ({});
    while(s--, s-- > 0) {
      file = finfo[i++];
      switch(finfo[i++]) {
      case -2:
        file += "/";
        break;
      case -1:
        file += "@";
        break;
      default:
        if(find_object(path + file))
          file += "*";
      }
      strs += ({ file });
    }
  }
  return strs;
}

public int query_wiz_level(mixed player) {
  return LEVEL(player);
}

public int query_boot_time() {
  mixed *info;
  if ( !(info = get_extra_wizinfo(0)) || sizeof(info) <= BOOTTIME_INDEX)
    return 0;
  return info[BOOTTIME_INDEX];
}

public varargs string query_wiz_tag(mixed player, int flags) {
  int lvl;
  FAKE_OBJECT;
  lvl = LEVEL(player);
  if (lvl >= ARATAR_LVL) return (flags & 1) ? "Aratar" : "Aratar";
  if (lvl >= VALA_LVL) return (flags&1) ? "Vala" : "Vala";
  if (lvl >= HERALDO_LVL) return (flags & 1) ? "Heraldo" : "Heral";
  //if (lvl >= LORD_LVL && (flags&2)) return (flags&1) ? "Domainlord" : "Lord";
  //if (lvl >= WIZARD_LVL)  return (flags & 1) ? "Wizard" : "Wiz";
  if (lvl >= MAIA_LVL) return (flags & 1) ? "Maia" : "Maia";
  return 0;
}

public mixed *remove_alist(mixed key, mixed *alist) {
  int s, p;

  if((p = assoc(key, alist[0])) >= 0)
    for(s = sizeof(alist); s--; alist[s] = alist[s][0..p-1] + alist[s][p+1..]);
  return alist;
}

// Return the name of an object's blueprint.
public varargs string blueprint(mixed obj) {
  int p;

  if(stringp(obj))
    return (p = member(obj, '#')) < 0 ? obj : obj[0..p-1];
  else if(objectp(obj) || obj = PO)
    return (p = member(obj = object_name(obj), '#')) < 0 ? obj : obj[0..p-1];
  else return 0;
}

// Load a file and return the blueprint.
public varargs object load_object(string file, string creator) {
  object obj;
  if (!find_object(file) && file_size(file+".c") > 0)
  {
    FAKE_OBJECT;
    call_other(file, "???");
  }
  obj = find_object(file);
  if (!obj && creator)
  {
    obj = (object)creator->compile_object(file);
    if (!obj)
      obj = (object)creator->compile_object(file+".c");
    rename_object(obj, file);
  }
  return obj;
}

// Determine all environments of an object
public varargs object * all_environments(object obj)
{
  object * rc;

  rc = ({});
  if (!obj)
    obj = PO;
  while (environment(obj))
  {
    obj = environment(obj);
    rc += ({ obj });
  }
  return rc;
}

// Search for an object deeply
public varargs object deep_present(mixed what, object where)
{
  object rc, *objs;
  int i;

  rc = present(what, where || PRE);
  if (!rc)
  {
    objs = deep_inventory(where||PRE);
    if (objectp(what))
      objs = objs & ({ what });
    else
    {
      for (i = 0; i < sizeof(objs); i++)
        if (objs[i]->id(what))
          break;
      objs = objs[i..];
    }
    rc = sizeof(objs) ? objs[0] : 0;
  }
  return rc;
}

// Terminal Colour Free String: Free a string of terminal_colour's substrings
public string tcfstr(string str) {
    return terminal_colour( str, ([ 0 : "" ]) );
}

//--- filename resolving for shortcuts --------------------------------------
public varargs string resolve_file(string file, object anchor) {
  switch (file[0]) {
  case '/': case '+': case '&': case '~':
    return (string) MASTER->make_path_absolute(file, getuid(anchor || PRE));
  }
  return (string) MASTER->make_path_absolute( object_name(anchor || PRE)
                                      + "/../"+file, getuid(anchor || PRE));
}

public string find_savefile(mixed pl) {
  if (objectp(pl)) pl = geteuid(pl);
  if (!stringp(pl)) return 0;
  pl = lower_case(pl);
  pl = "/"+SAVEPATH+pl[0..0]+"/"+pl;
  if (file_size(pl+".o") < 0) return 0;
  return pl;
}

//--- call_out-Emergency break ((c) Morgengrauen) ------------------------

static int CallOutStopped = 0;
static int CallOutCount = 0;
static int CountMessages = 0;
static string LastMessage;

public void call_out(mixed what, int delay, varargs mixed *args)
{
  object tmp;
  int num;
  string message;

  if (to_string(PO)[0..7] == SECUREPATH)
  {
    tmp = TO;
    FAKE_OBJECT;
    apply(symbol_function("efun::call_out"), what, delay, args);
    set_this_object(tmp);
    return;
  }

  if (CallOutStopped) {
    num = sizeof(efun::call_out_info());
    if (num < CALL_OUT_MAX/4) {
      message = "NOTE: call_outs reactivated, "+num+" pending.\n";
      catch(load_object(CHANNELMASTER)->SendMsg("error", message));
      catch(write_file("/log/CALLOUT",ctime()+" call_outs reactivated.\n"));
      CallOutStopped = 0;
    }
  }
  if (CallOutStopped) {
    message = sprintf("%O %O %O %O\n", PO, what, delay, args);
    if (LastMessage == message) CountMessages++;
    else {
      if (CountMessages) {
        catch(write_file("/log/CALLOUT",
                  sprintf("Last message repeated %d times.\n", CountMessages)
              ));
        CountMessages = 0;
      }
      catch(write_file("/log/CALLOUT", message));
      LastMessage = message;
    }
    return;
  }

  if (!(++CallOutCount%50)) {
    CallOutCount = 0;
    num = sizeof(efun::call_out_info());

    if (num > CALL_OUT_MAX) {
      message = "ERROR: Max number of call_outs exceeded. call_outs stopped.\n";
      catch(load_object(CHANNELMASTER)->SendMsg("error", message));

      catch(write_file("/log/CALLOUT",ctime()+" *** EMERGENCY BREAK: "
                                +num+" call_outs ***\n"));
      CallOutStopped = 1;
      return;
    }

    if (num > CALL_OUT_WARN) {
      message = sprintf( "WARNING: %d call_outs pending, upper limit is %d.\n",
                         num, CALL_OUT_MAX);
      catch(load_object(CHANNELMASTER)->SendMsg("error", message));
    }
  }
  tmp = TO;
  FAKE_OBJECT;
  apply(symbol_function("efun::call_out"), what, delay, args);
  set_this_object(tmp);
  return;
}

//---------------------------------------------------------------------------
// Funciones de dados
//---------------------------------------------------------------------------

#define FX  20 // esto es porq randoms pequeños no son homogeneos
private varargs int dice(int d, int num) {
	int res;
	if (d < 1) return 0;
	if (num < 1) num = 1;
	res = num;
	while (num--) res += random(d<<FX)>>FX;
	return res;
} //usar recursividad para esto es absurdo... :)

public varargs int d2(int num)   { return dice(  2,num); }
public varargs int d3(int num)   { return dice(  3,num); }
public varargs int d4(int num)   { return dice(  4,num); }
public varargs int d6(int num)   { return dice(  6,num); }
public varargs int d8(int num)   { return dice(  8,num); }
public varargs int d10(int num)  { return dice( 10,num); }
public varargs int d12(int num)  { return dice( 12,num); }
public varargs int d20(int num)  { return dice( 20,num); }
public varargs int d100(int num) { return dice(100,num); }

public int d20Check() {
  int res;
  switch (res = d20()) {
    case  1: return res - d20Check(); break; //break porsiaca
    case 20: return res + d20Check(); break; //break porsiaca
  }
  return res;
}

public int d100Check() {
  int res;
  switch (res = d100()) {
    case 01.. 05: return res - d100Check(); break; //break porsiaca
    case 96..100: return res + d100Check(); break; //break porsiaca
  }
  return res;
}

//---------------------------------------------------------------------------
// Funciones matematicas
//---------------------------------------------------------------------------

///Sumar un array
/**
Hace el sumatorio de un array de numeros ENTEROS. (paso de hacerlo con floats)
Iba ha hacerla recursiva, pero seguro q gasta mas...
@param array el array de numeros
@return el sumatorio del array
*/
public int sum(int *array) {
    int tmp, res = 0;
    foreach(tmp: array) res += tmp;
    return res;
}

///Multiplicar un array
/**
Hace el ¿multiplicatorio/productorio? de un array de numeros ENTEROS. (paso de hacerlo con floats)
Iba ha hacerla recursiva, pero seguro q gasta mas...
La meto para q vaya de pareja con sum, pero no se si alguna vez se usara.
@param array el array de numeros
@return el multiplicatorio del array
*/
public int prod(int *array) {
    int tmp, res = 1;
    foreach(tmp: array) res *= tmp;
    return res;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Funciones de experiencia
//---------------------------------------------------------------------------
// [Nyh] si, tio, sigue una formula, y el ultimo nivel es 2072, luego overflow
public int level2xp(int l)	{ return (l*l-l)*500; }
// [Nyh] si, macho, me he despejado la formula inversa... y aqui la planto:
public int xp2level(int xp) { return (1+to_int(pow(1+xp/125,1.0/2)))/2; }
//---------------------------------------------------------------------------

public nomask string get_file_extension(string file)
{
    int ind = strrstr(file, ".");
    if (ind == -1 ||ind == strlen(file)) return 0;
    return file[ind + 1..];
}

public nomask string remove_file_extension(string file)
{
    string ext;
    if (!(ext = get_file_extension(file))) return file;
    return file[..(strlen(file) - strlen(ext) - 2)];
}


private varargs int valid_mysql(string fun, string query)
// valida si un objeto puede usar las funciones mysql
{
    object ob = PO;
    if (!ob) return 0;
    if (object_name(ob) != DBMASTER && !IS_CON(getuid(ob)))
    {
        log_file("ILLEGAL_MYSQL",
                 ctime() + ":" + getuid(ob) + " intentó ejecutar la función " + fun +
                 (query ? " con la sentencia '" + query + "'" : "") + ".\n\n");
        if (living(ob)) tell_object(ob, "¡No tienes permiso para ejecutar esta función!\n");
        return 0;
    }
    return 1;
}

//---------------------------------------------------------------------------
// Funciones mysql

public nomask int db_connect(string db, string user, string password)
{
    if (!valid_mysql("db_connect")) return 0;
    return efun::db_connect(db, user, password);
}

public nomask int db_affected_rows(int handle)
{
    if (!valid_mysql("db_affected_rows")) return 0;
    return efun::db_affected_rows(handle);
}

public nomask string *db_coldefs(int handle)
{
    if (!valid_mysql("db_coldefs")) return 0;
    return efun::db_coldefs(handle);
}

public nomask int db_close(int handle)
{
    if (!valid_mysql("db_close")) return 0;
    return efun::db_close(handle);
}

public nomask int db_exec(int handle, string consulta)
{
    if (!valid_mysql("db_exec", consulta)) return 0;
    return efun::db_exec(handle, consulta);
}

public nomask int db_insert_id(int handle)
{
   if (!valid_mysql("db_insert_id")) return 0;
    return efun::db_insert_id(handle);
}

public nomask mixed db_fetch(int handle)
{
    if (!valid_mysql("db_fetch")) return 0;
    return efun::db_fetch(handle);
}

public nomask string db_error(int handle)
{
    if (!valid_mysql("db_error")) return 0;
    return efun::db_error(handle);
}

public nomask int *db_handles()
{
    if (!valid_mysql("db_handles")) return 0;
    return efun::db_handles();
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Mud Sound Protocol

private int _can_hear_sound(object ob, string sound, int type)
// devuelve 1 si el objeto puede escuchar el sonido, 0 en caso contrario
{
    // if (!ob->CanHear()) return 0;
    // lo comento mientras hagamos algo que distinga entre sonidos de estado y sonidos reales
    if (type == IS_SOUND && (!ob->QuerySounds() || !ob->QuerySoundEnabled(sound))) return 0;
    if (type == IS_MUSIC && (!ob->QueryMusic() || !ob->QueryMusicEnabled(sound))) return 0;
    return 1;
}

private void _send_audio_str(object ob, string name, string sound, int volume, int type)
// envía la cadena de sonido o música al objeto <ob>, con el volúmen <volume>,
// o de no haberlo, con el volúmen por defecto del jugador para ese tipo de sonido: música o sonido.
// A su vez, ajusta LastSound o LastMusic al jugador, para tener constancia del último escuchado
{
    string format, ext;
    if (!ob) return;
    if (type == IS_OFF)
    // se va a detener, así que no se hacen comprobaciones
    {
        if (   (strstr(sound, SOUND_START_STR) == 0 && ob->QuerySounds())
            || (strstr(sound, MUSIC_START_STR) == 0 && ob->QueryMusic()))
        {
            ob->TellDirectly(sound + ")\n");
        }
        return;
    }
    format = (string)ob->QuerySoundFormat();
    name = regreplace(name, "@EXT@", format, 0);
    sound = regreplace(sound, "@EXT@", format, 1);
    if (!_can_hear_sound(ob, name, type)) return;
    ob->TellDirectly(sound +
                     (!volume && (volume = (type == IS_SOUND ? ob->QuerySoundVolume() :
                               ob->QueryMusicVolume())) ? " V=" + volume : "") + ")\n");
    if (type == IS_SOUND) ob->SetLastSound(name);
    else if (type == IS_MUSIC) ob->SetLastMusic(name);
}


private void _send_audio_to_players(object *obs, string name, string sound, int volume, int type)
// Busca en obs los players existentes y los players dentro de las rooms existentes,
// y les manda el sonido o musica especificado
{
    object *players, *rooms;
    players = filter(obs, (:if (!query_once_interactive($1)) return 0; _send_audio_str($1, $2, $3, $4, $5); return 1;:),
                     name, sound, volume, type);
    rooms = obs - players || ({});
    filter(rooms, (:member(inherit_list($1), ROOM + ".c") >= 0 ?
                    filter((all_inventory($1) - $6), (:(query_once_interactive($1) ?
                                                        _send_audio_str($1, $2, $3, $4, $5) : 0):),
           $2, $3, $4, $5) :
           0:), name, sound, volume, type, players);
}


private varargs void _stop_sound_or_music(mixed ob, mixed exclude, int type)
{
    string str;

    if ((!pointerp(ob) && !objectp(ob)) || (exclude && !pointerp(exclude) && !objectp(exclude)))
    {
        raise_error("Error en la llamada a " + (type == IS_MUSIC ? "stop_music" : "stop_sounds") +
                    ". Asegúrate de haber introducido los parámetros en el orden y con los tipos correctos.\n");
    }
    if (objectp(ob)) ob = ({ob});
    else ob -= ({0});
    if (exclude)
    {
        if (objectp(exclude)) exclude = ({exclude});
        else exclude -= ({0});
        if (!sizeof(ob -= exclude)) return;
    }

    str = (type == IS_MUSIC ? MUSIC_START_STR + "(" + MUSIC_OFF : SOUND_START_STR + "(" + SOUND_OFF);
    _send_audio_to_players(ob, type == IS_SOUND ? SOUND_OFF : MUSIC_OFF, str, 0, IS_OFF);
}

public nomask varargs void stop_sounds(mixed ob, mixed exclude)
{
    return _stop_sound_or_music(ob, exclude, IS_SOUND);
}

public nomask varargs void play_sound(mixed ob,  string name, mixed exclude, int volume, int loop, int priority, string type)
{
    string sound, ext;
    int i;
    object *players, *rooms;

    if (!name || (!pointerp(ob) && !objectp(ob)) || (exclude && !pointerp(exclude) && !objectp(exclude)))
    {
        raise_error("Error en la llamada a play_sound. Asegúrate de haber introducido los parámetros en el orden y con los tipos correctos.\n");
    }

    if (objectp(ob)) ob = ({ob});
    else ob -= ({0});
    if (exclude)
    {
        if (objectp(exclude)) exclude = ({exclude});
        else exclude -= ({0});
        if (!sizeof(ob -= exclude)) return;
    }

    sound = SOUND_START_STR "(";

    if (name == "Off")
    // se detienen todos los sonidos
    {
        return stop_sounds(ob, exclude);
    }
    if ((ext = get_file_extension(name)) != 0 && strlen(ext) == 3 && member(SOUND_SUPPORT, ext) >= 0)
    {
        name = remove_file_extension(name) + ".@EXT@";
    }
    else if (!ext) name += ".@EXT@";
    // si el fichero no tiene extensión, bien porque se la hayamos quitado para adecuarla al
    // formato del jugador, bien porque ya de por si los programadores no se la hayan puesto,
    // se añade al name @EXT@, que se reemplazará por la extensión que cada
    // jugador tenga, en la función correspondiente

    sound += name;
    // @EXT@, de haberla,  se reemplaza por la extensión que cada jugador tenga establecida en sus sonidos

    if (volume)
    {
        if (volume > 100) volume = 100;
        else if (volume <= 0) volume = 1;
        sound += " V=" + volume;
    }

    if (loop)
    {
        if (loop < -1) loop = -1;
        sound += " L=" + loop;
    }

    if (priority)
    {
        if (priority < 0) priority = 0;
        else if (priority > 100) priority = 100;
        sound += " P=" + priority;
    }

    if (type)
    {
        sound += "T=" + type;
    }
    sound += " U=" + SOUND_URL + "@EXT@/";

    _send_audio_to_players(ob, name, sound, volume, IS_SOUND);
}

public nomask varargs void stop_music(mixed ob, mixed exclude)
{
    return _stop_sound_or_music(ob, exclude, IS_MUSIC);
}


public nomask varargs void play_music(mixed ob, string name, mixed exclude, int volume, int loop, int contin, string type)
{
    string music;
    object *rooms, *players;

    if (!name || (!pointerp(ob) && !objectp(ob)) || (exclude && !pointerp(exclude) && !objectp(exclude)))
    {
        raise_error("Error en la llamada a play_music. Asegúrate de haber introducido los parámetros en el orden y con los tipos correctos.\n");
    }

    if (objectp(ob)) ob = ({ob});
    else ob -= ({0});
    if (exclude)
    {
        if (objectp(exclude)) exclude = ({exclude});
        else exclude -= ({0});
        if (!sizeof(ob -= exclude)) return;
    }

    music = MUSIC_START_STR "(";

    if (name == "Off")
    // se detienen todos los sonidos
    {
        return stop_music(ob);
    }
    music += name;
    if (volume)
    {
        if (volume > 100) volume = 100;
        else if (volume <= 0) volume = 1;
        music += " V=" + volume;
    }

    if (loop)
    {
        if (loop < -1) loop = -1;
        music += " L=" + loop;
    }

    if (contin)
    {
        if (contin < 0) contin = 0;
        else if (contin > 1) contin = 1;
        music += " C=" + contin;
    }

    if (type)
    {
        music += "T=" + type;
    }

    music += " U=" + SOUND_URL + "@EXT@/";

    _send_audio_to_players(ob, name, music, volume, IS_MUSIC);
}




//---------------------------------------------------------------------------

public nomask varargs int send_server_request(string request, int id, varargs string *extra)
{
    string *supported_requests = ({"SendAuthCode", "RegeneratePassword", "ChangeEmail", "SendAdmin", "shutdown"});
    string udp_msg;
    if (!request)
    {
        return raise_error("Se necesita una petición para ejecutar esta función.\n"), 0;
    }
    if (!id && request != "SendAdmin" && request != "shutdown")
    {
        raise_error("Debes especificar una ID para enviar la petición.\n");
    }
    if (id && !MASTER->find_userinfo(id))
    {
        return raise_error("La ID especificada no existe.\n"), 0;
    }
    if (member(supported_requests, request) < 0)
    {
        return raise_error("Petición no válida.\n"), 0;
    }
    if (request == "shutdown") udp_msg = "shutdown";
    else
    {
        udp_msg = request + "|" + id + "|" + implode(map(extra,
            lambda(({SYM(ex)}),
                   ({ SF(regreplace),
                      ({ SF(regreplace),
                         ({SF(to_string), SYM(ex)}),
                      "\n|\r\n", "@NL@", 1}),
                    "[|]", "@BV@", 1}))), "|");
    }
    return send_udp("127.0.0.1", SRV_PORT, udp_msg + "\n");
}

public nomask int send_udp(string host, int port, mixed message)
{
    object ob = PO;
    if (!ob) return 0;
    if (object_name(PO) == INETD || IS_CON(getuid(PO))) return efun::send_udp(host, port, message);
    return raise_error("No tienes permiso para ejecutar esta función.\n"), 0;
}


// Funciones obsoletas sobreescritas por sefuns

/* This sefun is meant to replace the deprecated efun cat().
 * Feel free to add it to your mudlibs, if you have much code using cat() or
 * want to use cat().
 */
#define CAT_MAX_LINES 50

varargs int cat(string file, int start, int num)
{
    if (extern_call())
        set_this_object(previous_object());

    int more;

    if (num < 0 || !this_player())
        return 0;

    if (!start)
        start = 1;

    if (!num || num > CAT_MAX_LINES) {
        num = CAT_MAX_LINES;
        more = strlen(read_file(file, start+num, 1));
    }

    string txt = read_file(file, start, num);
    if (!txt)
        return 0;

    tell_object(this_player(), txt);

    if (more)
        tell_object(this_player(), "*****TRUNCATED****\n");

    return strlen(txt & "\n");
}

