/* SIMAURIA '/bin/wiz/_gente.c'
   ============================
   [w] Woo@simauria
   [m] Mirill@Simauria
   [M] Maler@simauria
   [h] Nyh@Simauria

   31-03-99 [w] Traspaso desde el player.c.
   11-06-99 [m] Feminizado.
   11-10-01 [M] Councilierizado
   24-11-04 [h] Ordeno a la gente por IPs, eto obliga a retocar bastante codigo

*/

#include "/secure/wizlevels.h"
#include <colours.h>
#include <properties.h>

//"1"->"  1", "23"->" 23", "138"->"138"
string norm(string str) {
    switch (strlen(str)) {
    case 1: return "  "+str; break;
    case 2: return " "+str;  break;
    }
    return str;
}

int main( string arg )
{
  object *list;
  int i, a;
  string a_age,a_ipnum,a_name,a_level,a_idle,a_room,a_end, a_title;
  string *lines = ({});

  switch (TP->QueryTTY()) {
    case "vt100":
      a_ipnum = ""; a_name = TC_BOLD; a_level = TC_NORMAL;
      a_idle = TC_BLINK; a_room = TC_NORMAL; a_end = TC_NORMAL;
      a_title = TC_INVERS; a_age = TC_NORMAL;
      break;
      case "ansi":
      a_ipnum = TC_GREEN; a_name = TC_YELLOW; a_level = TC_RED;
      a_idle = TC_WHITE; a_room = TC_CYAN; a_end = TC_NORMAL;
      a_title = TC_INVERS; a_age = TC_PURPLE;
      break;
      default:
      a_title = a_ipnum = a_name = a_level = a_idle = a_room = a_end = "";
      a_age = "";
    }
  list = users();

  if (!IS_LEARNER(TP)) {
    for (i=sizeof(list)-1;i >= 0;i--) {
      if (!list[i]->QueryShort()) list -= ({list[i]});
    }
  }

  write(a_title+"Hay " + sizeof(list) + " jugadores");
  for (i=0, a=0; i < sizeof(list); i++)
    if (query_idle(list[i]) >= 5 * 60) a++;
  if (a) write(" (" + (sizeof(list) - a) + " activos)");

  write(". " + query_load_average() + a_end+ "\n");

  for (i=sizeof(list); i--;) {
    string nm, tag;
    nm = capitalize(list[i]->QueryRealName() || list[i]->QueryName()
                    || "<logon>");
    if (list[i]->QueryInvis() || !list[i]->Short()) nm = "(" + nm + ")";
    if (strlen(nm) < 8) nm += "\t";
    nm = a_ipnum+implode(map(explode(query_ip_number(list[i]),"."), SF(norm)),".")+"\t"+a_name+nm+"\t"+a_level;
    tag = query_wiz_tag(list[i], 2);
    if (list[i]->QueryGender()==GENDER_FEMALE)
    {
      switch(tag) {
        case "God": tag="Godess"; break;
        case "Domainlord": tag="Domainlady"; break;
        case "Lord": tag="Lady";
      }
    }

    if (!tag) tag=list[i]->QueryLevel()+"/"+xp2level(list[i]->QueryXP());
    nm += tag+"\t"+a_age;
    a = list[i]->QueryAge();
    if      (a / 43200 > 9) nm += a / 43200 + " D";
    else if (a / 43200 > 0) nm += a / 43200 + "  D";
    else if (a /  1800 > 9) nm += a / 1800 + " h";
    else if (a /  1800 > 0) nm += a / 1800 + "  h";
    else if (a /    30 > 9) nm += a / 30 + " m";
    else                    nm += a / 30 + "  m";
    if (query_idle(list[i]) >= 5 * 60)
      nm += a_idle+" I";
    nm += "\t";
    if (environment(list[i]))
      nm += a_room+object_name(environment(list[i]));
    lines+= ({ nm+a_end+"\n" });
  }
  filter(sort_array(lines,SF(>)),SF(write));

  return 1;
}
