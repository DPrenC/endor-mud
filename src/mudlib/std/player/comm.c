/**
 * ENDOR-MUD/std/player/comm.c
 */

#include <config.h>
#include <properties.h>
#include <colours.h>
#include <wizlevels.h>
#include <prompt.h>
#include <sounds.h>
#include UDP_HEADER

#define MAX_TELLS 100 // [w] Numero de mensajes maximos guardados.

//-----------------------------------------------------------------------------

public varargs mixed Query(string str); // /std/base

//-----------------------------------------------------------------------------

private nosave string *mensajes; // [w] Guarda los ultimos 'tel's recibidos.
private string *channels = ({});
private nosave int channels_on = 1;
private int earmuffs;   // 0 nada, 1 ignora los gritos
private int ignoreAll;  // 0 No ignora a nadie, >0 ignora a todos.
private int echomode;   // Si es !0 de cero recibes tus propios mensajes
private int ch_line;  // 0 Implica separacion de una linea, > 0 lo contrario.
private int prompt;

private mapping ignoredNames = ([]); // Time to end ignore, indexed by name
private nosave string away;

//-----------------------------------------------------------------------------

private string *BuildChannelList(); // forward

//-----------------------------------------------------------------------------

public string FancyPrompt() {
    int myhp, mysp;
    string tmp;

    myhp = TO->QueryHP();
    mysp = TO->QuerySP();

    tmp = "PG=";
    switch (myhp*100/TO->QueryMaxHP()) {
        case 0..15:  tmp += TC_RED + myhp + TC_NORMAL; break;
        case 16..74: tmp += TC_YELLOW + myhp + TC_NORMAL; break;
        default:     tmp += TC_GREEN + myhp + TC_NORMAL; break;
    }
    tmp += " PM=";
    switch (mysp*100/TO->QueryMaxSP()) {
        case 0..15:  tmp += TC_PURPLE + mysp + TC_NORMAL; break;
        case 16..74: tmp += TC_BOLD TC_BLUE + mysp + TC_NORMAL; break;
        default:     tmp += TC_CYAN + mysp + TC_NORMAL; break;
    }

    tmp += "> ";
    return tmp;
}

//-----------------------------------------------------------------------------

public int QueryPrompt()        { return prompt; }
public int SetPrompt(int to) {
    if (!IS_VALID_PROMPT(to)) return prompt;

    switch(to) {
        case PR_NO_PROMPT:
            set_prompt("", TO);
            break;
        case PR_STD_PROMPT:
            set_prompt("> ", TO);
            break;
        case PR_FANCY_PROMPT:
            set_prompt(SF(FancyPrompt), TO);
            break;
        default:
            // Hay casos no contemplados aqui sino en wizard
    }
    return prompt = to;
}

public int QueryIgnoreAll()     { return ignoreAll; }
public int SetIgnoreAll(int i)  { return ignoreAll = i; }

public string QueryAway()       { return away; }
public string SetAway(string s) { return away = s; }

public int QueryChLine()        { return ch_line; }
public int SetChLine(int i)     { return ch_line = i; }

public int SetEchoMode(int i)   { return echomode = i; }
public int QueryEchoMode()      { return echomode; }

public mapping SetIgnored(mapping i)   { return ignoredNames = i; }
public mapping QueryIgnored()          { return copy(ignoredNames); }
public void AddIgnored(string name, int until) {
    m_add(ignoredNames, name, until);
}
public void RemoveIgnored(string name) {
    m_delete(ignoredNames, name);
}
public int CheckIgnored(string name) {
    if (QueryIgnoreAll()) return 3;
    if (member(ignoredNames, name)) {
        if (ignoredNames[name] < 0) return 2;
        if (ignoredNames[name] - time() > 0) return 1;
        m_delete(ignoredNames, name);
    }
    return 0;
}

public int QueryEarmuffs()      { return earmuffs; }
public int SetEarmuffs(int i)   { return earmuffs = i; }

public int QueryMessages()      { return copy(mensajes); }

//-----------------------------------------------------------------------------

protected void echo_txt(string msg) {
    if (!msg) return;
        if (echomode) write(msg);
    else write("Ok.\n");
}

//-----------------------------------------------------------------------------

varargs int check_ignore(string type, object by)
{
  int itype;
  int rc; /* 1: Ok, 0: ignore, -1: Silent ignore */
  int tzeit, zeit; /* Time to ignore left; if <= 0: no longer ignored. */
  string name;

  rc = 1;

  if (!by)
    by = PO;

  if(QueryIgnoreAll()) return rc = 0; // Ignora a todos
  while(TI && by && !IS_ARCH(by)) {
    if (    !m_contains(&zeit, ignoredNames, getuid(TI)))
      zeit = -1;
    else if (zeit <= 0)
      zeit = 1;
    else
      zeit = zeit-time();
    if (zeit <= 0)
      m_delete(ignoredNames, getuid(TI));

    if (   !m_contains(&tzeit, ignoredNames, name = type))
      tzeit = -1;
    else if (tzeit <= 0)
      tzeit = 1;
    else
      tzeit = tzeit-time();
    if (tzeit <= 0)
      m_delete(ignoredNames, name);

    itype = member(({"gritar", "todos"}), name);
    if (itype != -1 && tzeit > 0) {
      rc = -1;
      break;
    }
    if (itype == 0 && query_wiz_level(PO) < earmuffs) {
      rc = -1;
      break;
    }
    if (zeit > 0) {
      switch(type) {
      case "conversar": rc = -1; break;
      case "telepatia":
        if ((!IS_LEARNER(TP) && TO->QueryInvis()) || (!interactive(TO) && query_once_interactive(TO)))
          rc = -1;
        else
          rc = 0;
        break;
      default: rc = 0;
      }
      break;
    }
    break;
  } /* while (TI...) */
  return rc;
}

int ear (string msg, string type) {
  int rc; /* 1: Ok, 0: ignore, -1: Silent ignore */
  string away;

  rc = check_ignore(type);
  if (stringp(msg))
  {
    if (rc > 0)
    {
      TO->catch_msg(msg);
      switch (type)
      {
        case "communicate": play_sound(TO, SOUND_CANALES("decir")); break;
        case "tell": play_sound(TO, SOUND_CANALES("telepatia")); break;
      }
      if ("tell" == type && (away = QueryAway()) && !(TO->QueryInwiz() && !query_wiz_level(TP)))
        write(capitalize(getuid(TO))+" está ausente, "+away+".\n");
    }
    else if (rc == 0)
      write(capitalize(getuid(TO))+" te ignora.\n");
  }
  return rc;
}

int _tell_ear (object ob, string msg, string type) {
  int rc;
  if (!call_resolved(&rc, ob, "ear", msg, type))
  {
    if (stringp(msg))
    {
      tell_object(ob, msg);
    }
    rc = 1;
  }
  return rc;
}

void SetChannels(string *chs) { channels=chs; }
string *QueryChannels() {
	return channels_on ? (m_indices(mkmapping(channels))) : ({});
}

void ChannelOn(string ch) {
  if (!channels) channels=({});
  channels-=({ch});
  channels+=({ch});
}

void ChannelOff(string ch) {
  if (!channels) channels=({});
  channels-=({ch});
}

int sendmsg(string msg) {
// [k] Nuevo codigo
  string ch;
  int learner;
  string *chan;

  if (!msg) { return notify_fail("¿Enviar qué?\n"); }
  if (Query(P_FROG))
    msg = "¡¡Crik!! ¡¡¡Criiiik!!!";

  ch=query_verb()[1..<1];
  learner = IS_MAIA(TO);
  if (ch == "") ch = learner ? "ainu" : IS_BEGINNER(TO) ? "nobel" : "endor";
  if (!channels) channels = ({});
  if (!channels_on)
     { write("Has deshabilitado temporalmente tus canales.\nEscribe 'canal activar' para activalos\n");
       return 1;
     }

  chan = BuildChannelList();

  if (member(chan, ch) < 0)
     { write("Canal desconocido: "+ch+".\n");
       return 1;
     }

  if (member(channels, ch) < 0)
     { write("El canal "+ch+" no está activado.\n");
       return 1;
     }

  CHANNELMASTER->SendMsg(ch, msg);
  return 1;
}

int sendemote(string msg) {
  string ch;
  int learner;

  if (!msg) { notify_fail("¿Mandar qué?\n"); return 0; }
  if (Query(P_FROG))
    msg = "da una voltereta mientras croa.";

  ch=query_verb()[2..];
  learner = IS_MAIA(TO);
  if (ch == "") ch = learner ? "ainu" : "endor";
  if (!channels) channels=({});
  if (!channels_on)
    write("Has desactivado temporalmente todos tus canales.\n");
  else if (member(
			(learner
			 ? (string*)CHANNELMASTER->QueryAllChannels()+

//[t] añadidas estas líneas para hacer emotes en los canales de arch y gods
			    (IS_ARATAR(TO)?CHANNELMASTER->QueryGodChannels():({}))+
			    (IS_VALA(TO)?CHANNELMASTER->QueryArchChannels():({}))
			 : (string*)CHANNELMASTER->QueryPlayerChannels()), ch) < 0)
    return notify_fail("Canal desconocido: "+ch+".\n");
  else if (member(channels, ch) < 0)
    write("El canal "+ch+" no está activado.\n");
  else
    CHANNELMASTER->SendEmote(ch, msg);
  return 1;
}

private string *BuildChannelList() {
// [k] Genera una lista con los canales a los que 'TO' tiene acceso
string *chan;

  chan = ({});
  if (IS_MAIA(TO))
  {
      chan += (string*) CHANNELMASTER->QueryAllChannels();
      if (IS_VALA(TO)) chan += (string*) CHANNELMASTER->QueryArchChannels();
      if (IS_ARATAR(TO)) chan += (string*) CHANNELMASTER->QueryGodChannels();
  }
  else
  {
      if (!IS_BEGINNER(TO)) chan += (string*) CHANNELMASTER->QueryPlayerChannels();
      else chan += (string*) CHANNELMASTER->QueryBeginnerChannels();
  }
  return chan;
}

int chann(string str)
{
string *chan;

  if (!str)
     {
       notify_fail("Uso: canal [canal]     Activa o desactiva el canal.\n"
                   "     canal salto       Activa o desactiva el salto de línea antes de un mensaje.\n"
                   "     canal activar     Activa todos los canales.\n"
                   "     canal desactivar  Desactiva todos los canales.\n");
       return 0;
     }

  if (!channels) channels=({});
  chan = BuildChannelList();

// [w] Añadido para el salto de linea.
  if (str=="salto")
  {
   if(TP->QueryChLine()) {
    TP->SetChLine(0);
    write("Activando el salto de línea antes de recibir un mensaje por el canal.\n");
    return 1;
   } else {
    TP->SetChLine(1);
    write("Desactivando el salto de línea antes de recibir un mensaje por el canal.\n");
    return 1;
   }
  }


  if (str=="desactivar")
  {
   write("Desactivando todos los canales.\n");
   play_sound(TP,SND_CANALES("desactivar"));
   channels = ({});
   return 1;
  }

  if (str=="activar")
  {
   write("Activando todos los canales.\n");
   play_sound(TP, SND_CANALES("activar"));
   channels += chan;
   return 1;
  }


  if (member(chan, str) == -1)
        { notify_fail("El canal '"+str+"' no existe.\n");
          return 0;
        }
  if (member(channels, str) >= 0)
        {
          ChannelOff(str);
          write("Desactivando el canal '"+str+"'.\n");
          play_sound(TP, SND_CANALES("desactivar"));
          return 1;
        }
  write("Activando el canal '"+str+"'.\n");
  ChannelOn(str);
  play_sound(TP, SND_CANALES("activar"));

  return 1;
}

int chon(string str) {
// [k] Nuevo codigo
string *chan;

  if (!str)
     { channels_on = 1;  // Activa los canales
       printf("Reactivando los canales\n");
       return 1;
     }
  if (!channels) channels=({});
  chan = BuildChannelList();

  if (str=="*") {
      write("Activando todos los canales.\n");
      channels += chan;
      return 1;
    }

  if (member(chan, str) == -1)
        { notify_fail("El canal "+str+" no existe.\n");
          return 0;
        }
  if (member(channels, str) >= 0)
        { notify_fail("El canal "+str+" ya está activo.\n");
          return 0;
        }
  write("Activando el canal "+str+".\n");
  ChannelOn(str);

  return 1;
}

int choff(string str) {
// [k] Nuevo codigo
string *chan;

  if (!str)
    { channels_on = 0;
      write("Desactivando temporalmente los canales.\n");
      return 1;
    }

  if (!channels) channels=({});
  chan = BuildChannelList();

  if (str=="*")
    { write("Desactivando todos los canales.\n");
      channels=({});
      return 1;
    }

  if (member(chan, str) < 0)
    { write("Canal desconocido: "+str+".\n");
      return 1;
    }

  if (member(channels, str) < 0)
    { write("El canal "+str+" no está activado.\n");
      return 1;
    }

  write("Desactivando el canal "+str+".\n");
  ChannelOff(str);
  return 1;
}

string filter_listeners(object who, string ch) {
  string *chs;
  string listener;
  if ((chs=(string*)who->QueryChannels()) && member(chs, ch) >= 0)
  {
    listener = capitalize((string)who->QueryRealName());
    if (who->QueryInvis()) listener = "("+listener+")";
    return listener;
  }
  write("Nadie te escucha...\n");
  return 0;
}
mixed filter_invis(object who) {
  return !(IS_LEARNER(who) && who->QueryInvis());
}

int chwho(string str) {
  int s, learner;
  object *vis_users;
  string *listeners;
  string *chan;

  if (!str)
   return notify_fail("Uso: cquien <canal>\n"),0;

  chan=BuildChannelList();
  if (member(chan, str) < 0)
     { write("Canal desconocido: "+str+".\n");
       return 1;
     }

// [w] Ahora los users los coge de ListChannelUsers y no de users como antes.
  if (!IS_LEARNER(TO))
    vis_users = filter("/obj/chmaster"->ListChannelUsers(str), SF(filter_invis));
  else
    vis_users = "/obj/chmaster"->ListChannelUsers(str);

  listeners = map(vis_users, SF(filter_listeners), str);
  if (sizeof(listeners))
    printf("%-78=s", "Los usuarios actuales del canal "+str+" son:\n"+
	   implode(listeners-({0}), ", ")+".\n");
  else
    write("No hay nadie usando el canal "+str+".\n");
  return 1;
}

int chwho_bak(string str) {
  int s, learner;
  object *vis_users;
  string *listeners;

  learner = IS_LEARNER(TO);
  if (!str) str = learner ? "valar" : "endor";
  if (member(
		   (learner
		    ? (string*)CHANNELMASTER->QueryAllChannels()
		    : (string*)CHANNELMASTER->QueryPlayerChannels()), str) < 0)
    return notify_fail("Canal desconocido: "+str+".\n");
  if (!IS_LEARNER(TO))
    vis_users = filter(users(), SF(filter_invis));
  else
    vis_users = users();
  listeners = map(vis_users, SF(filter_listeners), str);
  if (sizeof(listeners))
    printf("%-78=s", "Actualmente los que están a la escucha en el canal "+str+" son:\n"+
	   implode(listeners-({0}), ", ")+".\n");
  else
    write("Parece ser que nadie está escuchando el canal "+str+".\n");
  return 1;
}

int channels(string str) {
  string *g_chs, *a_chs, *w_chs, *p_chs, *c_chs, *b_chs, tmp;
  int s;

  if (!channels) channels=({});
  if (IS_GOD(TO)) {
    g_chs=(string*)CHANNELMASTER->QueryGodChannels();
    write(ANSI_BLUE+"CANALES DE ARATAR:\n"+ANSI_NORMAL);
    tmp="";
    s=sizeof(g_chs);
    while(s--) {
      tmp+=("  "+(g_chs[s]+" :")[0..11]);
      if (member(channels, g_chs[s]) < 0)
	tmp+= ANSI_RED+" off\n"+ANSI_NORMAL;
      else
	tmp+= ANSI_GREEN+" on\n"+ANSI_NORMAL;
    }
    printf("%-78#s\n", tmp);
  }

  if (IS_ARCH(TO)) {
    a_chs=(string*)CHANNELMASTER->QueryArchChannels();
    write(ANSI_BLUE+"CANALES DE VALAR:\n"+ANSI_NORMAL);
    tmp="";
    s=sizeof(a_chs);
    while(s--) {
      tmp+=("  "+(a_chs[s]+" :")[0..11]);
      if (member(channels, a_chs[s]) < 0)
	tmp+= ANSI_RED+" off\n"+ANSI_NORMAL;
      else
	tmp+= ANSI_GREEN+" on\n"+ANSI_NORMAL;
    }
    printf("%-78#s\n", tmp);
  }

  if (IS_LEARNER(TO)) {
    w_chs=(string*)CHANNELMASTER->QueryWizChannels();
    write(ANSI_BLUE+"CANALES DE MAIA:\n"+ANSI_NORMAL);
    tmp="";
    s=sizeof(w_chs);
    while(s--) {
      tmp+=("  "+(w_chs[s]+" :")[0..11]);
      if (member(channels, w_chs[s]) < 0)
	tmp+= ANSI_RED+" off\n"+ANSI_NORMAL;
      else
	tmp+= ANSI_GREEN+" on\n"+ANSI_NORMAL;
    }
    printf("%-78#s\n", tmp);
  }

  if (IS_BEGINNER(TO))
  {
    b_chs=(string*)CHANNELMASTER->QueryBeginnerChannels();
    write(ANSI_BLUE+"CANALES DE NOBEL:\n"+ANSI_NORMAL);
    tmp="";
    s=sizeof(b_chs);
    while(s--) {
      tmp+=("  "+(b_chs[s]+" :")[0..11]);
      if (member(channels, b_chs[s]) < 0)
  	     tmp+= ANSI_RED+" off\n"+ANSI_NORMAL;
      else
     	  tmp+= ANSI_GREEN+" on\n"+ANSI_NORMAL;
    }
    printf("%-78#s\n", tmp);
  }
  else
  {
    p_chs=(string*)CHANNELMASTER->QueryPlayerChannels();
    write(ANSI_BLUE+"CANALES DISPONIBLES:\n"+ANSI_NORMAL);
    tmp="";
    s=sizeof(p_chs);
    while(s--) {
      tmp+=("  "+(p_chs[s]+" :")[0..11]);
      if (member(channels, p_chs[s]) < 0) tmp+= ANSI_RED+" off\n"+ANSI_NORMAL;
      else tmp+= ANSI_GREEN+" on\n"+ANSI_NORMAL;
    }
    printf("%-78#s\n", tmp);
  }

/*
  c_chs=(string*)CHANNELMASTER->QueryGuildChannels();
  write("Canales de Gremio:\n");
  tmp="";
  s=sizeof(c_chs);
  while(s--) {
    tmp+=("  "+(c_chs[s]+" ...........")[0..11]);
    if (member(channels, c_chs[s]) < 0) tmp+=" no\n";
    else tmp+=" sí\n";
  }
  printf("%-78#s\n", tmp);
*/
  if (!channels_on)
    write("Tienes todos tus canales desactivados.\n");

  return 1;
}

public int AddMensaje(string quien, string que)
{
 string txt;
 string *t;

 if(!mensajes) mensajes=({});
 t = explode(ctime(), " ") - ({""});
 txt = t[3] + ", " + TC_TEL_WHO + quien + TC_NORMAL;
 mensajes += ({ txt + "##" + TC_TEL_MSG + que + TC_NORMAL + "\n" });

 if(sizeof(mensajes) > MAX_TELLS) mensajes = mensajes[<MAX_TELLS..];

 return 1;
}

_earmuffs(e) {
  if (stringp(e) && ""!= e) earmuffs = to_int(e);
  write("Earmuffs are on "+earmuffs+"\n");
  return 1;
}

_all_communicate(object *obj, string name, string what) {
	int i;
	string msg;

	i = sizeof(obj);
	while (i--) {
		obj[i]->AddMensaje(name, what);
		msg = TC_TEL_WHO + name + " dice" + TC_NORMAL + ": '"
		    + TC_TEL_MSG + what + TC_NORMAL + "'\n";
		_tell_ear(obj[i], msg, "communicate");
	}
}

_communicate(str) {
  string verb;
  string str2;
  object *wiz, *other;
  int i;

  verb = query_verb();
  if (verb[0] == "'"[0]) str = verb[1..] + (str ? " "+str : "");
  other = all_inventory(environment(TO))-({TO});
  if (QueryInvis()) {
    wiz = filter(other, SF(query_wiz_level));
    if (!query_wiz_level(TO))
      wiz += filter_objects(other-wiz, "Query", P_SEE_INVIS);
    other = other - wiz;
  }
  if (str)
  {
    echo_txt(("Dices: '"+str+"'\n"));
    _all_communicate(other, Query(P_NAME), str);
    if (sizeof(wiz))
	_all_communicate(wiz, capitalize(QueryRealName()), str);
  }
  else
  {
    echo_txt(("No dices nada.\n"));
    map(other, SF(_tell_ear)
                   , ("\n"+Query(P_NAME)+" no dice nada.\n")
                   , "communicate");
    if (sizeof(wiz))
      map(wiz, SF(_tell_ear)
                     , ("\n("+capitalize(QueryRealName())+") no dice nada.\n")
                     , "communicate");
  }
  return 1;
}

_whisper(str) {
  object ob;
  string who;
  string msg;
  string it;

  if (!str || sscanf(str, "%s %s", who, msg) != 2) {
    write("Susurrar que?\n");
    return 1;
  }
  it = lower_case(who);
  ob = find_object(it);
  if (!CanSee() || !ob || !present(it, environment(TP))) {
    write("No puedo ver a ese jugador aqui.\n");
    return 1;
  }
  echo_txt(("\nSusurras a "+ob->Query(P_NAME)+": "+msg+".\n"), ob);
  _tell_ear(ob, ("\n"+Query(P_NAME) + " te susurra: " + msg +"\n"), "whisper");
  say(("\n"+Query(P_NAME)+" susurra algo a "+ob->Query(P_NAME)+".\n"), ob);
  return 1;
  }


static _converse() {
  write("Comienzas a hablar. Escribe '**' o '.' para parar.\n");
  write("]");
  input_to("_converse_more");
  return 1;
}

static _converse_more(str) {
  string cmd;
  if (str == "**" || str == ".") {
    write("Ok.\n");
    return;
  }
  if (str && str != "") {
    map(all_inventory(environment(TO))-({TO}), SF(_tell_ear)
                  , ("\n"+Query(P_NAME) + " dice: '" + str + "'\n")
                  , "converse");
  }
  write("]");
  input_to("_converse_more");
}

_tell_mudlink (string text) {
  object ml;
  if (ml = find_object("mudlink")) {
    tell_object(ml, text); write ("Ok.\n");
  }
  else write ("No existe conexión al Intermud.\n");
}

/*-------------------------------------------------------------------------
**  Stringformatting
*/

string mkstr (int len) {
  string rc, pattern;
  int actlen;

  if (len <= 0) return "";
  pattern = "          ";
  rc = pattern;
  actlen = strlen(pattern);
  while (actlen < len) rc += rc, actlen *= 2;
  return rc[0..len-1];
}

string ladjust (string str, int len) {
  int actlen;

  if (!str || len <= 0) return 0;
  if ((actlen = strlen(str)) >= len) return str;
  return str+mkstr(len-actlen);
}

string radjust (string str, int len) {
  int actlen;

  if (!str || len <= 0) return 0;
  if ((actlen = strlen(str)) >= len) return str;
  return mkstr(len-actlen)+str;
}

_rpeers() {
  mapping hosts;
  int i;
  mixed muds;

  muds = ladjust("Nombre Mud", 20) + "  Estado       Ultimo acceso";
  write(muds + "\n"
"-----------------------------------------------------------------"[0..strlen(muds)] + "\n");
  muds = sort_array(m_indices(hosts = INETD->query("hosts")), SF(>));
  for (i = 0; i < sizeof(muds); i++) {
    write(ladjust(hosts[muds[i]][HOST_NAME], 20) + "  " +
          (hosts[muds[i]][HOST_STATUS] ?
	   hosts[muds[i]][HOST_STATUS] > 0 ?
	   "ACTIVO       " + ctime(hosts[muds[i]][HOST_STATUS])[4..15] :
	   "NO ACTIVO    " + ctime(-hosts[muds[i]][HOST_STATUS])[4..15]
	   : "DESCONOCIDO") +
	  "\n");
  }
  return 1;
}

_rdict(string str) {
  string u;

  if (!str || str == "" | str == "?") {
    notify_fail("Usage: dict <word>\n");
    return 0;
  }
  if (stringp(u = geteuid(TO)))
    _tell_mudlink("@dict "+u+"="+str+"\n");
  return 1;
}

static _echoto(str) {
  object ob;
  int i;
  string who, msg, *whos;
  if (!str || sscanf(str, "%s %s", who, msg) != 2) {
    write("Eco a <quien> <que>?\n");
    return 1;
  }
  if (!stringp(who))
    return 0;
  whos = explode(who, ",");
  for (i = 0; i < sizeof(whos); i++) {
    if (!strlen(whos[i])) {
      whos[i] = 0;
      continue;
    }
    ob = find_object(lower_case(whos[i]));
    if (!ob) {
      write("No hay nadie llamado '"+whos[i]+"'.\n");
      whos[i] = 0;
      continue;
    }
    if (_tell_ear(ob, msg + "\n", "echoto") > 0)
    {
      whos[i] = capitalize(whos[i]);
      if (ob->QueryInvis() || !ob->Short())
        whos[i] = "("+whos[i]+")";
    }
    else
      whos[i] = 0;
  }
  whos -= ({ 0 });
  if (sizeof(whos) < 1)
    write("No hay nadie aqui a quien hacer eco.\n");
  else {
    if (sizeof(whos) == 1)
      who = whos[0];
    else
      who = implode(whos[0..<2], ",") + " y "+whos[<1];
    echo_txt("Eco a "+who+": "+msg+"\n");
  }
  return 1;
}

_inet_tell(who,msg) {
	/* This part handles the intermud tell. */
	object ob;
	int i;
	string mudname, user;
	string mesg;

	if (sscanf(who, "%s@%s", user, mudname) == 2) {
#if __EFUN_DEFINED__(send_imp)
	    if (mesg = INETD->send_udp(mudname, ([
		REQUEST: "tell",
		RECIPIENT: user,
		SENDER: TP->QueryRealName(),
		DATA: msg
	    ]), 1))
		write(mesg);
	    else
		write("Mensaje transmitido.\n");
#else
            write("Perdon, la comunicacion entre muds no esta habilitada.\n");
#endif
	    return 1;

	/* End of intermud tell routine. */

	}
	return 0;
}

// Handle abbreviated names.
string * _handle_abbrev_names (string arg) {
  string * names, *rnames, *tmp, name;
  object * recp;
  int ambig, i, j;

  names = explode(arg, ",") - ({ "" });

  // Normal players can't reach invisible players, nobody can reach netdead
  // players, so don't consider them at all.
  recp = filter(users(), SF(interactive));
  if (!IS_LEARNER(TP))
    recp -= filter_objects(recp, "QueryInvis");

  rnames = map_objects(recp, "QueryRealName");
  ambig = 0; // Flag: if non-zero, ambiguous abbrev was given.
  for (i = sizeof(names); i--; ) {
    name = lower_case(names[i]);
    tmp = ({});
    for (j = sizeof(rnames); j--; ) {
      if (!strstr(rnames[j], name))
        if (name != rnames[j]) {
          tmp += ({ rnames[j] });
          rnames[j..j] = ({});
        }
        else { // Perfect match
          tmp = ({});
          break;
        }
    }
    switch(sizeof(tmp)) {
    case 1:
      if (member(names, tmp[0]) < 0)
        names[i] = tmp[0];
      else
        names[i] = 0;
    case 0: // Might be an exact name, a foo@bar or similar.
      break;
    default:
      tmp = map(tmp, SF(capitalize));
      write("¿Quién es '"+names[i]+"': ");
      if (sizeof(tmp) > 1)
        write(implode(tmp[0..<2], ", ")+" o ");
      write(tmp[<1]+"?\n");
      ambig = 1;
      break;
    }
  }

  return ambig ? 0 : (names - ({ 0 }));
}

_tell(str) {
  object ob;
  string ptext, wtext, name, *whos, txt, msg;
  string wname, pname, from;
  int i, j;

  if (!str) return notify_fail("tel[epatia] <quien> <que>\n");
  if (sscanf(str, "%s %s", name, msg) != 2) {
    return notify_fail("tel[epatia] <quien> <que>\n");
  }

  if (TO->QueryInwiz()) {
    pname = "Alguien";
    wname = capitalize(QueryRealName());
    ptext = "Alguien";
    wtext = "("+capitalize(QueryRealName())+")";
  }
  else if (lower_case(Query(P_NAME)) != QueryRealName()) {
    pname = Query(P_NAME);
    wname = Query(P_NAME)+" ("+capitalize(QueryRealName());
    ptext = Query(P_NAME);
    wtext = Query(P_NAME)+" ("+capitalize(QueryRealName())+")";
  }
  else
    wname = pname = ptext = wtext = Query(P_NAME);


  if (!Query(P_FROG))
  {
    wtext += " te dice";
    ptext += " te dice";
  }
  else
  {
    wtext += " te dice con voz de rana";
    ptext += " te dice con voz de rana";
  }

  whos = _handle_abbrev_names(name);
  if (!whos)
    return 1;

  for (i = 0; i < sizeof(whos); i++)
  {
    if (!strlen(whos[i]))
    {
      whos[i] = 0;
      continue;
    }
    if (!ob = find_object(LOWER(whos[i])))
    {
      write("No hay nadie que se llame '"+whos[i]+"'.\n");
      whos[i] = 0;
      continue;
    }
    if (_tell_ear(ob, 0, "tell") > 0)
    {
      if (IS_LEARNER(ob))
      {
        from = wname;
        txt = wtext;
      }
      else
      {
        from = pname;
        txt = ptext;
      }
      txt = TC_TEL_WHO + txt + TC_NORMAL;
      txt = txt + ": " + TC_TEL_MSG + "'" + msg + "'" + TC_NORMAL + "\n";
      ob->AddMensaje(from, msg);
      _tell_ear(ob, txt, "tell");
      if (!IS_LEARNER(TP)) {
        if (ob->QueryInwiz())
        {
          write("No hay nadie que se llame '"+whos[i]+"'.\n");
	      whos[i] = 0;
        }
        else if (!interactive(ob) && query_once_interactive(ob))
        {
          write("No hay nadie que se llame '"+whos[i]+"'.\n");
	      whos[i] = 0;
        }
      }
      else if (!interactive(ob) && query_once_interactive(ob))
        write(CAP(whos[i]) +" no esta conectado ahora.\n");
    }
    else
    {
      if (!(ob->QueryInwiz() && !query_wiz_level(TO)))
      {
        write(capitalize(getuid(ob))+" te está ignorando.\n");
      }
      else
      {
        write("No hay nadie que se llame '"+whos[i]+"'.\n");
      }
      whos[i] = 0;
    }
  }

  whos -= ({ 0 });
  if (sizeof(whos) < 1)
    write("Nadie te ha escuchado.\n");
  else {
    whos = map(whos, (:CAP($1):));

    if (sizeof(whos) == 1)
      name = whos[0];
    else
      name = implode(whos[0..<2], ",") + " y "+whos[<1];
    txt = "Dijiste a "+name+": "+msg+"\n";
    // txt = (txt);
    echo_txt(txt);
  }
  return 1;
}

int _away(string arg) {
  if (!arg)
  {
    write("Ya no estas ausente.\n");
    say(Query(P_NAME)+" ha vuelto.\n");
    SetAway(0);
    return 1;
  }
  if (lower_case(arg) == "check" || arg == "?")
  {
    if (away = QueryAway())
      write("Tu mensaje de ausencia es:\n  "
            +capitalize(getuid(TO))+" esta ausente, "+away+"\n");
    else
      write("No tienes ningun mensaje de ausencia establecido.\n");
    return 1;
  }
  say(Query(P_NAME)+" esta ausente, "+arg+".\n");
  SetAway(arg);
  write("Tu mensaje de ausencia es:\n  "+capitalize(getuid(TO))+" esta ausente, "+away+".\n");
  return 1;
}

//------------------------------------------------------------------------------

static add_comm_commands() {
  add_action("_away", "ausente");
  add_action("_communicate", "'", 1);
  add_action("_communicate", "decir");
  add_action("_whisper", "susurrar");
  add_action("_converse", "conversar");
  add_action("_tell", "tel");
  add_action("_tell", "telepatia");
  add_action("_tell", "telepatía");
    add_action("sendmsg", "-", 1);
  add_action("sendemote", "--", 1);
  add_action("chann", "canal");
  add_action("chwho", "cquien");
  add_action("channels", "canales");
}
