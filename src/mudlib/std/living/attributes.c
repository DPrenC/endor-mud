/* SIMAURIA 'std/living/attributes.c'
   ==================================
   [h] Hyp@nightfall
   [m] Mateese@nightfall
   [w] Woo
   [h] Nyh@Simauria

   14-06-93 [h,m] Creacion de este archivo.
   28-12-96 [w] Comprobacion, nada modificado.
   08-12-04 [h] Retoco y borro cosas.
*/

#include "/secure/wizlevels.h"
#include <properties.h>
#include <attributes.h>

/*===========================================================================
 * The mapping with all attributes and the variables for some of the
 * hardcoded attributes.
 */
private mapping pAttrs = ([]);
private mapping pAttrBoni = ([]);

/*===========================================================================*/
// Internal purposes

public int SetBonus(string aname, int val)
{
  if (!pAttrBoni && val)
    pAttrBoni = ([ aname : val ]);
  else if (pAttrBoni && !val)
  {
    if (!sizeof(pAttrBoni = m_delete(pAttrBoni, aname)))
      pAttrBoni = ([]);
  }
  else
    pAttrBoni[aname] = val;
  return val;
}

public int QueryBonus(string aname)
{
  return pAttrBoni && pAttrBoni[aname];
}

public int AddBonus(string aname, int delta)
{
  return SetBonus(aname, (pAttrBoni && pAttrBoni[aname])+delta);
}

/*===========================================================================
 * The querying and setting functions for the attributes.
 * NOTE: when an softcoded attribute is set, several checks are made to keep
 *       memory usage of the attribute mapping low. This means attributes set
 *       to zero will automatically be removed and if the mapping is empty,
 *       the mapping will be set to zero.
 *       If you KNOW that you are dealing with a softcoded attribute call
 *       the functions with additional last argument = SOFTCODED.
 */
public varargs mixed QueryAttr(string aname, int sc) {
  mixed ret;

  return (!sc && call_resolved(&ret, TO, "Query" + aname)) ?
    ret : (pAttrs ? pAttrs[aname] : 0);
}

public varargs mixed SetAttr(string aname, mixed arg, int sc) {
  mixed ret;

  if (!sc && call_resolved(&ret, TO, "Set" + aname, arg)) return ret;
  if (pAttrs) {
    if (arg) return pAttrs[aname] = arg;
    if (sizeof(pAttrs = m_delete(pAttrs, aname)) == 0) pAttrs = ([]);
  }
  else if(arg)
  {
    pAttrs = ([ aname : arg ]);
    return arg;
  }
  return 0;
}

public void RemoveAttr(string aname) {
  if(pAttrs)
  {
    if (sizeof(pAttrs = m_delete(pAttrs, aname)) == 0)
      pAttrs = ([]);
  }
  if(pAttrBoni)
  {
    if (sizeof(pAttrBoni = m_delete(pAttrBoni, aname)) == 0)
      pAttrBoni = ([]);
  }
}

private static int _mod_attr( string aname, int sc, int bonus
                            , int delta, int min, int max)
{
  int val;
  val = QueryAttr(aname, sc)+delta;
  if (min < max)
  {
    if (val > max && delta > 0)
    {
      delta -= (val-max);
      val = max;
    }
    else if (val < min && delta < 0)
    {
      delta += (min-val);
      val = min;
    }
  }
  if (bonus)
    AddBonus(aname, delta);
  return SetAttr(aname, val, sc);
}

// No usada nunca
public varargs int ChangeAttr(string aname, int delta, int min, int max)
{
  return _mod_attr(aname, 0, 0, delta, min, max);
}

// Usado en algunos sitios como conjuros o fuente crowy o objetos magicos.
public varargs int ModifyAttr(string aname, int delta, int min, int max)
{
  return _mod_attr(aname, 0, 1, delta, min, max);
}

//Se usa
public mixed SetAttribute (mixed attr, mixed val) {
  return SetAttr(attr, val, 1);
}

//Se usa
public mixed QueryAttribute (mixed attr) {
  return QueryAttr(attr, 1);
}

//Se usa
public void RemoveAttribute(string aname) {
  RemoveAttr(aname);
}

// No usado
public varargs int ChangeAttribute(string aname, int delta, int min, int max)
{
  return _mod_attr(aname, 1, 0, delta, min, max);
}

//No usado
public varargs int ModifyAttribute(string aname, int delta, int min, int max)
{
  return _mod_attr(aname, 1, 1, delta, min, max);
}

/*===========================================================================
 * The querying and setting functions for all default (soft- and hardcoded)
 * attributes.
 * NOTE: we do not know, if the actual object has turned some softcoded
 *       attributes into hardcoded attributes. So we HAVE to use
 *       the Query- and SetAttr() function to get/set the correct
 *       values. So these functions have a VERY high evaluation cost.
 */


//Usado solo en la quest del coliseum q no esta en juego
//Y ademas, esa quest ta codeada fea.
public varargs mapping QueryAttrs(int sc) {
  mapping map;
  mixed ret;
  int s;
  string aname, *ind;

  map = pAttrs || ([]);
  if (!sc)
  {
    ind = LIVING_ATTRS;
    for(s = sizeof(ind); s--;)
    {
      // "Cryptic" you think? Yes, but we must be sure to get the
      // true values.
      aname = ind[s];
      map[aname] = call_resolved(&ret, TO, "Query" + aname, 1)
                   ? ret : (pAttrs ? pAttrs[aname] : 0);
    }
  }
  return map;
}

// Copy the given attrs mapping into the hardcoded attrs or pAttrs.

public varargs mapping SetAttrs(mapping attrs, int sc) {
  mixed *ind, *val;
  int s;

  if (sc)
  {
    if (!attrs)
      pAttrs = ([]);
    else
      pAttrs = copy(attrs);
    return attrs;
  }
  pAttrs = ([]);
  ind = m_indices(attrs);
  val = m_values(attrs);
  for(s = sizeof(attrs); s--; val[s] = SetAttr(ind[s], val[s]));
  return mkmapping(ind, val);
}

// Shortcut to handle just the softcoded attributes.

public mapping QueryAttributes() {  return QueryAttrs(1); }
public mapping SetAttributes (mixed a)
{
  mapping attr;
  if (pointerp(a))
    return SetAttrs(mkmapping(a[0], a[1]), 1);
  return SetAttrs(a, 1);
}

// Undo any remembered modification.
// Para quitar los donificadores de todos los atributos
public void RestoreAttrs()
{
  mixed *ind, index;
  int i;

  if (pAttrBoni)
  {
    ind = m_indices(pAttrBoni);
    for (i = sizeof(ind); i--; )
    {
      index = ind[i];
      SetAttr(index, QueryAttr(index)-pAttrBoni[index]);
    }
    pAttrBoni = ([]);
  }
}

/*===========================================================================*/

//Usada solo en el racemaster
public mapping QueryStats()
{
  mapping rc;
  string *statlist;
  int i;

  statlist = STATS;
  rc = ([]);
  for (i = 0; i < sizeof(statlist); i++)
    rc[statlist[i]] = QueryAttr(statlist[i]);
  return rc;
}

//Usada solo en el racemaster
public mapping SetStats(mixed stats)
{
  mapping rc;
  string *statlist;
  int i, val;

  statlist = STATS;
  if (pointerp(stats))
  {
    for (i = 0; i < sizeof(stats[0]); i++)
      SetAttr(stats[0][i], stats[1][i]);
  }
  else if (mappingp(stats))
  {
    for (i = 0; i < sizeof(statlist); i++)
      if (m_contains(&val, stats, statlist[i]))
        SetAttr(statlist[i], val);
  }
  return QueryStats();
}
