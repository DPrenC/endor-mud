/* ENDOR-MUD/std/guild/stats.c
   ===========================
   [r] Thragor
   [t] Theuzifan

   10-02-95 [r] Creacion.
   17-04-96 [r] Cambia la función de calculo de los stats.
   07-05-96 [r] Cambia la función de calculo de AdvanceCost.
   30-07-98 [t] Elimina lo concerniente a los skills. La información de estos
                va en el player.c
   15-10-98 [t] Traduccion.
   04-02-99 [t] cristianizado
   27-11-99 [t] Cambiado XXXLevel por XXXGuildLevel
   02-12-99 [t] Avanzar niveles de Stat sólo quitan XPs de gremio...
   23-02-00 [w] Pus ahora pone Des en vez de Dex y Fza en vez de Str.
   28-02-00 [n] Cambiada la comprobación en CalcMinStat de si eres JAN o no.
                Vamos, que he cambiado un 20 por un 30. Si peta, la culpa es
                de Uzi.
   28-02-00 [n] Cambiada la comprobación en CalcMinStat de si eres JAN o no.
                Vamos, que he cambiado un 20 por un 30. Si peta, la culpa es
                de Uzi. (Lo repito a petición de Uzi).
   01-04-00 [w] Ale, ahora ya pueden subir todos los stats perfectamente,
                faltaba una comprobación por la cual el stat que te impedia
                subir si estaba a 'imposible' no te dejaba... Creo que no
                tiene porque tener efectos secundarios de todas formas lo
                modificado está en la linea 172 (aprox).
   12-03-03 [t] Se usan, en la medida de lo posible, los TrueStats en vez
   		de los stats, que pueden ser modificados con bonuses.
   29-05-03 [t] Arreglado un fallo de overflow en el computo de niveles si
   		el nivel era demasiado alto.
*/

#include <guild.h>
#include <races.h>     // RD_STAT
#include <config.h>    // RACEMASTER, NOTIFY_
#include <stats.h>

#define T(x) "True"+x

#ifndef STATS
#define STATS ({P_CON,P_STR, P_DEX, P_INT, "Cha", P_WIS})//"TrueCon","TrueStr","TrueDex","TrueInt"})
#endif

inherit NMB;

private static mapping Pminstats,    // e. g. ([P_CON:1,P_STR:3,P_DEX:5,P_INT:1])
                       Pmaxstats,    // see minstats
                       Pmaxhlpstats; // max. for HLPs

public varargs mapping QueryMaxStats(object pl); //forward
public varargs mapping QueryMaxHLPStats(object pl); //forward
public varargs int QueryMaxStat(string stat,object pl); //forward
public varargs int QueryMaxHLPStat(string stat,object pl); //forward

/*
* Prototypes from /std/guild/member.c
*/

/*
** Stat related help-functions
** ===========================
*/
// Return the modification from the Racefile, so we may
// check this for the guild, too.
protected int get_race_modification(object pl, string stat) {
  return (RACEMASTER->RaceObject(pl->QueryRace(), pl))->QueryStatBonus(stat);
}

// How much XP may the player spend on Stats
protected int CalcFreeXP(object pl) {
  if (pl->QueryGuildLevel()<0) pl->SetGuildLevel(0);
  return pl->QueryGuildXP()-level2xp(pl->QueryGuildLevel());
}

// return the amount of xp the player <pl> has to spend to advance
// the stat <stat>, where stat is P_CON, P_STR, P_DEX or P_INT
// the amount is 1/3 * (xp for level (==stat+1) - xp for level (==stat))
// then it is modified by the race-stats and the MaxStats of the
// guild. So an intelligent race in a spellcaster-guild has to pay
// very few XP for advancing Int, but a weak race in a cleric-guild
// has to pay very much XP for advancing Str.

// [Nyh]
// Coge lo q tienes de base en el stat sin en mod de gremio.
// Calcula cuanto te costaria subir de ese nivel al superior.
// Lo divide por... 5 en estos momentos.
// Le aplica un % en funcion de los maximos del gremio.
// Lo redondea y lo devuelve.
public int CalcAdvanceCosts(object pl,string stat) {
  int num = 0, percent = 200;

  if (pl->Query(T(stat))<1) pl->Set(stat,1);

  if ((num=pl->Query(T(stat))-get_race_modification(pl,stat))<1) num = 1;
  num = (level2xp(num+1)-level2xp(num))/5;

  if (pl->QueryGuildLevel()<30) percent -= to_int((QueryMaxStat(stat)*100)/a_avarage(m_values(QueryMaxStats())));
  else percent -= to_int((QueryMaxHLPStat(stat)*100)/a_avarage(m_values(QueryMaxHLPStats())));

  num = (num*percent/100);

  return round(num);
}

public string CalcMinStat(object pl)
// Calculate the minimal stat of a player and return it (P_CON, ...)
// this is used to check, whether the player may advance a stat or
// not (e. g. a race with Str + 4 might advance Strength to the
// MaxStat for Strength of the Guild plus 4.
{
  string res;
  closure maxfun;
  int i,rmod,smod;
  maxfun = pl->QueryGuildLevel()<30?symbol_function("QueryMaxStat",TO)
                              :symbol_function("QueryMaxHLPStat",TO);
  for (i=0;i<sizeof(STATS);i++)
    {
      smod = round(get_race_modification(pl,STATS[i])/2.0);
      // the modification for the currently checked stat
      if (res) rmod = round(get_race_modification(pl,res)/2.0);
      // if we have alread a minimal stat, get the modification
      // which belongs to this stat
      if (   !res // if no minimum exists up to now
          || (   pl->Query(res)-rmod>pl->Query(T(STATS[i]))-smod
              && !(pl->Query(T(STATS[i]))>=apply(maxfun,T(STATS[i]),pl))
             )
         )
       res = STATS[i];
     }
  return res;
}

protected int check_level2stats(object pl,int mod)
// Calculate if <pl> may advance the stats further
// depending on the avarage stats (race-modifications
// will be ignored) compared to the level of the player
{
  int i;
  float *res,val;

  i = sizeof(STATS);
  res = ({});
  while(i--)
    {
      val = pl->Query(T(STATS[i]))-get_race_modification(pl,STATS[i])/2.0;
      if (val<1.0) val = 1.0;
      res+=({val});
    }
  return round(a_avarage(res))<pl->QueryGuildLevel()+mod;
}

public int CanAdvance(object pl,string stat)
// Check if the player can advance the current stat (for one point)
// The results are defined in <guild.h>:
// ADV_NOT_XP, ADV_NOT_LEVEL, ADV_OTHER_FIRST,
// ADV_TOO_HIGH, ADV_OK
{
//  int modify;
  string minstat,maxstat,c;
  closure maxfun;

//  modify = get_race_modification(pl,stat);
  minstat = CalcMinStat(pl);
  maxfun = pl->QueryGuildLevel()<30?symbol_function("QueryMaxStat",TO)
                              :symbol_function("QueryMaxHLPStat",TO);
  if (pl->Query(T(stat))>=apply(maxfun,stat,pl))
    return notify_fail("Ya no puedes avanzar más.\n",
		       NOTIFY_NOT_VALID),ADV_TOO_HIGH;
  if (!check_level2stats(pl,2))
    return notify_fail("No tienes suficiente nivel.\n",
		       NOTIFY_NOT_VALID),ADV_NOT_LEVEL;
  if ((pl->Query(T(   stat)) - round(get_race_modification(pl,   stat)/2.0))-
      (pl->Query(T(minstat)) - round(get_race_modification(pl,minstat)/2.0))>3)
    // is the difference between the minimal stat and the stat you
    // want to advance too high?
    {
/* [woo] Comprobacion añadida...
         Lo que hace es que mira si el stat que te impide subir está
         al máximo, y si es así te deja subir sin problemas */
      if ((pl->Query(minstat)>=apply(maxfun,minstat,pl))) {
//        if (find_object("nyh")) dtell("nyh",sprintf("%O ->Query(%O) = %O, max = %O\tADV_OK\n",pl,minstat,pl->Query(minstat),apply(maxfun,minstat,pl)));
      	return ADV_OK;
      }
      else {
/* [woo] Hasta aquí */
       notify_fail("No tienes suficiente "+
        (["Int":"inteligencia",
          "Dex":"destreza",
          "Str":"fuerza",
          "Con":"constitución",
            "Cha":"carisma",
                "Wis":"sabiduría"])[minstat]+".\n",
        NOTIFY_NOT_VALID);
      return ADV_OTHER_FIRST;
      }
    }
  if (CalcFreeXP(pl)<CalcAdvanceCosts(pl,stat))
    return notify_fail("No tienes suficientes XPs para avanzar la "+stat+".\n",
		       NOTIFY_NOT_VALID),ADV_NOT_XP;
  return ADV_OK;
}

public int AdvanceStat(object pl,string stat)
// Try to advance the stat of a player and give the corrosponding
// message (ok or notify_fail ;-) )
{
  if (CanAdvance(pl,stat)!=ADV_OK) return 0;
  TP->AddGuildXP(-CalcAdvanceCosts(pl,stat));
  TP->Set(stat,TP->Query(T(stat))+1);
  write("De acuerdo.\n");
  return 1;
}

protected int comment_cost(object pl,string stat,string comment)
// needed to show why you can't advance a certain stat (in the
// AdvanceCostList
// results: 0  possible
//          1  possible, but not now
//         -1  not possible (maximum reached)
{
  int result;
  result = CanAdvance(pl,stat);
  comment = "   ";
  if (result==ADV_OK) return 0;
  if (result==ADV_TOO_HIGH)
    {
      comment = " Al máximo";
      return -1;
    }
  if (result==ADV_NOT_XP) comment = "(XP insuficientes)";
  else if (result==ADV_NOT_LEVEL) comment = "(Necesitas más nivel)";
  else if (result==ADV_OTHER_FIRST) comment = "(Desequilibrado)";
  return 1;
}

public string AdvanceCostList(object pl)
// return a printable list of Stat-Advancecosts
{
  string c,res,cost,*stats;
  int i;

  res = "";
  stats = sort_array(STATS,SF(>));
  for (i=0;i<sizeof(stats);i++)
    {
      if (comment_cost(pl,stats[i],&c)==-1)
	{
	  cost = "Al máximo";
	  c = "";
	}
      else
	cost = to_string(CalcAdvanceCosts(pl,stats[i]));
      res+=sprintf(" %-12s (%02d): %'.'10s %s\n",(["Int":"Inteligencia","Dex":"Destreza","Str":"Fuerza","Con":"Constitución","Cha":"Carisma","Wis":"Sabiduría"])[stats[i]],pl->Query(T(stats[i])),
		   " "+cost,c);
    }
  return res;
}

public void PrintAdvanceCosts(object pl)
// the result of the 'cost'-command
// it will show you:
// 1. The QP and XP you have
// 2. The 'free' XP (not needed for the current level)
// 3. The list of stats and how much it costs to advance them
// 4. The level up to which you might advance
// 5. The QP you need to advance
// 6. The XP you need to advance
// 7. The next guildquest you need to advance
{
  int rlvl,lvl,qp,xp,h;
  string res;
  if (!pl) return;
  rlvl = ((rlvl = pl->QueryGuildRealLevel())>(h = TO->GuildQuestLevel(pl)))?h:rlvl;
  if ((lvl = pl->QueryGuildLevel())<0) pl->SetGuildLevel(0);
  qp = QUESTMASTER->QueryQuestPoints(pl);
  xp = pl->QueryGuildXP();
  res = sprintf("Nivel actual: %d.\n"
		"Puntos actuales: %d/%d puntos de quest y %d XP.\n",lvl,qp,
		QUESTMASTER->QueryTotalQuestPoints(),xp);
  if ((h = xp-level2xp(lvl))>0)
    res+=sprintf("Te sobran %d XPs para usarlos subiendo niveles.\n",h);
  res+=AdvanceCostList(pl);
  if (lvl<rlvl)
    res+=sprintf("Puedes avanzar hasta el nivel %d.\n",rlvl);
  else
  {
    if ((h=(int)QUESTMASTER->QPointLevel(lvl+1))>qp)
      res += sprintf("Te faltan %d (%d) Puntos de Quest más para subir de nivel.\n",h-qp,h);
    if ((h = level2xp(lvl+1)-xp)>0)
      res += sprintf("Te faltan %d XPs más para subir de nivel.\n",h);
    if ((h = TO->GuildQuestLevel(pl))<lvl+1 && h+1 < sizeof(TO->GuildQuests()))
      res += sprintf("Todavía tienes pendiente el guildquest \"%s\".\n",TO->GuildQuests()[h+1]);
  }
  tell_object(pl,res+"\n");
                 /*
                 "(x) ... no tienes suficientes XPs\n"
                 "(n) ... no tienes suficiente nivel para avanzar\n"
                 "(o) ... hay otros stats demasiado bajos para avanzar éste\n");
                 */
}

protected void CorrectStats(object pl)
// Called when joining the guild. If the stats of the joining
// player are too high they are set to the maximum possible.
{
  int i,m;
  mixed attr;

  for (i=0;i<sizeof(STATS);i++) {
    m = TO->QueryMaxHLPStat(STATS[i],pl);
    if (pl->Query(T(STATS[i])) > m)
      pl->Set(STATS[i],m);
  }
}

/*
* ----------------------------------------------------------------------
* Queries, Settings, Adds
* ----------------------------------------------------------------------
*/

/*
* Stats
* =====
*/

public mapping SetMinStats(mapping stats)
// Set the minimum stats you need to enter this guild, e. g.
// ([P_CON:1,P_DEX:1,P_STR:1,P_INT:1])
// Purpose is to make it impossible for Newbies to enter a
// guild (except adventurers)
{
  if (   !mappingp(stats)
      || min(m_values(stats))<1
      || sizeof(stats)!=sizeof(STATS)
      || sizeof(m_values(stats)-STATS)
      || sizeof(STATS-m_values(stats))
     )
    return Pminstats||G_MINSTATS;
  return Pminstats = stats;
}

public varargs mapping QueryMinStats(object pl)
{
  string *idx;
  int i;
  mapping st;
  st = (Pminstats||G_MINSTATS)+([]);
  if (!pl) return st;
  i = sizeof(idx = m_indices(st));
  while(i--)
    st[idx[i]]=max(({1,round(get_race_modification(pl,idx[i])/3.0)+st[idx[i]]}));
  return st;
}

public varargs int QueryMinStat(string stat,object pl)
{
  return QueryMinStats(pl)[stat];
}

public mapping AddMinStat(string stat,int value)
// Add a minimum stat, e. g. AddMinStat(P_DEX,3)
{
  if ((value<1)
      ||(member(STATS,stat)==-1)
     )
    return Pminstats||G_MINSTATS;
  if (!Pminstats) Pminstats = G_MINSTATS;
  Pminstats[stat]=value;
  return Pminstats;
}

public mapping SetMaxStats(mapping stats)
// Set the maximum stats you might get when
// you are Low-Level-Player;
// the following functions just work like those
// for the minstats
{
  if (   !mappingp(stats)
      || min(m_values(stats))<1
      || sizeof(stats)!=sizeof(STATS)
      || sizeof(m_indices(stats)-STATS)
      || sizeof(STATS-m_indices(stats))
     )
    return Pmaxstats||G_MAXSTATS;
  return Pmaxstats = stats;
}

public mapping SetModMaxStats(mapping stats)
// Set the maximum stats you might get when
// you are Low-Level-Player;
// the following functions just work like those
// for the minstats
{
  if (   !mappingp(stats)
      || sizeof(stats)!=sizeof(STATS)
      || sizeof(m_indices(stats)-STATS)
      || sizeof(STATS-m_indices(stats))
     )
    return Pmaxstats||G_MAXSTATS;
  foreach(string stat:STATS) stats[stat]+=MAX_STAT;
  return SetMaxStats(stats);
}

public varargs mapping QueryMaxStats(object pl)
{
  string *idx;
  int i;
  mapping st;
  st = (Pmaxstats||G_MAXSTATS)+([]);
  if (!pl) return st;
  i = sizeof(idx = m_indices(st));
  while(i--)
    st[idx[i]]=max(({1,round(get_race_modification(pl,idx[i])/2.0)+st[idx[i]]}));
  return st;
}

public varargs int QueryMaxStat(string stat,object pl)
{
  return QueryMaxStats(pl)[stat];
}

public mapping AddMaxStat(string stat,int value)
{
  if ((value<1)
      ||(member(STATS,stat)==-1)
     )
    return Pmaxstats||G_MAXSTATS;
  if (!Pmaxstats) Pmaxstats = G_MAXSTATS;
  Pmaxstats[stat]=value;
  return Pmaxstats;
}

public mapping SetMaxHLPStats(mapping stats)
// Set the maximum stats for the guild, a HLP
// might get.
{
  if (   !mappingp(stats)
      || min(m_values(stats))<1
      || sizeof(stats)!=sizeof(STATS)
      || sizeof(m_indices(stats)-STATS)
      || sizeof(STATS-m_indices(stats))
     )
    return Pmaxstats||G_MAXSTATS;
  return Pmaxhlpstats = stats;
}

public mapping SetModMaxHLPStats(mapping stats)
// Set the maximum stats for the guild, a HLP
// might get.
{
  if (   !mappingp(stats)
      || sizeof(stats)!=sizeof(STATS)
      || sizeof(m_indices(stats)-STATS)
      || sizeof(STATS-m_indices(stats))
     )
    return Pmaxstats||G_MAXSTATS;
  foreach(string stat:STATS) stats[stat]+=HLP_STAT;
  return SetMaxHLPStats(stats);
}



public varargs mapping QueryMaxHLPStats(object pl)
{
  string *idx;
  int i;
  mapping st;
  st = (Pmaxhlpstats||G_MAXSTATS)+([]);
  if (!pl) return st;
  i = sizeof(idx = m_indices(st));
  while(i--)
    st[idx[i]]=max(({1,round(get_race_modification(pl,idx[i])/2.0)+st[idx[i]]}));
  return st;
}

public varargs int QueryMaxHLPStat(string stat,object pl)
{
  return QueryMaxHLPStats(pl)[stat];
}

public mapping AddMaxHLPStat(string stat,int value)
{
  if ((value<1)
      ||(member(STATS,stat)==-1)
     )
    return Pmaxhlpstats||G_MAXSTATS;
  if (!Pmaxhlpstats) Pmaxhlpstats = G_MAXSTATS;
  Pmaxhlpstats[stat]=value;
  return Pmaxhlpstats;
}

