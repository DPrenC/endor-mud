/**
 * ENDOR-MUD/std/player/skills.c
 */

#include <colours.h>
#include <living.h>
#include <properties.h>
#include <skills.h>
#include "/secure/wizlevels.h"

//-----------------------------------------------------------------------------

#define DEFAULT_LEARN  5

//-----------------------------------------------------------------------------

inherit "/std/living/skills";

//-----------------------------------------------------------------------------

public int save();

//------------------------------------------------------------------------------

public int QuerySkillLearnLevel(string name)
{
  if (!HasSkill(name)) return 0;
  return DEFAULT_LEARN;
}

public string QuerySkillLearnMessage(string name)
{
  if (!HasSkill(name)) return 0;
  return "Consigues avanzar con tu habilidad de '"+name+"'.\n";
}

//------------------------------------------------------------------------------

// Sobrecargada para salvar cada vez que se añade un skill
public varargs mapping AddSkill(string name, int level, mixed modif, int maximum, int not_enabled)
/**
 * name:  nombre del skill
 * level: nivel inicial del skill (0..100)
 * maximum: nivel maximo de aprendizaje del skill (0..100)
 * modif: stat del jugador que hará de modificador de skill. No es necesario y por defecto es la Destreza.
 * not_enabled: si el skill no esta activo
 */
{
  ::AddSkill(name, level, modif, maximum, not_enabled);
  save();
  return QuerySkills();
}

// Sobrecargada para añadir la posibilidad de mejorar el skill
public varargs int UseSkill(string name, int bonus, int nomod)
{
  int rc, apr;

  rc = ::UseSkill(name, bonus, nomod);

  if (rc > 0) { // Ha usado el skill
    apr = QuerySkillLearnLevel(name);
  }
  else { // ha fallado
    apr = QuerySkillLearnLevel(name) >> 1; // Divido entre dos
  }

  //Es tu nivel del skill menor que el maximo permitido?
  if (QuerySkillLevel(name) < QueryMaxSkillLevel(name))
    //Si. Aprendes a usar mejor ese skill?
    if (d100() < apr)
      //Si, pero cada vez le cuesta mas;
      if (random(QueryMaxSkillLevel(name)) > QuerySkillLevel(name))
      {
        if (QuerySkillLearnMessage(name)) TO->catch_msg(QuerySkillLearnMessage(name));
        SetSkillLevel(name, QuerySkillLevel(name)+1);
        save();
      }

  return rc;
}

public void add_general_skills()
{
  int i;
  int niv_hab;

  for (i=0; i<sizeof(HAB_GENERALES); i++)
  {
    niv_hab=d20();
    if (!HasSkill(HAB_GENERALES[i])) AddSkill(HAB_GENERALES[i], niv_hab, P_DEX, 30);
  }
  return 0;
}

create()
{
  call_out("add_general_skills", 5);
}

