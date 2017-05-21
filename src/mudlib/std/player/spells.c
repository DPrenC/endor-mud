/**
 * SIMAURIA '/std/player/spells.c'
 */

//------------------------------------------------------------------------------

#include <properties.h>
#include <magia.h>

//------------------------------------------------------------------------------

#define DEFAULT_LEARN  10

inherit "/std/living/spells";

//------------------------------------------------------------------------------

public int save();

public string QueryGuild();
public int QueryGuildLevel();

//------------------------------------------------------------------------------

public int QuerySpellLearnLevel(string name)
{
  if (!HasSpell(name)) return 0;
  return DEFAULT_LEARN;
}

public string QuerySpellLearnMessage(string name) {
  if (!HasSpell(name)) return 0;
  return "Mejoras el nivel de práctica del conjuro '"+name+"'.\n";
}

//------------------------------------------------------------------------------

// Sobrecargada para salvar cada vez que se añade un spell
public varargs mapping AddSpell(string name, int level, mixed modif, int maximum, int not_enabled)
/**
 * name:  nombre del spell
 * level: nivel inicial del spell (0..100)
 * maximum: nivel maximo de aprendizaje del spell (0..100)
 * modif: stat del jugador que hará de modificador de spell. No es necesario y por defecto es la Destreza.
 * not_enabled: si el spell no esta activo
 */
/** [Woo dijo en su momento] Esto solo es para casos MUY excepcionales en los que
                 tenga que intervenir un wiz, en cualquier otro caso hay
                 que usar AddPlayerSpell().
 */
{
  ::AddSpell(name, level, modif, maximum, not_enabled);
  save();
  return QuerySpells();
}

// Sobrecargada para añadir la posibilidad de mejorar el spell
public varargs int UseSpell(string name, mixed diff, mixed nomod, object scroll)
{
  int rc, apr;

  rc = ::UseSpell(name, diff, nomod);

  if (rc > 0) { // Ha usado el skill
    apr = QuerySpellLearnLevel(name);
  }
  else { // ha fallado
    apr = QuerySpellLearnLevel(name) >> 1; // Divido entre dos
  }

  //Es tu nivel del spell menor que el maximo permitido?
  if (QuerySpellLevel(name) < QueryMaxSpellLevel(name))
    //Si. Aprendes a usar mejor ese spell?
    if (d100() < apr)
      //Si, pero cada vez le cuesta mas;
      if (random(QueryMaxSpellLevel(name)) > QuerySpellLevel(name))
      {
        if (QuerySpellLearnMessage(name)) TO->catch_msg(QuerySpellLearnMessage(name));
        SetSpellLevel(name, QuerySpellLevel(name)+1);
        save();
      }

  return rc;
}

//------------------------------------------------------------------------------

public int AddPlayerSpell(string name, int level, int level_max, mixed stat)
/* [w] Función que se encarga de añadir un hechizo a un jugador realizando
   todas las comprobaciones oportunas como que puede memorizarlo y si
   el hechizo existe. Los valores que devuelve son:
      1    Si todo funciona correctamente
      0    Si no introduces ningún nombre de hechizo
     -1    Si no existe ese hechizo
     -2    Si no tiene suficiente nivel para memorizarlo
*/
{
 string spell;

 if (!name) return 0;
 name=lower_case(name);
 if (!spell=SPELL(name)) return -1;
 if (spell->QueryMemorizeLevel(QueryGuild())>QueryGuildLevel()) return -2;
 AddSpell(name, level, stat, level_max);
 return 1;
}

//------------------------------------------------------------------------------
