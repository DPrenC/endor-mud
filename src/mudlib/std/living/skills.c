/**
 * SIMAURIA /std/living/pSkills.c
 */

//------------------------------------------------------------------------------

#include <attributes.h>

#define SK_PERC    0
#define SK_MAX     1
#define SK_STAT    2
#define SK_ENABLED 3

//------------------------------------------------------------------------------

private mapping pSkills = ([:4]); // [nombre: nivel; nivel_max; stat; enabled]

//------------------------------------------------------------------------------

public int HasSkill(string name)
{
  return member(pSkills, name||"");
}

public int SkillIsEnabled(string name)
{
  if (HasSkill(name)) return pSkills[name, SK_ENABLED];
  return 0;
}

public int EnableSkill(string name)
{
  if (!HasSkill(name)) return 0;
  pSkills[name, SK_ENABLED]=1;
  return 1;
}

public int DisableSkill(string name)
{
  if (!HasSkill(name)) return 0;
  pSkills[name, SK_ENABLED]=0;
  return 1;
}

public mapping QuerySkills()
{
  return copy(pSkills);
}

public mapping SetSkills(mapping p)
{
  if (mappingp(p)) pSkills = p;
  return QuerySkills();
}

public mapping RemoveSkill(string name)
{
  m_delete(pSkills, name);
  return QuerySkills();
}

public int SetSkillLevel(string name, int level)
{
  if (!HasSkill(name)) return 0;
  if (level<  0) level = 0;
  if (level>100) level = 100;
  return pSkills[name, SK_PERC]=level;
}

public int QuerySkillLevel(string name)
{
  if (!HasSkill(name)) return 0;
  return pSkills[name, SK_PERC];
}

public int QueryMaxSkillLevel(string name)
{
  if (!HasSkill(name)) return 0;
  return pSkills[name, SK_MAX];
}

public int SetMaxSkillLevel(string name, int maximum)
{
  if (!HasSkill(name)) return 0;
  return pSkills[name, SK_MAX] = maximum;
}

//------------------------------------------------------------------------------

public varargs mapping AddSkill(string name, int level, mixed stat, int maximum, int not_enabled)
/**
 * name:  nombre del skill
 * level: nivel inicial del skill (0..100)
 * (Opcional) stat: stat del jugador que hará de staticador de skill.
 * (Opcional) maximum: nivel maximo de aprendizaje del skill (0..100)
 * (Opcional) not_enabled: si el skill no esta activo
 */
{

//  dtell("nyh",sprintf("%O->AddSkill(%O, %O, %O, %O, %O)\n", TO, name, level, stat, maximum, not_enabled));
//  dtell("nyh",sprintf("\tInicio: pSkills = %O\n", QuerySkills()));
  if (!sizeof(name)) return pSkills;

  if (level <   1)   level = 0;
  if (level > 100)   level = 100;

  if (maximum <   1) maximum = 0;
  if (maximum > 100) maximum = 100;

  if (!maximum) maximum = level;
  else if (level > maximum) level = maximum;

  if (member(STATS, stat) < 0) stat = 0;
  //if (!stat) stat = P_DEX;

  if (HasSkill(name))
  { // No le bajo el nivel del skill
    if (maximum<pSkills[name, SK_MAX]) maximum = pSkills[name, SK_MAX];
    if (level<pSkills[name, SK_PERC])  level = pSkills[name, SK_PERC];
  }

  m_add(pSkills, name, level, maximum, stat, !not_enabled);

//  dtell("nyh",sprintf("\tFin pSkills = %O\n", QuerySkills()));


  return QuerySkills();

}

//------------------------------------------------------------------------------

public varargs int UseSkill(string name, int bonus, int nomod)
/* name: nombre del skill a usar
   bonus: dificultad del skill en ese momento
          valores positivos indica MAS facil
   nomod:si no quieres q use el modificador de habilidad
*/
{
  int chance;

  if (!HasSkill(name)) return 0;
  if (!SkillIsEnabled(name)) return 0;

  //formulilla pa saber si lo hago bien o mal
  chance = pSkills[name, SK_PERC] + bonus;

  if (!nomod && pSkills[name, SK_STAT]) chance += TO->Query(pSkills[name, SK_STAT]);

  if (find_object("nyh") && find_object("nyh")->Query("DebugSkills"))
    dtell("nyh",sprintf("%O->UseSkill(%O, %O, %O) chance final = %O\n", TO->QueryName(), name, bonus, nomod, chance));

  return chance - d100();
}

//------------------------------------------------------------------------------
