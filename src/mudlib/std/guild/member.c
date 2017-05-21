/**
 * SIMAURIA /std/guild/member.c
 */

#include <guild.h> // MEMBER_STAT, ....
#include <config.h> // QUESTMASTER, EXPLOREMASTER
#include <wizlevels.h> // IS_LEARNER

#define PD "/obj/player_dummy"

#define T_QP     0
#define T_XP     1
#define T_AGE    2
#define T_RACE   3
#define T_GENDER 4
#define T_LEVEL  5

#define T_SIZE   6

#define TOP_MEMBER  "member"
#define TOP_QP      "questpoints"
#define TOP_PLDATA  "playerdata"
#define TOP_FUN     "fun"
#define TOP_TODO    "todo"
#define TOP_RESULT  "result"

#define HBINT   2 // interval between two heart_beats in seconds

private mapping members; // ([string name:int time of entering;int level;
                        //   int stat])

private nosave string *creators,    // the creators of this guild
                      *Ptoplist;    // Toplist updated every reset
private static int updated; // time when toplist got last updated
public string QueryGuildclass();
public int ForbidJoin(object pl);
public int AddMember(string name, int level, int stat);
public mapping QueryMember(mixed who);



create() {
    seteuid(getuid());
    LoadGuild();
}

protected string dtime(int time)
// return the time in hours
{
  return to_string(time/(60*60));
}

public string *SetTopList(string *tl)
{
  return Ptoplist = tl;
}

public string *QueryTopList()
{
  return (Ptoplist||({}))+({});
}

public void LoadGuild()
// Carga los miembros del gremio.
{
    members = GUILDMASTER->QueryMembers(getuid());
}

/*
* Status checks of players concerning the guild
* =============================================
*/

public int is_creator(mixed who)
// return 1 if <who> is one of the creators of this guild
// -> SetCreator()
{
  if (objectp(who)) who = getuid(who);
  return member(creators||({}),lower_case(who||""))!=-1;
}

public int is_leader(mixed who)
// return 1 if <who> is one of the guildleaders of this guild
// (because this is used to check rights: the creator is a leader, too
// -> QueryGuildleader(), QueryViceGuildleader(), ChangeStat()
{
  mapping mb;
  if (!who) return 0;
  if (objectp(who)) who = getuid(who);
  if (!(mb = QueryMember(who))) return 0;
  return (mb[who,MEMBER_STAT]==G_LEADER
         ||mb[who,MEMBER_STAT]==G_VICELEADER)||is_creator(who);
}

public int is_member(mixed who)
// return 1 if <who> is a member of this guild
// the creators are automatically members of this guild
// -> AddMember()
{
  mapping mb;
  if (!who) return 0;
  if (objectp(who)) {
    if (who->QueryGuild()==QueryGuildclass() && !ForbidJoin(who)) {
    	if (!(mb = QueryMember(getuid(who)))) {
    		write("Recuperando los datos perdidos del gremio...\n");
    		AddMember(getuid(who), who->QueryGuildLevel(), G_MEMBER);
    		return 1;
    	}
    	return 1;
    }
  }
  return GUILDMASTER->IsMember(getuid(), who);
}

public int check_member(object who)
// check if <who> is a valid member of this guild
{
  if (!who) return 0;
  if (!interactive(who)) return 0;
  return is_member(getuid(who));
}

public string MemberList()
{
  int i;
  string *m,result;

  m = sort_array(m_indices(members||([])),SF(>));
  result = "Nombre      |Estado|Nivel|Última vez que estuvo en el gremio\n"
           "------------+------+-----+------------------------\n";

  for (i=0;i<sizeof(m);i++)
    result+=STR->ladjust(capitalize(m[i]),12)+"|"+
            STR->radjust(IS_LEARNER(m[i])?(is_creator(m[i])?"cr":"wiz"):
                         members[m[i],MEMBER_STAT],6)+"|"+
            STR->radjust(to_string(members[m[i],MEMBER_LEVEL]),5)+"|"+
            ctime(members[m[i],MEMBER_TIME])+"\n";
  return result;
}

/*
* TopScorelist related help-funs
* ==============================
*/

protected int compare_values(int val1,int val2)
// Return
//  -1 if both are equal
//   1 if val1<val2
//   0 if val1>val2
{
  return (val1!=val2?(val1<val2?1:0):-1);
}

public int check_greater(string n1,string n2,mapping values)
// Esta función se usa para ordenar los jugadores de la
// Lista de Veteranos comparando los stats del jugador <n1>
// con los del jugador <n2> de la siguiente forma:
// <n1> irá delante de <n2> si..
// 1.- <n1> tiene más QP, o
// 2.- <n1> tiene mas EP, o
// 3.- <n1> tiene más XP, o
// 4.- <n1> tiene más nivel, o
// 5.- <n1> tiene más edad, o
// 6.- se ordena alfabéticamente.
{
  int i;
  return ((i = compare_values(values[n1,T_QP],values[n2,T_QP]))!=-1)
    ?i
    :((i = compare_values(values[n1,T_XP],values[n2,T_XP]))!=-1)
    ?i
    :((i = compare_values(values[n1,T_AGE],values[n2,T_AGE]))!=-1)
    ?i
    :n1>n2;
}

public mixed sort_mapping(mapping to_sort,closure sort_fun)
     // Returns the sorted indizes of the mapping.
     // The sort-fun will get the two indizes to compare and the
     // mapping to_sort itself to return 1, if the first arg is
     // greater than arg 2 and else 0.
{
  mixed idx;
  idx = m_indices(to_sort);
  idx = sort_array(idx,lambda(({SYM(a1),SYM(a2)}),
			      ({sort_fun,SYM(a1),SYM(a2),to_sort})));
  return idx;
}

private void init_vals(string pl,int xp,int age,int level,
		       string race,int gender)
{
  object jug;
  mapping props;

  if (!jug=find_object(lower_case(pl)))
  {
    props = PD->QueryProperties(pl);
    xp = props[P_XP];
    age = props["Age"]*HBINT;
    race = props[P_RACE];
    gender = props[P_GENDER];
    level = props[P_LEVEL];
  }
  else
  {
    xp= jug->Query(P_XP);
    age= jug->Query("Age")*HBINT;
    race= jug->Query(P_RACE);
    gender = jug->Query(P_GENDER);
    level = jug->Query(P_LEVEL);
  }
}

private string create_topscore_line(string pl,mapping mpl,string *idx)
{
  int i;
  i = member(idx,pl)+1;
  return W(
		   STR->radjust(to_string(i),3)+".  "+
		   STR->ladjust(capitalize(pl),15,".")+
		   "   "+STR->radjust(to_string(mpl[pl,T_LEVEL]),5,".")+"   "+
		   STR->radjust(dtime(mpl[pl,T_AGE]),5,".")+"   "+
		   STR->ladjcut(capitalize(mpl[pl,T_RACE]||""),17,".")+"   "+
		   STR->ladjcut((mpl[pl,T_GENDER]==2?"Femenino":"Masculino"),12,"."));
}

public varargs void update_toplist(int topstate,mapping data)
{
  mixed help;
  int i;
  while(remove_call_out("update_toplist") != -1);
  LoadGuild();
  data = data||([]);
  switch(topstate)
    {
    case 0:
      help = m_indices(members||([]));
      data[TOP_MEMBER] = help-filter(help,SF(query_wiz_level));
      break;
    case 1:
      if (!member(data,TOP_FUN))
        data[TOP_FUN] = symbol_function("QueryQuestPoints",QUESTMASTER);
      if (!member(data,TOP_TODO))
        data[TOP_TODO] = data[TOP_MEMBER]+({});
      help = data[TOP_TODO][0..49];
      data[TOP_RESULT] = (data[TOP_RESULT]||({}))+map(help,data[TOP_FUN]);
      if (sizeof(help)<sizeof(data[TOP_TODO]))
	{
	  data[TOP_TODO] = data[TOP_TODO]-help;
	  call_out(SF(update_toplist),1,topstate,data);
	  return;
	}
      m_delete(data,TOP_FUN);
      m_delete(data,TOP_TODO);
      data[TOP_QP] = mkmapping(data[TOP_MEMBER],data[TOP_RESULT]);
      m_delete(data,TOP_RESULT);
      break;
    case 2:
      if (!member(data,TOP_RESULT))
	data[TOP_RESULT] = m_allocate(0,T_SIZE);
      if (!member(data,TOP_TODO))
        data[TOP_TODO] = data[TOP_MEMBER]+({});
      help = data[TOP_TODO][0..24];
      for(i=0;i<sizeof(help);i++)
	{
	  int xp,age,level,gender;
	  string race;
	  init_vals(help[i],&xp,&age,&level,&race,&gender);
	  data[TOP_RESULT][help[i],T_QP] = data[TOP_QP][help[i]];
	  data[TOP_RESULT][help[i],T_XP] = xp;
	  data[TOP_RESULT][help[i],T_AGE] = age;
	  data[TOP_RESULT][help[i],T_RACE] = race;
	  data[TOP_RESULT][help[i],T_GENDER] = gender;
	  data[TOP_RESULT][help[i],T_LEVEL] = level;
	}
      if (sizeof(help)<sizeof(data[TOP_TODO]))
	{
	  data[TOP_TODO] = data[TOP_TODO]-help;
	  call_out(SF(update_toplist),1,topstate,data);
	  return;
	}
      m_delete(data,TOP_TODO);
      data[TOP_PLDATA] = data[TOP_RESULT];
      m_delete(data,TOP_RESULT);
      m_delete(data,TOP_MEMBER);
      break;
    case 3:
      data[TOP_RESULT] = sort_mapping(data[TOP_PLDATA],SF(check_greater));
      break;
    case 4:
      help = map(data[TOP_RESULT],SF(create_topscore_line),
		       data[TOP_PLDATA],data[TOP_RESULT]);
      SetTopList(help);
      updated = time();
      return;
    }
  ++topstate;
  call_out(SF(update_toplist),2,topstate,data);
}

public varargs string toplist(int size)
// returns the Top20-Players
{
  string txt,*tl;
  int i;
  if (!size) size = 19;
  if (!i = sizeof(tl = QueryTopList()))
    return updated?"La lista esta vacia.\n":"La lista de veteranos se está actualizando.\n";
  txt =  STR->cadjust("La lista de veteranos del "+(TO->QueryGuildname()||"gremio")+" ("+
		      to_string(i)+" miembro"
		      +(i==1?"":"s")+")",75)+"\n\n"
    "      Nombre            Nivel   Horas   Raza                Sexo\n"+
    STR->mkstr(75,"-")+"\n";
  txt+=implode(tl[0..size],"\n")+"\n";
  txt+="\n  Última modificación: "+STR->etime(1,ctime(updated))+".\n";
  return txt;
}

/*
* ----------------------------------------------------------------------
* Queries, Settings, Adds
* ----------------------------------------------------------------------
*/


public string *SetCreators(mixed cr)
// cr might be a string or an array of strings, i. e. you might
// specify one or several creators. The creators will appear in
// the who-list of the guild.
{
  int i;
  if (stringp(cr)) cr = ({cr});
  cr -= ({0});
  for (i=0; i<sizeof(cr); i++) cr[i] = lower_case(cr[i]);
  return creators = cr;
}

public mixed QueryCreators()
{
  return (creators||({}))+({});
}

/*
* Member
* ======
* ([string name:int time of entering;int level;string stat;string *msgs])
*/

public mapping QueryMember(mixed who)
{
    if (!objectp(who) && !stringp(who)) return 0;
    if (objectp(who)) who = getuid(who);
    return GUILDMASTER->QueryMember(getuid(), who);
}
public varargs mapping QueryMembers(int ForceQuery)
{
  if (ForceQuery) LoadGuild();
  return members||([]);
}


public int AddMember(string name, int level, int stat)
// Add a member to the guild. If the member already exists, (s)he won't
// be added. The 'time'-entry will be set to the current time.
{
  if (!name) return 0;
  if (is_member(name)) return -1;
  if (!members) members = m_allocate(0,MEMBER_ENTRIES);
  if (!GUILDMASTER->AddMember(getuid(), name, level, stat)) return 0;
  m_add(members, name, time(), level, stat);
  return 1;
}

public int RemoveMember(string name)
// Remove a member from the guild and inform us. ("InformRemove")
{
  string h;
  
  if (!name|| !is_member(name)) return 0;
  if ((name == TO->QueryGuildleader())&&(h=TO->QueryViceGuildleader()))
    TO->ChangeStat(h,G_LEADER);
  GUILDMASTER->RemoveMember(getuid(), name);
  m_delete(members,name);
  TO->InformRemove(name);
  return 1;
}

public int ChangeStat(string name,string stat)
// Change the status of a member (e. g. from member to guildleader)
{
  if (!name || !QueryMember(name)) return 0;
  if (!GUILDMASTER->ChangeStats(getuid(), name, stat)) return 0;
  members[name,MEMBER_STAT]=stat;
  return 1;
}

public int QueryStat(string name)
// Return the status of a member
{
  mapping mb;
  if (!name||!(mb = QueryMember(name))) return 0;
  return mb[name,MEMBER_STAT];
}

public string QueryGuildleader()
// Return the Guildleader of the guild; 0 if there's no leader
{
    return GUILDMASTER->QueryGuildleader(getuid());
}

public string QueryViceGuildleader()
// Return the Vice-Guildleader of the guild; 0 if there's no vice-leader
{
    return GUILDMASTER->QueryGuildleader(getuid());
}

public int ChangeLevel(string name,int level)
// Change the level of a member
{
  if (!name || !QueryMember(name)) return 0;
  if (!GUILDMASTER->ChangeLevel(getuid(), name, level)) return 0;
  members[name,MEMBER_LEVEL]=level;
  return 1;
}

public int QueryLevel(string name)
// Return the level of a member
{
  object ob;
  mapping mb;

  ob=find_object(lower_case(name));
  if (ob && ob->QueryGuild()==QueryGuildclass()) return ob->QueryGuildLevel();
  if (!name || !(mb = QueryMember(name))) return 0;
  return mb[name, MEMBER_LEVEL];
}

public int UpdateTime(string name)
// Update the enter-time of a member to the current time
{
  if (!name||!QueryMember(name)) return 0;
  members[name,MEMBER_TIME]=time();
  return 1;
}

public int QueryTime(string name)
// return the time when the member last entered
{
  mapping mb;
  if (!name||!(mb = QueryMember(name))) return 0;
  return mb[name,MEMBER_TIME];
}

public int AddMessage(string name, string from_name, string message)
// Add a message to the messages of a member
{
    return GUILDMASTER->AddMessage(getuid(), name, from_name, message);
}

public int RemoveMessage(int id)
// Remove a message
{
    return GUILDMASTER->RemoveMessage(id);
}

public int RemoveMessages(string name)
// Remove all messages
{
    return GUILDMASTER->RemoveMessages(getuid(), name);
}

public mapping QueryMessages(string name)
// Get the mapping mesages of a guild member
{
    return GUILDMASTER->QueryMessages(getuid(), name);
}
