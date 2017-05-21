/**
 * ENDOR-MUD'/std/player/body.c'
 */

#include <config.h>
#include <properties.h>
#include <health.h>
#include <wizlevels.h>
#include <weather.h>
#include <moving.h>
#include <npc.h>
#include <guild.h> // NIVEL_MAXIMO
#include <sounds.h>
#include <colours.h>
#define TIMEOUT 2

inherit "/std/living/body";

public mixed Query(string name);  // std/base
public string QueryRealName(); // std/living/description
StopAllHunting(); // std/living/combat
save(); // std/player

public int QueryTrueStr();  // std/living/stats
public int QueryTrueCon();  // std/living/stats
public int QueryTrueDex();  // std/living/stats
public int QueryTrueInt();  // std/living/stats

public varargs void RegisterCmdFun(mixed funarg, mixed args); // living/commands
public void CallOut(mixed fun, int delay, varargs mixed * args); // living/heart

//-----------------------------------------------------------------------------

nosave int age_to_save;
nosave int time_last_age;

private int playerkills;    // cuantos jugadores ha matado
private int playerdeaths;   // cuantas veces ha muerto
private int lDeathTime; // la fecha de la última muerte
private string lDeathName; // quién lo mató
private int lDeathDisconnected; // si murió desconectado
private int age;

//-----------------------------------------------------------------------------

private int GuildLevel;

private string quests;
private string explored;

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Sobreescribo lo de los niveles del base
//-----------------------------------------------------------------------------

//devuelve el nivel maximo q puede tener un tio con qp
//pongo 40 como nivel maximo a partir del cual ya no aumentan los qp
#define MAX_Q_LEVEL	HLP_RLVL
public int QueryMaxLevel() {
    int qp;
    int maxl=0;
    qp = to_int(QUESTMASTER->QueryQuestPoints(TO));
    do {maxl++;} while (   qp>=to_int(QUESTMASTER->QPointLevel(maxl))
                        && maxl<MAX_Q_LEVEL);
    if (maxl && maxl < MAX_Q_LEVEL) maxl--;
    return (maxl<MAX_Q_LEVEL)?maxl:NIVEL_MAXIMO;
}

public int QueryGuildLevel()	{ return GuildLevel; }
public int SetGuildLevel(int l)	{ return GuildLevel=(l>QueryMaxLevel())?QueryMaxLevel():l; }

public int QueryRealLevel () {
    int maxlevel, reallevel;
    maxlevel = QueryMaxLevel();
    reallevel = xp2level(QueryXP());
    return (reallevel>maxlevel)?maxlevel:reallevel;
}
public int QueryLevel()         { return QueryRealLevel(); }

public int SetRealLevel(int i)  { return QueryRealLevel(); }
public int SetLevel(int i)      { return QueryRealLevel(); }

//-----------------------------------------------------------------------------

//[t] Se supone que solo puedes hacer quests en tu guild actual...
SetQuests(q) {
  return object_name(PO) == QUESTMASTER ? quests = q : 0;
}
QueryQuests() { return quests; }

public string QueryExplored() { return copy(explored); }
public string SetExplored() {
  string str;
  object lorobola;

  /* if SetExplored() is invoked by an unregistered object, EXPLOREMASTER
   * sets bit 0. Thus we need to ignore bit 0 when evaluating the
   * explored variable.
   * The EXPLOREMASTER uses our PO to check for validity
   */
  str = explored || "";
  explored = EXPLOREMASTER->SetExplored(str);
// quería anular este código de momento para Endor pero algo no va como debería.
  if (str != explored) {
    /* este sí puedo anularlo, pongo un str fijo.
    switch(random(4)) {
      case 3:	str = "Estás seguro de no haber visto esto antes...\n"; break;
      case 2:	str = "Chocante, ¿no?\n"; break;
      case 1:	str = "Eso ha sido una auténtica experiencia, desde luego.\n"; break;
      case 0:
      default:	str = "Desde luego eso ha sido interesante.\n"; break;
    }
    */
    str=ANSI_BLUE+"Consigues un punto de exploración.\n"+ANSI_NORMAL;
    RegisterCmdFun(lambda(({SYM(msg),SYM(unwind)})
                         , ({SF(||), SYM(unwind)
                                 , ({SF(tell_object), TO, SYM(msg) }) })
                         ), str);
    /*if (!catch(lorobola = clone_object("/std/food")) && lorobola) {
      lorobola->AddId(({"un lorito hinchable unido a una pelota de goma con una polea",
                        "loro","lorito","lorobola","bola","pelota de goma"}));
      lorobola->SetShort("una lorobola");
      lorobola->SetLong("Se trata de un lorito hinchable unido a una pelota de goma con una polea.\n"
        "En su cuello puedes ver un cartelito que pone:\n"+
        capitalize(TP->QueryRealName())+" estuvo en un sitio importante.\n");
      lorobola->SetValue(0);
      lorobola->SetWeight(1);
      lorobola->SetFoodKind("food");
      lorobola->SetFoodStuff(1);
      lorobola->SetFoodMsgs(({"..¡¡kraaa!!...¿urg?...¡dskraa!...\n",
                            "@@Pl_Name@@ se papea una lorobola.\n"}));
      if (lorobola->move(TO) != ME_OK) lorobola->remove();
            }*/
  }

  return QueryExplored();
}

//-----------------------------------------------------------------------------

public int QueryKills()     { return playerkills; } //cuantas veces se ha muerto
public int AddKill()        { return ++playerkills; } //añade una muerte cuando se muere

public int QueryDeaths()    { return playerdeaths; }
public int AddDeath()       { return ++playerdeaths; }

public int SetLDeathTime(int time) { return lDeathTime = time; }
public int QueryLDeathTime() { return lDeathTime; }
public string SetLDeathName(string liv) { return lDeathName = liv; }
public string QueryLDeathName() { return lDeathName; }

public int SetLDeathDisconnected(int d) { return lDeathDisconnected = d; }
public int QueryLDeathDisconnected() { return lDeathDisconnected; }


//-----------------------------------------------------------------------------

protected varargs void update_age(int enforce) {
  if (interactive(TO) || enforce) age += (time() - time_last_age)/2;
  time_last_age = time();
}

public int QueryAge() {
  update_age();
  return age;
}
public int SetAge(int i) { return QueryAge(); }

public string AgeString() {
  int i;
  string str;

  str = "";
  i = QueryAge();
  if (i/43200) { str += (i/43200) + " días "; i = i - (i/43200)*43200; }
  if (i/1800) { str += (i/1800) + " horas "; i = i  - (i/1800)*1800; }
  if (i/30) { str += (i/30) + " minutos "; i = i - (i/30)*30; }
  str += (i*2) + " segundos.";
  return str;
}

//------------------------------------------------------------

protected varargs void autosave(int initial) {
  update_age();
  if (age > age_to_save) {
    save();
    age_to_save = age + (initial ? 50 : 500);
  }
  if (interactive(TO)) CallOut(SF(autosave), 2*(age_to_save-age)+2);
}

//-----------------------------------------------------------------------------

public varargs void Die(mixed silent) {

  /* Do not kill ghosts! */
  if (TO->QueryGhost()) {
    TO->catch_msg("¡Ya estás en forma espiritual, no puedes morir de nuevo.\n");
    return 0;
  } /* invented by Jhary on Sept 5th, bugfixed by Pumuckel, Sept 6th */

  ::Die(silent);
}

//-----------------------------------------------------------------------------

#ifdef LOG_KILLS
private void _log_kill() {
  int i=0;
  object attacker_ob,ob;
  string myname, mylevel, klevel, kname, rname, *cops;
  string kname2,DieMsg,str1,str2;

  myname = capitalize(QueryRealName());
  if (i = query_wiz_level(TO)) mylevel = "w"+i;
  else mylevel = QueryLevel()+"/"+ xp2level(QueryXP());

  attacker_ob = QueryKiller()||TP;

  if (attacker_ob) {
    if (query_wiz_level(TO) && query_wiz_level(attacker_ob)) return; // Nothing to log.
    if (!(kname = attacker_ob->QueryRealName())
     && !(kname = attacker_ob->QueryName())
     && !(kname = (attacker_ob->QueryShort() || attacker_ob->QueryIntShort()))
       )
    {
      kname = "<invis>";
      kname2 = "Algo";
    }
    else kname2 = kname;
    if (!attacker_ob->QueryIsPlayer()) kname += " ["+object_name(attacker_ob)+"]";
    else if ((rname = attacker_ob->QueryRealName()) && kname != rname) kname += " ["+rname+"]";
    if (query_once_interactive(attacker_ob) && (i = query_wiz_level(attacker_ob)) ) klevel = "w"+i;
    else klevel = attacker_ob->QueryLevel();
  }
  else {
    klevel = kname = "???";
    kname2 = "Algo";
  }

 if (attacker_ob && query_once_interactive(attacker_ob) && (TO != attacker_ob)) {
    rname = ctime()+" "+kname+"("+klevel+") mato a "
            +myname+"("+mylevel+")\n";
   write_file("/log/KILLER", rname);
   attacker_ob->AddKill();
 }
 else {
   write_file("/log/KILLS", ctime() + ": "+myname+"("+mylevel+") murió por la acción de "+
                    kname+"("+klevel+"), creador: "+
                    (attacker_ob?getuid(attacker_ob):"<nadie>")
                    +((environment() && environment()->QueryKillZone())
                     ? " (LEGAL)"
                     : "")
                    +"\n");
 }

  if (!attacker_ob) CHANNELMASTER->SendEmote("infomud", myname+" ha muerto.", SND_SUCESOS("muerte_jugador"));
  else {
    // Parche anti Pepe murió a manos de Pepe
    if (!DieMsg=attacker_ob->QueryDieMsg()) {
        if (TO == attacker_ob) {
            CHANNELMASTER->SendEmote("infomud", myname+" ha muerto.", SND_SUCESOS("muerte_jugador"));
        }
        else {
            CHANNELMASTER->SendEmote("infomud", kname2+" ha matado a "+myname+".", SND_SUCESOS("muerte_jugador"));
        }
    }
    else if (sscanf(DieMsg,"%s#jug#%s",str1,str2)==2)
        CHANNELMASTER->SendEmote("infomud",str1+myname+str2, SND_SUCESOS("muerte_jugador"));
    else if (living(attacker_ob))
        CHANNELMASTER->SendEmote("infomud", kname2+" ha matado a "+myname+".", SND_SUCESOS("muerte_jugador"));
    else
        CHANNELMASTER->SendEmote("infomud", myname+" ha muerto.", SND_SUCESOS("muerte_jugador"));
  }
}
#endif

/**
 * public int another_life()
 * Sobrecargada de /std/living/body, información alli.
 */
protected int another_life() {
    object asesino;
#ifdef LOG_KILLS
    _log_kill();
#endif

    // Dejar el cuerpo y convertirnos en fantasma:
    LeaveCorpse();

    // Al morir pierdes la xp extra ganada ese nivel (solo de guild)
    TO->SetGuildXP(level2xp(TO->QueryGuildLevel()));
    // Y tb un punto en cada stat, pero en endor-mud se anula
/*
    if (TO->QueryTrueStr() > 1) TO->SetStr(TO->QueryTrueStr()-1);
    if (TO->QueryTrueCon() > 1) TO->SetCon(TO->QueryTrueCon()-1);
    if (TO->QueryTrueDex() > 1) TO->SetDex(TO->QueryTrueDex()-1);
    if (TO->QueryTrueInt() > 1) TO->SetInt(TO->QueryTrueInt()-1);
*/
    // Y se resetean estos valores
    TO->SetAlcohol(0);
    TO->SetFood(0);
    TO->SetDrink(0);
    TO->SetTP(0); //nuevo para endor
    TO->SetSP(0); // nuevo para endor
    // Y añadimos una muerte
    AddDeath();
   // y la fecha de la última y quien lo mató
    TO->SetLDeathTime(time());
    TO->SetLDeathName(   call_other((asesino = TO->QueryKiller() || PO), "QueryName")
                      || asesino->QueryShort() || asesino->QueryIntShort() || "alguien");
    if (TO->QueryNetdead()) TO->SetLDeathDisconnected(1);
    else TO->SetLDeathDisconnected(0);
    TO->SetKiller(0);
    TO->catch_msg("\nTe estremeces de forma incontrolable mientras la vida abandona tu cuerpo....\n\n"
    "Todo lo vivido se despliega ante tus ojos durante un eterno instante....\n"
    "Sientes como te desembarazas de tu envoltura de carne mortal...\n"
    "todo dolor, fatiga y pesar desaparece por completo....\n"
    "El mundo físico pierde nitidez ante tu vista que ahora es de 360 grados....\n"
    "Desapareces en un vórtice de prístina luz blanca...\n\n");
    clone_object("/room/death_mark")->move(TO, M_SILENT);
    save();

    return 1;
}

//------------------------------------------------------------

public void create() {
  ::create();
  time_last_age = time();
  age_to_save = age + 50;
  autosave();
}
