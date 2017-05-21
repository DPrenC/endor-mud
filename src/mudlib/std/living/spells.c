/**
 * SIMAURIA /std/living/spells.c
 *
 * [Nyh] Brutalmente copiado del skills
 */

//------------------------------------------------------------------------------

#include <attributes.h>

#define SP_PERC    0
#define SP_MAX     1
#define SP_STAT    2
#define SP_ENABLED 3

//------------------------------------------------------------------------------

private mapping pSpells = ([:4]); // [nombre: nivel; nivel_max; stat; enabled]

//------------------------------------------------------------------------------

public int HasSpell(string name)
{
  return member(pSpells, name);
}

public int SpellIsEnabled(string name)
{
  if (HasSpell(name)) return pSpells[name, SP_ENABLED];
  return 0;
}

public int EnableSpell(string name)
{
  if (!HasSpell(name)) return 0;
  pSpells[name, SP_ENABLED]=1;
  return 1;
}

public int DisableSpell(string name)
{
  if (!HasSpell(name)) return 0;
  pSpells[name, SP_ENABLED]=0;
  return 1;
}

public mapping QuerySpells()
{
  return copy(pSpells);
}

public mapping SetSpells(mapping p)
{
  if (mappingp(p)) pSpells = p;
  return QuerySpells();
}

public mapping RemoveSpell(string name)
{
  m_delete(pSpells, name);
  return QuerySpells();
}

public int SetSpellLevel(string name, int level)
{
  if (!HasSpell(name)) return 0;
  if (level<  0) level = 0;
  if (level>100) level = 100;
  return pSpells[name, SP_PERC] = level;
}

public int QuerySpellLevel(string name)
{
  if (!HasSpell(name)) return 0;
  return pSpells[name, SP_PERC];
}

public int QueryMaxSpellLevel(string name)
{
  if (!HasSpell(name)) return 0;
  return pSpells[name, SP_MAX];
}

public int SetMaxSpellLevel(string name, int maximum)
{
  if (!HasSpell(name)) return 0;
  return pSpells[name, SP_MAX] = maximum;
}

//------------------------------------------------------------------------------

public string QuerySpellLearnMessage(string name)
{
  return HasSpell(name)?"Mejoras el nivel de práctica del conjuro '"+name+"'.\n":0;
}

public int QuerySpellChance(string name)
/* Devuelve el nivel al que tienes el spell. Un 0 es que no lo tienes, ya
   que el rango va de 1..100
*/
{
  return HasSpell(name)?pSpells[name, SP_PERC]:0;
}

public mixed QuerySpellModifier(string name)
/* Devuelve el modificador de el spell.
*/
{
  if (!HasSpell(name)) return 0;
  return pSpells[name, SP_STAT] || P_INT;
}

//------------------------------------------------------------------------------

public varargs mapping AddSpell(string name, int level, mixed stat, int maximum, int not_enabled)
/**
 * name:  nombre del spell
 * level: nivel inicial del spell (0..100)
 * (Opcional) stat: stat del jugador que hará de modificador de spell.
 * (Opcional) maximum: nivel maximo de aprendizaje del spell (0..100)
 * (Opcional) not_enabled: si el spell no esta activo
 */
{
  if (!sizeof(name)) return pSpells;

  if (level <   1)   level = 0;
  if (level > 100)   level = 100;

  if (maximum <   1) maximum = 0;
  if (maximum > 100) maximum = 100;

  if (!maximum) maximum = level;
  else if (level > maximum) level = maximum;

  if (member(STATS, stat) < 0) stat = 0;
  //if (!stat) stat = P_DEX;

  if (HasSpell(name))
  {
    if (maximum<pSpells[name, SP_MAX]) maximum=pSpells[name, SP_MAX];
    if (level<pSpells[name, SP_PERC]) level=pSpells[name, SP_PERC];
  }

  m_add(pSpells, name, level, maximum, stat, 1);

  return QuerySpells();
}

//------------------------------------------------------------------------------

public varargs int UseSpell(string name, mixed diff, mixed nomod, object scroll)
/** Usos:
//public int UseSpell(string name)
//public int UseSpell(string name, int diff)
//public int UseSpell(string name, int diff, int nomod)
//public int UseSpell(string name, int diff, int nomod, object scroll)
//public int UseSpell(string name, int diff, object scroll)
//public int UseSpell(string name, object scroll, int nomod)
//public int UseSpell(string name, object scroll)
 * Argumentos:
   name: nombre del spell a usar
   (opcional) objectp(diff): Objeto del pergamino a lanzar (si es pergamino)
   (opcional) intp(diff): dificultad del spell en ese momento (-100..100)
                          valores positivos indica MAS facil
   (opcional) objectp(nomod): Objeto del pergamino a lanzar (si es pergamino)
              intp(nomod): si no quieres q use el modificador de habilidad ponlo a 1
   (opcional) scroll: Objeto del pergamino a lanzar (si es pergamino)
 */
{
  int chance;

  if (!HasSpell(name)) return 0;
  if (!SpellIsEnabled(name)) return 0;

  if (!scroll)
  {
    if (objectp(diff))
    {
      scroll = diff;
      diff = 0;
    }
    else if (objectp(nomod))
    {
      scroll = nomod;
      nomod = 0;
    }
  }

  if (scroll) chance = 25;
  else chance = QuerySpellChance(name);

  chance += TO->Query(QuerySpellModifier(name));

  return (chance - d100())>0;
}

//------------------------------------------------------------------------------
