// Comando ficha

#include "/secure/config.h"
#include "/secure/wizlevels.h"
#include "/secure/userinfo.h"
#include "/secure/daemons.h"
#include UDP_HEADER

#include <properties.h>

#define HBINT         2   /* interval between two heart_beats in seconds    */
#define MINIDLE      60   /* minimum idle time in seconds to be stated idle */

#define MDTQS "/obj/lib/mdtqs"

inherit MDTQS;
inherit STR;

private static int QueryRealLevel(string player, int level)
// devuelve el nivel de jugador basándose en los puntos de quest, de un
// jugador no conectado
{
    int level_qp, qp;

    qp = QUESTMASTER->QueryQuestPoints(player);
    if (qp == QUESTMASTER->QueryTotalQuestPoints()) return level;
    level_qp = "/std/guild/level"->QPtoLevel(qp);
    return (level_qp > level ? level : level_qp);
}


private static string dtime(int time)
{
  string ret;

  ret = "";
  if( time >= 86400) {
    ret += time/86400+"d ";
    time %= 86400;
  }
  if (time < 36000) ret += "0";
  ret += time/3600+":";
  time %= 3600;
  if (time < 600) ret += "0";
  ret += time/60+":";
  time %= 60;
  if (time < 10) ret += "0";
  ret += time+"";
  return ret;
}

/* definitions for the finger command */
#define FS_PRESAY   0
#define FS_TITLE    1
#define FS_RACE     2
#define FS_GUILD    3
#define FS_TAG      4
#define FS_AWAY     5
#define FS_NDEAD    6
#define FS_COUNT    7

#define FI_IDLE   0
#define FI_GENDER 1
#define FI_AGE    2
#define FI_GHOST  3
#define FI_WLEVEL 4
#define FI_LDATE  5
#define FI_NDEAD  6
#define FI_XP     7
#define FI_COUNT  8


/* the finger command */
int main(string str) {
  string filename, *data;
  int    pos, char;
  object player;
  mixed  *userinfo;
  string *sdata, ip, name, ipnum;
  int    *idata, i;
  string user, mud;
  string err;
  int	hide_wiz_status=0;

  if (!str) return notify_fail("Sintáxis: 'ficha <jugador>'\n");

  seteuid(getuid());

  str = implode(explode(str, " ")-({""})," ");
  if (str=="") return notify_fail("Sintáxis: 'ficha <jugador>[@<mud>]'");
  if (sizeof(explode(str," "))>1) return notify_fail("No uses espacios en el nombre.\n");

  /* switch to lower case */
  str=lower_case(str);

  /* intermud finger? */
  if (2 == sscanf(str, "%s@%s", user, mud)) {
    if (err = UDP_CMD_DIR "finger"->send_finger(mud,user)) write(err);
    else write("Petición de información enviada.\n");
    return 1;
  }

  /* does this player exist? */
  userinfo=MASTER->find_userinfo(str);
  filename="/save/"+str[0..0]+"/"+str+".o";
  if(!userinfo && file_size(filename)<0) return notify_fail("Este jugador no existe en Simauria.\n");

  if(userinfo && file_size(filename) <= 0) {
    pos = query_wiz_level(str);
    if (!pos) return notify_fail("Este jugador no existe en Simauria.\n");
    write(capitalize(str)+" es un wizard retirado.\n");
    if (IS_LEARNER(TP)) write("Último nivel de wizard: "+pos+" ("+query_wiz_tag(str, 1)+").\n");
    else write("Último trabajo: "+query_wiz_tag(str, 1)+".\n");
    return 1;
  }

  idata = allocate(FI_COUNT);
  sdata = allocate(FS_COUNT);

  /* is it logged in? */
  if(player = find_object(str)) {
    /* the player is logged in: query information directly */
    idata[FI_LDATE]=player->QueryLastSave();
    ipnum = query_ip_number(player);
    if (ipnum) {
      ip=query_ip_name(player);
      if((idata[FI_IDLE]=query_idle(player))<MINIDLE) idata[FI_IDLE]=0;
      if (!idata[FI_LDATE]) idata[FI_LDATE]=file_date(filename);
    }
    else {
      if(file_size(filename)<0) return notify_fail("No puedo encontrar datos sobre " + capitalize(str) + ".\n");
      data=explode(read_file(filename),"\n");
      ip=(regexp(data,"^called_from_ip")+({""}))[0][16..<2];
      if (!idata[FI_LDATE]) idata[FI_LDATE]=file_date(filename);
      idata[FI_NDEAD]=player->QueryNetdead();
      sdata[FS_NDEAD]=player->QueryNetdeadRoom();
      if (!sdata[FS_NDEAD]) sdata[FS_NDEAD] = to_string(environment(player));
    }
    sdata[FS_PRESAY]=player->QueryPresay();
    name=player->QueryName();
    sdata[FS_TITLE]=player->QueryTitle();
    sdata[FS_RACE]=player->QueryRace();
    sdata[FS_GUILD]=player->QueryGuild();
    sdata[FS_AWAY]=player->QueryAway();
    if (IS_ARCH(TP)) sdata[FS_TAG] = query_wiz_tag(player, 7);
    else sdata[FS_TAG] = query_wiz_tag(player, 5);
    idata[FI_GENDER]=player->QueryGender();
    if (idata[FI_GENDER]==GENDER_FEMALE) {
      switch (sdata[FS_TAG]) {
        case "God": sdata[FS_TAG]="Goddess";break;
        case "Domainlord": sdata[FS_TAG]="Domainlady"; break;
        case "Lord": sdata[FS_TAG]="Lady";
      }
    }

    idata[FI_AGE]=HBINT*player->QueryAge();
    idata[FI_GHOST]=player->QueryGhost();
    idata[FI_XP] = player->QueryXP();

    if(!(idata[FI_WLEVEL]=query_wiz_level(player)))
    {
      idata[FI_WLEVEL]=-xp2level(idata[FI_XP]);
    }
    if (player->QueryInwiz() && !query_wiz_level(TP)) hide_wiz_status = 1;
  }
  else {
    /* the player is not logged in: query the information from the savefile */
    if(file_size(filename)<=0) return notify_fail("No puedo encontrar datos sobre " + capitalize(str) + ".\n");
    data=explode(read_file(filename),"\n");
    idata[FI_LDATE]=to_int((regexp(data,"^pLastSave")+({""}))[0][10..]);
    if (!idata[FI_LDATE]) idata[FI_LDATE]=file_date(filename);
    ip=(regexp(data,"^called_from_ip")+({""}))[0][16..<2];
    sdata[FS_PRESAY]=(regexp(data,"^presay")+({""}))[0][8..<2];
    name=capitalize(str);
    sdata[FS_TITLE]=(regexp(data,"^title")+({""}))[0][7..<2];
    sdata[FS_RACE]=(regexp(data,"^aRace")+({""}))[0][7..<2];
    if (!strlen(sdata[FS_RACE])) sdata[FS_RACE]=(regexp(data,"^race")+({""}))[0][6..<2];
    sdata[FS_GUILD]=(regexp(data,"^guild")+({""}))[0][7..<2];
    sdata[FS_AWAY]=0;
    hide_wiz_status = query_wiz_level(LOWER(name)) > 0;
    if (IS_ARCH(TP)) sdata[FS_TAG] = query_wiz_tag(lower_case(name), 7);
    else sdata[FS_TAG] = query_wiz_tag(lower_case(name), 5);
    idata[FI_GENDER]=to_int((regexp(data,"^pGender")+regexp(data,"^gender")+({""}))[0][7..]);
    if (idata[FI_GENDER]==GENDER_FEMALE) {
      switch (sdata[FS_TAG]) {
        case "God": sdata[FS_TAG]="Goddess";break;
        case "Domainlord": sdata[FS_TAG]="Domainlady"; break;
        case "Lord": sdata[FS_TAG]="Lady";
      }
    }
    idata[FI_AGE]=HBINT*to_int((regexp(data,"^age")+({""}))[0][4..]);
    idata[FI_GHOST]=to_int((regexp(data,"^aLState")+regexp(data,"^ghost")+({""}))[0][6..]);
    idata[FI_XP] = to_int((regexp(data,"^aXP")+({""}))[0][4..]);
    if(!(idata[FI_WLEVEL]=query_wiz_level(str))) idata[FI_WLEVEL]=-xp2level(idata[FI_XP]);
  }

  /* format some strings */
  if(!sdata[FS_RACE] || sdata[FS_RACE]=="") sdata[FS_RACE]="<ninguna>";
  if(!sdata[FS_GUILD] || sdata[FS_GUILD]=="") sdata[FS_GUILD]="<ninguno>";
  if(idata[FI_GENDER]<0 || idata[FI_GENDER]>3) idata[FI_GENDER]=3;
  if (!IS_LEARNER(TP)) {
    write(capitalize(str)+":\n");
    if (player && ipnum && !player->QueryInvis()) {
      write(capitalize(str)+" está conectad"+({"o","o","a","o"})[idata[FI_GENDER]]);
      write(" desde ["+"/lib/country"->resolve_ip_number(ipnum)+"].\n");
    }
    else {
      if (hide_wiz_status)
        write("No ves a "+capitalize(str)+" conectad"+({"o","o","a","o"})[idata[FI_GENDER]]+".\n");
      else
        write(capitalize(str)+" no está conectad"+({"o","o","a","o"})[idata[FI_GENDER]]+" "
              +ctime(idata[FI_LDATE])+" ("+dtime(time()-idata[FI_LDATE])+")\n"
             );
    }
    if (sdata[FS_AWAY] && !hide_wiz_status) write(capitalize(str)+" está ausente, "+sdata[FS_AWAY]+".\n");
  }
  else if (player) {
    if (ipnum) {
      write(capitalize(str)+" está conectad"+({"o","o","a","o"})[idata[FI_GENDER]]+".\n"
             "llamando desde "+ip+" ("+ipnum+") ["+"/lib/country"->resolve_ip_number(ipnum)+"].\n");
      if(idata[FI_IDLE] && IS_LEARNER(TP))
        write("Tiempo inactivo: "+dtime(idata[FI_IDLE])+"\n");
    }
    else {
      if (idata[FI_NDEAD] > 1) {
        write(capitalize(str)+" está desconectad"+({"o","o","a","o"})[idata[FI_GENDER]]
              +" desde "+ctime(idata[FI_NDEAD])
              +" ("+dtime(time()-idata[FI_NDEAD])+")\n"
               "  en "+sdata[FS_NDEAD]+".\n"
             );
      }
      else write(capitalize(str)+" está desconectad"+({"o","o","a","o"})[idata[FI_GENDER]]+".\n");
      write("Su última conexión fué desde "+ip+" ["+"/lib/country"->resolve_ip_number(ipnum)+"].\n");
    }
    if (sdata[FS_AWAY]) write(capitalize(str)+" está ausente, "+sdata[FS_AWAY]+".\n");
  }
  else {
    write(capitalize(str)+" no está conectad"+({"o","o","a","o"})[idata[FI_GENDER]]+".\n"
          "La última conexión fué desde "+ip+" ["+"/lib/country"->resolve_ip_number(ipnum)+"].\n"
          "Se desconectó el "
          +etime(0,ctime(idata[FI_LDATE]))+" ("+dtime(time()-idata[FI_LDATE])+")\n");
  }

  if(IS_LEARNER(TP)) {
    /* output routine for learners and wizards */
    write("Nombre completo: "+sdata[FS_PRESAY]+name+" "+sdata[FS_TITLE]+".\n");
    if(idata[FI_GHOST]) write("Este jugador es actualmente un fantasma.\n");
    write("Raza: "+sdata[FS_RACE]+". Sexo: "+
	  ({"neutro","masculino","femenino", "<asexual>"})[idata[FI_GENDER]]+
	  ".\nEdad: "+dtime(idata[FI_AGE]) + ".\n");
    if (!userinfo[USER_MAIN_CHARACTER])
    // no tiene personaje principal asociado
    {
      write("No tiene personaje principal asociado.\n");
    }
    else if (userinfo[USER_MAIN_CHARACTER] == userinfo[USER_ID])
    // personaje principal
    {
      string *names;
      write("Es un personaje principal. ");
      names = map(MASTER->find_secundary_characters(userinfo[USER_ID]) || ({}), (:$1[AR_NAME]:));
      if (sizeof(names))
      {
        write("Personajes asociados: " + implode_list(names) + ".\n");
      }
      else
      {
        write("No tiene personajes secundarios.\n");
      }
    }
    else
    // personaje secundario
    {
      write("Personaje secundario de " +
            CAP(MASTER->find_userinfo(userinfo[USER_MAIN_CHARACTER])[USER_NAME]) +
            ".\n");
    }
    if (idata[FI_WLEVEL] < 1)
    {
      int real_level = QueryRealLevel(str,-idata[FI_WLEVEL]);
      if (real_level == -idata[FI_WLEVEL])
      {
        write("Nivel de jugador: "+(-idata[FI_WLEVEL]));
      }
      else
      {
        write("Nivel de jugador: " + -idata[FI_WLEVEL] + "   " +
              "Nivel de jugador con relación a sus puntos de quest: " + real_level);
      }
    }
    else if (IS_ARCH(TP)) write("Nivel de wizard: "+idata[FI_WLEVEL]+" ("+(sdata[FS_TAG]||"Jugador")+")");
    else write("Trabajo: "+(sdata[FS_TAG]||"Jugador"));
    write("\nDirección de E-Mail: "+ (userinfo[USER_EMAIL] && userinfo[USER_EMAIL] != "0" ? userinfo[USER_EMAIL] : "ninguna") + ".\n");

    data=GetWizardInfo(str);
    if (sizeof(data)) {
      write("Dominios: ");
      if ((idata[FI_GENDER])!=2)
        for (i=0; i<sizeof(data); i++) {
          if (i > 0) write(", ");
          if (data[i][0..0]=="-") write("Member de "+capitalize(data[i][1..]));
          if (data[i][0..0]=="+") write("Vicelord de "+capitalize(data[i][1..]));
          if (data[i][0..0]=="*") write("Lord de "+capitalize(data[i][1..]));
        }
      else for (i=0; i<sizeof(data); i++) {
        if (i > 0) write(", ");
        if (data[i][0..0]=="-") write("Member de "+capitalize(data[i][1..]));
        if (data[i][0..0]=="+") write("Vicelady de "+capitalize(data[i][1..]));
        if (data[i][0..0]=="*") write("Lady de "+capitalize(data[i][1..]));
      }
      write(".\n");
    }

  }
  else { /* !IS_LEARNER(TP) */

    /* output routine for players */
    name=capitalize(str);
    write("Nombre completo: "+sdata[FS_PRESAY]+name+" "+sdata[FS_TITLE]+"\n"
	  "Raza: "+sdata[FS_RACE]+"   Sexo: "+
	  ({"neutro","masculino","femenino", "<asexual>"})[idata[FI_GENDER]]+"\n");
    if (sdata[FS_TAG]) {
      write("Trabajo: "+(sdata[FS_TAG]||"Jugador")+"\n");
    }

   data=GetWizardInfo(str);
   if (data) {
     write("Dominios: ");
     if ((idata[FI_GENDER])!=2) for (i=0; i<sizeof(data); i++)    {
       if (i > 0) write(", ");
       if (data[i][0..0]=="-") write("Member de "+capitalize(data[i][1..]));
       if (data[i][0..0]=="+") write("Vicelord de "+capitalize(data[i][1..]));
       if (data[i][0..0]=="*") write("Lord de "+capitalize(data[i][1..]));
     }
     else for (i=0; i<sizeof(data); i++) {
       if (i > 0) write(", ");
       if (data[i][0..0]=="-") write("Member de "+capitalize(data[i][1..])+".\n");
       if (data[i][0..0]=="+") write("Vicelady de "+capitalize(data[i][1..])+".\n");
       if (data[i][0..0]=="*") write("Lady de "+capitalize(data[i][1..])+".\n");
     }
     write(".\n");
   }
  }
  filename="/players/"+str+"/.project";
  if(file_size(filename)>=0) write("Proyecto: "+explode(read_file(filename), "\n")[0]+"\n");
  if(IS_LEARNER(TP) && idata[FI_WLEVEL] > 0) {
    filename="/players/"+str+"/.plan";
    if(file_size(filename) <= 0) write("Sin plan.\n");
    else if(file_size(filename) > 32767) write("Demasiados planes.\n");
    else write("Plan:\n"+read_file(filename)+"\n");
  }
  return 1;
}
