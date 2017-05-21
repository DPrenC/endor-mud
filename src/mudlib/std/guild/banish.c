/* SIMAURIA /std/guild/banish.c
   ----------------------------
   [t] Theuzifan
   [k] kastwey
   15-10-98 [t] Traduccion.
   04-02-99 [t] Castellanización.
   05-05-08 [k] Cambio esto de almacenamiento en ficheros, a base de datos
*/

#include <guild.h>
#include <wizlevels.h>
#include <config.h>

private nosave mapping banished;
// ([name:time of banish;banisher;reason])

/*
* ----------------------------------------------------------------------
* Helpfunctions
* ----------------------------------------------------------------------
*/

protected int check_banish(string whom,string who)
{
  if (IS_LEARNER(whom)) return 1;
  if (IS_LORD(who)) return 1;
  return TO->is_leader(who);
}

/*
* ----------------------------------------------------------------------
* Banishing players from the guild
* ----------------------------------------------------------------------
*/


public varargs mapping QueryBanished(int ForceQuery)
{
  if (!ForceQuery) return banished;
  return banished = GUILDMASTER->QueryBanished(getuid());
}

public mapping QueryBanish(mixed whom)
{
    if (!objectp(whom) && !stringp(whom)) return 0;
    if (objectp(whom)) whom = getuid(whom);
    return GUILDMASTER->QueryBanish(getuid(), whom);
}

public int IsBanished(string name)
{
    return GUILDMASTER->IsBanished(getuid(), name);
}

public string AddBanish(string whom,string why)
{
  string who;
  int id;
  who = getuid(TI);
  if (!whom) return ERR_NONAME;
  whom = lower_case(whom);
  if (!find_savefile(whom)) return ERR_NOPLAYER;
  if (!check_banish(whom,who)) return ERR_NOALLOW;
  if (IsBanished(whom)) return ERR_ALREADY;
  if (!banished) banished = m_allocate(0,3);
  if (!(id = GUILDMASTER->AddBanish(getuid(), whom, who, why))) return ERR_UNKNOWN;
  log_file("GUILDBANISH",ctime()+" "+capitalize(who)+" ha desterrado a "+
                         capitalize(whom)+" de "+TO->QueryGuildname()+"\n"
                         " Razón: "+(why?why:"<no dió ninguna razón>")+"\n");

  m_add(banished, whom, id, time(), who, why?why:"<no dió ninguna razón>");
  return NO_ERR;
}

public string RemoveBanish(string whom)
{
  string who;
  mapping bn;

  who = getuid(TI);
  if (!whom) return ERR_NONAME;
  whom = lower_case(whom);
  if (!check_banish(whom,who)) return ERR_NOALLOW;
  if (!QueryBanish(whom)) return ERR_NOT_BANISHED;
  if (!GUILDMASTER->RemoveBanish(getuid(), whom)) return ERR_UNKNOWN;
  log_file("GUILDBANISH",ctime()+" "+capitalize(who)+" debaneado por "+
                         capitalize(whom)+" de "+TO->QueryGuildname()+"\n");
  if (banished) m_delete(banished,whom);
  return NO_ERR;
}

public string ListBanished()
{
  int i;
  string *m,result;

  m = sort_array(m_indices(banished||([])),SF(>));
  result = "Nombre      |Baneado por |Razón\n"
           "------------+------------+--------------------------------------\n";
  for (i=0;i<sizeof(m);i++)
    result+=STR->ladjust(capitalize(m[i]),12)+"|"+
            STR->radjust(banished[m[i],BANISH_BANISHER],12)+"|"+
            banished[m[i],BANISH_REASON];
  return result;
}


public string Banisher(string whom)
{
  mapping bn;
  if (!whom ||!IsBanished(whom)) return 0;
  bn = QueryBanish(whom);
  return bn[whom, BANISH_BANISHER];
}
  

