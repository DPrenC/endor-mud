/* SIMAURIA /std/guild/guildquests.c
   ---------------------------------
   [t] Theuzifan

   15-10-98 [t] Traducido.
   04-02-99 [t] Quedaba algo por traducir...
*/

#include <guild.h> // Q_LEVEL, Q_CREATOR, ...
#include <config.h> // QUESTMASTER

#define LSF(x) symbol_function(x, TO)	// lfun
#define ESF(x) symbol_function(x)	// efun

private static mapping guildquests;
// guildquests = ([quest_id:quest_level;quest_creator;quest_short;quest_long])

public mapping GuildQuests()
// return the guildquests in the form:
// ([<level>:<short>])
{
  string *ids;
  mapping res;
  int i;

  if (!guildquests) return ([]);
  res = m_allocate(0,1);
  i = sizeof(ids = m_indices(guildquests));
  while(i--)
    res[guildquests[ids[i],Q_LEVEL]]=guildquests[ids[i],Q_SHORT];
  return res;
}

protected int GetQuestLevel(string q)
// return the level where you need to do the guildquest
{
  return (guildquests||([]))[q,Q_LEVEL];
}

public int GuildQuestLevel(object pl)
// Return the level up to which <pl> might reach without solving
// another guildquest
{
  string *ids;
  int maxlvl,*qlvls;

  if (!pl) return 0;
  maxlvl = 100;
  ids = m_indices(guildquests||([]));
  ids-=QUESTMASTER->QueryPlayerQuests(pl);
  if (!sizeof(ids)) return maxlvl;
  qlvls = map(ids,LSF("GetQuestLevel"));
  return (NMB->min(qlvls))-1;
}

public varargs string ListGuildquests(mixed pl,mapping res,mapping nres)
// Return a printable list of all guildquests
// if res is passed by reference, it will contain a mapping
// after returning: ([lvl:({quests})])
// nres will return a mapping like this: ([nr:<quest>])
{
  int i,s,j;
  string *qids,list,id;
  mixed h;

  if (!s = sizeof(guildquests||([]))) return "No hay guildquests.\n";
  qids = m_indices(guildquests);
  h = sort_array(m_values(guildquests),ESF(">"));
  res = m_allocate(0,1);
  for(i=0;i<s;i++)                    // build the res-mapping
    {
      if (!res[h[i]]) res[h[i]]=({});
      for (j=0;j<sizeof(qids);j++)
        if (guildquests[qids[j],Q_LEVEL]==h[i])
          res[h[i]]+=({qids[j]});
    }
  list = "";
  nres = ([]);
  for(i=0;i<s;i++)                   // now build the list from the res-mapping
    for(j=0;j<sizeof(res[h[i]]);j++)
      {
        id = res[h[i]][j];
        list+=sprintf("%2d. %s (nivel %d)",(i+j+1),
                                           guildquests[id,Q_SHORT],h[i])+
          ((QUESTMASTER->QueryQuestSolved(id,pl))?" (solucionado)":"")+"\n";
        nres[i+j+1] = id;
      }
  return list;
}

/*
* ----------------------------------------------------------------------
* Queries, Settings, Adds
* ----------------------------------------------------------------------
*/

/*
* Guildquests
* ===========
* ([quest_id:quest_level;quest_creator;quest_short;quest_long])
*/

public mapping SetGuildquests(mapping quests)
// Set the mapping of guildquest. 'Design' see above
{
  if (!mappingp(quests)) return guildquests||([]);
  return guildquests = quests;
}

public mapping QueryGuildquests()
{
  return guildquests||([]);
}

public mapping AddGuildquest(string id,
                             int lvl,
                             string creator,
                             string short,
                             string long)
// Add a guildquest. The id is the quest_id, which will be
// recognized by the Quest-Controler
{
  if (!id) return guildquests;
  if (!guildquests) guildquests = m_allocate(0,4);
  guildquests[id,Q_LEVEL]=lvl;
  guildquests[id,Q_CREATOR]=creator;
  guildquests[id,Q_SHORT]=short;
  guildquests[id,Q_LONG]=long;
  return guildquests;
}
