/**
 * SIMAURIA '/std/player/wiz_utils.c'
 */

#include <colours.h>
#include <moving.h>
#include <wizlevels.h>
#include <sounds.h>

#define DOC_PATH       "/doc/wizards/comandosX/"

#include "./wiz_utils.lib.ic"

/* ----------------------------------------------
 * Inicializa las variables globales que vamos a utilizar.
 */
public int QueryInwiz(); // std/wizard/description

static void inicializar_variables() {
 variable = ([]);
 scriptline=0;
 scriptsize=0;
 msgto=0;
 return;
}

/* ----------------------------------------------
 * Add_actions con todos los comandos para wizs.
 */
static add_wiz_utils_cmds()
{
 if (IS_LEARNER(TP))
 {
  add_action("xcmd_call"       ,"xcall",1);
  add_action("xcmd_callouts"   ,"xcallo",1);
  add_action("xcmd_clean"      ,"xclea",1);
  add_action("xcmd_clone"      ,"xclo",1);
  add_action("xcmd_cmds"       ,"xcm",1);
  add_action("xcmd_dbg"        ,"xdbg",1);
  add_action("xcmd_dclean"     ,"xdcle",1);
  add_action("xcmd_ddes"       ,"xdd",1);
  add_action("xcmd_des"        ,"xde",1);
  add_action("xcmd_dlook"      ,"xdl",1);
  add_action("xcmd_dupdate"    ,"xdu",1);
  add_action("xcmd_eval"       ,"xev",1);
  add_action("xcmd_forall"     ,"xfo",1);
  add_action("xcmd_goto"       ,"xgo",1);
  add_action("xcmd_grep"       ,"xgr",1);
  add_action("xcmd_hbeats"     ,"xhb",1);
  add_action("xcmd_help"       ,"xhelp");
  add_action("xcmd_ids"        ,"xid",1);
  add_action("xcmd_info"       ,"xinf",1);
  add_action("xcmd_inherit"    ,"xinh",1);
  add_action("xcmd_inventory"  ,"i");
  add_action("xcmd_inventory"  ,"inventario");
  add_action("xcmd_light"      ,"xli",1);
  add_action("xcmd_load"       ,"xloa",1);
  add_action("xcmd_look"       ,"xloo",1);
  add_action("xcmd_lpc"        ,"xlp",1);
  add_action("xcmd_man"        ,"xman",1);
  add_action("xcmd_more"       ,"xmor",1);
  add_action("xcmd_move"       ,"xmov",1);
  add_action("xcmd_msg"        ,"xmsg",1);
  add_action("xcmd_news"       ,"xnews",1);
  add_action("xcmd_npc"        ,"xnp",1);
  add_action("xcmd_player"     ,"xpl",1);
  add_action("xcmd_props"      ,"xprop",1);
  add_action("xcmd_quit"       ,"xqu",1);
  add_action("xcmd_revive"     ,"xre",1);
  add_action("xcmd_sh"         ,"xsh",1);
  add_action("xcmd_trace"      ,"xtrac",1);
  add_action("xcmd_trans"      ,"xtran",1);
  add_action("xcmd_update"     ,"xup",1);
  add_action("xcmd_who"        ,"xwh",1);
 }
 inicializar_variables();
}


/* ----------------------------------------------
 * Funciones principales de los comandos.
 */
static xcmd_man(str) {
    string pagina;

    if (!str || str=="?") return notify_fail("xman <comando>");
    pagina = DOC_PATH+str;
    if (file_size(pagina)>=0) {
        write("Manual de los comandos X (ayuda sobre '"+str+"'):\n");
        TI->more(pagina);
    }
    else return notify_fail("No hay ayuda disponible sobre '"+str+".");
    return 1;
}

static xcmd_news(str) {
    string pagina;

    if (str=="?") return notify_fail("xnews");
    pagina = DOC_PATH+"news";
    if (file_size(pagina)>=0) {
        write("Sistema de Noticias de los comandos X:\n");
        TI->more(pagina);
    }
    else return notify_fail("No se ha realizado ningun cambio a destacar.");
    return 1;
}

static int xcmd_trans(string str) {
    object obj;
    object old_env;

    if (!str || str=="?") return notify_fail("xtran(s) <objeto>");
    if ((obj=XFindObj(str))&&ENV(obj)) {
        if (obj==TI) return notify_fail("¡Ya estás a tu lado!\n");
        if (ENV(TI)==ENV(obj))
            return notify_fail("!"+CRNAME(obj)+" ya está a tu lado!\n");
        tell_room(ENV(obj), CRNAME(obj)+" desaparece.\n", ({ obj }));
        tell_room(ENV(TI), CRNAME(obj) + " ha sido teletransportad"
                         + (obj->QueryGenderEndString())+" a esta "
                         "habitación por "+CRNAME(TI)+".\n",({ TI }));
        old_env = environment(obj);
        MoveObj(obj, ENV(TI), 1);
        tell_object(TI,CRNAME(obj)+" viene a tu encuentro.\n");
        tell_object(obj, "Has sido teletransportad" + (obj->QueryGenderEndString())+" junto a "+CRNAME(TI)+".\n");
        log_file("TELETRANS", ctime() + ". " + CAP(NREAL(TI)) + " teletransportó a " + CAP(NREAL(obj)) + " a " + object_name(environment(TI)) + ", desde " + object_name(old_env) + ".\n");
    }
    else write("Fallo al teletransportar al objeto.\n");
    return 1;
}

static int xcmd_goto(string str) {
  object obj, tmp;

  if (str=="?")
  return notify_fail("xgo(to) [objeto]");
  if(!str) str="/d/limbo/comun/habitacion/limbo/torrewiz/rooms/"+geteuid()+"/workroom";
  if(!(obj=XFindObj(str))) {
    if(!(str=XFindFile(str))) return 1;
    if(catch(call_other(str, "???"))) return 1;
    obj=find_object(str);
  }
  tmp=obj;
  while(obj&&living(obj)) obj=ENV(obj);
  if (TI==obj)
   return notify_fail("Teletransportarte a donde tu estas?");
  if (ENV(TI)==ENV(obj) || ENV(TI)==obj)
   return notify_fail("Ya estás en ese lugar.");
  if (!QueryInwiz()) play_sound(({environment(), (obj ? obj : tmp)}), SND_SUCESOS("teleport"));
  else play_sound(filter(all_inventory(environment()) + all_inventory((obj ? obj : tmp)), (:query_once_interactive($1) && query_wiz_level($1):)), SND_SUCESOS("teleport"));

  TI->move(obj ? obj : tmp, 3);
  return 1;
}

static int xcmd_more(string str) {
  string file;
  int line;

  if (!str || str=="?")
   return notify_fail("xmor(e) <nombre_fichero>");

  if(file=XFindFile(str))
    XMoreFile(file, 1);
  return 1;
}

static int xcmd_quit(string str) {
  if(str=="?")
   return notify_fail("xqu(it) [here]");

  if(str=="here")
  {
   str=object_name(ENV(TI));
   if(member(str, '#')<0) TI->SetHome(str);
  }
  TI->quit();
  return 1;
}

static int xcmd_inventory(string str) {
  int i,yes;
  object item,living;

  if (str=="?")
  {
   WR("i[nventory] [pnj/jugador].");
   return 1;
  }

  if (str)
  {
  if (!(living=XFindObj(str)))
  {
   return 1;
  }
  if (!is_living(living)) {
   WR("Ese objeto no es ni un jugador ni un pnj.");
   return 1;
  }
  } else living=TI;

  if(!first_inventory(living))
  {
   if(living==TI)
    {
    WR("No tienes nada.");
   } else
    WR(CAP(living->QueryName())+" no tiene nada.");
   return 1;
  }
  if(living==TI)
  {
   WR("Inventario:");
  } else {
   WR("Inventario de "+CAP(living->QueryName())+":");
  }
  FORALL(item, living) PrintShort(ARIGHT(++i+". ", 4, " "), item);
  return 1;
}

static int xcmd_help(string str)
{
 if (str=="?")
  return notify_fail("xhelp");
 TI->more(DOC_PATH+"xhelp");
 return 1;
}

static int xcmd_info(string str) {
  object obj;

  if(!str||str=="?")
   return notify_fail("xinf(o) <objeto>");
  if(obj=XFindObj(str)) {
    if(is_player(obj)) {
      WR(PlayerWho(obj));
      WR(PlayerMail(obj, 0));
      WR(PlayerIP(obj, 0));
      WR(PlayerRace(obj, 0));
      WR(PlayerDomain(obj, 0));
      WR(PlayerStats(obj, 0));
      WR(PlayerSnoop(obj, 0));
    } else WR("No es un jugador");
  }
  return 1;
}

static int xcmd_look(string str) {
  object obj;
  string st;

  if(str=="?")
   return notify_fail("xloo(k) [objeto]");
  if(str) {
    if(obj=XFindObj(str)) PrintObj(obj);
  } else {
    obj=ENV(TI);
    PrintObj(obj);
  }
  return 1;
}

static int xcmd_revive(string str) {
  object obj;

  if(!str||str=="?")
   return notify_fail("xre(vive) <jugador>");
  if(obj=XFindObj(str)) {
    if(is_player(obj)) {
     if(!obj->QueryGhost())
     {
       if(obj==TI) {
        return notify_fail("Estas viv"+(obj->QueryGenderEndString())+", no necesitas resucitar.");
       } else {
        return notify_fail(CAP(obj->QueryName())+" esta viv"+(obj->QueryGenderEndString())+", no le hace falta revivir.");
       }
     }

     if(object_name(ENV(obj))=="/room/death_room")
      return notify_fail(CAP(obj->QueryName())+" aun esta experimentando la muerte, espera un poco.");

     if(obj!=TI)
     {
      WR("Reviviendo a"+(obj->QueryGender()==2?" la":"l")+" jugador"+(obj->QueryGender()==2?"a":"")+" "+CRNAME(obj));
     }
     obj->turn_heart_beat(0);
     obj->turn_heart_beat(1);
     obj->SetGhost(0);
     if(obj==TI)
     { WR("Vuelves a estar viv"+(obj->QueryGenderEndString())+".");
     } else {
       WR(CAP(obj->QueryName())+" ha dejado de ser un fantasma.");
     }
    } else
      WR("El objeto especificado no es un jugador");
  }
  return 1;
}

static int xcmd_call(string str) {
  object obj, callobj;
  string file, callstr, callfun, callexpr, error, errlog;
  int *ru1, *ru2, time;
  mixed res;

  if(!str || str=="?")
  return notify_fail("xcall <objeto>-><funcion>(<argumentos>)");
  if(sscanf(str, "%s->%s(%s", callstr, callfun, callexpr)!=3)
    return 0;
  if(!(callobj=XFindObj(callstr))) return 1;
  else {
    file=LPC_FILE+".c";
    if(file_size(file)>0) rm(file);
    if(obj=find_object(LPC_FILE)) Destruct(obj);
    write_file(file,
    	"#pragma verbose_errors\n"
    	"#include <properties.h>\n"
	"object get(string str) {\n"
	"	return PO->XFindObj(str);\n"
	"}\n"
	"mixed eval(object obj, object me, object here){\n"
	"	if (!function_exists(\""+callfun+"\", obj)) {\n"
	"		raise_error(sprintf(\"La función %O->"+callfun+" no existe.\", obj));\n"
	"		return -1;\n"
	"	}\n"
	"	return obj->"+callfun+"("+callexpr+";\n"
	"}\n");
    errlog = ERR_FILE;
    if(file_size(errlog)>0) rm(errlog);
    if(error=catch(obj=clone_object(file))) { WR("Error: "+error[1..]);}
    else {
      ru1=rusage();
      error=catch(res=(mixed)obj->eval(callobj, TI, ENV(TI), callfun));
      ru2=rusage();
      if(error) { WR("Error: "+error[1..]); }
      else {
	time=ru2[0]-ru1[0]+ru2[1]-ru1[1];
	WR("Tiempo de ejecucion: "+(time<0 ? 0 : time)+" ms");
	WR("Resultado: "+mixed_to_string(res, MAX_RECURSION));
	if(objectp(res)) m_add(variable, "result", res);
        log_file("XCALL", ctime()+", "+capitalize(TP->QueryRealName())+
             ", "+str+", ret "+mixed_to_string(res, MAX_RECURSION)+"\n");
      }
    }
    rm(file);
  }
  if(obj) Destruct(obj);
  return 1;
}

static int xcmd_move(string str) {
  object obj1, obj2;
  string what, into;
  object old_env;

  if(!str)
  return notify_fail("xmov(e) <objeto> into <objeto>");
  if((sscanf(str, "%s into %s", what, into)==2)&&
     (obj1=XFindObj(what))&&(obj2=XFindObj(into)))
  {
    old_env = environment(obj1);
    MoveObj(obj1, obj2, 0);
    log_file("XMOVE",
             ctime() + ". " + CAP(TNREAL) + " movió " +
             (obj1->QueryName() || obj1->QueryShort() || obj1->QueryIntShort() || "algo") +
             " a " + (obj2->QueryName() || obj2->QueryShort() || obj2->QueryIntShort() || "algún sitio") +
             " (" + object_name(obj2) + "), desde " +
             (old_env->QueryIntShort() || old_env->QueryShort() || old_env->QueryName() || old_env->QueryLocate()) +
             " (" + object_name(old_env) + ").\n");
  }
  return 1;
}

static int xcmd_clone(string str) {
  object obj;
  string file, errlog, error;

  if(!str || str=="?")
   return notify_fail("xclo(ne) <nombre_fichero>");
  if(!(file=XFindFile(str))) return 1;
  errlog=ERR_FILE;
  if(file_size(errlog)>0) rm(errlog);
  if(obj=find_object(file)) {
    Destruct(obj);
    WR("Actualiza y clona: "+short_path(file));
  } else WR("Clona: "+short_path(file));
  if(!(error=catch(obj=clone_object(file)))) {
    m_add(variable, "clone", obj);
    if(!MoveObj(obj, ENV(TI), 1)) {
      WR("No se puede mover el objeto a esta habitacion"); }
    else if(!obj->QueryNoGet()) {
      if(!MoveObj(obj, TI, 1)) {
	WR("No se puede mover el objeto a tu inventario"); }
    }
  } else WR("Error: "+error[1..]);
  return 1;
}

static int xcmd_load(string str) {
  int i, f;
  object obj, *inv, vroom;
  string file, errlog, error, *strs;

  if(!str)
   return notify_fail("xloa(d) <nombre_fichero>");
  if(!(file=XFindFile(str))) return 1;
  errlog=ERR_FILE;
  if(file_size(errlog)>0) rm(errlog);
  if(obj=find_object(file)) {
    if(catch(call_other(VOID, "???"))) {
      WR("Error: no se encontro "+VOID+" para poner a salvo los jugadores");
      return 1;
    } else vroom = find_object(VOID);
    if(inv=filter(all_inventory(obj), "is_player", TO))
      for(i=0; i<sizeof(inv); i++) MoveObj(inv[i], vroom, 1);
    Destruct(obj);
    WR("Actualiza y carga: "+file);
  } else WR("Carga: "+file);
  call_other(file, "???");
  if(inv) {
    obj=find_object(file);
    for(i=0; i<sizeof(inv); i++)
      if(inv[i]) MoveObj(inv[i], obj, 1);
  }
  play_sound(TP, SND_SUCESOS("cargar"));
  return 1;
}

static int xcmd_eval(string str) {
  object obj;
  string file, error;
  int *ru1, *ru2, time;
  mixed res;

  if (!str || str=="?")
   return notify_fail("xev(al) <expresion>");
  file=LPC_FILE+".c";
  if(file_size(file)>0) rm(file);
  if(obj=find_object(LPC_FILE)) Destruct(obj);
  write_file(file, "#pragma verbose_errors\n#include <properties.h>\n"+
	     "get(str){return PO->XFindObj(str);}\n"+
	     "eval(me,here){return "+str+";}");
  if(error=catch(obj=clone_object(file))) { WR("Error: "+error[1..]); }
  else {
    ru1=rusage();
    error=catch(res=(mixed)obj->eval(TI, ENV(TI)));
    ru2=rusage();
    if(error) { WR("Error: "+error[1..]); }
    else {
      time=ru2[0]-ru1[0]+ru2[1]-ru1[1];
      WR("Tiempo de ejecucion: "+(time<0 ? 0 : time)+" ms");
      WR("Resultado: "+mixed_to_string(res, MAX_RECURSION));
      if(objectp(res)) m_add(variable, "result", res);
      log_file("XEVAL", ctime()+", "+capitalize(TP->QueryRealName())+
           ", "+str+", ret "+mixed_to_string(res, MAX_RECURSION)+"\n");

    }
  }
  rm(file);
  if(obj) Destruct(obj);
  return 1;
}

static int xcmd_dupdate(string str) {
  int i, s;
  object obj;
  string file, *list;

  if(!str || str=="?")
   return notify_fail("xdu(pdate) <nombre_fichero>");
  if(!(file=XFindFile(str))) return 1;
  if(LAST(file, 2)==".c") file=LEFT(file,3);
  if(obj=XFindObj(file)) {
    PrintShort("Actualizando completamente: ", obj);
    list=inherit_list(obj);
    for(s=sizeof(list); i<s; i++) {
      if(obj=find_object(list[i])) Destruct(obj);
    }
  }
  return 1;
}

static int xcmd_cmds(string str) {
  object obj;
  string file;
  mixed *cmds;
  int i, s;

  if(str=="?")
   return notify_fail("xcm(ds) [objeto]");
  if(!str) obj=ENV(TI);
  else if(!(obj=XFindObj(str)))
    return 1;
  file=TMP_FILE;
  s=sizeof(cmds=query_actions(TI,1|2|4|8|16));
  for(i=0; i<s; i+=5) {
    if(cmds[i+3]==obj) {
      write_file(file, ALEFT(cmds[i]+" ", 15, ".")+
		 (cmds[i+2] ? " * " : " . ")+cmds[i+4]+"()\n");
    }
  }
  XMoreFile(file, 0);
  return 1;
}

int xcmd_des(string str) {
  object obj;

  if (!str || str=="?")
   return notify_fail("xde(s) <objeto>");
  if (obj=XFindObj(str))
  {
    if (find_object(lower_case(str)))
      log_file("XDEST", ctime()+", "+capitalize(TP->QueryRealName())+
               " destruye a "+capitalize(obj->QueryName()||obj->QueryShort()||"<algo>")+"\n");
    PrintShort("Eliminando: ", obj);
    Destruct(obj);
    if (obj)
    {
      notify_fail("No puedes destruir a "+obj->QueryShort()+".\n");
      return 0;
    }
  }
  return 1;
}

static int xcmd_update(string str) {
  object obj;
  string file;

  if (!str || str=="?")
   return notify_fail("xup(date) <nombre_fichero>");
  if(!(file=XFindFile(str))) return 1;
  if(LAST(file, 2)==".c") file=LEFT(file, 3);
  if((obj=XFindObj(file))&&(obj=find_object(pure_file_name(obj)))) {
    PrintShort("Actualizando: ", obj);
    Destruct(obj);
  } else WR("El objeto no ha sido encontrado");
  return 1;
}

static int xcmd_who(string opt) {
  string *strs;

  if (opt=="?")
   return notify_fail("xwh(o) [mail|ip|race|guild|domain|job|stats|snoop]");
  if(!opt) strs=map(users(), "PlayerWho", TO);
  else switch(opt) {
  case "mail":
    strs=map(users(), "PlayerMail", TO, 1);
    break;
  case "ip":
    strs=map(users(), "PlayerIP", TO, 1);
    break;
  case "race":
  case "guild":
    strs=map(users(), "PlayerRace", TO, 1);
    break;
  case "job":
  case "jobs":
    strs=map(users(), "PlayerJobs", TO, 1);
    break;
  case "domain":
    strs=map(users(), "PlayerDomain", TO, 1);
    break;
  case "stat":
  case "stats":
    strs=map(users(), "PlayerStats", TO, 1);
    break;
  case "snoop":
    strs=map(users(), "PlayerSnoop", TO, 1);
    break;
  default:
    return 0;
  }
  strs=sort_array(strs, "string_compare", TO);
  WR(implode(strs,"\n"));
  return 1;
}

static int xcmd_grep(string str) {
  int i, s, t;
  string *files, *ts;

  if (!str || str=="?")
   return notify_fail("xgr(ep) <cadena> <ficheros>");
  if(!((ts=explode(str, " "))&&((s=sizeof(ts))>1))) return 0;
  str=implode(ts[0..s-2], " ");
  if(!(regexp(({"dummy"}), str))) {
    WR("Expresion incorrecta");
    return 1;
  }
  if(file_size(TMP_FILE)>0) rm(TMP_FILE);
  if((t=sizeof(files=long_get_dir(XFile(ts[s-1]), 0)))&&
     (file_size(files[0])>=0)) {
    for(i=0; i<t; i++) XGrepFile(str, files[i]);
    XMoreFile(TMP_FILE, 0);
    rm(TMP_FILE);
  }
  else WR("No se puede(n) leer el/los fichero(s)");
  return 1;
}

static int xcmd_hbeats(string str) {
  object obj;
  object *hbeatinfo;
  string tmp, file;
  int i, s;

  if (str=="?")
   return notify_fail("xhb(eats) [cadena de busqueda]");
  file=TMP_FILE;
  if(file_size(file)>0) rm(file);
  if(!str) str=RNAME(TI);
  else if(!regexp(({"dummy"}), str)) {
    WR("Expresion incorrecta");
    return 1;
  }
  s=sizeof(hbeatinfo=heart_beat_info());
  for(i=0; i<s; i++) {
    if(hbeatinfo[i]&&objectp(hbeatinfo[i])) {
      tmp=ObjFile(hbeatinfo[i]);
      if(sizeof(regexp(({tmp}), str)))
	write_file(file, tmp+"\n");
    }
  }
  XMoreFile(file, 0);
  return 1;
}

static int xcmd_sh(string str) {

  if (!str || str=="?")
   return notify_fail("xsh <nombre_fichero>");
  if(scriptline) {
    WR("No se puede ejecutar otro fichero hasta que no haya terminado el anterior");
    return 1;
  }
  if(!(str=XFindFile(str))) return 1;
  str=read_file(str, 1, 1000);
  if(!(scriptline=explode(str, "\n"))) {
    WR("Fichero de comandos incorrecto");
    return 1;
  }
  scriptsize=sizeof(scriptline);
  XExecFile(0);
  return 1;
}

static int xcmd_ddes(string str) {
  object obj;

  if (!str || str=="?")
   return notify_fail("xdd(es) <objeto>");
  if(obj=XFindObj(str)) {
    PrintShort("Eliminando completamente: ", obj);
    filter(deep_inventory(obj), "Destruct", TO);
    Destruct(obj);
  }
  return 1;
}

static int xcmd_dlook(string str) {
  object obj;

  if (str=="?")
   return notify_fail("xdl(ook) [objeto]");
  if(!str) str=RNAME(TI);
  if(obj=XFindObj(str)) DeepPrintShort(obj, 0, 0);
  return 1;
}

static int xcmd_forall(string str) {
  int i, s, t, u;
  string pat, cmd, arg, *strs, *files, fh, fr, fe, ft, ff;

  if (!str || str=="?")
   return notify_fail("xfo(rall) <ficheros> <comando>");
  if(sscanf(str, "%s %s", pat, arg)!=2) return 0;
  files=long_get_dir(pat, 0);
  if(!(s=sizeof(files))) {
    WR("No se encontraron ficheros equivalentes");
    return 1;
  }
  strs=explode(files[0], "/");
  fh="/";
  if(t=sizeof(strs)-1) fh+=implode(strs[0..t-1], "/");
  for(i=0; i<s; i++) {
    ft=explode(files[i], "/")[t];
    if((u=sizeof(strs=explode(ft, ".")))&&--u) {
      ff=implode(strs[0..u-1], ".");
      fr=fh+"/"+ff;
      fe=strs[u];
    } else {
      fe="";
      ff=ft;
      fr=files[i];
    }
    cmd=string_replace(arg, "!!", files[i]);
    cmd=string_replace(cmd, "!e", fe);
    cmd=string_replace(cmd, "!f", ff);
    cmd=string_replace(cmd, "!h", fh);
    cmd=string_replace(cmd, "!r", fr);
    cmd=string_replace(cmd, "!t", ft);
    if(!(TI->command_me(cmd)))
      break;
  }
  return 1;
}

static int xcmd_ids(string str) {
  object obj;

  if (!str || str=="?")
   return notify_fail("xid(s) <objeto>");
  if(obj=XFindObj(str))
    WR("UID=\""+getuid(obj)+"\" / EUID=\""+geteuid(obj)+"\"");
  return 1;
}

static int xcmd_inherit(string str) {
  int s;
  object obj;
  string *strs, *inlist;

  if (!str || str=="?")
   return notify_fail("xinh(erit) <objeto> [funcion]");
  if(!(strs=strip_explode(str, " "))) return 0;
  if(obj=XFindObj(strs[0])) {
    inlist=inherit_list(obj);
    s=sizeof(inlist);
    while(s--) {
      if(catch(call_other(inlist[s], "???"))) {
	WR("Fallo al cargar los objetos heredados");
	return 1;
      }
    }
    obj=find_object(inlist[0]);
    if(sizeof(strs)==1) Inheritance(obj ,0 ,"");
    else Inheritance(obj, strs[1], "");
  }
  return 1;
}

static int xcmd_light(string str) {
  int s, addlight;

  if (str=="?")
   return notify_fail("xli(ght) [luz]");
  if(str) {
    if(!sscanf(str, "%d", addlight)) return 0;
    TI->SetLight(TI->QueryLight()+addlight);
  }
  WR("Niveles actuales de luz: "+ ENV(TI)->QueryIntLight());
  return 1;
}

static int xcmd_lpc(string str) {
  object obj;
  string file, error;
  int *ru1, *ru2, time;
  mixed res;

  if (!str || str=="?")
   return notify_fail("xlp(c) <codigo lpc>");
  file=LPC_FILE+".c";
  if(file_size(file)>0) rm(file);
  if(obj=find_object(LPC_FILE)) Destruct(obj);
  write_file(file, "#pragma verbose_errors\n#include <properties.h>\n"+
	     "get(str){return PO->XFindObj(str);}\n"+
	     "eval(me,here){"+str+"}");
  if(error=catch(obj=clone_object(file))) {WR("Error: "+error[1..0]);}
  else {
    ru1=rusage();
    error=catch(res=(mixed)obj->eval(TI, ENV(TI)));
    ru2=rusage();
    if(error) { WR("Error: "+error[1..]); }
    else {
      time=ru2[0]-ru1[0]+ru2[1]-ru1[1];
      WR("Tiempo de ejecucion: "+(time<0 ? 0 : time)+" ms");
      WR("Resultado: "+mixed_to_string(res, MAX_RECURSION));
      if(objectp(res)) m_add(variable, "result", res);
      if (query_wiz_level(TP) < 70) log_file("XLPC", ctime()+", "+capitalize(TP->QueryRealName())+
             ", "+str+", ret "+mixed_to_string(res, MAX_RECURSION)+"\n");
    }
  }
  if (!error)
    rm(file);
  if(obj) Destruct(obj);
  return 1;
}

static int xcmd_props(string str) {
  int i, s;
  object obj;

  if (!str || str=="?")
   return notify_fail("xprop(s) <objeto>");
  if(obj=XFindObj(str))
    DumpProperties(obj);
  return 1;
}

static int xcmd_clean(string str) {
  object env;

  if (str=="?")
   return notify_fail("xcle(an) [objeto]");
  if(!str) env=ENV(TI);
  else env=XFindObj(str);
  if(env) {
    PrintShort("Limpiando: ", env);
    filter(filter(all_inventory(env), "is_not_player", TO),
		 "Destruct", TO);
  }
  return 1;
}

static int xcmd_callouts(string str) {
  object obj;
  mixed callouts, args, fun;
  string tmp, txt, *tarr;
  int delay, i, s;

  txt="";
  if (str=="?")
   return notify_fail("xcallo(uts) [cadena de busqueda]");
  if(!str || str == "$m" || str == "$me") str="^\\[~/";
  else if(!regexp(({"dummy"}), str)) {
    WR("Expresion incorrecta");
    return 1;
  }
  callouts=call_out_info();
  s=sizeof(callouts);
  if (str == "$h" || str == "$here")
  {
    str=object_name(environment(TP));
    tarr=explode(str, "/");
    str=tarr[sizeof(tarr)-1];
  }
  for(i=0; i<s; i++) {
    if(callouts[i]&&pointerp(callouts[i])) {
      fun = callouts[i][1];
      obj = closurep(fun) ? to_object(fun) : callouts[i][0];
      tmp=ObjFile(obj)+" "+callouts[i][2]+"s "+ to_string(fun)+"("+
      (sizeof(callouts[i])>3?mixed_to_string(callouts[i][3], MAX_RECURSION):"")
        +")";

      if(sizeof(regexp(({tmp}), str)))
	txt=txt+tmp+"\n";
   }
  }
  if (txt!="") txt="Callouts de '"+str+"':\n"+txt;
  else txt="El objeto '"+str+"' no tiene callouts.\n";
  write(txt);
  return 1;
}

static int xcmd_dbg(string str) {
  object obj;

  if (!str || str=="?")
   return notify_fail("xdb(g) <objeto>");
  if(obj=XFindObj(str)) {
    debug_info(1, obj);
    debug_info(0, obj);
  }
  return 1;
}

int xcmd_dclean(string str) {
  object env;

  if (str=="?")
   return notify_fail("xdc(lean) [objeto]");
  if(!str) env=ENV(TI);
  else env=XFindObj(str);
  if(env) {
    PrintShort("Limpiando completamente: ", env);
    filter(filter(all_inventory(env), "is_not_player", TO),
		 "DeepClean", TO);
  }
  return 1;
}

static int xcmd_msg(string str) {
  string tmp;

  if (str=="?")
   return notify_fail("xms(g) [to <objeto>|all]");
  if(!str) {
    WR("Enviar mensaje a la habitacion");
    WR("Terminar mensaje con \".\" o \"**\"");
    say("Mensaje de "+CRNAME(TI)+":\n");
    input_to("XMsgSay");
    return 1;
  } else if(sscanf(str, "to %s", tmp)) {
    if(msgto=XFindObj(tmp)) {
      PrintShort("Enviar mensaje a: ", msgto);
      WR("Terminar mensaje con \".\" o \"**\"");
      tell_object(msgto, "Mensaje de "+CRNAME(TI)+" para ti:\n");
      input_to("XMsgTell");
    }
    return 1;
  } else if(str=="all") {
    WR("Enviar mensaje a todos los jugadores");
    WR("Terminar mensaje con \".\" o \"**\"");
    filter(users()-({TP}), SF(tell_object),
        "Mensaje de "+CRNAME(TI)+" para todos:\n");
    input_to("XMsgShout");
    return 1;
  }
  return 0;
}

static int xcmd_trace(string str) {
  string file;
  object obj;

  if (str=="?")
   return notify_fail("xtrac(e) <objeto>");
  if (query_wiz_level(TI) < 40)
   return notify_fail("No tienes nivel suficiente para usar el xtrace.");
  if(!str) {
    trace(0);
    WR("Finalizando rastreo ["+short_path("/"+traceprefix(0))+"]");
  } else if(obj=XFindObj(str)) {
    PrintShort("Rastreando: ", obj);
    file=object_name(obj);
    file=RIGHT(file, 1);
    traceprefix(file);
    trace(TRACE_LEVEL);
  }
  return 1;
}

static int xcmd_player(string str) {
  string file, msg;
  string tag;
  object obj;

  if (str=="?" || !str)
   return notify_fail("xpl(ayer) <jugador>");

  msg="";
  if(obj=XFindObj(str))
  {
    if(is_player(obj))
    {
     tag=query_wiz_tag(lower_case(obj->QueryName()),7);
     if (obj->QueryGender()==GENDER_FEMALE)
     {
       switch(tag) {
         case "God": tag="Godess"; break;
         case "Domainlord": tag="Domainlady"; break;
         case "Lord": tag="Lady";
       }
     }
     msg+="Mostrando información acerca de "TC_YELLOW+capitalize(obj->QueryRealName())+TC_NORMAL"....\n";
     msg+=TC_BOLD"-------------------------------------------------------------------------------"TC_NORMAL"\n";
     msg+="  "TC_GREEN"Presay  :"TC_NORMAL" "+(obj->QueryPresay()!=""?obj->QueryPresay():"<ninguno>")+
       "\n  "TC_GREEN"Título  :"TC_NORMAL" "+(obj->QueryTitle()!=""?obj->QueryTitle():"<ninguno>")+"\n";
     msg+="  "+STR->ladjust(TC_GREEN"Estado  :"TC_NORMAL" "+(obj->QueryGhost()?"Fantasma":"Vivo"),35," ")+
       STR->ladjust(TC_GREEN"Rana    :"TC_NORMAL" "+(obj->QueryFrog()?"Si":"No"),34," ")+
       TC_GREEN"Raza    :"TC_NORMAL" "+(obj->QueryRace() && obj->QueryRace()!=""?obj->QueryRace():"<ninguna>")+"\n";
     msg+=STR->ladjust("  "TC_GREEN"Sexo    :"TC_NORMAL" "+({"neutro","masculino","femenino", "<asexual>"})[obj->QueryGender()],35," ")+
       STR->ladjust("  "TC_GREEN"Gremio  :"TC_NORMAL" "+(obj->QueryGuild()?obj->QueryGuild():"<ninguno>"),34," ")+
       (query_wiz_level(lower_case(obj->QueryName()))?
       "  "TC_GREEN"Nivel   : "TC_NORMAL+query_wiz_level(lower_case(obj->QueryName()))+" "+
       query_wiz_tag(lower_case(obj->QueryName()),7):
       "  "TC_GREEN"Nivel   : "TC_NORMAL+obj->QueryLevel()+" Jugador")+"\n";
     msg+=STR->ladjust("  "TC_GREEN"PuntosXP:"TC_NORMAL" "+obj->QueryXP(),35," ")+
       STR->ladjust("  "TC_GREEN"PuntosHP:"TC_NORMAL" "+obj->QueryHP()+"/"+obj->QueryMaxHP(),34," ")+
       "  "TC_GREEN"PuntosSP:"TC_NORMAL" "+obj->QuerySP()+"/"+obj->QueryMaxSP()+"\n";
     msg+=STR->ladjust("  "TC_GREEN"PuntosTP:"TC_NORMAL" "+obj->QueryTP()+"/"+obj->QueryMaxTP(),35," ")+
       STR->ladjust("  "TC_GREEN"PuntosQP:"TC_NORMAL" "+QUESTMASTER->QueryQuestPoints(obj),34," ")+
       "  "TC_GREEN"PuntosEP:"TC_NORMAL" "+EXPLOREMASTER->CountBits(obj->QueryExplored())+"/"+
       EXPLOREMASTER->TotalEP()+"\n";
     msg+=STR->ladjust("  "TC_GREEN"Peso    :"TC_NORMAL" "+(obj->QueryWeight()-obj->QueryWeightContents()),35," ")+
       STR->ladjust("  "TC_GREEN"Carga   :"TC_NORMAL" "+obj->QueryWeightContents(),34)+TC_GREEN"  MaxCarga: "TC_NORMAL+
      obj->QueryMaxContent()+"\n";
     msg+=STR->ladjust("  "TC_GREEN"Fza     :"TC_NORMAL" "+obj->QueryStr(),35," ")+
       STR->ladjust("  "TC_GREEN"Con     :"TC_NORMAL" "+obj->QueryCon(),34," ")+TC_GREEN"  RegHP   : "TC_NORMAL+obj->QueryRegHP()+"\n";
     msg+=STR->ladjust("  "TC_GREEN"Int     :"TC_NORMAL" "+obj->QueryInt(),35," ")+
       STR->ladjust("  "TC_GREEN"Des     :"TC_NORMAL" "+obj->QueryDex(),34," ")+TC_GREEN"  RegSP   : "TC_NORMAL+obj->QueryRegSP()+"\n";
     msg+=STR->ladjust("  "TC_GREEN"Alcohol :"TC_NORMAL" "+obj->QueryAlcohol()+"/"+obj->QueryMaxAlcohol(),35," ")+
       STR->ladjust("  "TC_GREEN"Hambre  :"TC_NORMAL" "+obj->QueryFood()+"/"+obj->QueryMaxFood(),34," ")+
       "  "TC_GREEN"Sed     :"TC_NORMAL" "+obj->QueryDrink()+"/"+obj->QueryMaxDrink()+"\n";
     msg+=STR->ladjust("  "TC_GREEN"Coraje  :"TC_NORMAL" "+obj->QueryWhimpy(),35," ")+
       STR->ladjust("  "TC_GREEN"IVision :"TC_NORMAL" "+obj->QueryIVision(),34," ")+
       "  "TC_GREEN"UVision :"TC_NORMAL" "+obj->QueryUVision()+"\n";

     msg+=TC_BOLD"-------------------------------------------------------------------------------"TC_NORMAL"\n";
     STR->smore(msg,TP->QueryPageSize());
     return 1;
    }
    else
     return notify_fail("No se trata de un jugador");
  }
  return 1;
}

static int xcmd_npc(string str) {
  string file, msg, *ids;
  object obj;
  int i;

  if (str=="?" || !str)
   return notify_fail("xnp(c) <pnj>");

  msg="";
  if(obj=XFindObj(str))
  {
    if(obj->QueryIsNPC() || obj->QueryIsPet())
    {
     msg+="Mostrando informacion acerca de "TC_YELLOW+obj->QueryName()+TC_NORMAL"....\n";
     msg+=TC_BOLD"-------------------------------------------------------------------------------"TC_NORMAL"\n";
     msg+="  "TC_GREEN"Ids     : "TC_NORMAL;
     ids=obj->QueryIds();
     if (ids)
      msg+=implode(ids,",")+"\n";
     else
      msg+="<no tiene identificativos>\n";
     msg+="  "+STR->ladjust(TC_GREEN"Estado  :"TC_NORMAL" "+(obj->QueryGhost()?"Fantasma":"Vivo"),35," ")+
       STR->ladjust(TC_GREEN"Raza    :"TC_NORMAL" "+(obj->QueryRace() && obj->QueryRace()!=""?obj->QueryRace():"<ninguna>"),34," ")+
       TC_GREEN"Sexo    :"TC_NORMAL" "+({"neutro","masculino","femenino", "<asexual>"})[obj->QueryGender()]+"\n";
     msg+=STR->ladjust("  "TC_GREEN"Gremio  :"TC_NORMAL" "+(obj->QueryGuild()?obj->QueryGuild():"<ninguno>"),35," ")+
       STR->ladjust("  "TC_GREEN"Nivel   : "TC_NORMAL+obj->QueryLevel()+" Npc",34," ")+
       "  "TC_GREEN"KillXP  : "TC_NORMAL+obj->QueryKillXP()+"\n";
     msg+=STR->ladjust("  "TC_GREEN"PuntosXP:"TC_NORMAL" "+obj->QueryXP(),35," ")+
       STR->ladjust("  "TC_GREEN"PuntosHP:"TC_NORMAL" "+obj->QueryHP()+"/"+obj->QueryMaxHP(),34," ")+
       "  "TC_GREEN"PuntosSP:"TC_NORMAL" "+obj->QuerySP()+"/"+obj->QueryMaxSP()+"\n";
     msg+=STR->ladjust("  "TC_GREEN"Fza     :"TC_NORMAL" "+obj->QueryStr(),35," ")+
       "  "TC_GREEN"Con     :"TC_NORMAL" "+obj->QueryCon()+"\n";
     msg+=STR->ladjust("  "TC_GREEN"Int     :"TC_NORMAL" "+obj->QueryInt(),35," ")+
       "  "TC_GREEN"Des     :"TC_NORMAL" "+obj->QueryDex()+"\n";
     msg+=STR->ladjust("  "TC_GREEN"Alcohol :"TC_NORMAL" "+obj->QueryAlcohol()+"/"+obj->QueryMaxAlcohol(),35," ")+
       STR->ladjust("  "TC_GREEN"Hambre  :"TC_NORMAL" "+obj->QueryFood()+"/"+obj->QueryMaxFood(),34," ")+
       "  "TC_GREEN"Sed     :"TC_NORMAL" "+obj->QueryDrink()+"/"+obj->QueryMaxDrink()+"\n";
     msg+=STR->ladjust("  "TC_GREEN"Coraje  :"TC_NORMAL" "+obj->QueryWhimpy(),35," ")+
       STR->ladjust("  "TC_GREEN"IVision :"TC_NORMAL" "+obj->QueryIVision(),34," ")+
       "  "TC_GREEN"UVision :"TC_NORMAL" "+obj->QueryUVision()+"\n";

     msg+=TC_BOLD"-------------------------------------------------------------------------------"TC_NORMAL"\n";
     STR->smore(msg,TP->QueryPageSize());
     return 1;
    }
    else
     return notify_fail("No se trata de un pnj");
  }
  return 1;
}
