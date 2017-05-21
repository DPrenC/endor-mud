/* SIMAURIA '/obj/player_dummy.c'
   ==============================
   [w] Woo@simauria

   Con este objeto puedes ver las propiedades de un jugador aunque no
   esté conectado en ese instante.
*/

#define PD_AGE "Age"
#define PD_EXPLORED "Explored"

#include <properties.h>
#include <attributes.h>

private static string loaded;
private static mapping properties;

public mapping pAttrs;
public int intoxicated, alignment, Con, Dex, soaked, stuffed, pGender,
  hit_point, Int, invis, ivision, level, max_alcohol, max_drink,
  max_food, max_hp, max_sp, spell_points, Str, uvision, whimpy,
  experience, age, pagesize, faliases;
public mixed mmsgin,mmsgout,msgin,msgout;
public string race, *channels, aCorpse, explored, guild,
  home, presay, quests, title, tty;

// Small hack, until all save their main data in pAttrs
public int aLevel,aXP,aRace;

public status LoadData(string pl)
{
  string file;
  if (!file = find_savefile(pl)) return 0;
  seteuid(getuid());
  pAttrs
    = intoxicated = alignment = Con = Dex = soaked = stuffed = pGender
    = hit_point = Int = invis = ivision = level = max_alcohol = max_drink
    = max_food = max_hp = max_sp = spell_points = Str = uvision = whimpy
    = experience = age = pagesize = faliases
    = mmsgin = mmsgout = msgin = msgout
    = race = channels = aCorpse = explored = guild
    = home = presay = quests = title = tty

    = 0;
  restore_object(file);
  seteuid(0);
  loaded = pl;
  return 1;
}

public mixed trans_pl(mixed pl)
{
  if (!pl) return 0;
  if (objectp(pl)) return pl;
  if (find_object(pl)) return find_object(pl);
  if (stringp(pl) && find_object(lower_case(pl))) return find_object(lower_case(pl));
  return pl;
}

public mapping QueryProperties(mixed pl)
{
  pl = trans_pl(pl);
  if (objectp(pl)) return pl->QueryProperties();
  if (pl==loaded&&properties) return properties+([]);
  if (!pl||!LoadData(pl)) return ([]);
  properties = ([]);
  if (pAttrs)
    properties+=pAttrs;
  // P_ACTIONS, P_ADS, P_AGGRESSIVE, P_ALCOHOL, P_ALIGN, P_ARMOURS,
  // P_ATTACK_CHANCE, P_BRIEF, P_COMBAT_STYLE, P_CON, P_DEFENSE, P_DEG_ALCOHOL,
  // P_DEG_DRINK, P_DEG_FOOD, P_DEX, P_DRINK, P_FOOD, P_FREE_HANDS, P_GENDER,
  // P_GO_CHANCE, P_HANDS, P_HP, P_IDS, P_INT, P_INT_LONG, P_INT_NOISE,
  // P_INT_SHORT, P_INT_SMELL, P_INVIS, P_IVISION, P_LEVEL, P_LONG, P_LSTATE,
  // P_MAGIC_DEFENCE, P_MAGIC_DEFENSE, P_MAXSP, P_MAX_ALCOHOL, P_MAX_DRINK,
  // P_MAX_FOOD, P_MAX_HP, P_MAX_POISON, P_MMSGIN, P_MMSGOUT, P_MSGIN, P_MSGOUT,
  // P_NAME, P_NOISE, P_OBVIOUS, P_POISON, P_RACE, P_RATE_ALCOHOL, P_RATE_HP,
  // P_RATE_POISON, P_RATE_SP, P_SHORT, P_SMELL,
  // P_SP, P_STR, P_UVISION, P_WEAPONS, P_WHIMPY, P_XP
  else
    {
      properties[P_ALCOHOL] = intoxicated; // int
      properties[P_ALIGN] = alignment; // int
      properties[P_CON] = Con; // int
      properties[P_DEX] = Dex; // int
      properties[P_DRINK] = soaked; // int
      properties[P_FOOD] = stuffed; // int
      properties[P_HP] = hit_point; // int
      properties[P_INT] = Int; // int
      properties[P_INVIS] = invis; // int
      properties[P_IVISION] = ivision; // int
      properties[P_LEVEL] = level; // int
      properties[P_MAX_ALCOHOL] = max_alcohol; // int
      properties[P_MAX_DRINK] = max_drink; // int
      properties[P_MAX_FOOD] = max_food; // int
      properties[P_MAX_HP] = max_hp; // int
      properties[P_MAX_SP] = max_sp; // int
      properties[P_MMSGIN] = mmsgin; // mixed
      properties[P_MMSGOUT] = mmsgout; // mixed
      properties[P_MSGIN] = msgin; // mixed
      properties[P_MSGOUT] = msgout; // mixed
      properties[P_RACE] = race; // string
      properties[P_SP] = spell_points; // int
      properties[P_STR] = Str; // int
      properties[P_UVISION] = uvision; // int
      properties[P_WHIMPY] = whimpy; // int
      properties[P_XP] = experience; // int
    }
  properties[P_GENDER] = pGender; // int
  properties[P_ATTRS] = pAttrs; // mapping
  properties[P_CHANNELS] = channels; // *string
  properties[P_CORPSE] = aCorpse; // string
  properties[P_FALIASES] = faliases; // mixed
  properties[P_GUILD] = guild; // string
  properties[P_HOME] = home; //string
  properties[P_PAGESIZE] = pagesize; // int
  properties[P_PRESAY] = presay; // string
  properties[P_QUESTS] = quests; // string
  properties[P_TITLE] = title; // string
  properties[P_TTY] = tty; // string
  properties[PD_AGE] = age; // int
  properties[PD_EXPLORED] = explored; // string

  // Small hack (see above)
  properties[P_LEVEL] = properties[P_LEVEL]||aLevel;
  properties[P_RACE] = properties[P_RACE]||aRace;
  properties[P_XP] = properties[P_XP]||aXP;

  return properties+([]);
}
