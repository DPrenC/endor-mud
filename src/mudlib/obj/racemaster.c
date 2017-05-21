/**
 * ENDOR-MUD '/obj/racemaster.c'
 */

#pragma no_clone

#include <config.h>
#include <races.h>
#include <attributes.h>
#include <wizlevels.h>
#include <guild.h>
#include <properties.h>

/*-------------------------------------------------------------------------*/

static object player;    /* For the local Pl_funs() */

/*-------------------------------------------------------------------------*/

/* For simple process_string()s, return the players name and gender_stuff */

string Pl_name() { return (string) player->QueryName(); }
string Pl_pro() { return (string) player->QueryPronoun(); }
string Pl_poss() { return (string) player->QueryPossessive(); }
string Pl_obj() { return (string) player->QueryObjective(); }
int Pl_gender() { return player->QueryGender(); }

string Pl_Name() { return capitalize((string) player->QueryName()||""); }
string Pl_Pro() { return capitalize((string) player->QueryPronoun()||""); }
string Pl_Poss() { return capitalize((string) player->QueryPossessive()||""); }
string Pl_Obj() { return capitalize((string) player->QueryObjective()||""); }


/* Funciones anyadidas para usar el castellano. Sigo el modelo de las
anteriores. Por si acaso he creado nuevas funciones y he respetado las
antiguas.
*/

// sufijo para sustantivos /-o/-a
string suf() { return (string) player->QueryGenderEndString(); }
// sufijo para sustantivos / /-a
string suf2() { return (string) player->QueryGenderEndString2(); }
// articulo el/el/la
string art() { return (string) player->QueryArtDetString(); }
// articulo mayusculas el/el/la
string Art() { return capitalize((string) player->QueryArtDetString()||""); }
// articulo indeterminado un(o)/un/una
string ind() { return (string) player->QueryArtIndString(); }
// genero neutro/macho/hembra
string genero() { return (string) player->QueryGenderString(); }
// pronombre
string pron() { return (string) player->QueryPronoun(); }
// pronombre mayusculas
string Pron() { return capitalize((string) player->QueryPronoun()||""); }
// pronombre posesivo (no se usa, siempre es 'su')
string pose() { return (string) player->QueryPossessive(); }
// pronombre posesivo mayuscula (no se usa, siempre es 'su')
string Pose() { return capitalize((string) player->QueryPossessive()||""); }
// nombre
string nombre() { return (string) player->QueryName(); }
// nombre mayusculas
string Nombre() { return capitalize((string) player->QueryName()||""); }


/*-------------------------------------------------------------------------*/

create_blueprint()
{
  seteuid(getuid());
}

/*-------------------------------------------------------------------------
 * string *AllRaceNames ()
 *   Return the names of all know races.
 */

static int cmp_str (string s1, string s2) { return s1 > s2; }
static string strip_dotc (string fname) { return fname [0..<3]; }

string *AllRaceNames() {
  return sort_array (map(get_dir(RACES("*")), "strip_dotc"
                               , TO)
                    , "cmp_str", TO);
}

string *AllPlayerRaceNames() {
    return ({"enano", "humano", "hobbit", "medio-elfo", "orco", "dunadan", "uruk-hai", "trasgo", "beornida", "elfo-noldo", "elfo-sinda", "elfo-silvano", "wose", "rohir"});
}
string *RazasBase() {
    return ({"humano", "elfo", "orco", "hobbit", "enano", "alto-hombre"});
}
string *RazasHumanos(){
    return ({"hombre-comun", "hombre-bosque", "lossadan", "beornida", "wose", "rohir", "dunlendino", "haradan", "variag", "oriental"});
}
string *RazasElfos(){
    return ({"medio-elfo", "noldo", "sinda", "silvano"});
}
string *RazasOrcos(){
    return ({"orco-comun", "uruk", "trasgo", "medio-orco"});
}
string *RazasEnanos(){
    return ({"barbiluengo", "barbafuego", "barbatiesa", "cintura-ancha", "puñoferreo", "piepetreo", "rizosnegros"});
}
string *RazasHobbits(){
    return ({"peloso", "albo", "fuerte"});
}
string *RazasAltosHombres(){
    return ({"numenoreano-negro", "corsario", "dunadan"});
}
/*-------------------------------------------------------------------------
 * object RaceObject (string race, [object pl])
 *   Search the race-object for given race.
 */

varargs object RaceObject(string race, object pl) {
  string testa, testb;
  string fname;
  object rc;

  if (!stringp(race) || !sizeof(race)) return 0;
  if (!pl && !(pl = TP)) return 0;
  if (member(race, ' ') >= 0) return 0; // Nada de espacios, que la ruta peta

  if (pl->QueryIsNPC() || pl->QueryIsPet())
  {
    fname = RACES("npc/"+race);
    if (file_size(fname+".c") <= 0) fname = RACES(race);
  }
  else fname = RACES(race);

  if (file_size(fname+".c") <= 0) return 0;
  if (rc = find_object (fname)) return rc;

  return load_object(fname);
}

/*-------------------------------------------------------------------------
 * string RaceDescr (string race, [object pl])
 *   Returns a descriptional string for <race>.
 */

varargs string RaceDescr (string race, object pl) {
  object rc;
  if (rc = RaceObject(race, pl)) return (string) rc->QueryRaceDescription();
  return 0;
}

/*-------------------------------------------------------------------------
 * int CheckStat (object pl, string stat, int val)
 *   Check the given <stat> with value <val> for <pl> according
 *   to it's level and race against the max. allowed value, and return
 *   the lesser of both.
 */

int CheckStat(object pl, string stat, int val) {
  int at2;
  object raceobj;

  if (!(raceobj = RaceObject( (string) pl->QueryRace(), pl ) )) return 0;

  at2 = xp2level((int) pl->QueryXP()) + raceobj->QueryStatBonus(stat) + (int) pl->QueryBonus(stat);

  if (val <= at2) at2 = val;

  if (at2 < 1) at2 = 1;
  return at2;
}

/*-------------------------------------------------------------------------
 * int AdvanceCosts (string stat, int base, int delta)
 *   Return amount of experience an increase of <stat> from the current
 *   value <base> by <delta> has to cost.
 */

int AdvanceCosts (string stat, int base, int delta) {
  if (delta <= 0) return 0;
  return (level2xp(base+delta) - level2xp(base)) / 10;
}

/*-------------------------------------------------------------------------
 * int CheckAdvance (object pl, string stat, int delta)
 *   Check if the <pl>ayer has enough experience to advance this <stat>
 *   by the given <delta> value. Returns the costs in experience
 *   if advancing is ok, else zero.
 */

int CheckAdvance (object pl, string stat, int delta) {
  int at, costs, xp;
  mixed *rdata;

  at =  call_other(pl,"QueryTrue"+stat) + delta;
  if (at != CheckStat (pl, stat, at)) return 0;
  costs = AdvanceCosts (stat, at-delta, delta);
  xp = (int) pl->QueryXP();
  if (level2xp(pl->QueryLevel())+costs > xp) return 0;
  return costs;
}

/*-------------------------------------------------------------------------
 * void AdjustStats (object pl)
 *   Adjust the stats for <pl> according to it's level and race.
 *   El máximo de un stat es mi nivel más el modificador de raza.
 */

public void AdjustStats(object pl) {
  int level;
  object raceobj;
  mapping statmap;

  if (!(raceobj = RaceObject( (string) pl->QueryRace(), pl) ) ) return 0;

  level = xp2level((int) pl->QueryXP());

  statmap = (mapping) pl->QueryStats() || ([]);

  foreach (mixed statname : STATS)
  {
    if (member(statmap, statname))
    {
      int maxstat = level + raceobj->QueryStatBonus(statname);
      int stat = statmap[statname];

      if (maxstat < 1) maxstat = 1;
      if (stat > maxstat ) statmap[statname] = maxstat;
    }
  }

  pl->SetStats(statmap);
}

/*-------------------------------------------------------------------------
 * void InitRace (object pl, string race)
 *   Sets the <race> of the <pl> and also all inferred values.
 *   Esta función SOLO debe de ser llamada cuando un living NO tiene raza
 */

public int InitRace(object pl, string race) {
  object raceobj;
  int con, itl, dex, str, cha, wis;

  if (!(raceobj = RaceObject(race, pl))) {
    if (pl->QueryIsPlayer()) // Catch wrong inits of player objects
      log_file ("ILLEGAL", ctime(time())+(TI ? (" ("+getuid(TI)+")"):"")
                +" Illegal race '"+race+"'\n");
    return 0;
  }

  player = pl; /* for functions that are called via process_string() */

  /* If necessary, rescue old stat settings */
  if (!sizeof((string)pl->QueryRace()))
  { // No tengo raza, deberia de ser asi SIEMPRE
    con = itl = dex = str = cha = wis = 1;
  }
  else
  {
    object old_raceobj = RaceObject((string)pl->QueryRace(), pl);
/* anulo la escritura en el log de racemaster
    log_file("RACEMASTER",
             sprintf("[%s] %O llamó a InitRace(%O, %O) cuando ya tenia raza (%O)\n",
             ctime() , PO, pl, race, pl->QueryRace()));
*/
    con = (int) pl->QueryCon() - old_raceobj->QueryStatBonus(P_CON);
    itl = (int) pl->QueryInt() - old_raceobj->QueryStatBonus(P_INT);
    dex = (int) pl->QueryDex() - old_raceobj->QueryStatBonus(P_DEX);
    str = (int) pl->QueryStr() - old_raceobj->QueryStatBonus(P_STR);
    cha = (int) pl->QueryCha() - old_raceobj->QueryStatBonus("Cha");
    wis = (int) pl->QueryWis() - old_raceobj->QueryStatBonus(P_WIS);
  }

  pl->SetMaxAlcohol(raceobj->QueryMaxAlcohol());
  pl->SetAlign     (raceobj->QueryAlign     ());
  pl->SetMaxDrink  (raceobj->QueryMaxDrink  ());
  pl->SetMaxFood   (raceobj->QueryMaxFood   ());
  pl->SetIVision   (raceobj->QueryIVision   ());
  pl->SetSize      (raceobj->QuerySize      ());
  pl->SetBando      (raceobj->QueryBando      ());
  pl->SetUVision   (raceobj->QueryUVision   ());
  pl->SetWeight    (raceobj->QueryWeight    ());

  pl->SetHands      (raceobj->QueryHands()      );
  pl->SetResistances(raceobj->QueryResistances());

  pl->SetLong       (process_string(raceobj->QueryLong()));

  if ( (con += raceobj->QueryStatBonus(P_CON)) < 1) con = 1;
  if ( (dex += raceobj->QueryStatBonus(P_DEX)) < 1) dex = 1;
  if ( (itl += raceobj->QueryStatBonus(P_INT)) < 1) itl = 1;
  if ( (str += raceobj->QueryStatBonus(P_STR)) < 1) str = 1;
    if ( (cha += raceobj->QueryStatBonus("Cha")) < 1) cha = 1;
        if ( (wis += raceobj->QueryStatBonus(P_WIS)) < 1) wis = 1;

  pl->SetCon(con);
  pl->SetDex(dex);
  pl->SetInt(itl);
  pl->SetStr(str);
    pl->SetCha(cha);
    pl->SetWis(wis);

  pl->SetRace(race);

  AdjustStats(pl);

//  if (pl->QueryIsPlayer()) pl->set_title(art()+" nuev"+suf()+" "+capitalize(race));
  if (pl->QueryIsPlayer()) pl->set_title(art()+" joven "+capitalize(race));
  return 1;
}

/*-------------------------------------------------------------------------
 * void RestoreRace (object pl)
 *   Restores the not-saved values of <pl>ayer which are concerned by its
 *   race.
 */

public void RestoreRace(object pl) {
  mixed *data;
  string race, desc;
  object raceobj;

  race = (string) pl->QueryRace();

  if (!(raceobj = RaceObject(race, pl))) return;

  player = pl; // Para el process string

  pl->SetWeight(raceobj->QueryWeight());
  pl->SetHands (raceobj->QueryHands() );
  pl->SetSize  (raceobj->QuerySize()  );
pl->SetBando  (raceobj->QueryBando()  );
// [Nyh] toco para que la Long se pueda cambiar y se mantenga...
  if ((desc=pl->QueryAttribute(P_OWN_LONG)) && (desc!=0) && (desc!="") /*&& (desc!=([]))*/)
  	pl->SetLong(desc);
  else pl->SetLong(process_string(raceobj->QueryLong()));

}
