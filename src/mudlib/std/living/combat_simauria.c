/* /std/living/combat.c
**
** The combat routines for living objects are here.
**
** This file is (c) Nightfall 1992. You may use of it whatever you like, but
** you should put a reference in your file if you do it.
**
** [h] Nyh@Simauria
**
**  xx-03-03 [h] Coge lo que habia que procedia del combate original de
**		 Simauria (adaptado desde nightfall) con el remake que
**		 hizo nemesis y que nunca llego a entrar en juego, lo
**		 agita mucho, añade dosis propias en cantidades variables
**		 y sale lo que puedes ver.
**		 Digamos que esto seria como una version 1.5 del sistema
**		 de combate de Simauria...
**		 Ha, y borro los kilos de lineas de comentarios de aqui arriba
**------------------------------------------------------------------------
*/

#include <config.h>
#include <properties.h>
#include <living.h>
#include <combat.h>
//#include <combattune.h>
#include <wizlevels.h>
#include <attributes.h>
#include <colours.h>
#include <skills.h>
#include <gremios.h> //combate_bueno y demas


//#define NYH_DEBUG_PUPA
//#define DEBUG_AGGRESSIVE
//#define DEBUG_DEFENSIVE_SKILLS
//#define DEBUG_NOPEGO
#define ESTADISTICAS
//#define DEBUG_ELE
//#define DEBUG_COMBATACTION

#define COLOR_ALL

#define HERE environment(TO)

#undef ENV
#define ENV environment

/*#include "log.h"*/

//------------------------------------------------------------------------------

// std/base
public mixed Query(string pn);
public mixed Set(string pn, mixed arg);

// std/living/description
public int QueryCitizenship();
public varargs object QueryRaceObj(int reload);
public int CanSeeObject(object liv);
public string QueryRace();
public int QueryIsNPC();
public int QueryIsPlayer();
public string QueryName();
public string QueryShort();
public int QueryLevel();
public int QueryGhost();
public varargs int QuerySize();

// std/living/restrictions
public int QueryLoad();

// std/living/heart
public void GetHeart(int user);
public void DropHeart(int user);
public int CheckHeart(int user);

// std/living/stats
public varargs int QueryStr(int real);
public varargs int QueryDex(int real);
public int QueryCon();
public int QueryInt();

// std/living/body
public varargs int DoDamage (int damage, int gentle);
public int AddXP (int xp);
public int QueryXP();
public int QueryHP();
public int QueryStunned ();
public int SetStunned (int i);
public int QueryDisabled();
public int QueryParalyzed();
public varargs int QueryGuildLevel(string g);
public string QueryGuild();
public int QueryStatusNormal();
public int QueryStatusResting();
public int QueryStatusSleeping();
public int QueryStatusTripped();
public int QueryStatusHelpless();

// std/thing/moving
public object *QueryFollowers();

// std/living/chat
public void DoAttackChat (object enemy);

//std/living/skills
public varargs int UseSkill(string name, int bonus, int nomod);
public int HasSkill(string name);

// Forward
public int Fighting();
public closure QueryFriendFunction();
public int QueryAggressive();
public int QueryAttackChance();
public int QueryAttackOwnRace();
public string *QueryHunters();
public int IsHunter(mixed e);
public int IsEnemy(mixed e);
private varargs object GetEnemy(object *en);
private object GetEnemyFrom(object *e);
public object SetEnemy(object en);

//------------------------------------------------------------------------------

private nosave mapping hbstat;

private nosave   mixed *pHands = ({});
private nosave   mixed pCombatDelayMsg;
private nosave     int pCombatDelay;
private nosave mapping pDefences = ([]);
private nosave  object *pWeapons = ({}), *pArmours = ({}), *pShields = ({});
private nosave     int pAggressive, pAttackChance, pAttackOwnRace;
private nosave  object *pEnemies = ({});
private nosave  string *pHunters = ({}); //cambiado a string!!!!
private nosave  string *pCombatAction = ({}); //array q almacena las futuras acciones en el combate.
private nosave  object pEnemy; //el objeto al que le quiero pegar.
private nosave closure pFriendFunction, pChkFightFunction, pChkMagicFunction;

#ifdef COMBATMODE
private int pCombatMode;	// modos de combate, yum yum.
#endif
//colorines:
private string	pColorAtaco, pColorAtacado, pColorAjeno;
private int pCombateBreve;

//Nyh, estadisticas
#ifdef ESTADISTICAS
private nosave int golpes, aciertos, danyo, recibidos, esquivados, parados;
#endif

// -----------------------------------------------------------------------------
// hbstat
// -----------------------------------------------------------------------------

/* Heartbeat-Statistic:
 * index is enemy name, [0]: number HBs, [1] enemy object
 * Look for 'HBSTAT' comments, also in /std/living/body, /std/player/life
 * and /std/player.
 */

//#define HBLOG

public SubeHBStat(object enemy) { hbstat[to_string(enemy), 0]++; }
public AddHBStat(object enemy)  { hbstat += ([ to_string(enemy):0;enemy ]); }

private mapping SetHBStat(mapping m) { return hbstat = m; }
public mapping QueryHBStat() { return hbstat; }
void clean_hbstat() {
  string *names;
  int i;

  if (!query_once_interactive(TO)) return;
  names = m_indices(hbstat);
  for (i = sizeof(names); i-- ;)
  {
	 if (!hbstat[names[i],1])
	 {
#ifdef HBLOG
		write_file("/log/HBSTAT", sprintf("%O enemigo %s desaparecido: %d hbs\n", TO, names[i], hbstat[names[i],0]));
#endif
		m_delete(hbstat, names[i]);
	 }
  }
}

void hbstat_kill(object obj) {
  object eobj;
  int nrhb;
  if (query_once_interactive(TO)
	&& m_contains(&nrhb, &eobj, hbstat, to_string(obj))
	  )
  {
#ifdef HBLOG
	 if (eobj == obj)
		write_file("/log/HBSTAT", sprintf("%O: mató %O: %d hbs\n", TO, obj, nrhb));
	 else
		write_file("/log/HBSTAT", sprintf("%O: mató %O similar a %O: %d hbs\n", TO, obj, eobj, nrhb));
#endif
	 m_delete(hbstat, to_string(obj));
  }
}

void hbstat_idied() {
  string * names;
  object eobj;
  int nrhb, i;

  if (!query_once_interactive(TO)) return;
  clean_hbstat();
  names = m_indices(hbstat);
  for (i = sizeof(names); i-- ;)
  {
#ifdef HBLOG
	 write_file("/log/HBSTAT", sprintf("%O murió: enemigo %O: %d hbs\n", TO, hbstat[names[i] ,1], hbstat[names[i],0]));
#endif
	 m_delete(hbstat, names[i]);
  }
}

hbstat_flush() {
  string * names;
  object eobj;
  int nrhb, i;

  if (!query_once_interactive(TO)) return;
  clean_hbstat();
  names = m_indices(hbstat);
  for (i = sizeof(names); i--;)
  {
#ifdef HBLOG
	 write_file("/log/HBSTAT", sprintf("%O flushed: enemigo %O: %d hbs\n", TO, hbstat[names[i] ,1], hbstat[names[i],0]));
#endif
	 m_delete(hbstat, names[i]);
  }
}

// -----------------------------------------------------------------------------
// Fin hbstat
// -----------------------------------------------------------------------------
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// -----------------------------------------------------------------------------
// Inicializacion y funciones misceláneas
// -----------------------------------------------------------------------------

//Nyh
//msg =
#define CANKILL_SPEAK	0
#define CANKILL_VOID	1

public varargs int CanKill(object ob,int msg){
int i;
 if ( !(i=0, ob && objectp(ob)) || (i=1,ob->QueryGhost()) ||
       (i=2,ob == TO) ||(i=3,environment(ob)->QuerySafe()) ||
       (i=4,(ob->Query(P_CANT_FIGHT) & C_NORMAL_FIGHT)) ||
       (i=5,(query_once_interactive(TO) && !query_wiz_level(TO) && query_once_interactive(ob))))
 {
   if (i == 5)
   // intento de PK
   {
       log_file("TRY_PK", ctime() + ": " + TNAME + " intentó luchar contra " + NNAME(ob) + ". "
           "Comando: " + query_verb() + ".\n");
   }
   if (msg) switch (i) {
   	case 0: return notify_fail("No es un objetivo valido.\n"); break;
   	case 1: return notify_fail("No puedes atacar a un fantasma.\n"); break;
   	case 2: return notify_fail("¿Quieres suicidarte?.\n"); break;
   	case 3: return notify_fail("Estás en una habitacion segura.\n"); break;
   	case 4: return notify_fail("No puedes atacar a "+capitalize(ob->QueryName())+".\n");
    case 5: return notify_fail("No se permite la lucha entre jugadores.\n"); break;
   }
   return 0;
 }
 return 1;
}

// By default: don't attack other NPCs if being a NPC <-comentado
// or don't attack players if being a player <-solo esto ahora
public int IsFriend(object victim) {
    return QueryFriendFunction()?funcall(QueryFriendFunction(), victim)
                                :(QueryIsPlayer() && victim->QueryIsPlayer());
}

public int CheckAggressive(object victim) {
#ifdef DEBUG_AGGRESSIVE
  int i;
//if (find_object("nyh")) dtell("nyh",sprintf("%O->CheckAggressive(%O)\n",TO,victim));
  i = IsHunter(victim)
    || (   ( QueryAggressive()==2 || (QueryAggressive()==1 && (victim->QueryIsPlayer() || victim->Query(P_IS_PET))))
        && ( ( (victim->QueryRace() == QueryRace())
		    ? QueryAttackChance()*QueryAttackOwnRace()/1000
		    : QueryAttackChance() ) > random(1000) )
        && ( !IsFriend(victim) )
       );
  if (i && QueryAggressive()==2 && !victim->QueryIsPlayer() && !victim->Query(P_IS_PET) )
    write_file("/log/combat/aggressive",sprintf("%O: %O ataco a %O\n",ctime(time()),object_name(TO),object_name(victim)));
//if (find_object("nyh")) dtell("nyh",sprintf("\t CheckAggressive return %O;\n",i));
  return i;
#else
  return IsHunter(victim)
    || (   ( QueryAggressive()==2 || (QueryAggressive()==1 && (victim->QueryIsPlayer() || victim->Query(P_IS_PET))))
        && ( ( (victim->QueryRace() == QueryRace())
		    ? QueryAttackChance()*QueryAttackOwnRace()/1000
		    : QueryAttackChance() ) > random(1000) )
        && ( !IsFriend(victim) )
       );
#endif
}

public int CheckAutoAttack (object victim) {
//if (find_object("nyh")) dtell("nyh",sprintf("%O->CheckAutoAttack(%O)\n",TO,victim));
//if (find_object("nyh")) dtell("nyh",sprintf("IsHunter(victim):%O\n",IsHunter(victim)));
//if (find_object("nyh")) dtell("nyh",sprintf("CanSeeObject(victim):%O\nquery_once_interactive(victim):%O\n",CanSeeObject(victim),query_once_interactive(victim)));
  if (   !victim
      || victim == TO
      || !living(victim)
      || environment(victim)->QuerySafe()
      || victim->QueryGhost()
      || !CanSeeObject(victim)
      || !CheckAggressive(victim)
      || IS_LEARNER(victim)
      //|| !query_once_interactive(victim)
     ) {
//if (find_object("nyh")) dtell("nyh",sprintf("\t CheckAutoAttack return 0;\n"));
    return 0;
  }
//if (find_object("nyh")) dtell("nyh",sprintf("\t CheckAutoAttack return 1;\n"));
  return 1;
}

/*
 * kill - start combat
 * Sets the enemy thus starting combat
 * Don't attack ghosts or invisible wizards.
 */
public int Kill(object ob) {
  closure fun;
  if (!CanKill(ob, CANKILL_VOID) || ((fun = ob->QueryChkFightFunction()) && !funcall(fun, TO))) return 0;
  if (SetEnemy(ob))
  {
    /* Antes de nada, comprobamos que el jugador no este invisible */
    if (ob->QueryInvis() && !IS_LEARNER(ob)) {
      write("La ilusion se desvanece y vuelves a ser visible.\n");
      say(capitalize(ob->QueryRealName())+" aparece de la nada.\n");
      ob->SetInvis(0);
    } /* Fin de la comprobacion del invis*/
    GetHeart(HEART_COMBAT);
	 /* HBSTAT */
    if ( query_once_interactive(TO) && IsHunter(ob) )
      hbstat += ([ to_string(ob):0;ob ]);
    return 1;
  }
  return 0;
}

create() {
  pAggressive = 0;
#ifdef ESTADISTICAS
  golpes = aciertos = danyo = esquivados = recibidos = parados = 0;
#endif
  pHands = ({});
  pWeapons = ({});
  pEnemies = ({});
  pHunters = ({});
  pArmours = ({});
  pShields = ({});
  pEnemy = 0;
  pDefences = ([]);
  pAttackChance = 1000;
  pAttackOwnRace = 0;
  pFriendFunction = 0;
  pChkFightFunction = 0;
  pChkMagicFunction = 0;

  hbstat = m_allocate(0, 2);
}

public void init() {
  int delay;

  if (CheckAutoAttack(TP)) {
    /* We decided to kill this player. Now how fast can we react? */
    delay = 6 - (QueryInt()*STAT_SCALE+QueryDex()*STAT_SCALE)/50;
    if (delay < 1) Kill(TP);
    else call_out("Kill", delay, TP);
  }
}

// -----------------------------------------------------------------------------
// Fin Inicializacion y funciones misceláneas
// -----------------------------------------------------------------------------
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// -----------------------------------------------------------------------------
// Set, Query, Add, Remove
// -----------------------------------------------------------------------------
#ifdef COMBATMODE
public int SetCombatMode(int i)	{return pCombatMode=i;}
public int QueryCombatMode()	{return pCombatMode;}
public int AddCombatMode(int i)	{return pCombatmode=pCombatmode|i;}
public int RemoveCombatMode(int i) {return pCombatmode=pCombatmode&(i^COMBATMODE_ALL);}
#endif
//Nyh estadistica:
#ifdef ESTADISTICAS
public int QueryGolpes()	{return golpes;}
public int QueryAciertos()	{return aciertos;}
public int QueryFallos()	{return golpes-aciertos;}
public int QueryDanyo()		{return danyo;}
public int QueryRecibidos()	{return recibidos;}
public int QueryEsquivados()	{return esquivados;}
public int QueryParados()	{return parados;}
public float QueryDanyoMedioTotal() {return golpes?(float)danyo/golpes:0;}
public float QueryDanyoMedio()	{return aciertos?(float)danyo/aciertos:0;}

public int AddRecibido()	{return ++recibidos;}
public int AddEsquivado()	{return ++esquivados;}
public int AddParado()		{return ++parados;}
public int AddGolpe()		{return ++golpes;}
public int AddDanyo(int dam)	{return danyo+=dam;}
public int AddAcierto()		{return ++aciertos;}
#endif
//fin estadistica

private int AddOneCombatAction(string str) {
  if (!pCombatAction) pCombatAction=({});
  if (!stringp(str)) return 0;
  return sizeof(pCombatAction+=({str}));
}
public int AddCombatAction(mixed str) {
  if (pointerp(str)) return sizeof(filter(str,"AddOneCombatAction"));
  else return AddOneCombatAction(str);
}
public string GetNextCombatAction() {
  if (!pCombatAction || !sizeof(pCombatAction)) return COMBATACTION_DEFAULT;
  else {
    string tmp;
    tmp = pCombatAction[0];
    pCombatAction = pCombatAction[1..];
    return tmp;
  }
}

public string *QueryCombatAction() { return copy(pCombatAction);}

//colorines
//private string	pColorAtaco, pColorAtacado, pColorAjeno;
//TC_BOLD, COLORANSI
public string QueryColorAtaco()   { return pColorAtaco||ANSI_NONE;}
public string QueryColorAtacado() { return pColorAtacado||ANSI_NONE;}
public string QueryColorAjeno()   { return pColorAjeno||ANSI_NONE;}

public string SetColorAtaco(string color) {return pColorAtaco=color;}
public string SetColorAtacado(string color) {return pColorAtacado=color;}
public string SetColorAjeno(string color) {return pColorAjeno=color;}

public int SetCombateBreve(int i) { return i?(pCombateBreve=1):(pCombateBreve=0);}
public int QueryCombateBreve()	  { return pCombateBreve;}
//fin colorines

public int SetAggressive(int a)     { return pAggressive = a; }
public int QueryAggressive()     { return pAggressive; }

public int SetAttackChance(int a)  { return pAttackChance = a; }
public int QueryAttackChance()      { return pAttackChance; }

public int SetAttackOwnRace(int a) { return pAttackOwnRace = a; }
public int QueryAttackOwnRace()     { return pAttackOwnRace; }

public closure QueryFriendFunction()		{ return pFriendFunction; }
public varargs closure SetFriendFunction(mixed mix, mixed ob)	{
    if (stringp(mix))
    {
        if (ob) return pFriendFunction = symbol_function(mix, ob);
        else return pFriendFunction = symbol_function(mix);
    }
    return pFriendFunction = mix;
}

public closure QueryChkFightFunction() { return pChkFightFunction; }
public varargs closure SetChkFightFunction(mixed mix, mixed ob)
{
    if (stringp(mix))
    {
        if (ob) return pChkFightFunction = symbol_function(mix, ob);
        else return pChkFightFunction = symbol_function(mix);
    }
    if (!closurep(mix)) return pChkFightFunction;
    return pChkFightFunction = mix;
}

public closure QueryChkMagicFunction() { return pChkMagicFunction; }
public varargs closure SetChkMagicFunction(mixed mix, mixed ob)
{
    if (stringp(mix))
    {
        if (ob) return pChkMagicFunction = symbol_function(mix, ob);
        else return pChkMagicFunction = symbol_function(mix);
    }
    if (!closurep(mix)) return pChkMagicFunction;
    return pChkMagicFunction = mix;
}

public int QueryCombatDelay()	   { return pCombatDelay; }
public varargs int SetCombatDelay(int time, string s) {
  if (time < 1) return time = pCombatDelay = pCombatDelayMsg = 0;
  GetHeart(HEART_COMBAT);
  if (s && stringp(s)) pCombatDelayMsg = s;
  else if (!pCombatDelayMsg) pCombatDelayMsg = "Ahora mismo no puedes hacer eso.\n";
  return pCombatDelay = time;
}
public string QueryCombatDelayMsg()	  { return pCombatDelayMsg; }
public string SetCombatDelayMsg(string s) { return pCombatDelayMsg=stringp(s)?s:0; }

// Nuevas Funciones
public mapping QueryDefenceMap() { return copy(pDefences || ([])); }
//si hay flag NO suma la defensa base (TD_NORMAL o TD_MAGICO))
public varargs int QueryDefence(int type, int flag)  {
  if (flag) return (pDefences||([]))[type];
  else {
    if (type>TD_MAGICO) return (pDefences||([]))[type]+(pDefences||([]))[TD_MAGICO];
    else if (type>TD_NORMAL) return (pDefences||([]))[type]+(pDefences||([]))[TD_NORMAL];
    else return (pDefences||([]))[type];
  }

}
public varargs int GetDefence(int type, int flag)  { return QueryDefence(type, flag); }

public int AddDefence(int type, int value) {
 int total;

 if (!VALID_DAMAGE_TYPE(type)) return 0;
 if (!pDefences) pDefences = ([ ]);
 total = GetDefence(type) + value;
 if (total) pDefences[type] = total;
 else m_delete(pDefences,type);
 return total;
}
// Nuevas Funciones:

public int SetDefence(int type, int value){
  if (!VALID_DAMAGE_TYPE(type)) return 0;
  if (!pDefences) pDefences = ([ ]);
  if (value) pDefences[type] = value;
  else m_delete(pDefences,type);
  return value;
}

public mapping SetDefenceMap(mapping m){
 int i, *types;

 if (!mappingp(m)) m = ([ ]);
 if (!member(m,DT_INTR)) m[DT_INTR] = GetDefence(DT_INTR);
 pDefences = ([ ]);
 types = m_indices(m);
 for (i=sizeof(types); i--; )
 SetDefence(types[i], m[types[i]]);
 return QueryDefenceMap();
}

public int SetAC(int ac)   { return SetDefence(DT_INTR,ac); }
public varargs int QueryAC()  { return GetDefence(DT_INTR); }

// Función introducida por mí mismo a través de mi propio mecanismo...
public void RemoveEnemies() { pEnemies=({ }); }

public object *QueryEnemies()    { return pEnemies=(pEnemies||({}))-({0}); }

// Nueva función
public varargs int AddEnemy(object e) {
  object *f;

  if (member(pEnemies,e)!=-1) return 2;

  if (   !e || e->QueryGhost() || e==TO || !present(e)
      || (query_once_interactive(TO) && !query_wiz_level(TO) && query_once_interactive(e)))
  {
      return 0;
  }

  pEnemies += ({e});
  f = QueryFollowers();
  if (member(f,0)!=-1) f-=({0});
  map_objects(f,"NotifyAddEnemy",e);
  GetHeart(HEART_COMBAT);
  return 1;
}

// [Nyh] 18-03-08 Nueva función, matar al que use SetEnemies.
public void AddEnemies(object *e) {
  foreach(object o : e) AddEnemy(o);
}

public object QueryEnemy()	  { return (pEnemy && present(pEnemy))?pEnemy:(pEnemy=GetEnemyFrom(QueryEnemies())); }
public object SetEnemy(object en) { return pEnemy=AddEnemy(en)?en:0;}

//Nyh SetEnemies añadido, hace log de quien lo usa!!
public object *SetEnemies(mixed e) {
  write_file("log/combat/SetEnemies.log",sprintf("%O llamo a %O->SetEnemies(%O)\n",PO,TO,e));
  if (sizeof(pEnemies = filter(e, (: $1 && present($1) && $1!=TO && !$1->QueryGhost() :) )||({})))
  {
    GetHeart(HEART_COMBAT);
  }
  return pEnemies;
}

public int RemoveEnemy(object e) {
  object *f;

  if (member(pEnemies,e)!=-1) {
    pEnemies-=({e});
    if (e==QueryEnemy()) SetEnemy(0);
    f = QueryFollowers();
    if (member(f,0)!=-1) f-=({0});
    map_objects(f,"NotifyRemoveEnemy",e);
    if (!sizeof(pEnemies) && !QueryCombatDelay()) DropHeart(HEART_COMBAT);
    return 1;
  }
  return 0;
}

// Función introducida por mí mismo a través de mi propio mecanismo...
public void RemoveHunters() { pHunters = ({ }); }

public string *QueryHunters() { return copy(pHunters); }

// Nueva función
public status AddHunter(object e) {
  object *f;

  if (!e) return 0;
  else if (IsHunter(e)) return 2;
  pHunters += ({ to_string(e) });
  f = QueryFollowers();
  if (member(f,0)!=-1) f-=({0});
  map_objects(f,"NotifyAddHunter",e);
  return 1;
}

// Nueva función
public status RemoveHunter(object e) {
  object *f;

  if (IsHunter(e)) {
    pHunters -= ({ to_string(e) });
    f = QueryFollowers();
    if (member(f,0)!=-1) f-=({0});
    map_objects(f,"NotifyRemoveHunter",e);
    return 1;
  }
  return 0;
}

// private object *SetArmours(object *d) { return pArmours = d; }
public object *QueryArmours()     { return pArmours=(pArmours||({}))-({0}); }

// private object *SetWeapons(object *w) { return pWeapons = w; }
public object *QueryWeapons()     { return pWeapons=(pWeapons||({}))-({0}); }

// private object *SetShields(object *s) { return pShields = s; }
public object *QueryShields()     { return pShields=(pShields||({}))-({0}); }

public mixed *QueryHands()     { return pHands=(pHands||({}))-({0}); }

// Novedad: Se le puede poner el tipo de daño a la mano con ello (type)
public void AddHand(string short, mixed type, int wc) {
//  if (find_object("nyh")) dtell("nyh",sprintf("\tcombat::AddHand(short=%O, type=%O, wc=%O)\n",short,type,wc));
  if ( (!intp(type) || !VALID_DAMAGE_TYPE(type)) && !objectp(type) )
  type = 0;
  pHands += ({ ({ short, type, wc }) });
//  if (find_object("nyh")) dtell("nyh",sprintf("\t\tpHands=%O\n",pHands));
}

public mixed *SetHands(mixed h){ // ¡Usese con cuidado!
  int i;

  if (!h || !pointerp(h)) h = ({ });
  pHands = ({ });
  for (i=sizeof(h); i--; )
    AddHand(h[i][HAND_SHORT], h[i][HAND_WEAPON], h[i][HAND_WC]);
  return QueryHands();
}

// -----------------------------------------------------------------------------
// Fin Set, Query, Add, Remove
// -----------------------------------------------------------------------------
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// -----------------------------------------------------------------------------
// Misc. Functions
// -----------------------------------------------------------------------------

public int IsHunter(mixed e) {
  return (member(pHunters, stringp(e)?e:to_string(e))>-1);
}

public int IsEnemy(mixed e) {
  return (member(pEnemies, e)>-1);
}

public IsAttackingMe(object ob) {return living(ob)?ob->IsEnemy(TO):0;}

// [Nyh] Devuelve 1 si estoy en combate, es decir, si tengo enemigos o si
//       alguien de la habitacion me tiene como enemigo.
public int Fighting() {
  return (   sizeof(QueryEnemies())
          || (   environment()
              && sizeof(filter(all_inventory(environment()),SF(IsAttackingMe)))
             )
         );
}

public void StartHunting(object e) {
  if (RemoveEnemy(e) && e) {
     AddHunter(e);
// Comentada hasta que se me ocurra algo mejor.
     tell_object(e, ""+capitalize(QueryName()||"alguien")+" se ha quedado con tu cara.\n");
  }
}

public void StopHunting(mixed e) {
  object eobj;
  int    nrhb;

  if (stringp(e)) e = find_object(e);

  // HBSTAT
  if (query_once_interactive(TO) && e &&
		m_contains(&nrhb, &eobj, hbstat, to_string(e)) && nrhb)
	 {
#ifdef HBLOG
		write_file("/log/HBSTAT",
		 sprintf("%O %d: dejó de perseguir a %O %d: %d hbs\n",
			 TO, hbstat_level(TO), e, hbstat_level(e), nrhb));
#endif
		m_delete(hbstat, to_string(e));
	 }
  RemoveEnemy(e);
  RemoveHunter(e);
}
//fin nuevas funciones

// Un pelín más sofsticada que la antigua...
public void StopAttack()
  { filter(({ }) + QueryEnemies() + QueryHunters(), SF(StopHunting));}

// Mucho más sencilla
public void StopAllHunting() {
  object *obs;

  obs = ({ }) + QueryEnemies() + map(QueryHunters(),SF(find_object)) - ({0});

  filter(obs,"StopHunting");
  filter_objects(obs,"StopHunting",TO);
}

// -----------------------------------------------------------------------------
// Commands
// -----------------------------------------------------------------------------
public int stop_attack_mode(string arg) {
  filter(QueryEnemies()||({}),"StopHunting");
  write("¡OK.\n");
  return 1;
}
public int stop_hunting_mode(string arg) {
  StopAttack();
  write("OK.\n");
  return 1;
}
// -----------------------------------------------------------------------------
// Fin Commands
// -----------------------------------------------------------------------------
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


private int IsNotLigera(object ob)
  { return (member(LIGHT_WEAPONS,ob)<0); }
private int Consciente(object ob)
  { return !(ob->QueryCombatDelay() || ob->QueryDisabled() || ob->QueryParalyzed()); }
private int Molesto(object ob, int l)
  { return Consciente(ob)&&((QueryLevel()-ob->QueryLevel())<5);}

private object GetEnemyFrom(object *e) {
  object en;

  do {
    if (!sizeof(e)
     && !sizeof(e=filter(QueryEnemies(),SF(Molesto)))
     && !sizeof(e=filter(QueryEnemies(),SF(Consciente)))
     && !sizeof(e=QueryEnemies()) )
      return 0;
    en=e[random(sizeof(e))];
    if (!en || en->QueryHP() < 0 ) {
      StopHunting(en);
      e-=({en});
      en=0;
    }
    else if (!present(en) && (en!=environment())) {
      StartHunting(en);
      e-=({en});
      en=0;
    }
  }
  while (!en);
  return en;
}

/* Attack
 *
 * Make an attack, distinguish between magical attack and normal
 * weapon attack. */
public void Attack() {
  int i,j;
  object en;

#ifdef DEBUG_NOPEGO
  if (find_object("nyh")) dtell("nyh",sprintf("\t\tSI!!\n"));
#endif

  if (!(en=QueryEnemy())) return; //si no pillo enemigo no puedo atacar...
  // Perhaps do attack chatting
//  if (find_object("nyh")) dtell("nyh",sprintf("Check antes DoAttackChat\n"));
  if (!interactive(TO) && Query(P_ACHAT_CHANCE)) TO->DoAttackChat( en );
//  if (find_object("nyh")) dtell("nyh",sprintf("Check después DoAttackChat\n"));
#ifdef DEBUG_NOPEGO
  if (find_object("nyh")) dtell("nyh",sprintf("\tEnemigo: %O\n",en));
#endif
//resto ya lo chekeo en el heart_beat... pero por si acaso
//  if (!en || en->QueryHP() < 0 ) return StopHunting(en),0;
//  if (!present(en) && (en!=environment())) return StartHunting(en),0;
//...
  if (Query(COMBATACTION_FINTAR)) {
    if (en) command(HAB_ACUCHILLAR+" a "+en->QueryName());
    return;
  }

  if (i=sizeof(pWeapons)) {
    int bonus=0;
//  if (find_object("nyh")) dtell("nyh",sprintf("\tsizeof(pWeapons)\n"));
    if (i==1) COMBATMASTER->Attack(TO, en, pWeapons[0], bonus);
    else {
      int k=0;
      bonus-=10; //malus "per se" de ir a dos armas
      bonus-=(sizeof(filter(pWeapons, SF(IsNotLigera )))>1)?10:0;
      k=UseSkill(HAB_XARMAS)>0;
      COMBATMASTER->Attack(TO, QueryEnemy(), pWeapons[0], bonus-(k?0:10) );
      for (j=1;j<i;j++) COMBATMASTER->Attack(TO, QueryEnemy(), pWeapons[j], bonus-(k?0:30) );
    }
    if (i=sizeof(pHands)) {
      int k=0;
//    if (find_object("nyh")) dtell("nyh",sprintf("\t\tsizeof(pHands)\n"));
      for (j=i;j--;) {
     	if (intp(pHands[j][HAND_WEAPON]) && (pHands[j][HAND_WEAPON])>0 )
      	  COMBATMASTER->Attack(TO, QueryEnemy(), j, bonus-((k++)?0:((UseSkill(HAB_NATURAL)>0)?10:25)));
      	    // el 10 de si falla HAB_NATURAL es por ser ataques secundarios
      }
    }
  }
  else if (i=sizeof(pHands)) {
    int k=0;
//  if (find_object("nyh")) dtell("nyh",sprintf("\tsizeof(pHands)=%O\n",i));
    for (j=i;j--;) { //recorro al reves, q es como estan, y filtro las izquierdas...
//  if (find_object("nyh")) dtell("nyh",sprintf("\t\tmano%i: %O\n",j,pHands[j]));
      if (strstr(pHands[j][HAND_SHORT]," izquierda")!=-1 ) continue;
      if (!intp(pHands[j][HAND_WEAPON])) {
#ifdef DEBUG_ELE
      	if (find_object("nyh")) dtell("nyh",sprintf("[%O] Error, si que empuñaba un arma.\n\tpHands = %O\n\tj = %O\n",ctime(),pHands,j));
      	write_file("/log/combat/dam_type.log",sprintf("[%O] Error, si que empuñaba un arma.\n\tpHands = %O\n\tj = %O\n",ctime(),pHands,j));
#endif
      	continue;
      }
      COMBATMASTER->Attack(TO, QueryEnemy(), j, -((k++)?0:((UseSkill(HAB_NATURAL)>0)?0:25)));
        // aqui si falla HAB_NATURAL es 0 porq es ataque primario (no hay armas empuñadas)
    }
  }
//if (find_object("nyh")) dtell("nyh",sprintf("\tFin\n"));

//lo viejo:
  // Scan all pWeapons and free 'hands'
//  for (i = sizeof(pWeapons); i--;) if (w = pWeapons[i]) COMBATMASTER->Attack(w);
//  for (i = sizeof(pHands);   i--;) if (!objectp(pHands[i][HAND_WEAPON])) COMBATMASTER->Attack(i);
}

private int FeintModifier() {
  int mod=0, tmp=0;
  object *ene;

  mod = QueryGuildLevel();
  ene = QueryEnemies();

  foreach (object en:ene) {
    mod -= (en->QueryGuildLevel()*(GUILD_COMBAT[en->QueryGuild()]||COMBATE_REGULAR))/COMBATE_MAX;
    tmp -= en->QueryInt()+en->QueryLevel();
  }
  mod += UseSkill(HAB_ENGANYAR, QueryInt()+QueryLevel()-tmp);

  return mod;
}

//Fintar
public void Feint() {
    int i;
    i = FeintModifier();
    if (UseSkill(HAB_FINTAR, i)>0) {
        if (UseSkill(HAB_FINTA_MEJORADA, i)>0) {
            TO->catch_msg("¡Realizas una finta mejorada!\n");
            tell_room(environment(),"¡"+capitalize(TO->QueryName())+" realiza una finta mejorada!\n",({TO}));
            Set(COMBATACTION_FINTAR, 1);
            call_other(TO, COMBATACTION_ATTACK);
        }
        else {
            TO->catch_msg("¡Realizas una finta!\n");
            tell_room(environment(),"¡"+capitalize(TO->QueryName())+" realiza una finta!\n",({TO}));
            Set(COMBATACTION_FINTAR, 1);
        }
    }
    else {
      TO->catch_msg("Tu intento de realizar una finta ha fallado.\n");
    }
}

/*
 * combat heart beat. This is called from the main heart_beat.
 * Since combat and spell casting are mutual exclusive, we also
 * deal with the latter here.
 * We call the Attack() function if there is a reason to attack
 * someone. There are several reasons:
 * - I'm currently attacked by someone.
 */
void heart_beat() {
  int i;
  object *arr;

  if (!CheckHeart(HEART_COMBAT)) return;

  //Chekeo a los enemigos
  if (sizeof(arr=QueryEnemies())) {
    foreach (object en:arr) {
      if (!en || en->QueryHP() < 0 ) StopHunting(en);
      if (!present(en) && (en!=environment())) StartHunting(en);
    }
  }

  // No reason to continue doing heart beats because of combat
  if (!(sizeof(QueryEnemies()) || QueryCombatDelay() || QueryDisabled() || QueryStunned() || QueryParalyzed())) {
    DropHeart(HEART_COMBAT);
    return;
  }

  if (QueryCombatDelay()) {
    if (QueryCombatDelayMsg()) write(QueryCombatDelayMsg());
    SetCombatDelay(QueryCombatDelay()-1);
    return;
  }

  if (   QueryParalyzed()
      || QueryStunned()
      || QueryStatusResting()
      || QueryStatusSleeping())
  {
    return;
  }

  call_other(TO, GetNextCombatAction());

  return;
}

#define CHECK_MULT	-4
public int UsePhisicalDefensiveSkills(int dam) {
  if (QueryStunned() || (dam<1)) return (dam>0);
#ifdef DEBUG_DEFENSIVE_SKILLS
  write_file("/log/combat/defsk.log",sprintf("[%O] [%O]%O->UsePhisicalDefensiveSkills(%O)\n",ctime(),TO->QueryGuildLevel(),QueryName(),dam));
#endif

//  dtell("nyh",sprintf("%O->UsePhisicalDefensiveSkills(%O)\tDificultades: Esquiva = %O\tTaichi = %O\t"
//       , TO, dam, CHECK_MULT*dam - QueryLoad(), CHECK_MULT*dam));
  if (UseSkill(HAB_ESQUIVAR, CHECK_MULT*dam - QueryLoad())>0)
  {
    return ATK_ESQUIVADO;
  }

//  foreach (object ob:pWeapons)
  if (sizeof(pWeapons)) // Solo se usa una vez si tiene una o mas armas
  {
//    dtell("nyh",sprintf("Parada = %O\t", CHECK_MULT*dam));
    if (/*ob &&*/ UseSkill(HAB_PARADA, CHECK_MULT*dam)>0) return ATK_PARADO;
  }

  foreach (object ob:pShields) // Se usa una vez por escudo
  {
//    dtell("nyh",sprintf("Escudo = %O\t", CHECK_MULT*dam+ob->QueryAC()*5));
    if (ob && UseSkill(HAB_ESCUDO, CHECK_MULT*dam+ob->QueryAC()*5)>0) return ATK_BLOQUEADO;
  }
  if (!(sizeof(QueryWeapons()) && sizeof(QueryShields())) && UseSkill(HAB_TAICHI, CHECK_MULT*dam)>0)
  {
    return ATK_TAICHI;
  }

  return (dam>0);
}

//aun no implementada
public int UseMagicalDefensiveSkills(int diff) {
  return (diff>0);
}

// Esto formaba parte de Defend()
//Nota: si pasas damage por referencia devuelve el daño tras la reduccion
//	aunke mejor no usar...
public varargs int CalcArmourClass(int damage, int type, object atk, mixed flags, mixed *xtras) {
  int i, orgdam, defence, def;
  mixed *xtra;

  orgdam = damage = (damage>0?damage:0); // Daño causado inicialmente.
  def = defence = 0; // Defensa final contra el ataque.

//primera reduccion de daño, por esquivas y demas...
  if (def >= damage) return damage=0,orgdam;
  else damage = orgdam-def;

  /*  Comprobación de todas las armaduras que llevo puestas ahora  */
  //xtras = ({});
  if (member(pArmours,0)!=-1) pArmours -= ({0});
  foreach (object a: pArmours) {

//Nyh: parche temporal para que no use el esquivar del gremio
    if (a->QueryGuildObject()) continue;
// fin parche temporal

    xtra = a->Defend(atk, damage, type);
    if (pointerp(xtra)) {
      defence = xtra[0];
      if (sizeof(xtra)>1) xtras = (xtras||({})) + xtra[1..];
    }
    else defence = (int)xtra;
    def += defence;
    a->DegradeArmour( (["TOTAL": ( defence>0?1+random(defence) : 0 ) ]), ([]), flags, 100, 0 );
  }
//segunda reduccion de daño, por armaduras y demas...
  if (def >= damage) return damage=0,orgdam;
  else damage = orgdam-def;

//Mi defensa intrinseca
  def += QueryDefence(type);
//ultima reduccion de daño, por mi mismo...
  if (def >= damage) return damage=0,orgdam;
  else damage=orgdam-def;

  return def; //def=AC_TOTAL
}

/**
 * public varargs int CalcAtkHitBonus(object def, mixed weapon)
 *
 * @param def object (opcional): Objeto defensor
 * @param weapon object/int (opcional): Arma del atacante
 *
 * @return Devuelve el bono de defensa de def frente a un ataque de atk con weapon
 */
public varargs int CalcAtkHitBonus(object def, mixed weapon) {
  int atk_bonus = 0;
  string wt;

  wt = objectp(weapon) ? weapon->QueryWeaponType() : WT_HAND;

  // Modificadores por estado

  // Modificadores por nivel
  atk_bonus += COMBAT_GUILD_BONUS(QueryGuildLevel(), GUILD_COMBAT[QueryGuild()]);

  // Modificadores por caracteristicas
  atk_bonus += (member(LIGHT_WEAPONS, wt) == -1)? QueryDex() : QueryStr();

  // Modificadores por habilidades
  atk_bonus += ((UseSkill(HAB_EXPERTISE   ) > 0) ? BONUS_EXPERTISE : 0);
  atk_bonus += ((UseSkill(HAB_GUERRERO    ) > 0) ? BONUS_GUERRERO  : 0);

  atk_bonus += ((UseSkill(COMBAT_SKILL[wt]) < 1) ? MALUS_NO_SKILL  : 0);

  // Modificadores por conjuros
  // [Nyh] Muevo la chapuza de la sombra de kastwey aqui
  if (TO->HasSpell("sombra"))
  {
    object sombra;
    if (   (sombra = present("sombra_" + NREAL(TO), environment()))
        &&  sombra->QueryOwner() == TO )
    {
      atk_bonus += 10;
    }
  }

  // Modificadores por tamaño
  atk_bonus += TAM_BONUS[QuerySize()];

  return atk_bonus;
}

/**
 * public varargs int CalcDefHitBonus(object atk, mixed weapon)
 *
 * @param atk object (opcional): Objeto atacante
 * @param weapon object/int (opcional): Arma del atacante
 *
 * @return Devuelve el bono de defensa de def frente a un ataque de atk con weapon
 */
public varargs int CalcDefHitBonus(object atk, mixed weapon) {
  int def_bonus = 0;

  // Modificadores por estado
  def_bonus += QueryStatusHelpless()?DEFENDER_HELPLESS:0;
  def_bonus += QueryStatusTripped()? DEFENDER_PRONE:   0;
  def_bonus += QueryStunned()?       DEFENDER_STUNNED: 0;
  def_bonus += Query(P_BLIND)?       DEFENDER_BLINDED: 0;

  // Modificadores por nivel
  def_bonus += COMBAT_GUILD_BONUS(QueryGuildLevel(), COMBATE_MALO);

  // Modificadores por caracteristicas
  def_bonus += CanSeeObject(atk) ? QueryDex() : 0; // Solo aplico destreza si veo el ataque

  // Modificadores por habilidades
  def_bonus += ((UseSkill(HAB_REFLEXES    ) > 0) ? BONUS_REFLEXES  : 0);

  // Modificaciones por armaduras
  def_bonus += sum( map_objects(pArmours, "QueryAC") );

  // Modificadores por tamaño
  def_bonus += TAM_BONUS[QuerySize()];

  return def_bonus;
}

// Función útil para quitar código a Defend()
public varargs void attack_log(object atk, object def, string verb, string comment, string where) {
/* //Me lo penco hasta que lo adapte al combatmaster
  string mylevel,myname,klevel,kname;
  int i;

  if (!where) where = "/log/KILLER";
  else where = "/log/"+where;
  if (!def) def = TO;
  if (!atk) atk = TP;
  if (!verb) verb = "atacó a";
  if (!comment) comment = query_verb()?" por '"+query_verb()+"'":"";
  else if (strlen(comment) && comment[0]!=' ') comment = " "+comment;
  if (environment() && environment()->QueryKillZone()) comment += " (LEGAL)";
  if (  !interactive(def)	|| !atk || !interactive(atk) || atk == def || (IS_LEARNER(atk) && IS_LEARNER(def))) return;
  if (i = query_wiz_level(def)) mylevel = "w"+i;
  else mylevel = def->QueryLevel()+"/"+(xp2level(def->QueryXP()));
  myname = def->QueryRealName()||def->QueryName()||def->QueryShort()||"<invis>";
//  if ("/obj/testylib"->CheckTesty(def)) myname = "testy "+myname;
  kname = atk->QueryRealName()||atk->QueryName()|| atk->QueryShort()||"<invis>";
//  if ("/obj/testylib"->CheckTesty(atk)) kname = "testy "+kname;
  if (i = query_wiz_level(atk)) klevel = "w"+i;
  else klevel = atk->QueryLevel()+"/"+(xp2level(atk->QueryXP()));
  write_file(where,sprintf("%s %s(%s) %s %s(%s)%s\n",ctime(),kname,klevel,verb,myname,mylevel,comment));
*/
}

// -----------------------------------------------------------------------------
public varargs int Defend(int dam, int dam_type, mixed flags, string *xtras) {
  object atk, sombra;
  mixed ac;
  int i,chance,orgdam, res;

  orgdam=dam;

  GetHeart(HEART_COMBAT);
  atk = TP || PO;

  if (!intp(flags)) flags=0;
// [h] la siguiente linea es un parche "anti Woo"
  if (flags==1000) { //esto es culpa de la mania de Woo...
    if (PO->QuerySpellName()) flags = DEFEND_SPELL;
    else flags = DEFEND_NOMSG;
  }

//[h] el hbstat...
  if (!(flags&DEFEND_NOLIV)) { //es un hostion contra algo que vive
    if ( AddEnemy(atk) ) { /* HBSTAT */
      if ( query_once_interactive(TO) && !m_contains(&res, &ac, QueryHBStat(), to_string(atk)) )
        AddHBStat(atk);
#ifdef LOG_KILLS
      attack_log();
#endif
    }
  }
//linea debug, a veces da error de arguments don't match en el >=
if (!intp(dam_type)) write_file("/log/combat/dam_type.log",sprintf("[%O]\n\tTO: %O\n\tPO: %O\n\tDefend(%O, %O, %O, %O)\n",ctime(),TO,PO,dam, dam_type, flags, xtras));

  // [kastwey] Chapuzas por aquí, chapuzas por allá. Pongo una línea para que, si el player tiene
  // sombra (conjuro de kisalas), tenga más posibilidades de esquibar. Como esto hay
  // que reescribirlo tampoco me como mucho la cabeza enbuscar algo menos cutre que meterlo aquí
  // a machete. (si alguien lo ve y tiene ganas de colgarme, que lo cambie él :P).
  // [Nyh] kast, te colgare! menuda puta chapuza todo lo de la sombra...
  if (   (!(flags & DEFEND_F_NOLIV)) && QueryGuild() == GC_KISALA && TO->HasSpell("sombra")
      && (sombra = present("sombra_" + NREAL(TO)))
      && sombra->QueryOwner() == TO && d20() > 10)
  {
      res = ATK_ESQUIVADO;
  }

//[h] las habilidades de defensa
  else if (!(flags&DEFEND_NO_DEF_SK)) { //si uso habilidades de defensa
    if      (dam_type>=TD_MAGICO) res = UseMagicalDefensiveSkills(dam);
    else if (dam_type>=TD_NORMAL) res = UsePhisicalDefensiveSkills(dam);
    else res = dam>0;
  }
  else res = dam>0;
// [h] la armadura
  if (!(flags&DEFEND_NO_AC)) { //si uso la armadura
    ac = CalcArmourClass(dam, dam_type, atk, flags, &xtras);
    if (find_object("nyh") && find_object("nyh")->Query("DebugDefend"))
      dtell("nyh",sprintf("%O->CalcArmourClass(%O, %O, %O, %O) = %O\n"
           , TO, dam, dam_type, atk, flags, ac));
    if ((dam-=ac)<1 && dam_type>=DT_INTR && dam_type<=DT_CONV) dam = 1;
  }
//[h] el hacer pupitaaarrrrr
  if (res>ATK_FALLO) {
    dam=DoDamage(dam,dam_type,0,&xtras); //el 0 es el gentle...
    if (dam==0) res=ATK_RESISTO;
    else if (dam<0) { res=ATK_CURO; dam=0;}
  }
  else dam=0;

//[h] mandar los mensajes
  if (!(flags&DEFEND_NOMSG)) { //si que mando mensajes
    if (flags&DEFEND_SPELL) { //un conjuro!!
      COMBATMASTER->DoCombatMessage(atk, TO,
        ({dam_type, (PO->QuerySpellName())||"magia" }),
         dam, COMBATMESSAGE_SPELL);
    }
    else { //pues no es magia... es normal por codear
      TO->catch_msg("Posible error, dile a Nyh que ha pasado.\n");
      tell_object(atk,"Posible error, dile a Nyh que ha pasado.\n");
    }
  }

  ac = environment();
  if (environment() != ac && !(flags&DEFEND_NOLIV) && atk != TO)
    RemoveEnemy(atk);
  return dam||res; //positivo daño, negativo fallo
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// -----------------------------------------------------------------------------
// Upwards compatibility
// -----------------------------------------------------------------------------

protected int AddWeapon(object ob) {
  //dtell("nyh",sprintf("%O->AddWeapon(%O)\n", TO, ob));
  if (!pWeapons) pWeapons = ({});
#if __VERSION__ >= "3.3"
  pWeapons |= ({ ob });
#else
  pWeapons -= ({ ob });
  pWeapons += ({ ob });
#endif
  return 1;
}

protected int RemoveWeapon(object ob, int flags) {
  //dtell("nyh",sprintf("%O->RemoveWeapon(%O, %O)\n", TO, ob, flags));
  pWeapons -= ({ ob });
  return 1;
}

private int AddShield(object ob) {
  //dtell("nyh",sprintf("%O->AddShield(%O)\n", TO, ob));
  if (!pShields) pShields = ({});
#if __VERSION__ >= "3.3"
  pShields |= ({ ob });
#else
  pShields -= ({ ob });
  pShields += ({ ob });
#endif
  return 1;
}

protected int AddArmour(object ob) {
  int at;
  string sh;
  //dtell("nyh",sprintf("%O->AddArmour(%O)\n", TO, ob));

  if (!pArmours) pArmours = ({});
  if ( (at=ob->QueryArmourType())==AT_ESCUDO ) AddShield(ob);
  else
    foreach (object obj: pArmours)
      if (obj && obj->QueryArmourType()==at && (sh=obj->Short()) && sizeof(sh))
	      return write("Ya llevas "+sh+".\n"),0;
#if __VERSION__ >= "3.3"
  pArmours |= ({ ob });
#else
  pArmours -= ({ ob });
  pArmours += ({ ob });
#endif
  return 1;
}

protected int RemoveArmour(object ob, int flags) {
  //dtell("nyh",sprintf("%O->RemoveArmour(%O, %O)\n", TO, ob, flags));
  if (member(pArmours, ob)>=0) {
    if ( ob->QueryArmourType()==AT_ESCUDO ) pShields -= ({ ob });
    pArmours -= ({ob});
  }
  return 1;
}

protected void Ungrip(object ob) {
  int i;

  //dtell("nyh",sprintf("%O->Ungrip(%O)\n", TO, ob));
  for (i = sizeof(pHands); i-- ;)
	 if (pHands[i][HAND_WEAPON] == ob) pHands[i][HAND_WEAPON] = 0;
}

protected int Grip(object ob) {
  int i, h, free;
  //dtell("nyh",sprintf("%O->Grip(%O)\n", TO, ob));

  free=0;
  for (i = sizeof(pHands); i-- ;)
	 if (!pHands[i][HAND_WEAPON]) free++;
	 else if (ob == pHands[i][HAND_WEAPON]) return 1;

  if ((h = ob->QueryNumberHands()) < 1) h = 0;

  free=0;
  for ( i = sizeof(pHands); i--;)
	 if (!pHands[i][HAND_WEAPON]) free++;

  if (h > free) return 0;

  for (i = 0; i < sizeof(pHands) && h; i++)
	 if (!pHands[i][HAND_WEAPON]) {
		pHands[i][HAND_WEAPON] = ob;
		h--;
	 }
  return 1;
}
// -----------------------------------------------------------------------------
// Fin Upwards compatibility
// -----------------------------------------------------------------------------

