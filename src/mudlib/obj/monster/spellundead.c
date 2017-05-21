/* SIMAURIA '/std/monster/spellundead.c'
   ======================================
   [Al] Alura@simauria

   15-05-2001 Creacion para el undead
   18-05-2001 Modificacion pa q funcionen los VICMSG y demas
*/

#include <spellmonster.h>
#include <combat.h>
#include <magia.h>
#include <living.h>
#include <messages.h>

#define CASTER "/obj/caster"

private static mapping Pspells,
                       delayed, // ([id:hbs to wait])
                       chances; // ([id:chance]) a list of all chances
private static int Pcastchance; // the chance that the monster casts
                               // a spell at all
private static object *victims; // Current victims of the spell.

inherit "/std/undead";

/*
** =========================================
** Setting and Querying the actual victim(s)
** =========================================
*/

// FUNCTION: SetVictims
// PROPERTY: P_VICTIMS
// SYNTAX: void SetVictims(object *o)
// DISTRIBUTION: public
// DESCRIPTION:
//   Sets a list of victims which are attacked in the current round.
//   It is used for example to evaluate the description for the enemies
//   for printing out the combat-messages.
//
//   By default SetVictims() is called only in CastSpell():
//   \begin{itemize}
//     \item after all costs of the spell got calculated and before
//           all messages are evaluated. First function called after
//           SetVictims() is get_damage() which will run over all
//           victims.
//
//           This is the value set for the global environment-message.
//     \item in a loop over all victims. In this loop always only one
//           victim is in the array, which is the one who will receive
//           the damage.
//
//           This is the value true for the environment-message.
//     \item after all damage is dealt and all messages got printed, i. e.
//           at the end of CastSpell(), the victims will be set to 0.
//   \end{itemize}
//
//   It is always ensured, that only objects are in the array. Wrong settings
//   will be deleted from the array.
// SEE ALSO:
//   QueryVictims, CastSpell

public void SetVictims(object *o)
{
  if (!pointerp(o)) victims = 0;
  else victims = filter(o,SF(objectp));
}

// FUNCTION: QueryVictims
// PROPERTY: P_VICTIMS
// SYNTAX: object *QueryVictims()
// DISTRIBUTION: public
// DESCRIPTION:
//   Returns the currently set victims. It is ensured that an array is returned
//   and that all elements of the array are objects.
// SEE ALSO:
//   SetVictims

public object *QueryVictims()
{
  return filter(victims||({}),SF(objectp));
}

/*
** ============================
** Functions for process_string
** ============================
*/

// FUNCTION: build_list
// SYNTAX: string build_list(string *strs)
// DISTRIBUTION: protected
// DESCRIPTION:
//   The array of strings will be put into an enumeration (without sorting
//   them. If <strs> is empty an empty string will be returned.
// EXAMPLE:
//   \begin{code}
//     build_list(({"a","c","b"}))
//   \end{code}
//   The returned value is:
//   \begin{code}
//     "a, c and b"
//   \end{code}

protected string build_list(string *strs)
{
  if (!sizeof(strs))
    return "";
  return sizeof(strs)==1?strs[<1]:implode(strs[0..<2],", ")+" y "+strs[<1];
}

public varargs string MyName(string cap)
     // Return the name of the spellmonster.
     // If called with @@MyName|1@@ the name will be
     // inserted capitalized.
     // Example: Harry
{
  string res;
  res = QueryName()||QueryShort()||"someone";
  return cap?capitalize(res):res;
}

public varargs string MyPronoun(string cap)
     // Return the pronoun of the spellmonster.
     // If called with @@MyPronoun|1@@ the pronoun will be
     // inserted capitalized.
     // Example: He
{
  return cap?capitalize(QueryPronoun()||"el"):QueryPronoun();
}

public varargs string MyPossessive(string cap)
     // Return the possessive pronoun of the spellmonster.
     // If called with @@MyPossessive|1@@ the poss. pron. will be
     // inserted capitalized.
     // Example: His
{
  return cap?capitalize(QueryPossessive()||"su"):QueryPossessive();
}

public varargs string MyObjective(string cap)
     // Return the objective pronoun of the spellmonster.
     // If called with @@MyObjective|1@@ the obj. pron. will be
     // inserted capitalized.
     // Example: Him
{
  return cap?capitalize(QueryObjective()||"lo"):QueryObjective();
}

public varargs string VicName(string cap)
     // Return the name(s) of the victim(s) the spellmonster
     // is currently attacking. Before the spell is cast this
     // will return all names of all victims in a list.
     // During the actual spell, only one victim per time
     // is parsed through VicName.
     // If called with @@VicName|1@@ the name(s) will be
     // inserted capitalized.
     // Example 1: Thragor
     // Example 2: Thragor, Cadra and Tnt
{
  string *names;
  object *vics;
  string res;

  vics = QueryVictims();
  names = (map_objects(vics,"QueryName") - ({0}));
  if (!sizeof(names))
    names = ({"noone"});
  res = build_list(names);
  return cap?capitalize(res):res;
}

public varargs string VicPronoun(string cap)
     // Return the pronoun of the victim(s), i. e. if there's
     // more than one victim, 'they' is returned.
     // Other rules same as with VicName.
{
  string res;
  object *vics;

  if (sizeof(vics = QueryVictims())>1)
    res = "ellos";
  else
    res = vics[<1]->QueryPronoun()||"el";
  return cap?capitalize(res):res;
}

public varargs string VicPossessive(string cap)
     // Return the possessive pronoun of the victim(s), i. e. if there's
     // more than one victim, 'their' is returned.
     // Other rules same as with VicName.
{
  string res;
  object *vics;

  res = "su";
  return cap?capitalize(res):res;
}

public varargs string VicObjective(string cap)
     // Return the objtive pronoun of the victim(s), i. e. if there's
     // more than one victim, 'their' is returned.
     // Other rules same as with VicName.
{
  string res;
  object *vics;

  if (sizeof(vics = QueryVictims())>1)
    res = "los";
  else
    res = vics[<1]->QueryObjective()||"lo";
  return cap?capitalize(res):res;
}

public varargs string VicS(string verb,string cap)
     // Get the right ending of a verb depending on the amount of
     // victims. You should give the plural-form of the verb here.
{
  string res;
  if (!verb) return "";
  switch(verb)
    {
    case "is":
    case "are":
      res = sizeof(QueryVictims())==1?"is":"are";
      break;
    case "was":
    case "were":
      res = sizeof(QueryVictims())==1?"was":"were";
      break;
    default:
      res = sizeof(QueryVictims())==1
	?verb+(member(({'z','x','s'}),verb[<1])!=-1?"es":"s")
	:verb;
    }
  return cap?capitalize(res):res;
}

protected string parse_string(string str)
{
  string res;
  if (str=="") return "";
  res = process_string(str);
  res = "  "+W(res);
  if (res[<1]!='\n') res+="\n";
  return res;
}

/*
** ==========
** The Spells
** ==========
*/

public mapping SetSpells(mapping m)
{
  mixed *idx;
  int i;

  if (mappingp(m))
    {
      i = sizeof(idx = m_indices(m));
      chances = ([]);
      while(i--)
	chances[idx[i]] = (m[idx[i]][S_CHANCE] = m[idx[i]][S_CHANCE]||1);
    }
  return Pspells = m;
}

public mapping QuerySpells()
{
  return (Pspells||([]))+([]);
}

protected int get_free_id()
     // Automatically get the first free id (if the id was not specified
     // in the monster.
{
  int *idx;
  idx = filter(m_indices(QuerySpells()),SF(intp));
  if (!sizeof(idx)) return 0;
  return NMB->max(idx)+1;
}

/*
** AddSpell(id,mindam,maxdam) minimal configuration
** AddSpell(([....])) choose own id
** AddSpell(id,([....]))
** If no VICMSG is given, it will be genererated automatically,
** as the victim has to be informed.
*/

public varargs mapping AddSpell(mixed id_or_properties,
				mixed chance_or_properties,
				int mindam,int maxdam)
{
  mapping spells,props;
  mixed id;
  if (mappingp(id_or_properties))
    {
      id = get_free_id();
      props = id_or_properties;
    }
  else if (mappingp(chance_or_properties))
    {
      id = id_or_properties;
      props = chance_or_properties;
    }
  else
    {
      id = id_or_properties;
      props = ([]);
      props[S_MINDAM] = mindam;
      props[S_MAXDAM] = maxdam;
    }
  if (!props[S_VICMSG]&&props[S_MAXDAM])
    props[S_VICMSG] =
      ([
	MSG_NORMAL:({"@@MyName|1@@ te lanza un "+id+".\n",
	           "Alguien te lanza un "+id+".\n"}),
	MSG_DEAD:""
       ]);
  spells = QuerySpells();
  spells[id] = props;
  return SetSpells(spells);
}

/*
** ====================================
** Settings for the spell step by step.
** ====================================
*/

public void SetSpellChance(mixed id,int c)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_CHANCE] = c;
  SetSpells(spells);
}

public void SetSpellCombatDelay(mixed id,int i)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_COMBAT_DELAY] = i;
  SetSpells(spells);
}

public void SetSpellSimult(mixed id,status i)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_SIMULT] = i;
  SetSpells(spells);
}

public void SetSpellEnvMsg(mixed id,mapping msg)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_ENVMSG] = msg;
  SetSpells(spells);
}

public void SetSpellVicMsg(mixed id,mapping msg)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_VICMSG] = msg;
  SetSpells(spells);
}

public void SetSpellDelay(mixed id,int i)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_DELAY] = i;
  SetSpells(spells);
}

public void SetSpellVictims(mixed id,int i)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_VICTIMS] = i;
  SetSpells(spells);
}

public void SetSpellDamType(mixed id,int i)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_DAMTYPE] = i;
  SetSpells(spells);
}

public void SetSpellCheck(mixed id,closure f)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_CHECKFUN] = f;
  SetSpells(spells);
}

public void SetSpellFun(mixed id,closure f)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_FUN] = f;
  SetSpells(spells);
}

public void SetSpellMinDam(mixed id,int i)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_MINDAM] = i;
  SetSpells(spells);
}

public void SetSpellMaxDam(mixed id,int i)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_MAXDAM] = i;
  SetSpells(spells);
}

public void SetSpellHP(mixed id,int i)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_HP] = i;
  SetSpells(spells);
}

public void SetSpellSP(mixed id,int i)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_SP] = i;
  SetSpells(spells);
}

/*
** =============================================
** Chance that the monster casts a spell at all.
** =============================================
*/

public int QueryCastChance()
{
  return Pcastchance||20;
}

public int SetCastChance(int i)
{
  return Pcastchance = i;
}

/*
** ======================
** Casting of the monster
** ======================
*/

protected status check_cast(mixed id)
{
  mapping sp;
  delayed = delayed||([]);
  if (!member(delayed,id))
    {
      sp = QuerySpells()[id];
      if (sp[S_SP] && (QuerySP()-sp[S_SP]<0)) return 0;
      if (sp[S_HP] && (QueryHP()-sp[S_HP]<QueryWhimpy(1))) return 0;
      if (closurep(sp[S_CHECKFUN]))
	return funcall(sp[S_CHECKFUN]);
      return 1;
    }
  delayed[id]--;
  if (delayed[id]<1) m_delete(delayed,id);
  return 0;
}

protected mixed get_spell()
     // Return the spell, which will be cast.
{
  mapping sp;
  mixed *idx,res,false;
  int i,sum,select;
  idx = m_indices(chances||([]));
  i = sizeof(idx = filter(idx,SF(check_cast)));
  sp = QuerySpells();
  sum = 0;
  while(i--) sum+=sp[idx[i]][S_CHANCE]||1;
  select = random(sum)+1;
  sum = 0;
  false = get_free_id();
  res = false;
  i = sizeof(idx);
  while(i--&&res==false)
    {
      sum+=sp[idx[i]][S_CHANCE]||1;
      if (sum>=select) res = idx[i];
    }
  return res;
}

protected int get_damage(object victim,int mindam,int maxdam)
{
  return mindam+random(1+maxdam-mindam);
}

protected status valid_victim(object vic)
{
  return    vic
         && !vic->QueryGhost()
         && vic->QueryHP()>=0
         && vic->QueryMaxHP();
}

public varargs object *GetVictims(int nr_victims,
				  status check_repulse,
				  int damtype,
				  mixed id)
{
  object *en,*vic,*unconscious;
  closure repulse;

  en = (QueryEnemies()||({}))+({});
  vic = ({});
  if (nr_victims<0){
      en = filter(all_inventory(environment()),SF(living))-({TO});
      nr_victims = sizeof(en);
    }
  else if (!nr_victims) nr_victims = 1;
  en = filter(en,SF(valid_victim));
  unconscious= filter_objects(en,"QueryCombatDelay");
  while(nr_victims--&&(sizeof(en)||sizeof(unconscious))) {
      if (sizeof(en)){
	  vic+=({en[random(sizeof(en))]});
	  en-=vic;
	}
      else {
	  vic+=({unconscious[random(sizeof(unconscious))]});
	  unconscious-=vic;
	}
  }
  return vic;
}

public status CastSpell(mixed id)
{
  mapping sp;
  object *vic,env;
  int i,*dam;
  mixed msg,premsg1,premsg2;
  mixed func;

  if (!env = environment()) return 0;
  sp = (mapping) copy(QuerySpells()[id]||([]));
  if (member(sp,S_FUN)) sp = apply(sp[S_FUN],sp,&vic);
  if (!sp || !mappingp(sp)) return 0;
//  if (find_object("nyh")) dtell("nyh",sprintf("vic = %O\n",vic));
  if (!vic || !sizeof(vic)) vic = GetVictims(sp[S_VICTIMS],1,sp[S_DAMTYPE],id);
//  if (find_object("nyh")) dtell("nyh",sprintf("vic = %O\n",vic));
  if (!vic || !sizeof(vic)) {
    SetVictims(0);
    return 0;
  }
  else SetVictims(vic);

  SetCombatDelay(sp[S_COMBAT_DELAY],0); //el segundo parametro es el mensaje...
  delayed = delayed||([]);
  if (sp[S_DELAY]) delayed[id] = sp[S_DELAY];

  ReduceSP(sp[S_SP]);
  ReduceHP(sp[S_HP]);

  if (sp[S_MAXDAM]>sp[S_MINDAM]&&sp[S_MINDAM]>=0)
    dam = map(vic,SF(get_damage),sp[S_MINDAM],sp[S_MAXDAM]);
  if (member(sp,S_GLOBAL_ENVMSG))
    {
      if (stringp(msg = sp[S_GLOBAL_ENVMSG])) msg = ({msg,msg});
      tell_room(env,({ MSG_SEE }) + map(msg,SF(parse_string)));
    }
  i = sizeof(vic);
  while(i--)
    {
      SetVictims(({vic[i]}));
      if (member(sp,S_VICMSG)&&member(sp[S_VICMSG],MSG_NORMAL))
	{
	  if (stringp(msg = sp[S_VICMSG][MSG_NORMAL])) msg = ({msg,msg});
	  tell_object(vic[i],({ MSG_SEE }) + map(msg,SF(parse_string)));
	}
      if (member(sp,S_ENVMSG)&&member(sp[S_ENVMSG],MSG_NORMAL))
	{
	  if (stringp(msg = sp[S_ENVMSG][MSG_NORMAL])) msg = ({msg,msg});
	  tell_room(env,({ MSG_SEE }) + map(msg,SF(parse_string)),({vic[i]}));
	}
      if (member(sp,S_VICMSG)&&member(sp[S_VICMSG],MSG_DEAD))
	{
	  if (stringp(msg = sp[S_VICMSG][MSG_DEAD])) msg = ({msg,msg});
	  premsg1 = map(msg,SF(parse_string));
	}
      else
	premsg1 = 0;
      if (member(sp,S_ENVMSG)&&member(sp[S_ENVMSG],MSG_DEAD))
	{
	  if (stringp(msg = sp[S_ENVMSG][MSG_DEAD])) msg = ({msg,msg});
	  premsg2 = map(msg,SF(parse_string));
	}
      else
	premsg2 = 0;
    if (dam)
      vic[i]->Defend(dam[i],sp[S_DAMTYPE]||TM_CALOR,DEFEND_F_NOMSG);
    if (!vic[i]||vic[i]->QueryHP()<0)
	{
	  if (vic[i]&&premsg1)
	    tell_object(vic[i],({ MSG_SEE, premsg1}));
	  if (premsg2)
	    tell_object(env, ({ MSG_SEE, premsg2}));
	}
    }
  SetVictims(0);
  return member(sp,S_SIMULT)?!sp[S_SIMULT]:0;
}

public void Attack()
{
  status done;
  mixed spell;
  int check;
  done = 0;
  check = random(100)+1;
  if (   !QueryCombatDelay()
      && Pcastchance>=check
     )
    if ((spell = get_spell())!=get_free_id())
      done = CastSpell(spell);
  if (!done) (::Attack());
}

/*
** ==========
** The Create
** ==========
*/

create()
{
  ::create();
 SetCastChance(20);
  REGISTER->Register(TO,"SPELLUNDEAD");
  return 0;
}

