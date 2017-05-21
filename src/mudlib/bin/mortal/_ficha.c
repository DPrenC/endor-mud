// Comando ficha

#include "/secure/config.h"
#include "/secure/wizlevels.h"
#include "/secure/userinfo.h"
#include "/secure/daemons.h"
#include UDP_HEADER
#include <colours.h>
#include <stats.h> //para newstats
#include <characters.h>
#include <money.h>
#include <properties.h>
#include <bandos.h>
#define HBINT         2   /* interval between two heart_beats in seconds    */
#define MINIDLE      60   /* minimum idle time in seconds to be stated idle */

#define MDTQS "/obj/lib/mdtqs"

inherit MDTQS;
inherit STR;
public int datos_player(object player);
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
    ret += time/86400+" días ";
    time %= 86400;
  }
  //if (time < 36000) ret += "0";
  ret += time/3600+" horas ";
  time %= 3600;
  //if (time < 600) ret += "0";
  ret += time/60+" minutos ";
  time %= 60;
  //if (time < 10) ret += "0";
  ret += time+" segundos";
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
  string *sdata, ip, name, ipnum,razabase;
  int    *idata, i;
  string user, mud, err;
  string talla, subraza;
    int dinero, valid;
                object ob;
    int	hide_wiz_status=0;
    //no hay argumento, entonces sale la info del propio player.
  if (!str){
    seteuid(getuid());
    userinfo=MASTER->find_userinfo(TP->QueryRealName());
if (TP->QueryGhost()) {
       write("Estás muerto.\n");
       return 1;
    }

switch(TP->QuerySize()){
    case 1: talla="pequeño"; break;
    case 2: talla="mediano"; break;
    case 3: talla="grande"; break;
    case 4: talla="enorme"; break;
    case 0:
    default: talla="genérico"; break;
    }
    switch(TP->QueryRazabase()){
        case "humano": subraza="cultura"; break;
        case "elfo": subraza="estirpe"; break;
        case "enano": subraza="clan"; break;
        case "orco": subraza="subraza"; break;
        case "hobbit": subraza="variante"; break;
        case "alto-hombre": subraza="civilización"; break;
        default: subraza="subraza"; break;
        }

    i = EXPLOREMASTER->CountBits(TP->QueryExplored());

        write("Eres "+
              CAP(TP->QueryPresay())+" "+CAP(TP->QueryRealName())+" "+CAP(TP->QueryTitle())+
              ", vagando"+(TP->QueryInvis() ? " invisible" : "")+" por "+(!environment(TP)->QueryLocate() ? "algún lugar de Arda" : environment(TP)->QueryLocate())+".\n"+
                (IS_MAIA(TP) ? "Ainu de nivel "+query_wiz_level(TP)+".\n" : "")+
                (TP->QueryAway() ? "Ausente en estos momentos.\n" : "")+
                                          ((valid = CHARMASTER->QueryValidName(TNREAL)) == NICK_PENDING || valid == NICK_UNKNOWN?
               TC_RED + "Tu nombre aún no ha sido aceptado, si necesitas información al respecto contacta con un Vala."+ TC_NORMAL + "\n" :
               (valid == NICK_INVALID ? TC_RED + "Los valar no ven con buenos ojos tu nombre. "
                "Cuando te desconectes tu ficha será borrada de Endor-Mud. Puedes consultar esta situación con un Vala.\n" : "")) +

                    "\nPersonaje "+TP->QueryGenderString()+
                        ", tamaño "+talla+"."+
                        " De raza "+TP->QueryRazabase()+" y "+subraza+" "+TP->QueryRace()+".\n"+
((TP->QueryCitizenship()=="errante" || TP->QueryCitizenship()=="") ? " Vives de una forma errante" : " Tu ciudadanía es "+CAP(TP->QueryCitizenship()))+", perteneciente al "+TP->QueryBandoTxt()+".\n"+
                    (TP->QueryGuild()?"Tu nivel de "+TP->QueryGuild()+" es "+TC_BOLD+TP->QueryGuildLevel()+TC_NORMAL+" con ":"No perteneces a ninguna clase.\n")+
                           (TP->QueryGuild()?TC_BOLD+ TP->QueryGuildXP() +TC_NORMAL " puntos de experiencia"+", ":"")+
              TC_BOLD+
              (QUESTMASTER->QueryQuestPoints(TP))+TC_NORMAL" puntos de quest y "
              TC_BOLD+TC_NORMAL" "+(i*100)/EXPLOREMASTER->TotalEP()+"% de exploración ("+i+" EP).\n"+TC_NORMAL
               "Vida: "TC_BOLD+TP->QueryHP() +TC_NORMAL " de "+TP->QueryMaxHP()+"\n"+
              "Poder: "+TC_BOLD+TP->QuerySP() +TC_NORMAL " de "+TP->QueryMaxSP()+"\n"
"Vigor: "+TC_BOLD+TP->QueryTP() +TC_NORMAL " de "+TP->QueryMaxTP()+"\n"
               //"y tu carácter es "+TP->QueryAlignString(TP->QueryAlign())+".\n"
               "Te encuentras "+(TP->QueryStatusSleeping() ? "durmiendo, " : (TP->QueryStatusResting()==1 ? "descansando, " : ""))+
         TP->QueryHealthLoadMsg(0)+
    (TP->QueryIntWeight()==0 ? ".\n" : ", soportando una carga de "+(TP->QueryIntWeight()<1000 ? TP->QueryIntWeight()+" gramos.\n" : TP->QueryIntWeight()/1000+" kilos.\n"))+
               "\nLas características de tu personaje son:\n"
              TC_BLUE"\tFuerza:      "TC_NORMAL" "+TP->QueryStr()+" | "
              TC_BLUE"Destreza:    "TC_NORMAL" "+TP->QueryDex(1)+"\n"
              TC_BLUE"\tConstitución:"TC_NORMAL" "+TP->QueryCon()+" | "
              TC_BLUE"\tInteligencia:"TC_NORMAL" "+TP->QueryInt()+"\n"
              TC_BLUE"\tSabiduría:   "TC_NORMAL" "+TP->QueryWis()+" | "
              TC_BLUE"Carisma:     "TC_NORMAL" "+TP->QueryCha()+"\n"

              "\n");

        if (IS_MAIA(TP)) {
            write(TC_BLUE"Sed     : "TC_NORMAL+TP->QueryDrink()+
                "\n"TC_BLUE"Hambre  : "TC_NORMAL+TP->QueryFood()+
                "\n"TC_BLUE"Alcohol : "TC_NORMAL+TP->QueryAlcohol()+"\n");
        }
        else {
            i = (TP->QueryAlcohol()*100) / (TP->QueryMaxAlcohol()||1);
            switch(i) {
                case 90..101: write("Estás demasiado borrach"+TP->QueryGenderEndString()+".\n"); break;
                case 75.. 89: write("Te cuesta mantener la compostura.\n"); break;
                case 50.. 74: write("Te cuesta mantener el equilibrio.\n"); break;
                case 25.. 49: write("Te notas ligeramente embriagad"+TP->QueryGenderEndString()+".\n"); break;
                case 10.. 24: write("te vas notando algo de alcohol en el cuerpo.\n"); break;
                case  5..  9: write("Te notas algo contentill"+TP->QueryGenderEndString()+".\n"); break;
                case -1..  4: write("Estás sobri"+(TP->QueryGender()==GENDER_FEMALE?"a":"o")+".\n"); break;
                default: write("Tu nivel de alcohol en el cuerpo es: "
                               +TP->QueryAlcohol()+"\n");
            }
            i = (TP->QueryFood()*100) / (TP->QueryMaxFood()||1);
            switch(i) {
                case 90..101: write("Tu estómago está escesivamente lleno.\n"); break;
                case 75.. 89: write("Has comido suficiente.\n"); break;
                case 50.. 74: write("No tienes hambre.\n"); break;
                case 25.. 49: write("Tienes un poco de hambre.\n"); break;
                case 10.. 24: write("Ya tienes que ir pensando en comer algo.\n"); break;
                case  0..  9: write("Tienes hambre.\n"); break;
                default:
                  i = TP->QueryFood();
                  if (i > -10) write("Tienes mucha hambre.\n");
                  else if (i > -50) write("Estás hambrient"+TP->QueryGenderEndString()+".\n");
                  else if (i > -250) write("Te estás muriendo de hambre.\n");
                  else if (i > -500) write("Practicamente estás muert"+TP->QueryGenderEndString()+" de hambre.\n");
                  else write("Tu nivel de hambre es: "+i+"\n");
            }
            i = (TP->QueryDrink()*100) / (TP->QueryMaxDrink()||1);
            switch(i) {
                case 90..101: write("Tu estómago no acepta más líquido.\n"); break;
                case 75.. 89: write("Has bebido suficiente.\n"); break;
                case 50.. 74: write("No tienes sed.\n"); break;
                case 25.. 49: write("Te vendría bien beber algo.\n"); break;
                case 10.. 24: write("Tienes la boca seca.\n"); break;
                case  0..  9: write("Tienes sed.\n"); break;
                default:
                  i = TP->QueryDrink();
                  if (i > -10) write("Tienes mucha sed.\n");
                  else if (i > -50) write("Tu cuerpo necesita líquido urgentemente.\n");
                  else if (i > -250) write("Te estás muriendo de sed.\n");
                  else if (i > -500) write("Practicamente estás muert"+TP->QueryGenderEndString()+" de sed.\n");
                  else write("Tu nivel de sed es: "+i+"\n");
            }
        }
dinero = 0;
       for(ob=first_inventory(TP);ob;ob=next_inventory(ob)) {
        if(object_name(efun::blueprint(ob)) == "/obj/money") dinero = ob->QueryValue();
        }
        write((dinero<1 ? "No llevas dinero encima.\n" : "El dinero que llevas encima equivale a "+dinero+" monedas de cobre.\n"));
        if (TP->QueryWhimpy()) write(TC_BLUE"Tu valentía es del "+TC_NORMAL+(TP->QueryWhimpy()*100)/TP->QueryMaxHP()+"% ("+TP->QueryWhimpy()+")\n");
                    else write("Luchas de una forma valerosa.\n");
            write(
            (TP->QueryDeaths()==0 ? "Todavía no has muerto ninguna vez" : "Has muerto "+(TP->QueryDeaths()==1 ? "una vez" : TP->QueryDeaths()+" veces"))+
(TP->QueryDeaths()==0 ? (TP->QueryKills()==0 ? " y tampoco has matado a ningún jugador" : " pero sí has matado a "+TP->QueryKills()+" jugadores") : (TP->QueryKills()==0 ? " pero no has matado a ningún jugador" : " y has matado a "+TP->QueryKills()+" jugadores"))
                +".\n");

        write(TC_BLUE"Juego total: "TC_NORMAL+TP->AgeString()+"\n");
if (!userinfo[USER_MAIN_CHARACTER])
    // no tiene personaje principal asociado
    {
      write("No tienes personaje base en tu ficha, contacta con un Ainu para solucionarlo.\n");
    }
    else if (userinfo[USER_MAIN_CHARACTER] == userinfo[USER_ID])
    // personaje principal
    {
      string *names;
      write(CAP(TP->QueryRealName())+" es tu personaje base.\n");
      names = map(MASTER->find_secundary_characters(userinfo[USER_ID]) || ({}), (:$1[AR_NAME]:));
      if (sizeof(names))
      {
        write("Tus otros personajes: " + implode_list(names) + ".\n");
      }
      else
      {
//        write("No tiene personajes secundarios.\n");
      }
    }
    else
    // personaje secundario
    {
      write(CAP(TP->QueryRealName())+" es el personaje secundario de " +
            CAP(MASTER->find_userinfo(userinfo[USER_MAIN_CHARACTER])[USER_NAME]) +
            ".\n");
    }
        return 1;
    } //código de estado, comando sin argumento.
//ahora comando con argumento
  seteuid(getuid());
  str = implode(explode(str, " ")-({""})," ");
    if (sizeof(explode(str," "))>1) return notify_fail("No uses espacios en el nombre.\n");

  /* switch to lower case */
  str=lower_case(str);

  /* does this player exist? */
  userinfo=MASTER->find_userinfo(str);
  filename="/save/"+str[0..0]+"/"+str+".o";
  if(!userinfo && file_size(filename)<0) return notify_fail("No tenemos a ningún personaje registrado en Endor-Mud con el nombre de "+str+".\n");

  if(userinfo && file_size(filename) <= 0) {
    pos = query_wiz_level(str);
    if (!pos) return notify_fail("No tenemos a ningún personaje registrado en Endor-Mud con el nombre de "+str+".\n");
    write(capitalize(str)+" Se trata de un Ainu ya ajeno a las incunvencias de los confines de Arda.\n");
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
      if(file_size(filename)<0) return notify_fail("No está disponible la información de " + capitalize(str) + ".\n");
      data=explode(read_file(filename),"\n");
      ip=(regexp(data,"^called_from_ip")+({""}))[0][16..<2];
      if (!idata[FI_LDATE]) idata[FI_LDATE]=file_date(filename);
      idata[FI_NDEAD]=player->QueryNetdead();
      sdata[FS_NDEAD]=player->QueryNetdeadRoom();
      if (!sdata[FS_NDEAD]) sdata[FS_NDEAD] = to_string(environment(player));
    }
    sdata[FS_PRESAY]=player->QueryPresay();
    name=CAP(player->QueryRealName());
    sdata[FS_TITLE]=player->QueryTitle();
    sdata[FS_RACE]= CAP(player->QueryRazabase())+" "+CAP(player->QueryRace())+" de "+((player->QueryCitizenship()=="" || player->QueryCitizenship()=="errante") ? "vida errante" : CAP(player->QueryCitizenship()))+".\n Pertenece al "+ player->QueryBandoTxt();
        sdata[FS_GUILD]=player->QueryGuild()+(IS_MAIA(TP) ? " ("+player->QueryGuildLevel()+")" : "");
    sdata[FS_AWAY]=player->QueryAway();
        if (IS_MAIA(TP)) sdata[FS_TAG] = query_wiz_tag(player, 7);
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
    if(file_size(filename)<=0) return notify_fail("No está disponible la información de " + capitalize(str) + ".\n");
    data=explode(read_file(filename),"\n");
        idata[FI_LDATE]=to_int((regexp(data,"^pLastSave")+({""}))[0][10..]);
    if (!idata[FI_LDATE]) idata[FI_LDATE]=file_date(filename);
    ip=(regexp(data,"^called_from_ip")+({""}))[0][16..<2];
    sdata[FS_PRESAY]=(regexp(data,"^presay")+({""}))[0][8..<2];
    name=capitalize(str);
    sdata[FS_TITLE]=(regexp(data,"^title")+({""}))[0][7..<2];
        sdata[FS_RACE]=CAP((regexp(data,"^aRazabase")+({""}))[0][11..<2])+" "+CAP((regexp(data,"^aRace")+({""}))[0][7..<2])+" de "+
    (((regexp(data,"^aCitizenship")+({""}))[0][14..<2]=="" || (regexp(data,"^aCitizenship")+({""}))[0][14..<2]=="errante") ? "vida errante" : CAP((regexp(data,"^aCitizenship")+({""}))[0][14..<2]))+
        ".\nPertenece al "+(regexp(data,"^aBandoTxt")+({""}))[0][11..<2];
    if (!strlen(sdata[FS_RACE])) sdata[FS_RACE]=(regexp(data,"^race")+({""}))[0][6..<2];
    sdata[FS_GUILD]=(regexp(data,"^guild")+({""}))[0][7..<2]+(IS_MAIA(TP) ? " ("+(regexp(data,"^GuildLevel")+({""}))[0][11..<1]+")" : ""); // esto último no está muy claro
    sdata[FS_AWAY]=0;
    hide_wiz_status = query_wiz_level(LOWER(name)) > 0;
    if (IS_VALA(TP)) sdata[FS_TAG] = query_wiz_tag(lower_case(name), 7);
    else sdata[FS_TAG] = query_wiz_tag(lower_case(name), 5);
    idata[FI_GENDER]=to_int((regexp(data,"^pGender")+regexp(data,"^gender")+({""}))[0][7..]);
    if (idata[FI_GENDER]==GENDER_FEMALE) {
      switch (sdata[FS_TAG]) {
        case "God": sdata[FS_TAG]="Goddess";break;
        case "Domainlord": sdata[FS_TAG]="Domainlady"; break;
        case "Lord": sdata[FS_TAG]="Lady";
            case "Heraldo": sdata[FS_TAG]="Heralda";
                case "Vala": sdata[FS_TAG]="Valie";
      }
    }
    idata[FI_AGE]=HBINT*to_int((regexp(data,"^age")+({""}))[0][4..]);
    idata[FI_GHOST]=to_int((regexp(data,"^aLState")+regexp(data,"^ghost")+({""}))[0][6..]);
    idata[FI_XP] = to_int((regexp(data,"^aXP")+({""}))[0][4..]);
    if(!(idata[FI_WLEVEL]=query_wiz_level(str))) idata[FI_WLEVEL]=-xp2level(idata[FI_XP]);
  }

  /* format some strings */
  if(!sdata[FS_RACE] || sdata[FS_RACE]=="") sdata[FS_RACE]="Procedencia desconocida, informa a un Ainu";
  if(!sdata[FS_GUILD] || sdata[FS_GUILD]=="") sdata[FS_GUILD]="Sin oficio";
  if(idata[FI_GENDER]<0 || idata[FI_GENDER]>3) idata[FI_GENDER]=3;
  if (!IS_MAIA(TP)) {
    //write(capitalize(str)+":\n");
    if (player && ipnum && !player->QueryInvis()) {
      write(capitalize(str)+" está conectad"+({"o","o","a","o"})[idata[FI_GENDER]]+".\n"); //desde un player
          }
    else {
      if (hide_wiz_status)
        write(CAP(str)+" no vaga por Arda.\n");
      else
        write(CAP(str)+" no vaga por Arda desde el "
              +etime(1, ctime(idata[FI_LDATE]))+"\n hace "+dtime(time()-idata[FI_LDATE])+"\n"
             );
    }
    if (sdata[FS_AWAY] && !hide_wiz_status) write(capitalize(str)+" se encuentra ausente, "+sdata[FS_AWAY]+".\n");
  }
  else if (player) {
        if (ipnum) {
      write(CAP(str)+" está conectad"+({"o","o","a","o"})[idata[FI_GENDER]]+
      "\nIP: "+ip+"\n"); //desde un ainu
                               if(idata[FI_IDLE] && IS_MAIA(TP))
        write("Sin actividad: "+dtime(idata[FI_IDLE])+"\n");
        if(IS_MAIA(TP)) datos_player(player);
    }
    else {
      if (idata[FI_NDEAD] > 1) {
        write(capitalize(str)+" está desconectad"+({"o","o","a","o"})[idata[FI_GENDER]]
              +" desde "+etime(idata[FI_NDEAD])
              +"\n hace "+dtime(time()-idata[FI_NDEAD])+"\n"
               " en "+sdata[FS_NDEAD]+".\n"
             );
      }
      else write(capitalize(str)+" está desconectad"+({"o","o","a","o"})[idata[FI_GENDER]]+".\n");
            write("Su última conexión fué desde "+ip+"\n");
    }
    if (sdata[FS_AWAY]) write(capitalize(str)+" está ausente, "+sdata[FS_AWAY]+".\n");
  }
  else {
    write(capitalize(str)+" no vaga por Arda en estos momentos.\n"
                    "La última conexión fué desde "+ip+"\n"
          "Se desconectó el "
          +etime(1, ctime(idata[FI_LDATE]))+" hace "+dtime(time()-idata[FI_LDATE])+".\n");
  }

  if(IS_MAIA(TP)) {
    /* output routine for learners and wizards */
    write("Nombre completo: "+CAP(sdata[FS_PRESAY])+" "+name+" "+sdata[FS_TITLE]+".\n"); // desde un ainu a player desconectado
    if(idata[FI_GHOST]) write("Este jugador es actualmente un fantasma.\n");
    write(sdata[FS_RACE]+".\n Género: "+
	  ({"neutro","masculino","femenino", "<asexual>"})[idata[FI_GENDER]]+
	  	  ". Ocupación: "+sdata[FS_GUILD]+".\nJuego total: "+dtime(idata[FI_AGE]) + "\n");
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
       if (real_level == -idata[FI_WLEVEL]){
        if (IS_MAIA(TP)) write("Nivel de jugador: "+(-idata[FI_WLEVEL]));
      }else{
        if (IS_MAIA(TP)) write("Nivel de jugador: " + -idata[FI_WLEVEL] + ".\n Nivel de jugador con relación a sus puntos de quest: " + real_level);
      }
    }
    else if (IS_MAIA(str)) write("Nivel de Ainu: "+idata[FI_WLEVEL]+" ("+(sdata[FS_TAG]||"Jugador")+")");
         write("\nDirección de E-Mail: "+ (userinfo[USER_EMAIL] && userinfo[USER_EMAIL] != "0" ? userinfo[USER_EMAIL] : "ninguna") + ".\n");
}
  else { /* !IS_LEARNER(TP) */

    /* output routine for players */
    // de jugador a otro jugador, tanto conectado como desconectado.
    name=capitalize(str);
    write("Nombre completo: "+CAP(sdata[FS_PRESAY])+" "+name+" "+CAP(sdata[FS_TITLE])+"\n");
    if (IS_MAIA(str)){
         write("Nivel de Ainu: "+idata[FI_WLEVEL]+" ("+(sdata[FS_TAG]||"Jugador")+")\n");
        }else{
	   write(sdata[FS_RACE]+".\n Género: "+
	  ({"neutro","masculino","femenino", "<asexual>"})[idata[FI_GENDER]]+
	  ". Ocupación: "+sdata[FS_GUILD]+".\nJuego total: "+dtime(idata[FI_AGE]) + "\n");
}
     }
  return 1;
}

public int datos_player(object player){
    int i = EXPLOREMASTER->CountBits(player->QueryExplored());
            int dinero=0;
            object ob;
            for(ob=first_inventory(player);ob;ob=next_inventory(ob)) {
            if(object_name(efun::blueprint(ob)) == "/obj/money") dinero = ob->QueryValue();
}
        write("Está en "+environment(player)->QueryLocate()+" ("+environment(player)->QueryIntShort()+")\n"+player->QueryHomeTmp()+"\n");
    write("Estado: "+(player->QueryAway() ? "ausente" : "presente")+
    (player->QueryInvis() ? ", invisible" : "")+(player->QueryStatusSleeping() ? " y durmiendo.\n" : (player->QueryStatusResting()==1 ? " y descansando.\n" : ".\n")));
            write("Se encuentra "+player->QueryHealthLoadMsg(1)+".\n");
            write("STR: "+player->QueryStr()+", DEX: "+player->QueryDex()+", INT: "+player->QueryInt()+", CON: "+player->QueryCon()+", WIS: "+player->QueryWis()+", CHA: "+player->QueryCha()+".\n");
            write("Su peso: "+player->QueryWeight(1)+". Carga: "+player->QueryIntWeight()+". Tamaño: "+player->QuerySize()+".\n");
        write("Nivel de "+player->QueryGuild()+": "+player->QueryGuildLevel()+".\n"+
        "XP: "+player->QueryXP()+". GuildXP: "+player->QueryGuildXP()+".\n");
        write("QP: "+(QUESTMASTER->QueryQuestPoints(player))+". EP: "
              +i+"/"+EXPLOREMASTER->TotalEP()+". CP: 0.\n"); // los CP serán los puntos canjeables.
        write("Sed: "+player->QueryDrink()+"/"+player->QueryMaxDrink()+
                " Hambre: "+player->QueryFood()+"/"+player->QueryMaxFood()+
                " Alcohol: "+player->QueryAlcohol()+"/"+player->QueryMaxAlcohol()+"\n");
    write("Vida: "+player->QueryHP()+"/"+player->QueryMaxHP()+" "+
              "Poder: "+player->QuerySP() +"/"+player->QueryMaxSP()+" "+
"Vigor: "+player->QueryTP() +"/"+player->QueryMaxTP()+"\n");
write("IVision: "+player->QueryIVision()+". UVision: "+player->QueryUVision()+".\n");
write("Muertes: "+player->QueryDeaths()+". PK: "+player->QueryKills()+". Valentía: "+player->QueryWhimpy()+".\n");
        write("Dinero que porta: "+dinero+".\n");
    return 1;
}
