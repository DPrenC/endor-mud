/* Helptool V1.3
 * (c) 1992,1993 by Pumuckel
   Modificado y traducido por [i] Izet, 25-9-97
   Castellanizado por [n] Nemesis Mar'99
   Izet, por diox!!! COMO PONES 'jugadores ENLOGADOS'???
 */

inherit "/std/thing";
inherit STR;

#include <config.h>
#include <moving.h>
#include "./helptool.h"
#include <properties.h>
#include <wizlevels.h>
#include "/obj/lib/string.h"

#define BEEP ""
#define HELPTOOL        "Helptool v1.4"
#define Q_NAME          0
#define Q_CREATOR       1
#define Q_POINTS        2
#define Q_SHORT         3
#define Q_LONG          4

#define IS_NF_PLAYER(x) ((file_size("/save/"+x[0..0]+"/"+x+".o")>=0)?1:0)
#define OUT(x) {if (text=x) { SMore(text);return 1;} else return 0;}
#define COUNTRY(x) "/lib/country"->country(x)

create()
{
  ::create();
  seteuid(getuid());
  SetIds(({"tool", "helptool", "htool"}));
  SetLong("Éste es el 'helptool' que te ayuda a hacer diferentes cosas:\n\
QP <nombre>       devuelve los Puntos de Quest de un jugador <nombre>\n\
Quests <nombre>   devuelve los quests resueltos de un jugador <nombre>\n\
QL [<nombre>]     devuelve una lista con los posibles quests y sus puntos\n\
QPista <numero>   devuelve una pista para el quest #<number>\n\
WL [<nombre>]     devuelve la lista de wizards con rango de jugador <nombre>\n\
HP [<nombre>]     devuelve los puntos de vida del jugador <nombre>\n\
who ?             devuelve una lista de jugadores y wizs conectados\n\
beep <nombre>     hace 'beeps' al jugador/wiz <nombre> 5 veces\n\
INFO              devuelve las propiedades P_INFO de la habitación\n");
  SetReadMsg(HELPTOOL + " (c) Pumuckel Oct 1993\n\
                          Modificado por Izet, Sep 1997\n\
                          Castellanizado por Nemesis, Mar'99\n");
  Set(P_VERSION, HELPTOOL + " (c) Pumuckel Oct 1993\n");
  Set(P_NOSELL,"¡No vendas las utilidades de wizard!\n");
  SetNoDrop("¡No dejes tiradas por ahí las utilidades de wizard!");
  Set(P_AUTOOBJECT,1);
  SetMagic(1);
}

init()
{
  (::init());
  add_action("lower","",1);
  call_out("check", 5);
}

lower(string arg) {
  string text;

  switch (lower_case(query_verb())) {
  case "ayuda": return help(arg);
  case "qp":     OUT(query_qp(arg))
  case "quests": OUT(query_quests(arg))
  case "ql":     OUT(query_quest_list(arg))
  case "wl":     {wizlist(arg||"");return 1;}
  case "hp":     OUT(query_hp(arg))
  case "info": return info(arg);
  case "beep": return beep(arg);
  case "who": return new_who(arg);
  case "qpista": OUT(QUESTMASTER->QueryQuestLong(to_int(arg)-1))
  }
}

check()
{
  object env;

  env = environment();
  while(env && !living(env))
    env = environment(env);
  if(env) {
    /* no helptool for players */
    if(!IS_LEARNER(env)) {
      write("...destruyendo " + HELPTOOL + ", ¡Tú no eres un wizard!\n");
      if(!remove())
	destruct(TO);
    }
  }
}

help(str)
{
  if(!str) return 0;
  if(present(str) == TO) {
    write(QueryLong());
    return 1;
  }
  return 0;
}

QueryShort()
{
  object env;
  string name;

  env = environment();
  while(env && !living(env))
    env = environment(env);
  if(env) {
    if(!(name = env->QueryRealName()))
      if(!(name = env->QueryName()))
	name = env->QueryShort();
    name = capitalize(name);
    if(name[<1] == 's' || name[<1] == 'z' || name[<1] == 'x')
      name += "'";
    else
      name += "'s";
    return name + " " + HELPTOOL;
  }
  return "DeNadie's " + HELPTOOL;
}

mixed query_qp(string player) {
  object name;
  string text;

  if(!player) {
    notify_fail("Falta argumento: <nombre>\n");
    return 0;
  }
  player = lower_case(player);
  text = "";
  if (IS_NF_PLAYER(player)) {
    text += (capitalize(player) + " tiene " +
	     QUESTMASTER->QueryQuestPoints(player) +
             " Puntos de Quest de los " +
	     QUESTMASTER->QueryTotalQuestPoints() +
             " posibles.\n");
    return text;
  }
  FAIL("El jugador " + capitalize(player) + " no existe en Simauria.\n");
}

mixed query_quests(string player)
{
  string long, queststring;
  string *quests;
  int    count,i;
  object name;

  if(!player) {
    notify_fail("Falta argumento: <nombre>\n");
    return 0;
  }
  player = lower_case(player);
  if(IS_NF_PLAYER(player)) {
    if (count = sizeof(quests = QUESTMASTER->QueryPlayerQuests(player))) {
      long = capitalize(player) +
        " ha resuelto los siguientes Quests"+
	  ((count==1)?":\n":"s:\n");
      for (i=count; i--; long+=quests[i]+"\n");
    }
    else
      long = capitalize(player) + " no ha resuelto ningún Quest.\n";
    return long;
  }
  FAIL("El jugador " + capitalize(player) + " no existe en Simauria.\n");
}

mixed query_quest_list(string player)
{
  string text,text2;

  text = "Los siguientes Quests están disponibles";
  text += ((player && IS_NF_PLAYER(player))?
           " o resueltos por " + capitalize(player) + ":\n":":\n");
  text += QUESTMASTER->ListQuests(player);
  if (text2=query_qp(player))
    text+= text2;
  text += ("Hay "+
	   QUESTMASTER->QueryOfficialQP() + " + " +
	   QUESTMASTER->QueryMiniQP() + " = " +
           QUESTMASTER->QueryTotalQuestPoints() + " posibles Puntos de Quest.\n\
Para llegar a ser wizard un jugador necesita " + QUESTMASTER->QueryWizPoints() + " Puntos de Quest.\n");
  return text;
}

new_who2(from,to)
{
  string text,who_text;
  object *list;
  object player;
  int    i,j,learners,are_players_there;

  list = users();
  who_text = "";
  for (j=from;j<=to;j++) {
    learners = j;
    for(are_players_there=0, i=sizeof(list); !are_players_there && i--;)
      are_players_there=IS_LEARNER(list[i])==learners;
    if(are_players_there) {
      who_text += (learners ? "Wizards:\n" : "Jugadores:\n");
      for(i=0; i<sizeof(list); i++) {
	player=list[i];
	if(IS_LEARNER(player)==learners) {
	  if(!player->QueryInvis()) {
	    if(text=player->QueryPresay())
	      who_text += text;
	    who_text += capitalize(player->QueryRealName());
	    if(text=player->QueryTitle())
	      who_text += " "+text;
	    who_text += " [" + COUNTRY(player) + "]\n";
	  }
	  else
	    if(IS_LEARNER(TP)) {
	      who_text += "(" + capitalize(player->QueryRealName()) +
		") ["+ COUNTRY(player)+"]\n";
	    }
	}
      }
    }
    if (j!=to) who_text += "\n";
  }
  smore(who_text,TP->QueryPageSize(),0,0,1);
  return 1;
}

new_who(str) {
  if(!str) str = "todo";
  switch(lower_case(str)) {
  case "v": case "viejo":
    return 0;
  case "todo":
    new_who2(0,1);
    return 1;
  case "j": case "jugadores":
    new_who2(0,0);
    return 1;
  case "w": case "wizards":
    new_who2(1,1);
    return 1;
  case "?":
    write("\
who, commands:\n\
\n\
who ?\t\teste texto\n\
who v|viejo\tel comando quien de jugadores\n\
who j|jugadores\twho para todos los jugadores\n\
who w|wizards\nwho para todos los wizards\n\
");
    return 1;
  default:
    write("Usar 'who ?' para obtener mas información.\n");
    return 1;
  }
}

string query_hp(string player)
{
  object name;

  if(!player)
    return ("Tienes " + TP->QueryHP() + " Puntos de Vida.\n");
  if (name = find_object(lower_case(player)))
    return (capitalize(player) + " tiene " + name->QueryHP() + " Puntos de Vida.\n");
  FAIL("No existe esa forma de vida.\n");
}

info()
{
  string info_text;

  if (info_text = environment(TP)->Query(P_INFO)) {
    write(info_text);
    return 1;
  }
  else
    FAIL("No existe la propiedad P_INFO definida para esta habitación!\n");
}

beep(str) {
  object victim;

  if(!str) {
    tell_room(environment(TP),"BEEEEEEEEP!!!"+BEEP+"\n");
    return 1;
  }
  if(!(victim=find_object(lower_case(str))))
    FAIL("No puedo encontrar "+str+".\n");
  //  if(victim == find_object("izet")) FAIL("Izet no se deja beepear.\n");
  tell_object(victim,capitalize(getuid(TP))+" quiere hablar contigo."+BEEP+"\n");
  write("Beepeando a "+victim->QueryName()+"¡Hey, es divertido!\n");
  return 1;
}


