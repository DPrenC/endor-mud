/**
 * ENDOR-MUD'/std/living/body.c'
 */
#include <xp.h>
#include <attributes.h>
#include <combat.h>
#include <living.h>
#include <messages.h>
#include <moving.h>
#include <wizlevels.h>
#include <nightday.h>
#include <properties.h>
#include <colours.h>
#include <health.h>
#include <prompt.h>
#include <guild.h> //para la xp
#include <ts.h>    //[m] para tiradas de salvación
#include <sounds.h>

#define NETDEAD  (TO && !interactive() && query_once_interactive(TO))
#define AO QueryGenderEndString()

#ifndef OLD_GUILD_LEVEL
#define OLD_GUILD_LEVEL    0
#define OLD_GUILD_XP    1
#endif

public mixed Query(string pn);  // std/base
public mixed Set(string pn, mixed arg);   // std/base
public varargs mixed QueryAttr(string aname, int sc);  // std/living/attributes
public varargs mixed SetAttr(string aname, mixed value, int sc); // std/living/attributes
public int QueryAlign();         // std/living/description
public int QueryLState();        // std/living/description
public int SetLState(int i);     // std/living/description
public int QueryGhost();         // std/living/description
public string QueryGenderEndString(); // std/thing/description
public int QueryLevel();         // forward
public string QueryName();       // std/living/description
public string QueryRace();       // std/living/description
public /* mapping */ mixed QueryEnemies ();  // std/living/combat
public void StopAllHunting();    // std/living/enemies
public varargs int remove();     // std/living/moving
public varargs void Whimpy(int flags); // std/living/moving
public void DropHeart(int user); // std/living/heart
public void GetHeart(int user);  // std/living/heart
public int CheckHeart(int user); // std/living/heart
public int QueryHeart();         // std/living/heart
public int QueryCon();                 // std/living/stats
public varargs int QueryDex(int real); // std/living/stats
public varargs int QueryStr(int real); // std/living/stats
public int QueryInt();                 // std/living/stats
public int QueryConModifier();           // std/living/stats
public int QueryDexModifier();           // std/living/stats
public int QueryStrModifier();           // std/living/stats
public int QueryIntModifier();           // std/living/stats
public int SetDexBonus(int v);
public int SetConBonus(int v);
public int SetIntBonus(int v);
public int SetStrBonus(int v);
public int SetTmpStr(int v);     // std/living/stats
public int SetTmpCon(int v);     // std/living/stats
public int SetTmpDex(int v);     // std/living/stats
public int SetTmpInt(int v);     // std/living/stats
public int ApplyStat(string name, int diff); // std/living/stats
public int UseStat(string name, int diff);  // std/living/stats
public void DropOverload();  // std/living/restrictions
public int QueryLoad();                   // std/living/restrictions
public varargs int QueryWeight(int flag); // std/living/restrictions
public int QueryIntWeight();
public int QueryMaxIntWeight();           // std/living/restrictions
public int QueryGender();

public int QueryRegHP();    // forward
public int QueryRegSP();    // forward
public object LeaveCorpse();    // forward
public int QueryResistance(mixed type);    // forward
public int QueryHP();
public int QuerySP();
public int QueryMaxHP();
public int SetMaxHP(int i);
public int QueryMaxSP();
public int SetMaxSP(int i);
public int SetHP(int i);
public int SetSP(int i);
public int QueryFood();
public int QueryDrink();
public int QueryAlcohol();
public int QueryRateAlcohol();

/*--------------------------------------------------------------------------*/
private string guild;                   // nombre del gremio o "ninguno"
private int guildXP;
private mapping old_guilds;        //[t] gremios antiguos ([clase:nivel])


private int aHP, aMaxHP, aXP, pKillXP;
private int aSP, aMaxSP;
private int aTP, aMaxTP;
private int aAlcohol, aFood, aDrink;
private int aDegAlcohol, aDegFood, aDegDrink;
private int aMaxAlcohol, aMaxFood, aMaxDrink;
private int aRateAlcohol;
private mapping aResistances;

private static int pRegHP, pRegSP, pRegTP;
private static int aRateHP, aRateSP, aRateTP;
private mixed aWhimpy, aCorpse;
private int aStunned, aTiredMagic; //en heart_beats!!! (asaltos)
private int aParalyzed; // distinto de cero si esta paralizado

// These variables accumulate the 1/10-regeneration points
// over the heart_beat()s.
private int accHP, accSP, accTP;
// These variables accumulate the 1/10-degeneration points
// over the heart_beat()s.
private int accAlc, accFood, accDrink;

private static int aQuieroHuir;
private static object aKiller;
private static int aStatus;

private static object dead_ob; // Llama a dead_ob->player_died para que se encargue de la muerte
private static object *inform_death = ({}); // informa a estos objetos de la muerte
/*--------------------------------------------------------------------------*/

public varargs void Die(mixed silent);           // forward
public varargs mixed QueryWhimpy (int absolut);  // forward
public int QueryParalyzed();                     // forward

//----------------------------------------------------------------------------
// Status
//----------------------------------------------------------------------------
public int QueryStatus()         { return aStatus; }
public int SetStatus(int i)      { return aStatus=i; }
public int SetStatusNormal()     { return SetStatus(STATUS_NORMAL  ); }
public int SetStatusResting()    { return SetStatus(STATUS_RESTING ); }
public int SetStatusSleeping()   { return SetStatus(STATUS_SLEEPING); }
public int SetStatusTripped()    { return SetStatus(STATUS_TRIPPED ); }
public int SetStatusHelpless()   { return SetStatus(STATUS_HELPLESS); }
public int QueryStatusNormal()   { return (QueryStatus()==STATUS_NORMAL  ); }
public int QueryStatusResting()  { return (QueryStatus()==STATUS_RESTING ); }
public int QueryStatusSleeping() { return (QueryStatus()==STATUS_SLEEPING); }
public int QueryStatusTripped()  { return (QueryStatus()&STATUS_TRIPPED ); }

public int QueryStatusHelpless() {
  if (QueryParalyzed()) return 1;
  return (QueryStatus()&STATUS_HELPLESS);
}

//----------------------------------------------------------------------------
// DeadOb
//----------------------------------------------------------------------------
public object SetDeadOb(object o) { return dead_ob = o; }
public object QueryDeadOb() { return dead_ob; }

//----------------------------------------------------------------------------
// InformObj
//----------------------------------------------------------------------------
// [Nyh] Comento el Set porque los set de arrays acaban trayendo problemas
//public object *SetInformObjs(object *ob) { return inform_death=ob||({}); }
public object *QueryInformObjs() {
  inform_death = filter(inform_death, SF(objectp));
  return copy(inform_death);
}
public object *AddInformObj(object ob) {
  if (objectp(ob)) inform_death += ({ ob });
  return  QueryInformObjs();
}
public object *RemoveInformObj(object ob) {
  inform_death -= ({ob});
  return QueryInformObjs();
}

//----------------------------------------------------------------------------
// Killer
//----------------------------------------------------------------------------
public object QueryKiller()        { return aKiller; }
public object SetKiller(object o)    { return aKiller=living(o)?o:0; }

//----------------------------------------------------------------------------
// QuieroHuir
//----------------------------------------------------------------------------
public int QueryQuieroHuir()    { return aQuieroHuir; }
public int SetQuieroHuir(int i)    { return aQuieroHuir=i>0?1:0; }

//----------------------------------------------------------------------------
// Stunned
//----------------------------------------------------------------------------
public int QueryStunned()    { return aStunned; }
public int SetStunned(int i) {
  if (i>0) {
    GetHeart(HEART_HEAL);
    aStunned=i;
  }
  else aStunned=0;
  return QueryStunned();
}

//----------------------------------------------------------------------------
// TiredMagic
//----------------------------------------------------------------------------
public int QueryTiredMagic()    { return aTiredMagic; }
public int SetTiredMagic(int i) {
  if (i>0) {
    GetHeart(HEART_HEAL);
    aTiredMagic=i;
  }
  else aTiredMagic=0;
  return QueryTiredMagic();
}

//----------------------------------------------------------------------------
// Paralyzed
//----------------------------------------------------------------------------
public int QueryParalyzed()    { return aParalyzed; }
public int SetParalyzed(int i) {
  if (i>0) {
    GetHeart(HEART_HEAL);
    aParalyzed = i;
  }
  else aParalyzed = 0;

  return QueryParalyzed();
}

//----------------------------------------------------------------------------
// Guild
//----------------------------------------------------------------------------
public string SetGuild(string g)    { return guild=g; }
public string QueryGuild()        { return guild||"ninguno"; }
//----------------------------------------------------------------------------
// Old Guilds
//----------------------------------------------------------------------------
public mapping QueryOldGuilds()    { return old_guilds = old_guilds ? old_guilds : ([]);}
public mapping AddOldGuild(string g, int l, int xp) {
  if (!g) return 0;
  if (!old_guilds) old_guilds=([]);
  old_guilds+=([g:l;xp]);
  return QueryOldGuilds();
}
public mapping RemoveOldGuild(string g) {
  if (!g) return 0;
  if (!old_guilds) old_guilds=([]);
  m_delete(old_guilds, g);
  return old_guilds;
}
public int QueryOldGuild(string g)    { return(member(QueryOldGuilds(), g)); }
//para el cambio a new_xp
protected int SetOldGuildXP(string g, int xp) { return (old_guilds[g,OLD_GUILD_XP]=xp);}
//----------------------------------------------------------------------------
// Fin Old Guilds
//----------------------------------------------------------------------------
/*
total: xp y level
guild: guildxp y guildlevel
real:  modificado por los qp
*/
public int QueryOldGuildXP(string g)       { return member(QueryOldGuilds(), g)?(old_guilds[g,OLD_GUILD_XP]):-1;}
public varargs int QueryGuildXP(string g) { return g?QueryOldGuildXP(g):guildXP; }
public int QueryTotalXP()          { return aXP;}
public int QueryXP()              { return QueryTotalXP();}

public int QueryOldGuildLevel(string g)      { return xp2level(QueryOldGuildXP(g)); }
public varargs int QueryGuildLevel(string g) { return xp2level(QueryGuildXP(g)); }
public int QueryTotalLevel()             { return xp2level(QueryTotalXP()); }
public int QueryLevel()                 { return QueryTotalLevel(); }

public int SetOldGuildLevel(string g, int l) { return QueryOldGuildLevel(g); }
public int SetGuildLevel(int l)          { return QueryGuildLevel(); }
public int SetTotalLevel(int l)             { return QueryTotalLevel(); }
public int SetLevel(int l)             { return QueryLevel(); }

//----------------------------------------------------------------------------
// Experiencia
//----------------------------------------------------------------------------
public int SetGuildXP(int xp)    { return guildXP = xp>0 ? xp : 0; }
public int AddGuildXP(int xp) {
  int maxp, oldxp;

#ifdef DEBUG_MAX_XP //en guilds.h
  if (xp>MAX_XP) { //esto es para evitar demasiaods xp
    write_file("/log/NEW_XP",sprintf("%O llamo a %O->AddGuildXP(%O)\n",PO,TO,xp));
    xp=MAX_XP;
  }
#endif
  //no puedes tener mas xp q 2 niv por encima, el chekeo es asi de raro para
  // que no pete con la gente q pierde niveles por nuevas quests
  maxp = (level2xp(QueryGuildLevel()+2))-1;
  oldxp = QueryGuildXP();
//  if (find_object("nyh")) dtell("nyh",sprintf("level = %O,\toldxp = %O,\t maxp = %O",QueryGuildLevel(),oldxp,maxp));
  if ((xp>0) && (oldxp>=maxp)) return -1;
  xp += oldxp;
  if (xp>=maxp) xp=maxp;
  SetGuildXP(xp);
  return QueryGuildXP()-oldxp;
}
//----------------------------------------------------------------------------
public int SetXP (int i)          { return aXP = i >= 0 ? i : 0; }
public int AddXP(int xp) {
#ifdef DEBUG_MAX_XP //en guilds.h
  if (xp>MAX_XP) { //esto es para evitar demasiados xp
    write_file("/log/NEW_XP",sprintf("%O llamo a %O->AddXP(%O)\n",PO,TO,xp));
    xp=MAX_XP;
  }
#endif
  SetXP(xp+QueryXP());
  return AddGuildXP(xp);
}
public int exp(int experiencia){
    AddXP(experiencia);
    write((TP->QueryBrief()==1 ? TEXTO_XP_BREVE(experiencia) : TEXTO_XP(experiencia)));
    return 1;
}
//----------------------------------------------------------------------------
// Fin Experiencia
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Regeneracion
//----------------------------------------------------------------------------
public int QueryMaxTP() { return aMaxTP || (10+(5/STAT_SCALE)*(QueryCon()+QueryStr(1)));} // aumento el valor de la fatiga para endor.
public int QueryTP()    { return (aTP>QueryMaxTP())?(aTP=QueryMaxTP()):aTP;}

public int SetTP (int i) {
  if (NETDEAD || QueryLState() == LSTATE_GHOST) return aTP;
  GetHeart(HEART_HEAL);
  return aTP = i;
}

public int AddTP (int i) { return SetTP(i + QueryTP()); }

public int QueryRegTP ()     { return pRegTP; }
public int SetRegTP (int i)  { return pRegTP = i; }
public int AddRegTP (int i)  { return pRegTP += i; }

public int QueryRateTP ()     { return aRateTP; }
public int SetRateTP (int i)  { return SetRegTP(aRateTP = (i > 0 ? i : aRateTP)); }

//--------------------------------------------------------------------------
public int QueryMaxHP ()    { return query_once_interactive(TO)?MAX_HP(QueryGuild()||GC_NINGUNO,QueryCon()):(aMaxHP||MAX_HP(QueryGuild()||GC_NINGUNO,QueryCon()));}
public int SetMaxHP (int i) { return query_once_interactive(TO)?QueryMaxHP():(aMaxHP=i);}

public int QueryHP ()        { return aHP; }
public int SetHP (int i) {
  if (QueryLState() == LSTATE_GHOST /*|| i < 0*/) return aHP;
  GetHeart(HEART_HEAL);
  return aHP = i;
}
public int AddHP (int hps)  { return SetHP(hps + QueryHP()); }

public int QueryBaseRegHP() { return (QueryRace()=="troll")?(2*pRegHP):pRegHP; }
public int SetRegHP(int i)  { return pRegHP = i; }
public int AddRegHP(int i)  { return pRegHP += i; }

public int QueryRateHP()    { return aRateHP; }
public int SetRateHP(int i) { return SetRegHP(aRateHP = (i > 0 ? i : aRateHP));}

public int QueryRegHP() {
  int val;
  val = QueryBaseRegHP();
  if (QueryFood() < 0 || QueryDrink() < 0) val -= QueryRateHP();
  if (QueryAlcohol()) val += QueryRateAlcohol();
  switch (QueryStatus()) {
    case STATUS_SLEEPING: val *= 4; break;
    case STATUS_RESTING:  val *= 2; break;
    default:
  }
  return val;
}
//-----------------------------------------------------------------------
public int QueryMaxSP()       { return query_once_interactive(TO)?MAX_SP(QueryGuild()||GC_NINGUNO,QueryInt()):(aMaxSP||MAX_SP(QueryGuild()||GC_NINGUNO,QueryInt()));}
public int SetMaxSP (int i)   { return query_once_interactive(TO)?QueryMaxSP():(aMaxSP=i); }

public int QuerySP ()        { return aSP; }
public int SetSP (int i) {
  if (NETDEAD || QueryLState() == LSTATE_GHOST || i < 0) return aSP;
  GetHeart(HEART_HEAL);
  return aSP = i;
}
public int AddSP (int sps)   { return SetSP(sps + QuerySP()); }

public int QueryBaseRegSP()  { return (QueryRace()=="troll")?(pRegSP/2):pRegSP; }
public int SetRegSP(int i)   { return pRegSP = i; }
public int AddRegSP(int i)   { return pRegSP += i; }

public int QueryRateSP()     { return aRateSP; }
public int SetRateSP(int i)  { return SetRegSP(aRateSP = (i > 0 ? i : aRateSP));}

public int QueryRegSP() {
  int val;
  val = QueryBaseRegSP();
  if (QueryFood() < 0 || QueryDrink() < 0) val -= QueryRateSP();
  if (QueryAlcohol()) val += QueryRateAlcohol();
  switch (QueryStatus()) {
    case STATUS_SLEEPING: val *= 4; break;
    case STATUS_RESTING:  val *= 2; break;
    default:
  }
  return val;
}

public varargs int ChangeSP(int amount, int min) {
  int sp;

  if ((sp = QuerySP()) - min < amount) amount = sp-min;
  SetSP(sp -= amount);
  GetHeart(HEART_HEAL);
  return sp;
}

public int ReduceSP (int amount, int min) {
  int sp;

  if ((sp = QuerySP()) - min < amount)
    return 0;
  SetSP(sp -= amount);
  GetHeart(HEART_HEAL);
  return amount;
}

public int HealSP (int amount) {
  int maxsp;

  if (amount < 0)
    return 0;
  UseStat(A_INT, 0);
  amount = -amount;
  if (ChangeSP(&amount, 0) >= (maxsp = QueryMaxSP()))
    SetSP(maxsp);
  return -amount;
}

//----------------------------------------------------------------------------
// Fin Regeneracion
//----------------------------------------------------------------------------

public int QueryDisabled() { return QueryGhost()?0:QueryHP()<0; }
public int QueryEnabled()  { return !QueryDisabled(); }

public int QueryHealth() { return (QueryHP() * 100) / (QueryMaxHP()||1); }

public string HealthMsg(int health, int stunned, int paralyzed, int blind) {
  string str;
  string *efectos = ({});


  switch(health) {
  case  0..10: str = "moribund"+QueryGenderEndString(); break;
  case 11..20: str = "con heridas gravísimas"; break;
  case 21..50: str = "con heridas graves"; break;
  case 51..70: str = "herid"+QueryGenderEndString(); break;
  case 71..85: str = "con heridas leves"; break;
  case 86..95: str = "en buenas condiciones"; break;
  default:
    if (health < 0) str = "muert" + QueryGenderEndString();
    else str = "en perfectas condiciones";
  }
  if (stunned) {
      if (stunned > 10) efectos += ({"totalmente inconsciente"});
      else if (stunned > 5) efectos += ({"inconsciente"});
      else efectos += ({"aturdid"+QueryGenderEndString()});
  }
  if (paralyzed) efectos += ({"paralizad" + QueryGenderEndString()});
  if (blind) efectos += ({"cegad" + QueryGenderEndString()});
  return str + (sizeof(efectos) ? (health > 90 ? " pero " : " y ") + implode_list(efectos) : "");
}

public string QueryHealthMsg()
  { return HealthMsg(QueryHealth(), QueryStunned(), QueryParalyzed(), Query(P_BLIND)); }

/*--------------------------------------------------------------------------*/
/* Nyh comenta
amount es cuanto quieres quitarle
min es el minimo de vida al que le puedes dejar
Si min menor o igual a cero, no hay minimo

Nota: me he cargado kilos de codigo de esta función

xtras es para pasar mensajes al combat, solo pasa mensajes si le metes
un xtra distinto de 0 !!!, si xtras vale 0 los mensajes los digo
directamente
*/
  //nota del combat: el xtras es un array de arrays de 3 valores:
  // el primero es para el que pega (aqui es TP)
  // el segundo es para el que defiende (aqui es TO)
  // el tercero es para los demas del env
  // luego aqui debe valer ({ 0,str,0 })
public varargs int ReduceHP (int amount, int min, mixed xtras){
  int oldh, hp, newh;

  oldh = QueryHealth();
  hp = QueryHP();

  if ((min>0) && (hp - min < amount)) amount = hp-min;

  SetHP(hp -= amount);

  if (hp >= 0 && oldh / 10 != (newh = QueryHealth())/10 && TO) {
    string msg;
    msg = ((amount<0 && newh<95) ? "Continúas estando " : "Estás ")
            +HealthMsg(newh, QueryStunned(), QueryParalyzed(), Query(P_BLIND))+".\n";
    if (pointerp(xtras)) xtras += ({ ({ 0, msg, 0 }) });
    else TO->catch_msg(msg );
  }
  GetHeart(HEART_HEAL);
  return hp;
}

public int HealHP (int amount) {
  int maxhp, hp;

  if (amount < 0)  return 0;
  UseStat(A_CON, 0);
  hp=QueryHP();
  if (amount+hp>(maxhp=QueryMaxHP())) {
    amount=maxhp-hp;
    if (amount<0) amount=0;
  }

  amount = -amount;
  ReduceHP(&amount,0);
  /*
  if (ReduceHP(&amount, 0) >= (maxhp = QueryMaxHP()))
  {
    SetHP(maxhp);
  }*/
  return -amount;
}
/* Nyh comenta... cambio el uso del gentle
el gentle indica el porcentaje minimo de vida al que le puedes dejar
type es el tipo de daño que se le hace (para aplicar resistencias)
xtras es para pasar mensajes al combat, solo pasa mensajes si le metes
un xtra distinto de 0 !!!
*/
public varargs int DoDamage (int damage, int type, int gentle, mixed xtras) {
  int hp;


  if (QueryLState() == LSTATE_GHOST || damage < 0) return 0;

  gentle = (gentle>0)?(gentle*QueryMaxHP()/100):-1;
  UseStat(A_CON, 0);
  damage = (damage*(100-QueryResistance(type)))/100;
  //Nyh: comento la siguiente linea xq el unico catch_msg definido en el mud
  // no hace nada a no ser q sea MSG_HEAR o MSG_SEE
//  say(({MSG_DAMAGE, PO, damage }));

  if ((QueryHP()>-1) && ((hp=ReduceHP(&damage, gentle, &xtras))<0)) {
    SetKiller(TP); // Ojo, que TP puede ser TO
  }
  else if (damage > 0 && hp <= QueryWhimpy(1)) SetQuieroHuir(1);

  return damage;
}

//-----------------------------------------------------------------------

public mixed SetWhimpy (mixed v) {
  return aWhimpy = v;
}

public varargs mixed QueryWhimpy (int absolut) {
  return (absolut && stringp(aWhimpy))
          ? (QueryMaxHP() * to_int(aWhimpy)) / 100
          : aWhimpy;
}

public mixed SetCorpse(mixed c) { return aCorpse = c; }
public mixed QueryCorpse()      { return aCorpse; }

//-----------------------------------------------------------------------
public int SetKillXP (int i)      {
#ifdef DEBUG_MAX_XP
  write_file("/log/NEW_XP",sprintf("Llamada a %O->SetKillXP(%O)\n",TO,i));
  return 0;
#else
  return pKillXP = i;
#endif
}

// count es la media de nivel del grupo
// el maximo de saltos es MAX_LEVEL_DIF... la diferencia inferior no me importa
// Añado un minimo para la xp que da cada bicho... igual al nivel del bicho
// uso siempre el guildlevel q es el que vale, porque el otro en los jugatas
// es su nivel de jugador y no va bien
public varargs int QueryKillXP (int count, int calc) {
  int l, minxp;
  float xp;

  if (!count) count = QueryGuildLevel();
  l = QueryLevel()-count; //diferencia de niveles, positivo=muerto superior
  xp = FACTOR_EXP * count; //esto es lo q recibiria por matarle uno de su nivel
//  if (find_object("nyh")) dtell("nyh",sprintf("xpbase = %O\tl = %O\n",xp,l ));
  if (!QueryGuild() || QueryGuild()==GC_NINGUNO) /*l-= FACTOR_EXP_SIN_GREMIO;*/ xp*=FACTOR_EXP_SIN_GREMIO;
  if (l>MAX_LEVEL_DIF) l=MAX_LEVEL_DIF;
  if (l>0) { do { xp = xp * FACTOR_NIV; } while(--l); }
  if (l<0) { do { xp = xp / FACTOR_NIV; } while(++l); }

  if (xp < (minxp=QueryLevel())) return minxp;
  else return to_int(xp*2);  // probándolo en endor a ver como queda
  //else return to_int(xp+0.5); //el +0.5 es para el redondeo (simauria)
}

//-----------------------------------------------------------------------

public void Heal(int amount)
{
  HealHP(amount);
  HealSP(amount);
}

/*--------------------------------------------------------------------------*/

  // May be overloaded to something more useful.
/** public int another_life()
 * Esta función se llama cuando un living muere para ver que ocurre en
 * su siguiente vida.
 * Si devuelve 1 es que el living sigue funcionando, ya sea como fantasma o
 * como lo que sea.
 * Si devuelve 0 es que el living la ha palmado y se hara un REMOVE a este
 * objeto! (asi que cuidado con los players)
 */
protected int another_life() {
    return 0;
}


//los pet no reciben xp ni cuentan para el calculo...
private int GanaPX(object ob)   { return !(ob->Query(P_IS_PET)); }

  // May be overloaded to something more useful.
/** public varargs void Death(object *killers)
 * Killers es un array con los objetos q me han colaborado en matarme
 * killers[0] es quien dió el golpe final.
 *  Esta función se llama cuando el este living muere definitivamente y
 *  desaparece dejando tras de si su cadaver con sus pertenencias.
 * Informo a los inform_death, y chekeo el dead_ob.
 *  Aqui damos experiencia a los asesinos, les modificamos el alineamiento,
 *  enviamos el mensaje de que he palmado, dejo el cadaver.
 */
protected varargs void Death(object *killers) {
    int xp = 0, i;
    object *follow;

//    say(({ MSG_DIE, ob })); // MSG_DIE no existe

    if (!sizeof(killers) || killers[0] == TO) { // Nadie me ha matado, he sido yo solito
        // de momento aqui no hago nada, ni siquiera chistes sobre el
        // suicidio
    }
    else {
        i = sizeof(killers);
        killers->UpdateAlign(QueryAlign()/i);
        killers->RemoveEnemy(TO);
        // Mando los mensajes de muerte
        for ( ; i-- ; ) {
            if (i) tell_object(killers[i], "Colaboraste en la muerte de "+QueryName()+".\n");
            else   tell_object(killers[i], "Has matado a "+QueryName()+".\n");
        }
        // Reparto experiencia
        if (i = sizeof(killers = filter(killers, SF(GanaPX)))) {
            foreach (object en:killers) {
                tell_object(en, "Recibes "
                    + (en->AddXP(QueryKillXP(en->QueryGuildLevel())/i))
                    + " puntos de experiencia.\n");
            }
        }
    }
    //[Uzi] eliminar seguidores y seguidos
    if (TO->Query(P_IS_FOLLOWER)) {
        mixed who = TO->Query(P_IS_FOLLOWING);
        if (objectp(who)) {
            TO->Query(P_IS_FOLLOWING)->RemoveFollower(TO);
        }
    }
    follow = TO->Query(P_FOLLOWERS);
    i = sizeof(follow || ({}));
    if (i>0) while (i--) TO->RemoveFollower(follow[i]);
    // Fin eliminar seguidores y seguidos

    inform_death->inform_death(); // Llamo a la función inform_death de los inform_deads
    if (dead_ob  && call_other(dead_ob, "player_died")) return; // Override normal die.

    if (!another_life()) {
        LeaveCorpse();
        remove();
    }
}

/** public varargs void Die(mixed silent)
 * Esta función se llama cuando este living se muere, aqui pierde todas las
 * propiedades extrañas que tuviese, modificadores y demas.
 * Aqui tb se maneja el hbstat
 */
public varargs void Die(mixed silent) {
    object ob, killer;
    int i;
    object *enemies;

    //  if (find_object("nyh")) dtell("nyh",sprintf("%O->Die\n",TO->QueryName()));
    while (remove_call_out("Die") != -1); //borra cualquier callout de mas

    /* HBSTAT */
    TO->hbstat_idied();
    if (!silent)
    {
      play_sound(environment(), SND_SUCESOS("muerte"));
      say (capitalize(QueryName()) + " ha muerto.\n");
    }
    killer = QueryKiller() || TP;
    if (killer->Query(P_IS_PET)) killer = killer->QueryOwner();

    if (killer) {
      if (ob=killer->QueryLeader()) enemies = filter(ob->QueryTeam(),SF(present));
      else enemies = filter( (killer->QueryTeam())||({ killer }), SF(present));
    }
    else enemies = QueryEnemies();

    if (pointerp(enemies)) { // Me aseguro q killer es el primero
        enemies = ({ killer }) + (enemies - ({ killer }));
    }
    else enemies = ({ killer });

    enemies -= ({ 0 });
    enemies->hbstat_kill(TO); /* HBSTAT */

    StopAllHunting();

    SetTmpStr(0);
    SetTmpDex(0);
    SetTmpCon(0);
    SetTmpInt(0);
    SetStrBonus(0);
    SetDexBonus(0);
    SetConBonus(0);
    SetIntBonus(0);

    SetStunned(0);
    SetTiredMagic(0);

    Death(enemies);
}

//---------------------------------------------------------------------------
// Auxiliary functions to handle P_RESISTANCE
public mapping QueryResistanceMap() { return copy(aResistances||([])); }

/* Hay 2 resistencias genericas:
TD_INTR resiste todo lo fisico
TM_INTR resiste todo lo magico
y luego los TD_XXX y TM_XXX particulares de cada tipo de daño... bien, esto
rula asi: tu metes un tipo de daño y yo devuelvo el mayor de TX_INTR y TX_XXX
lo hago asin para poder poner resistencias genericas a físico y/o mágico */
/*si type es un int es el tipo de daño, en caso contrario
es un nombre de un hechizo...
*/
public int QueryResistance(mixed type) {
  aResistances = aResistances||([]);
  if (!intp(type)) return aResistances[type];
  if (type<=TD_CONV) { //daño físico
    if ((aResistances[TD_INTR])<(aResistances[type])) return aResistances[type];
    else return aResistances[TD_INTR];
  }
  else { //daño mágico
    if ((aResistances[TM_INTR])<(aResistances[type])) return aResistances[type];
    else return aResistances[TM_INTR];
  }
//  return (aResistances||([]))[type]; //antiguo
}

public int AddResistance(mixed type, int value) {
//if (find_object("nyh")) dtell("nyh",sprintf("%O->AddResistance(%i, %i)\n",TO->QueryName(),type,value));
  //if (!VALID_DAMAGE_TYPE(type)) return 0;
  //lo comento por resistencias especificas aunq todavia no las he inventado :-p
  if (!aResistances) aResistances = ([ ]);
  if (!(aResistances[type]+=value)) m_delete(aResistances,type);
  return aResistances[type];
}

public int SetResistance(int type, int value){
//if (find_object("nyh")) dtell("nyh",sprintf("%O->SetResistance(%i, %i)\n",TO->QueryName(),type,value));
//  if (!VALID_DAMAGE_TYPE(type)) return 0;
  if (!aResistances) aResistances = ([ ]);
  if (!value) m_delete(aResistances,type);
  return aResistances[type]=value;
}

public mapping SetResistanceMap(mapping m){
  int i, *types;
//if (find_object("nyh")) dtell("nyh",sprintf("%O->SetResistanceMap(%O)\n",TO->QueryName(),m));
  aResistances = ([ ]);
  if (mappingp(m)) {
    types = m_indices(m);
    for (i=sizeof(types); i--; )
    SetResistance(types[i], m[types[i]]);
  }
  return QueryResistanceMap();
}

//Compatibilidad:
public int Resistance(mixed type) { return QueryResistance(type); }

//esto se llama desde el racemaster
SetResistances(res)     { return SetResistanceMap(res);}

/****************************************************************************/

/* SIMAURIA '/std/npc/body.c'
   ==========================
   [g] Guybrush@simauria
   [w] Woo@simauria
   [a] Angor@Simauria
   [t] Theuzifan

   12-06-97 [g] Traduce body.c enterito. (pero es mu corto)
   26-12-97 [w] Puesto un lower_case() en la linea 215 ya que aparecia
                'A Un enano' por ejemplo y no quedaba del todo bien.
   20-07-98 [a] Se hereda la raza del PNJ en la nueva implementacion
                y se le pasa a corpse al morir
   13/11/98 [g] Cambia un lower_case por un capitalize, para que el
                nombre del player salga con mayuscula la primera.
   15-11-98 [a] Comenta la funcion de debug que se activaba (?) al entrar
                en los gremios (QueryVerMiembros())
   01-12-98 [t] En la linea 209, ahora no peta si no hay QueryName
   04-02-99 [t] Castellanizo
   11-03-99 [t] Añado el gender al corpse...
   13-03-99 [t] Quito TP en la macro 'AO'... nada más entrar
        es posible que no exista el TP, y al decir
        una frase del alcohol, ha soltao un pete desactivando
        el heart_beat()
   05-05-99 [w] Cambiado un capitalize por el cual aparecian cosas como
                'A Una orca le entra hipo'
   08-06-00 [t] Cambio los AddXXX para la comida, bebida... Si no puede
           añadirte lo que quieres, te lo pone al máximo y te devuelve
           lo que te ha añadido.
   03-03-03 [t] Añadido el estado al prompt.
--------------------------------------------------------------------------------
*/


public int QueryDegAlcohol() { return aDegAlcohol; }
public int SetDegAlcohol(int i) { return aDegAlcohol = i; }

public int QueryMaxAlcohol() { return aMaxAlcohol; }
public int SetMaxAlcohol(int i) { GetHeart(HEART_HEAL); return aMaxAlcohol = i; }

public int QueryAlcohol() { return aAlcohol; }
public int SetAlcohol(int i) {
  int max;
  max = QueryMaxAlcohol();
  GetHeart(HEART_HEAL);
  return aAlcohol = i > max ? max : i;
}

public int QueryRateAlcohol() { return aRateAlcohol; }
public int SetRateAlcohol(int i) { return aRateAlcohol = i; }

public int QueryDegDrink() { return aDegDrink; }
public int SetDegDrink(int i) { return aDegDrink = i; }

public int QueryMaxDrink() { return aMaxDrink; }
public int SetMaxDrink(int i) { GetHeart(HEART_HEAL); return aMaxDrink = i; }

public int QueryDrink() { return aDrink; }
public int SetDrink(int i) {
  int max;
  max = QueryMaxDrink();
  GetHeart(HEART_HEAL);
  return aDrink = i > max ? max : i;
}

public int QueryDegFood() { return aDegFood; }
public int SetDegFood(int i) { return aDegFood = i; }

public int QueryMaxFood() { return aMaxFood; }
public int SetMaxFood(int i) { GetHeart(HEART_HEAL); return aMaxFood = i; }

public int QueryFood() { return aFood; }
public int SetFood(int i) {
  int max;
  max = QueryMaxFood();
  GetHeart(HEART_HEAL);
  return aFood = i > max ? max : i;
}

//---------------------------------------------------------------------------

public int AddAlcohol(int strength)
{
  int alc;
  if (strength>0 && strength+QueryAlcohol()>QueryMaxAlcohol())
    strength=QueryMaxAlcohol()-QueryAlcohol();

  SetAlcohol(QueryAlcohol()+strength);


/*
  if ((alc = QueryAlcohol()) > QueryMaxAlcohol() && strength > 0)
    return 0;
  alc += strength;
  SetAlcohol(alc >= 0 ? alc : 0);

  return QueryAlcohol() - (alc-strength);
*/
  return strength;
}

public int AddDrink(int strength)
{
  if (strength>0 && strength+QueryDrink()>QueryMaxDrink())
    strength=QueryMaxDrink()-QueryDrink();

  SetDrink(QueryDrink()+strength);
  return strength;
}

public int AddFood(int strength)
{
  if (strength>0 && strength+QueryFood()>QueryMaxFood())
    strength=QueryMaxFood()-QueryFood();

  SetFood(QueryFood()+strength);
  return strength;
}

//---------------------------------------------------------------------------
public DoDigest() {
  int val;
  if (IS_LEARNER(TO) || LSTATE_GHOST == QueryLState()) return;

  // Reduce Drink.
  val = QueryDrink() - 1;
  accDrink += QueryDegDrink();
  if (accDrink > 100) {
    accDrink -= 100;
    SetDrink(val);
    if (val <= -500) {
      ReduceHP(1, 10);
      write("Estás deshidratad"+AO+".\n");
    }
    else if ( val <= 10 && random(100) < 10)  write("Tienes sed.\n");
  }

  // Reduce Food.
  val = QueryFood() - 1;
  accFood += QueryDegFood();
  if (accFood > 100) {
    accFood -= 100;
    SetFood(val);
    if (val <= -500) {
      ReduceHP(1, 10);
      write("Estás muert"+AO+" de hambre.\n");
    }
    else if ( val <= 10 && random(100) < 10) write("Tienes hambre.\n");
  }
  if (TO && interactive(TO)) GetHeart(HEART_HEAL);
}

//---------------------------------------------------------------------------

//devuelve 1 si debe seguir con el hb
private int HBRegSP() {
  int val, max, rate;

  val = QuerySP();
  max = QueryMaxSP();
  rate = QueryRegSP();

  if (rate < 0 || (val < max) && ((accSP+=rate)/10)) {
    val += accSP/10;
    accSP %= 10;
    if (accSP >= 0 && val >= max) { val=max; accSP=0; }
    SetSP(val);
  }
  if (val != max) return 1;
  return 0;
}

//devuelve 1 si debe seguir con el hb
private int HBRegTP() {
  int val, max, rate;

  val = QueryTP();
  max = QueryMaxTP();
  rate = QueryRegTP();

  if (rate < 0 || (val < max) && ((accTP+=rate)/4)) {
    val += accTP/4;
    accTP %= 4;
    if (accTP >= 0 && val >= max) { val=max; accTP=0; }
    SetTP(val);
  }
  if (val != max) return 1;
  return 0;
}

private int HBRegAlc() {
  if (LSTATE_GHOST==QueryLState()) return 1;
  else {
    int val, max, rate, i;
    string nombre;

    val = QueryAlcohol();
    max = QueryMaxAlcohol();
    rate = QueryDegAlcohol();
    nombre = QueryName()||"";
    if (val && (i = random(100)) < 4) {
      write(({ "Haces un gracioso sonido de hipo.\n","Te tambaleas ebrio.\n",
      "Estás tremendamente borrach"+AO+".\n","Lanzas un eructo brutal.\n","Sueltas una destemplada carcajada etílica.\n"})[i]);
      say(  ({ nombre+" hace un gracioso sonido de hipo.\n",    capitalize(nombre)+" se tambalea estúpidamente.\n",
                  capitalize(nombre)+" está notablemente etílic"+AO+".\n",capitalize(nombre)+" se ríe absurdamente sin ningún motivo.\n",
                  capitalize(nombre)+" eructa desagradablemente.\n"})[i]);
    }
    // Degenerate alcohol.
    if ((val>0) && ((accAlc+=rate)/100)) {
      val -= accAlc/100;
      accAlc %= 100;
      if (accAlc>=0 && val<=0) { val=0; accAlc=0; }
      if (!SetAlcohol(val)) write("Notas que desaparecen los últimos efectos del alcohol.\n");
    }
    if (TO && interactive(TO)) DoDigest();
    if (val != 0) return 1;
  }
  return 0;
}

public void heart_beat() {
  int val, alc;
  int rate, max;
  int hp, reghp, health;
  int flag = 0, load;

  //añado esta linea pa evitar gastar cpu sin necesidad
  if (!CheckHeart(HEART_HEAL)) return;

  // Si está muerto no se cura
  if (QueryLState() == LSTATE_GHOST) return;

  hp = QueryHP();
  reghp = QueryRegHP();
  health = QueryHealth();

//if (find_object("nyh")) dtell("nyh",sprintf("%O->base_heart, hp= %i, whimpy = %O\n",TO,hp,QueryWhimpy(1)));

  if (QueryStunned())    SetStunned(QueryStunned()-1);
  if (QueryTiredMagic()) SetTiredMagic(QueryTiredMagic()-1);

  if (!(load=CheckHeart(HEART_COMBAT))) {
    flag += HBRegSP();
    flag += HBRegTP();
  }
  flag += HBRegAlc(); //a esta no le importa el combate

  max = QueryMaxHP();
  // was: if (reghp < 0 || (val < max && !load)) {
  // but this kept the heart beat unnecessarily on.
  if (reghp < 0 || (hp < max && !load)) {
    accHP += reghp;
    if (accHP/10) {
      hp += accHP/10;
      accHP %= 10;
      if (accHP >= 0 && hp >= max) hp = max, accHP = 0;
      else if (hp != max) flag = 1;
      SetHP(hp);
    }
    else flag = 1;
  }

  if (hp < 0) Die();
  else {
    rate = QueryHealth();
    if (health >= rate+20 || health <= rate-10 || !(QueryStunned()+1 % 4))
      TO->catch_msg(((accHP > 0 && rate < 95) ? "Continuas estando "
                         : "Estas ")+HealthMsg(rate, QueryStunned(), QueryParalyzed(), Query(P_BLIND))+".\n"
                 );
  }

  if ( (QueryQuieroHuir() || (hp<=QueryWhimpy(1))) ) {
    if (sizeof(QueryEnemies()) && QueryEnabled() ) Whimpy(WHIMPY_HB);
    else SetQuieroHuir(0);
  }

  if (   !flag && !load && !val
      && !QueryStunned() && !QueryTiredMagic() && !QueryParalyzed() ) {
    DropHeart(HEART_HEAL);
  }
}

//---------------------------------------------------------------------------

public void create() {
  seteuid(getuid());
  SetRateHP(HP_RATE);
  SetRateSP(SP_RATE);
  SetRateTP(TP_RATE);
  SetCorpse("/std/corpse");
  SetRateAlcohol(ALCOHOL_RATE);
  SetDegAlcohol(ALCOHOL_DEG);
  SetDegDrink(DRINK_DEG);
  SetDegFood(FOOD_DEG);
  SetKiller(0);
  SetStatusNormal();
}

/*
--------------------------------------------------------------------------------
Funciones relacionadas con el manejo de los miembros
--------------------------------------------------------------------------------
- object LeaveCorpse
- void   SetDesmembrableEn(string *lista);
- string *QueryDesmembrableEn();
- void   QueryVerMiembros();
*/

private string *ListaMiembros;

/* Para ver la lista de miembros por pantalla */

/* [a] desconectada por que se pegaba (?) con los gremios
//para debug
void QueryVerMiembros(){
  int n,i;
  printf("Lista de miembros del pnj:\n");
  n=sizeof(ListaMiembros);
  printf("Numero de miembros:"+(string)n+"\n");
  if (n!=0) for(i=0;i<n;i++) printf("["+(string)i+"] "+ListaMiembros[i]+"\n");
}*/

void SetDesmembrableEn(string *lista){
     ListaMiembros=lista;
     //QueryVerMiembros();
     }

string *QueryDesmembrableEn(){return ListaMiembros;}

public object LeaveCorpse() {
  mixed fcp;
  object cp, *obs;
  int i;

  seteuid(getuid());

  if (QueryLState() == LSTATE_GHOST) {
    // Si no tenemos cuerpo no podemos dejarlo
    return 0;
  }

  fcp = QueryAttr(A_CORPSE);

  if (!stringp(fcp) || catch(cp = clone_object(fcp))) return 0;

  //[a] El cadaver hereda los miembros (que le queden) del pnj
  cp->SetDesmembrableEn(ListaMiembros);

  cp->SetMaxIntWeight(QueryMaxIntWeight());
  cp->SetWeight(QueryWeight(1)); //El 1 es para que devuelva solo el del cuerpo
  cp->SetRace(QueryRace());
  cp->Set(P_IDS, Query(P_IDS));
  cp->Set(P_ADS, Query(P_ADS));
  cp->SetName(QueryName());
  cp->Set(P_GENDER, Query(P_GENDER));
  cp->SetLevel(QueryLevel());
  cp->move(environment());
  obs = all_inventory(TO);
  for ( i=sizeof(obs); i-- ; ) {
    if (    !obs[i]->QueryMoneyObject() &&  obs[i]->Query(P_AUTOOBJECT)) continue;
    obs[i]->move(cp, M_NOCHECK);
  }
  cp->DoDecay(1);

  SetLState(LSTATE_GHOST); // He dejado el cuerpo, ahora soy fantasma.

  return cp;
}

/****************************************************************************/
// Salvaciones

public int QuerySaveBonusType(int type) {
    int ts = 0;
    mapping tsmap;

    if (!type) return 0;

    if (mappingp(tsmap = TS_MAP[QueryGuild()]))
    {
      ts += tsmap[type];
    }

    switch (type) {
      case SAVE_TYPE_FORTITUDE: ts += QueryConModifier(); break;
      case SAVE_TYPE_REFLEX:    ts += QueryDexModifier(); break;
      case SAVE_TYPE_WILL:      ts += QueryIntModifier(); break;
    }

    ts += QueryGuildLevel()/10;

    return ts;
}

public int QueryFortitude() {
    return QuerySaveBonusType(SAVE_TYPE_FORTITUDE);
}
public int QueryReflex() {
    return QuerySaveBonusType(SAVE_TYPE_REFLEX);
}
public int QueryWill() {
    return QuerySaveBonusType(SAVE_TYPE_WILL);
}
public mapping QueryTS() {
    return ([
              SAVE_TYPE_FORTITUDE: QueryFortitude(),
	            SAVE_TYPE_REFLEX:    QueryReflex(),
			        SAVE_TYPE_WILL:      QueryWill(),
			       ]);
}
/****************************************************************************/







