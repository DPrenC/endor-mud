/* SIMAURIA /std/guild/level.c
   ---------------------------
   [t] Theuzifan

   15-10-98 [t] Traducido.
   20-10-99 [t] Cambio algunas funciones para que no te cambie el título si
   		no lo deseas.
   27-11-99 [t] Cambiadas XXXLevel por XXXGuildLevel...
*/

#include <config.h> // QUESTMASTER
#include <living.h>    // NEUTER, MALE, FEMALE
#include <guild.h>

//#define MAX_LEVEL 50

private static mapping leveltitles; // leveltitel = ([lvl:Neuter;Male;Female])

/*
* Level related help-functions
* ============================
*/

public void AnnounceNewLevel()
// Announce a new level of a player
// if the player is invis, don't spread the message on the channel
{
  int lvl;
  lvl = TP->QueryGuildLevel();
  write("Ahora eres nivel "+to_string(lvl)+".\n");
  if (!TP->QueryInvis())
    CHMASTER->SendEmote("infomud",capitalize(getuid(TP))+
                      " ha conseguido aumentar su nivel hasta el "+to_string(lvl));
}

public int QPtoLevel(int qp)
// return the level you might get with your current QP
{
  int lvl;
  while(QUESTMASTER->QPointLevel(++lvl)<=qp);
  return --lvl;
}

public string GuildLeveltoTitle(int lvl,int gender)
// evaluate the title
{
  string rc;
  rc=TO->QueryTitle();
  while( leveltitles && !leveltitles[lvl,gender] && --lvl);
  return (leveltitles||m_allocate(0,3))[lvl,gender]||rc;
}

/*
* ----------------------------------------------------------------------
* Queries, Settings, Adds
* ----------------------------------------------------------------------
*/

// set all titles: ([lvl:neuter;male;female])
public mapping SetLevelTitles(mapping t) { return t?(leveltitles=t):(leveltitles||([]));}

public mapping QueryLevelTitles()	{ return leveltitles||([]);}

public mapping AddLevelTitle(int lvl,int gen,string title)
// Add a title for a certain gender, e. g.
// AddLevelTitel(1,NEUTER,"the utter creature");
{
  if (lvl<0) return leveltitles||([]);
  if (!leveltitles) leveltitles = m_allocate(0,3);
  leveltitles[lvl,gen]=title;
  return leveltitles;
}

public mapping AddNeuterTitle(int lvl,string title)
// Add a title for a neuter player
{
  return AddLevelTitle(lvl,NEUTER,title);
}

public mapping AddMaleTitle(int lvl,string title)
// Add a title for a male player
{
  return AddLevelTitle(lvl,MALE,title);
}

public mapping AddFemaleTitle(int lvl,string title)
// Add a title for a female player
{
  return AddLevelTitle(lvl,FEMALE,title);
}

public varargs mapping AddLevelTitles(int lvl,mixed arg1,string m,string f)
// Add titles for a certain level. This may be done in two ways:
// AddLevelTitles(1,({"neuter title","male title","female title"})) or
// AddLevelTitles(1,"neuter title","male title","female title")
// You may also just give one title for all genders. Example:
// AddLevelTitles(1,"all title")
{
  string n;
  if (lvl<0) return leveltitles||([]);
  if (!leveltitles) leveltitles = m_allocate(0,3);
  if (pointerp(arg1))
    if (sizeof(arg1)!=3)
      return leveltitles||([]);
    else
      n = arg1[NEUTER],
      m = arg1[MALE]||n,
      f = arg1[FEMALE]||n;
  else
    if (stringp(arg1))
      {
	n = arg1;
	m = m||n;
	f = f||n;
      }
    else return leveltitles||([]);
  AddLevelTitle(lvl,NEUTER,n);
  AddLevelTitle(lvl,MALE,m);
  AddLevelTitle(lvl,FEMALE,f);
  return leveltitles;
}
create()
{
    seteuid(getuid());
}
