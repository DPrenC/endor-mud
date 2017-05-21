/**
 * SIMAURIA '/obj/chmaster.c'
 */

#pragma no_inherit

#include "/secure/config.h"
#include <wizlevels.h>
#include <colours.h>
#include UDP_HEADER
#include <quiz.h>
#include <sounds.h>

#define CHANNEL        "channel"
#define COMMAND        "cmd"
#define CH_LINE         (!TP->QueryChLine()?"\n":"")

#define  LINE   78


// canales utilizados solo por wizs
static string *w_channels;
static string *w_std_channels = ({
//  "lpc","error","wiz","intermud"
  "error","wiz"
});

// canales usados solo por gods
static string *g_channels = ({
  "god"
});

// canales usados solo por archs.
static string *a_channels = ({
  "arch"
});

//canales de novatos, ayuda e informacion (validos para todos)
static string *b_channels=({
  "novatos", "ayuda", "info", "mud"
});

// canales de jugadores
static string *p_channels=({
  "chat","jugadores", "valencia", "jan", "coliseum","trivial"
});

//c de class, ya q g de guild es g de god
static string *c_channels=({
  "aventureros","conjuradores","guardabosques","guerreros","hechiceros",
  "kisalas","asesinos"
});

// canales que sonará para todos, incluso para el objeto lanzador del mensaje
private static string *u_channels = ({"trivial", "error", "mud", "info"});

// Para poner objetos que intercepten lo enviado a los canales
static mapping chan_hook = ([ ]);

public varargs mixed QueryChannelHooks(string ch) {
    if (ch) return chan_hook[ch];
    return chan_hook;
}

public varargs int AddChannelHook(mixed ob, string chan) {
    if (!chan) {
        chan = (string) ob;
        ob = previous_object();
    }
    if ( !ob ) return 0;

    if (sizeof(chan_hook[chan])) {
        chan_hook[chan] -= ({ ob }); // Para evitar duplicidades
        chan_hook[chan] += ({ ob });
    }
    else chan_hook[chan] = ({ ob });
    return 1;
}

public varargs int RemoveChannelHook(string chan, object ob) {
    if ( !ob && !(ob = previous_object()) ) return 0;

    if (sizeof(chan_hook[chan])) {
        chan_hook[chan] -= ({ ob }); // Para evitar duplicidades
        chan_hook[chan] += ({ ob });
    }
    else chan_hook[chan] = ({ ob });
    return 1;
}


int is_domain(string file)
{
  return file[0] != '.' && file_size("/d/" + file) == -2;
}

string indent_text (string txt, int start) {
  return txt[0..start-1]+sprintf("%*s%-*=s", start, "", LINE-start,
                          txt[start..])[start..];
}

void create() {
}

string *QueryAllChannels()  { return sort_array((w_channels?w_channels:w_std_channels)+p_channels+c_channels+b_channels, SF(<)); }
string *QueryGodChannels()  { return sort_array(g_channels, SF(<)); }
string *QueryArchChannels() { return sort_array(a_channels, SF(<)); }

string *QueryWizChannels() {
  if (IS_ARCH(TP)) {
    w_channels = w_std_channels + filter(get_dir("/d/*"), SF(is_domain));
    if (member(w_channels , "arch")>=0)
      w_channels -= ({"arch"});
  }
  else {
    w_channels = w_std_channels;
    if (TP->QueryDomains()) w_channels += TP->QueryDomains();
  }
  return sort_array(w_channels, SF(<));
}

string *QueryGuildChannels()    { return sort_array(c_channels, SF(<)); }
string *QueryPlayerChannels()   { return sort_array(p_channels+c_channels+b_channels, SF(<)); }
string *QueryBeginnerChannels() { return sort_array(b_channels, SF(<)); }

string *QueryPlayerDefaultChannels()   { return copy(p_channels + b_channels); }
string *QueryBeginnerDefaultChannels() { return copy(b_channels); }

void AddChannel(string ch) {
  if(ch && member(QueryAllChannels(), ch) < 0) p_channels += ({ ch });
}

private string _build_str(object to, string from, string ch, string what, int emote) {
    string msg;
    string color, txtcolor;
    string tmp;

    color =    TC_KEY + capitalize(ch) + "Who" + TC_KEY;
    txtcolor = TC_KEY + capitalize(ch) + "Msg" + TC_KEY;

    msg = "";
    if (!to->QueryChLine()) {
        msg = "\n";
    }
    msg += color + "[";
    if (emote) {
        switch (ch) {
            case "mud":
            case "coliseum":
            case "info":
            case "trivial":
                msg += capitalize(ch) + ": " + TC_NORMAL + txtcolor + what + TC_NORMAL + color + "]" + TC_NORMAL + "\n";
                break;
            case "wiz":
                msg += TC_NORMAL + from + " " + txtcolor + what + TC_NORMAL + color + "]" + TC_NORMAL + "\n";
                break;
            case "jugadores":
                if (IS_LEARNER(to)) {
                    msg += ch + ": ";
                }
                msg += TC_NORMAL + from + " " + txtcolor + what + TC_NORMAL + color + "]" + TC_NORMAL + "\n";
                break;
            case "novatos":
                if (!IS_BEGINNER(to)) {
                    msg += ch + ": ";
                }
                msg += TC_NORMAL + from + " " + txtcolor + what + TC_NORMAL + color + "]" + TC_NORMAL + "\n";
                break;
            default: msg += ch + ": " + TC_NORMAL + from + " " + txtcolor + what + TC_NORMAL + color + "]" + TC_NORMAL + "\n";
        }
    }
    else {
        switch (ch) {
            case "mud":
            case "coliseum":
            case "info":
                msg += TC_NORMAL + capitalize(ch) + color + "] " + TC_NORMAL + txtcolor + what + TC_NORMAL + "\n";
                break;
            case "wiz":
                msg += TC_NORMAL + from + color + "] " + TC_NORMAL + txtcolor + what + TC_NORMAL + "\n";
                break;
            case "jugadores":
                msg += TC_NORMAL + from;
                if (IS_LEARNER(to)) {
                    msg += color + ":" + ch + TC_NORMAL;
                }
                msg += color + "] " + TC_NORMAL + txtcolor + what + TC_NORMAL + "\n";
                break;
            case "novatos":
                msg += TC_NORMAL + from;
                if (!IS_BEGINNER(to)) {
                    msg += color + ":" + ch + TC_NORMAL;
                }
                msg += color + "] " + TC_NORMAL + txtcolor + what + TC_NORMAL + "\n";
                break;
            default: msg += TC_NORMAL + from + color + ":" + ch + "] " + TC_NORMAL + txtcolor + what + TC_NORMAL + "\n";
        }
    }
    return W(msg);
}

private void SendSound(object ob, string channel, string str)
// manda el sonido que sea, dependiendo del canal y del str
{
    string sonido;
    if (!ob) return;
    if (strstr(LOWER(str), LOWER(NNAME(ob))) != -1)
    // se está mandando el nombre de ese jugador
    {
        play_sound(ob, SND_CANALES("tunombre"));
        return;
    }
    if (member(w_std_channels - ({"error"}), channel) > -1) sonido = SND_CANALES("canal_wiz");
    else if (member(c_channels, channel) > -1) sonido = SND_CANALES("canal_gremios");
    else
    {
        switch(channel)
        {
            case "jugadores": sonido = SND_CANALES("canal_jugadores"); break;
            case "jan": sonido = SND_CANALES("canal_jan"); break;
            case "info": sonido = SND_CANALES("canal_info"); break;
            case "error": sonido = SND_CANALES("canal_error"); break;
            case "trivial": sonido = SND_CANALES("canal_trivial"); break;
            case "novatos": sonido = SND_CANALES("canal_novatos"); break;
            case "ayuda": sonido = SND_CANALES("canal_ayuda"); break;
            case "chat": sonido = SND_CANALES("canal_chat"); break;
        }
    }
    if (sonido) play_sound(ob, sonido);
}


public varargs void SendStr(string from, string ch, string str, int emote, string sound) {
  object *u;
  object fob;
  int g, a, s, w, p, c, b, rc;

  g=member(g_channels, ch) != -1;
  a=member(a_channels, ch) != -1;
  w=member(w_channels?w_channels:w_std_channels, ch) != -1;
  p=member(p_channels, ch) != -1;
  c=member(c_channels, ch) != -1;
  b=member(b_channels, ch) != -1;

  if (!w && !p && !g && !a && !c && !b) return;

  if (sizeof(u = QueryChannelHooks(ch))) {
      call_other(u, "NotifyChannel", from, ch, str, emote);
  }

  s = sizeof(u = users());
  fob = find_object(LOWER(from));
  while (s--)
  {
    // In certain situations (like exec()'ing souls, or during Gamedriver
    // initiated shutdowns, users() may return some destructed objects.
    //
    if (   !u[s]
        || (w && !IS_LEARNER(u[s]))
        || (g && !IS_GOD(u[s]))
        || (a && !IS_ARCH(u[s]))
        || (p && IS_BEGINNER(u[s]))
        || !(u[s]->QueryChannels())
        || (   c && (   ch != (u[s]->QueryGuild())
                     && ch != (u[s]->QueryGuild()+"s")
                     && ch != (u[s]->QueryGuild()+"es")
                    )
           )
       )
    {
      continue;
    }
    if (member((string*)u[s]->QueryChannels(), ch) < 0) continue;
    if (call_resolved(&rc, u[s], "check_ignore", "channel", PO) && rc <= 0) continue;

    if (ch == "jugadores" && IS_LEARNER(u[s]))
    {
      if (((mapping)u[s]->QueryIgnored()||([]))[getuid(fob)]) continue;
      tell_object(u[s], _build_str(u[s], from, ch, str, emote));
      if (member(u_channels, ch) > -1 || (fob && u[s] != fob))
      {
          if (fob && fob->QueryFrog()) play_sound(u[s], SND_PNJS("rana"));
          else
          {
              if (!sound) SendSound(u[s], ch, str);
              else play_sound(u[s], sound);
          }
      }
    }
    else
    {
      if (   (ch != "ayuda" && ch != "jan" && ch != "jugadores")
          || (ch == "ayuda" && IS_LEARNER(u[s])) // Canal ayuda solo leen learners
          || (ch == "jugadores" && !IS_BEGINNER(u[s]))
          || (ch == "jan"   && IS_HLP(u[s]))     // Canal hlp (jan) solo leen hlp
         )
      {
          tell_object(u[s], _build_str(u[s], from, ch, str, emote));
        if (member(u_channels, ch) > -1 || (fob && u[s] != fob))
        {
            if (fob && fob->QueryFrog()) play_sound(u[s], SND_PNJS("rana"));
            else
            {
                if (!sound) SendSound(u[s], ch, str);
                else play_sound(u[s], sound);
            }
        }
      }
    }
  }
}

void SendChannelMsg(string ch, string msg, string wh, int is_emote) {
    mapping data, hosts;
    string *muds;
    int i;

    data = ([
        REQUEST: "channel",
        SENDER: wh,
        CHANNEL: ch,
        "CHANNEL": ch, /* argl, backward compat hack - Pepel */
        DATA: msg
    ]);
    if (is_emote) data[COMMAND] = "emote";
    for(i = sizeof(muds = m_indices(hosts = INETD->query("hosts"))); i--; ) {
        /*
         * Don't send it to ourselves and check that the receiver
         * recognizes "channel" requests. Normally this checking is done
         * by the inetd, but we don't want it throwing out
         * 'invalid command' messages for muds that don't use channels
         * every time we send an intermud message.
         */

    if (
        (member(hosts[muds[i]][HOST_COMMANDS], "*") != -1
            || member(hosts[muds[i]][HOST_COMMANDS], "channel") != -1))
      INETD->send_udp(muds[i], data);
    }
}

public varargs void SendMsg(string ch, string msg, string sound) {
  string from;
  object ob;

  ob = TP;
  from = ob
    ? capitalize(getuid(ob))
    : object_name(PO);

  if (    (ch == "coliseum" || ch == "info" || ch == "mud" )
          && query_verb() == "="+ch)
  {
      write("El canal '"+ch+"' es sólo para escuchar. No intentes enviar mensajes por él.\n");
      return;
  }

  if (ch == "trivial")
  {
    int state = QUIZMASTER->QueryState();
    if (state == Q_STATE_NONE || state == Q_STATE_STARTING)
    {
      write("Ahora mismo no hay iniciada ninguna partida de trivial.\n");
      return;
    }
    if (state != Q_STATE_ANSWER)
    {
      write("No se está preguntando nada en el trivial en estos momentos.\n");
      return;
    }
    if (state == Q_STATE_ANSWER && QUIZMASTER->QueryAttempts()[from] >= Q_ATTEMPTS)
    {
      write("Has superado los intentos permitidos para responder a la pregunta.\n");
      return;
    }
  }

  if (ob && IS_BEGINNER(ob) && member(b_channels + u_channels, ch)<0) {
    write("Necesitas tener al menos nivel "+BEGINNER_RLVL+" para usar ese canal.\n");
    return;
  }
  if (ob && !IS_HLP(ob) && ch == "jan") {
    write("El canal `JAN' es sólo para veteranos del Mud.\n");
    return;
  }
  if (   (member(c_channels, ch)!=-1)
      && ob && !IS_LEARNER(ob)
      && (   ch!=(ob->QueryGuild()     )
          && ch!=(ob->QueryGuild()+"s" )
          && ch!=(ob->QueryGuild()+"es")
         )
      )
  {
    write("No eres miembro de ese gremio.\n");
    return;
  }
/* // Desactivo el intermud
  if (ch == "intermud") {
    return SendChannelMsg(ch, msg, from, 0);
  }
*/
  SendStr(from, ch, msg, 0, sound);
}

public varargs void SendEmote(string ch, string emo, string sound) {
  string from;
  object ob;

  ob = TP;
  from = ob
    ? capitalize(getuid(ob))
    : object_name(PO);

  if (    (ch == "coliseum" || ch == "info" || ch == "mud" || ch == "trivial")
          && query_verb() == "=="+ch)
  {
      write("No puedes enviar acciones por el canal '"+ch+"'.\n");
      return;
  }
  if (ob && IS_BEGINNER(ob) && member(b_channels + u_channels, ch)<-1) {
    write("Necesitas tener al menos nivel "+BEGINNER_RLVL+" para usar ese canal.\n");
    return;
  }
  if (ob && !IS_HLP(ob) && ch == "jan") {
    write("El canal `JAN' es sólo para veteranos del Mud.\n");
    return;
  }

  if (   (member(c_channels, ch)!=-1)
      && ob && !IS_LEARNER(ob)
      && (   ch!=(ob->QueryGuild()     )
          && ch!=(ob->QueryGuild()+"s" )
          && ch!=(ob->QueryGuild()+"es")
         )
      )
  {
    write("No eres miembro de ese gremio.\n");
    return;
  }

  SendStr(from, ch, emo, 1, sound);
}

/* called by inetd/udp/channel upon reception of a intermud msg */
void send_local_message(mapping data) {
  string msg;
  if ("emote" == data[COMMAND])
    msg = "["+data[CHANNEL]+":"+capitalize(data[SENDER])+"@"+data[NAME]
      +" "+data[DATA]+"]";
  else
    msg = "["+capitalize(data[SENDER])+"@"+data[NAME]+":"+data[CHANNEL]+"] "
      +data[DATA];
  SendStr(data[CHANNEL], msg, msg, 0);
}

object *ListChannelUsers(string ch)
{
  object *list;
  object *u;
  int a, g, s, w, p, c, b;

  list = ({});

  g=member(g_channels, ch) != -1;
  a=member(a_channels, ch) != -1;
  w=member(w_channels?w_channels:w_std_channels, ch) != -1;
  p=member(p_channels, ch) != -1;
  c=member(c_channels, ch) != -1;
  b=member(b_channels, ch) != -1;

  if (!w && !p && !g && !a && !c && !b) return list;
  for (s=sizeof(u=users());s--;) {
    /* In certain situations (like exec()'ing souls, or during Gamedriver
    ** initiated shutdowns, users() may return some destructed objects.
    */
    if (   !u[s]
        || (w && !IS_LEARNER(u[s]))
        || (g && !IS_GOD(u[s]))
        || (a && !IS_ARCH(u[s]))
        || !(u[s]->QueryChannels())
        || (   c && (   ch != (u[s]->QueryGuild())
                     && ch != (u[s]->QueryGuild()+"s")
                     && ch != (u[s]->QueryGuild()+"es")
                    )
           )
       )
    {
      continue;
    }
    if (member((string*)u[s]->QueryChannels(), ch) < 0) continue;
    list += ({u[s]});
  }
  return list;
}


