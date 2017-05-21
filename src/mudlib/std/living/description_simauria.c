/**
 * SIMAURIA '/std/living/description.c'
 */

#include "/secure/wizlevels.h"
#include <properties.h>
#include <attributes.h>
#include <messages.h>
#include <search.h>
#include <living.h>
#include <combat.h>
#include <config.h>
#include <colours.h>

inherit "/std/container/description";

/*--------------------------------------------------------------------------*/

public mixed QueryAttr(string name);    // std/living/attributes
public int QueryHP();                   // std/living/body
public int QueryMaxHP();                // std/living/body
public string QueryHealthMsg();         // std/living/body
public void DropOverload(); // std/living/restrictions
public varargs int QueryLoad();            // std/living/restrictions
public mixed QueryArmours();            // std/living/combat
public mixed QueryWeapons();            // std/living/combat
public mixed QueryHands();              // std/living/combat
public void DropHeart(int user);        // std/living/heart
public void GetHeart(int user);         // std/living/heart

public int QueryIsPlayer();             // forward
public int CanSeeObject(object ob);    // std/living/perception

/*--------------------------------------------------------------------------*/

private int aLState, aInvis, aActions, aMagicDef, aIsPet;
private int aHidden, aAlign;
private string aName, aRace, aCitizenship;
private string *aMsgIn, *aMsgOut, *aMMsgIn, *aMMsgOut;

private nosave object *aSeenBy;
private mixed raceObject;

private string presay = "", // <Presay> <Name> <title>
               title  = ""; // Ej: Pencamuds in the Dark Nyh -<{AnSiLoVeR}>-

//----------------------------------------------------------------------------
/**
 * Devuelve la luz que desprende el living, ya sea por que yo de por si
 * brillo o por que llevo algo encendido en mi inventario
 */
public int QueryBright() {
    return max(::QueryBright(), QueryIntLight());
}
/**
 * Cuando en un living cambia la luz interna (antorchas, lamparas, etc) esta
 * afecta al lugar donde se encuentre, asi que tendremos que notificar al
 * environment del cambio de mi luz cada vez que esto ocurra.
 * Por eso sobrecargo estas funciones y hago que llamen al emit_light que se
 * encarga justo de eso.
 */
public varargs void AddLightSource(object obj) {
    ::AddLightSource(obj);
    emit_light();
}
public varargs void RemoveLightSource(object obj) {
    ::RemoveLightSource(obj);
    emit_light();
}

/*--------------------------------------------------------------------------*/

public int QueryActions ()      { return aActions > 0 ? aActions : 1; }
public int SetActions (int i)   { return aActions = i; }

public int QueryHidden ()       { return aHidden; }
public int SetHidden (int i)    { return aHidden = i>0? (i>100?100:i) : 0; }

public int QueryInvis ()        { return aInvis; }
public int SetInvis (int i)     { return aInvis = i>0 ? 1 : 0; }

public object *QuerySeenBy() {return aSeenBy;}
public int AddSeenBy(object ob) {
  if (!objectp(ob)) return 0;
  if (!aSeenBy || !pointerp(aSeenBy)) return (aSeenBy=({ob})),1;
  aSeenBy+=({ob});
  return 1;
}
public int RemoveSeenBy(object ob) {
  if (!objectp(ob)) return 0;
  if (!aSeenBy || !pointerp(aSeenBy)) return (aSeenBy=({})), 1;
  aSeenBy -= ({ob});
  return 1;
}
public int ResetSeenBy() { return (aSeenBy=({})), 1; }

public int QueryMagicDefense ()     { return aMagicDef; }
public int SetMagicDefense (int i)  { return aMagicDef = i; }

public int QueryLState ()          { return aLState; }
public int SetLState (int i) {
    if (aLState == i) return aLState; // Ya estamos en ese estado.

    if (-1 == member( ({ LSTATE_NORMAL, LSTATE_GHOST, LSTATE_FROG }), i)) {
        return -1; // Error, estado desconocido
    }

    if (aLState == LSTATE_GHOST && i != LSTATE_NORMAL) {
        return -2; // De fantasma sólo puedes pasar a ser vivo
    }

    switch (aLState = i) {
    case LSTATE_NORMAL:
        if (TO->QueryHP()<0) TO->SetHP(1); // Ha resucitado!
        GetHeart(HEART_HEAL); // Por si estaba muerto.
        break;
    case LSTATE_GHOST:
        DropHeart(HEART_HEAL);
        break;
    case LSTATE_FROG:
        break;
    }

    DropOverload();

    return aLState;
}

public int QueryFrog() { return QueryLState() == LSTATE_FROG; }
public int SetFrog(int i) {
  if ((QueryLState() != LSTATE_GHOST) || i)
    SetLState(i ? LSTATE_FROG : LSTATE_NORMAL);
  return QueryLState() == LSTATE_FROG;
}

public int QueryGhost() { return QueryLState() == LSTATE_GHOST; }
public int SetGhost(int i) {
  return SetLState(i ? LSTATE_GHOST : LSTATE_NORMAL) == LSTATE_GHOST;
}

public string QueryRace ()        { return aRace; }
public string SetRace (string s)  {
/*
  if (aRace != s && !QueryLong())
  {
    aRace = s; // prevent endless recursion
    RACEMASTER->InitRace(TO, aRace);
  }
*/
  return aRace = s;
}

public varargs object QueryRaceObj(int reload) {
  string name;

  if (intp(raceObject) && raceObject && !reload)
    return 0;
  if (!objectp(raceObject)) {
    if (   catch(raceObject = RACEMASTER->RaceObject(QueryRace(), TO))
        || !raceObject)
      raceObject = -1;
  }
  return objectp(raceObject) ? raceObject : 0;
}

public string SetCitizenship(string s) { return aCitizenship = s; }
public string QueryCitizenship() { return aCitizenship; }


//-----------------------------------------------------------------------------

public varargs string QueryName(mixed true_name) {
  return ( QueryInvis() & !true_name) ? "Alguien" : aName;
}
public string SetName (string s) {
  return aName = SetShort(s);
}

public string QueryRealName () {
  return query_once_interactive(TO) ? getuid(TO) : lower_case(aName||"");
}
// No SetRealName()!

private void _announce_title() {
  if (TO->QueryPlayerStarted() && !QueryInvis())
    CHANNELMASTER->SendEmote("infomud", " "+QueryName(1)+" es ahora "+Short());
}

public string QueryPresay() { return presay || ""; }
public varargs string SetPresay(string s, int no_announce) {
  if (!stringp(s)) return QueryPresay();
  presay = s;
  if (no_announce&1) _announce_title();
  return QueryPresay();
}

public string QueryTitle() { return title || ""; }
public varargs string SetTitle(string t, int no_announce) {
  if (!stringp(t)) return QueryTitle();
  title = t;
  if (no_announce&1) _announce_title();
  return QueryTitle();
}

//-----------------------------------------------------------------------------

public int SetAlign (int v)      { return aAlign = v; }
public int QueryAlign ()         { return aAlign; }
public string QueryAlignString(int align) {
  int i;
  i = (1000 + align) * 17 / 2000;
  if (i > 16) i = 16; else if (i < 0) i = 0;
  return ({ "demoníaco", "cruel", "malvado", "odioso", "insoportable", "enfermo",
            "antisocial", "travieso", "neutral", "amistoso", "modoso", "bueno",
            "compasivo", "sagrado", "santo", "angelical", "divino"
         })[i];
}
public int UpdateAlign (int up) {
  return SetAlign( (9*QueryAlign())/10 - up);
}

public varargs string *QueryMsgIn (int sc) {
  if (sc || (sc = QueryLState()) == LSTATE_NORMAL)
    return aMsgIn || ({ "llega", "Alguien llega" });
  switch (sc) {
    case LSTATE_FROG: return ({ "llega saltando", "Oyes como unos saltitos" });
    case LSTATE_GHOST: return ({ "llega flotando", "Sientes un escalofrío" });
  }
  return ({ "llega", "Alguien llega" });
}
public string *SetMsgIn (string *m) {
  aMsgIn = m;
  return QueryMsgIn();
}

public varargs string *QueryMsgOut (int sc) {
  if (sc || (sc = QueryLState()) == LSTATE_NORMAL)
    return aMsgOut || ({ "se va", "Alguien se va" });
  switch (sc) {
    case LSTATE_FROG: return ({ "se va saltando", "Oyes como unos saltitos" });
    case LSTATE_GHOST: return ({ "se va flotando"
                               , "Sientes un escalofrío"});
  }
  return ({ "se va", "Alguien se va" });
}
public string *SetMsgOut (string *m) {
  aMsgOut = m;
  return QueryMsgOut();
}

public varargs string *QueryMMsgIn (int sc) {
  if (sc || (sc = QueryLState()) == LSTATE_NORMAL)
    return aMMsgIn || ({ "aparece de entre una nube de humo"
                       , "Oyes un suave 'flop'" });
  switch (sc) {
    case LSTATE_FROG: return ({ "cae del cielo golpeando el suelo, y maldice a las cigueñas"
                              , "Oyes una voz croando maldiciones" });
    case LSTATE_GHOST: return ({ "aparece inundandolo todo de un frío sepulcral"
                               , "Sientes un frío sepulcral en tus venas"});
  }
  return ({ "aparece de entre una nube de humo", "Oyes un suave 'flop'" });
}
public string *SetMMsgIn (string *m) {
  aMMsgIn = m;
  return QueryMMsgIn();
}

public varargs string *QueryMMsgOut (int sc) {
  if (sc || (sc = QueryLState()) == LSTATE_NORMAL)
    return aMMsgOut || ({ "desaparece en una nube de humo"
                        , "Oyes un suave 'swop'" });
  switch (sc) {
    case LSTATE_FROG: return ({ "es capturado de repente por una cigueña"
                              , "Algo rápido y alado pasa rozándote" });
    case LSTATE_GHOST: return ({ "gime agónicamente y desaparece"
                               , "De alguna manera te sientes más comodo" });
  }
  return ({ "desaparece en una nube de humo", "Oyes un suave 'swop'" });
}
public string *SetMMsgOut (string *m) {
  aMMsgOut = m;
  return QueryMMsgOut();
}


public varargs int QuerySize() {
  return (QueryLState() == LSTATE_FROG) ? P_SIZE_SMALL : ::QuerySize();
}

//--------------------------------------------------------------------------
/* static */ string *_armours ()

// Auxiliary function, used to build the (internal) long description of
// livings.

{
  mapping m;
  mixed   arm;

  arm = QueryArmours();

  if (pointerp(arm)) return map_objects(arm - ({ 0 }), "Short");
  m = arm || ([]);
  return map_objects(m_indices(m)-({m[AT_SKIN]}), "Short");
}

//--------------------------------------------------------------------------
static string *_list_weapons (string poss)

// Auxiliary function, used to build the (internal) long description of
// livings.

{
  string *result, str;
  int i, h, j;
  mixed *hands, arr;

  result = ({});
  hands = QueryHands();
  arr = QueryWeapons();
  if (sizeof(arr) && sizeof(arr -= ({ 0 }))) {
    object weapon;

    for (i = 0; i < sizeof(arr); i++) {
      weapon = arr[i];
      if (!objectp(weapon)) continue;
      str = weapon->Short() +" con";
      for (h = 0, j = 0; h < sizeof(hands); h++) {
        if (hands[h][HAND_WEAPON] == weapon) {
          str += (j++?" y ":" ")+poss+" "+hands[h][HAND_SHORT];
        }
      }
      result += ({ str });
    }
  }

  return result;
}

//--------------------------------------------------------------------------
/* static */ string *_weapons (string possessive)

// Auxiliary function, used to build the (internal) long description of
// livings.

{
  string *result, str;
  int i, h, j;
  mapping m, hands;
  mixed *ind, *hind;

  if (!mappingp(QueryHands())) return _list_weapons(possessive);
  hands = QueryHands();
  hind = m_indices(hands);
  m = QueryWeapons();
  result = ({});
  if (m) {
    object weapon;

    ind = m_indices(m);
    for (i = 0; i < sizeof(ind); i++) {
      weapon = ind[i];
      str = weapon->Short() +" con";
      for (h = 0, j = 0; h < sizeof(hind); h++) {
        if (hands[hind[h], HAND_OBJ] == weapon) {
          str += (j++?" y ":" ")+possessive+" "+hind[h];
        }
      }
      result += ({ str });
    }
  }

  return result;
}

//--------------------------------------------------------------------------
/* static */ string *_hands ()

// Auxiliary function, used to build the (internal) long description of
// livings.

{
  string * result;
  mixed hands;
  mapping mhands, obj;
  int i;

  result = ({});
  hands = QueryHands();

  if (!mappingp(hands))
  {
    for (i = 0; i < sizeof(hands); i++)
    {
      if (!sizeof(hands[i])) continue;
      obj = hands[i][HAND_WEAPON];
      if (   objectp(obj)
          && !obj->Query(P_EQUIPPED)
          && -1 == member(result, obj)
         )
      {
        result += ({ obj });
      }
    }
  }
  else
  {
    mhands = (mapping) hands;
    hands = m_indices(mhands);
    for (i = 0; i < sizeof(hands); i++)
    {
      obj = mhands[hands[i], HAND_OBJ];
      if (   objectp(obj)
          && !obj->Query(P_EQUIPPED)
          && -1 == member(result, obj)
         )
      {
        result += ({ obj });
      }
    }
  }

  return map_objects(result, "Short") - ({ "", 0 });
}

private string *_others()
{ // Devuelve los shorts de todo aquello equipado que NO esté en las manos, NO
  // sea arma y NO sea armadura... ¿habrá algo?
  object *other;

  other = filter(all_inventory(TO) - QueryArmours() - QueryWeapons(), (: $1->QueryEquipped() :));

  foreach (mixed *hand: QueryHands())
  { // Quito lo que lleve en las manos
    if (!sizeof(hand)) continue;
    other -= ({ hand[HAND_WEAPON] });
  }

  return map_objects(other - ({ 0 }), "Short");
}

//--------------------------------------------------------------------------
public string QueryHealthLoadMsg (int third)
{
  string str;

  switch (QueryLoad())
  {
    case -50 .. 0:
      str = (third? " y va " : " y vas ")+ "descargad" + QueryGenderEndString();
      break;
    case   1 .. 33:
      str = (third? " y va " : " y vas ")+ "ligeramente cargad" + QueryGenderEndString();
      break;
    case  34 .. 66:
      str = (third? " y va " : " y vas ")+ "medianamente cargad" + QueryGenderEndString();
      break;
    case  67 .. 100:
      str = (third? " y va " : " y vas ")+ "muy cargad" + QueryGenderEndString();
      break;
    default:
      str = (third? " y va " : " y vas ")+ "sobrecargad" + QueryGenderEndString();
      break;
  }
  return QueryHealthMsg()+str;
}

//--------------------------------------------------------------------------
protected string *_long (string str)

// Auxiliary function, used to build the (internal) long description of
// livings.

{
  string *strs, *result;
  string cp, pr;
  int i;

  strs = map_objects(all_inventory(), "Query", P_EXTRALOOK) - ({ 0, "" });
  if (sizeof(strs))
    result = ({ str || "", implode(strs, ""), "", "", "", "", "" });
  else
    result = ({ str || "", "", "", "", "", "", "" });

  pr = QueryPronoun();
  cp = capitalize(pr);

  result[2] = "Está "+QueryHealthLoadMsg(1)+".\n";

  if (i = sizeof(strs = _armours()))
  {
    if (i == 1) str = strs[0];
    else str = implode(strs[0..<2], ", ")+" y "+strs[<1];
    result[3] = "Está protegid"+QueryGenderEndString()+" con "+str+".\n";
  }

  if (i = sizeof(strs = _weapons(QueryPossessive()) - ({ "" }) ))
  {
    if (i == 1) str = strs[0];
    else str = implode(strs[0..<2], ", ")+" y "+strs[<1];
    result[4] = "Empuña "+str+".\n";
  }

  if (i = sizeof(strs = _hands()))
  {
    if (i == 1) str = strs[0];
    else str = implode(strs[0..<2], ", ")+" y "+strs[<1];
    result[5] = "Sostiene "+str+".\n";
  }

  if (i = sizeof(strs = _others()))
  {
    if (i == 1) str = strs[0];
    else str = implode(strs[0..<2], ", ")+" y "+strs[<1];
    result[6] = "Está equipad"+QueryGenderEndString()+" con "+str+".\n";
  }

  return result;
}

//--------------------------------------------------------------------------
// Adapt the perceptional functions.
// Also take care of invisibility and ghostness.

public varargs string Short (string what) {
  mixed str, invis;
  int state;

  if (TP && TP != TO && !TP->CanSeeObject(TO))
    return 0;

  state = QueryLState();
  if (state == LSTATE_FROG) {
    str = QueryRealName();
    if (!str) str = "una rana "+( QueryInvis() ? "invisible":"verde");
    else      str += " la rana "+( QueryInvis() ? "invisible":"verde");
  }
  else {
    invis = QueryInvis() ? "invisible ": "";
    str = description::Short();
    if (pointerp(str)) {
      if (state < sizeof(str))
        return str[state];
      str = str[0];
    }
    str = str || QueryName();
    str = (state == LSTATE_GHOST ? ("el fantasma "+invis) : invis)+str;
  }
  return str;
}

public varargs string IntShort (string what) {
  mixed str, invis;
  int state;

  if (TP && !TP->CanSeeObject(TO))
    return 0;

  state = QueryLState();
  if (state == LSTATE_FROG) {
    str = QueryRealName();
    if (!str) str = "una rana "+(QueryInvis() ? "invisible":"verde");
    else      str += " la rana"+(QueryInvis() ? "invisible":"verde");
  }
  else {
    invis = QueryInvis() ? "invisible ": "";
    str = description::IntShort();
    if (pointerp(str)) {
      if (state < sizeof(str))
        return str[state];
      str = str[0];
    }
    str = str || QueryName();
    str = (state == LSTATE_GHOST ? ("el fantasma "+invis) : invis)+str;
  }
  return "llevado por "+str;
}

public varargs string Long (string what) {
  mixed str, invis, desc;

  if (QueryInvis() && QueryHidden())
    invis = "Actualmente está invisible y además se está ocultando.\n";
  else if (QueryInvis())
    invis = "Actualmente está invisible.\n";
  else if(QueryHidden())
    invis = "Actualmente se está ocultando.\n";
  else
    invis = "";

  desc = QueryAttr(A_DESCRIPTION);

  switch (QueryLState()) {
  case LSTATE_FROG:
    str = QueryRealName();
    if (!str) str = "una rana "+(QueryInvis() ? "invisible":"verde")+".\n";
    else      str = str+", una rana "+(QueryInvis() ? "invisible":"verde")+".\n";
    str = "Es "+str;
    if (pointerp(desc) && LSTATE_FROG >= sizeof(desc) && desc[LSTATE_FROG])
      str += desc[LSTATE_FROG];
    break;
  case LSTATE_GHOST:
    str = description::Long();
    if (!pointerp(str) || LSTATE_GHOST >= sizeof(str) || !str[LSTATE_GHOST])
      str = "Es "+Short()+".\n";
    else
      str = str[LSTATE_GHOST]+invis;
    if (stringp(desc))
      str += desc;
    else if (pointerp(desc) && LSTATE_GHOST >= sizeof(desc) && desc[LSTATE_GHOST])
      str += desc[LSTATE_GHOST];
    break;
  default:
    str = description::Long();
    if (pointerp(str)) {
      if (LSTATE_NORMAL >= sizeof(str))
        str = "Es "+Short()+".\n";
      else
        str =  str[LSTATE_NORMAL]+invis;
    }
    if (stringp(desc))
      str += desc;
    else if (pointerp(desc) && LSTATE_NORMAL >= sizeof(desc) && desc[LSTATE_NORMAL])
      str += desc[LSTATE_NORMAL];
  }
  return implode(_long(str), "");
}

public varargs string ExaLong (string what) {
#if 0
  return what ? description::ExaLong(what) : Long();
#else
  return Long(what);
#endif
}

public varargs string IntLong (string what) {
  mixed str, invis;

  if (QueryInvis())
    invis = "Actualmente está invisible.\n";
  else
    invis = "";

  switch (QueryLState()) {
  case LSTATE_FROG:
    str = QueryRealName();
    if (!str) str = "una rana "+(QueryInvis() ? "invisible":"verde")+".\n";
    else      str = str+", una rana "+(QueryInvis() ? "invisible":"verde")+".\n";
    str = "Te lleva "+str;
    break;
  case LSTATE_GHOST:
    str = description::IntLong();
    if (!pointerp(str) || LSTATE_GHOST >= sizeof(str) || !str[LSTATE_GHOST])
      str = "Te lleva "+Short()+".\n";
    else
      str = str[LSTATE_GHOST]+invis;
    break;
  default:
    str = description::IntLong();
    if (pointerp(str)) {
      if (LSTATE_NORMAL >= sizeof(str))
        str = "Te lleva "+IntShort()+".\n";
      else
        str =  str[LSTATE_NORMAL]+invis;
    }
  }
  return implode(_long(str), "");
}

public varargs string ExaIntLong (string what) {
  return what ? description::ExaIntLong(what) : IntLong();
}

public string QueryPreContent() {
  return capitalize("Lleva:\n");
}

public varargs string Content(string what, mixed excl, object pl) {
  mixed m;

  if (intp(excl) && excl) {
    excl = ({});
    m = QueryArmours();
    if (pointerp(m)) excl += m - ({ 0 });
    else if (mappingp(m)) excl += m_values(m) - ({ m[AT_SKIN] });
    m = QueryWeapons();
    if (pointerp(m)) excl += m - ({ 0 });
    else if (mappingp(m)) excl += m_indices(m);
  }
  return ::Content(what, excl, pl);
}

/*--------------------------------------------------------------------------*/
// Classification of the living.

public int QueryIsPlayer() { return query_once_interactive(TO);}

public int QueryIsNPC()    { return living(TO) && !query_once_interactive(TO) && !Query(P_IS_PET);}

public int SetIsPet(int i) { return aIsPet = i; }
public int QueryIsPet() { return aIsPet; }

/*--------------------------------------------------------------------------
 * Search an item in the environment and the inventory with respect to the
 * visibility.
 */

public varargs mixed Search (mixed what, int mode) {
  return search(TO, what, mode&(~(SM_LOCATE)));
}

public varargs mixed * SearchM (mixed what, int mode, closure pred) {
  return searchm(TO, what, mode&(~(SM_LOCATE)), pred);
}

/*--------------------------------------------------------------------------
 * The id() function which takes respect to some attributes.
 */

public int id(string s) {
  int state;
  if (!s || (QueryInvis() && TP != TO && !IS_LEARNER(TP)))
    return 0;
  if (::id(s)) return 1;
  s = lower_case(s);
  state = QueryLState();
  return    s == lower_case(QueryName()||"")
         || s == lower_case(QueryRealName()||QueryName()||"")
         || (!query_once_interactive(TO) && s == lower_case(QueryRace()||""))
         || (state == LSTATE_GHOST && s == "fantasma")
         || (state == LSTATE_FROG  && s == "rana")
         || (TO == TP && (s == "mi" || s == "yo"))
        ;
}
