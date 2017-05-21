/**
 * ENDOR-MUD'/std/thing/description.c'
 */

#include <wizlevels.h>
#include <colours.h>
#include <properties.h>
#include <magia.h>

#undef ENV
#define ENV      environment()

#define SUBID  (to_string(TO)+":subid")

public mixed Query(string name); // std/base

//--- variables globales --------------------------------------------------

private string *pIds, *pAds, *pCids, *pCads;
private mapping pExtra, pSubdetails, pSubread;
private mixed pLong, pExaLong;
private mixed pShort, pSmell, pNoise, pReadMsg;
private mixed pDieMsg; // El mensaje que sale si este objeto mata
private int pValue, pSize, pMagic;
private int pBright = 0; // Lo que yo brillo (hacia fuera)
private int pGender; // Los things también pueden tener género

private nosave string * cSubdetails, * cSubread, * cSuball;

private nosave string pLastId, pLastVerb;
private nosave object pLastPl;

//--- private functions to keep memory use low ------------------------------

private void clear_subcache()
{
  cSubdetails = 0;
  cSubread = 0;
  cSuball = 0;
}

private void make_subcache()
{
  if (!cSuball)
  {
    cSubdetails = m_indices(pSubdetails || ([]));;
    cSubread    = m_indices(pSubread    || ([]));;
    cSuball = cSubdetails + cSubread;
  }
}

//--- flatten the keys of a mapping
private mapping flat_keys(mapping map)
{
  mixed *ind, val;
  int    i, j;
  if (!map)
    return 0;
  ind = m_indices(map);
  for (i = sizeof(ind); i--; )
    if (pointerp(ind[i]))
    {
      val = map[ind[i]];
      m_delete(map, ind[i]);
      for (j = sizeof(ind[i]); j--; )
        map[ind[i][j]] = val;
    }
  return map;
}

private void map_add(mapping map, mixed key, mixed val) {
  if (!map)
    map = ([]);
  if (stringp(val))
    val = to_string(quote(val));
  else if (pointerp(val) && sizeof(val) >= 3 && val[0] == "#call_other")
  {
    val[0] = SF(call_other);
    val = lambda(({'w}), val+({'w}));
  }
  if (pointerp(key))
  {
    if (pointerp(val))
      val = quote(val);
    map += mkmapping(key, map(key, lambda(0, val)));
  }
  else
    map[key] = val;
}

private void map_rm(mapping map, mixed key) {
  if (map) {
    if (stringp(key))
      m_delete(map, key);
    else
      map -= mkmapping(key);
    if (!sizeof(map))
      map = 0;
  }
}

//--- identificacion de objetos ------------------------------------------

public string *QueryIds()          { return pIds; }
public string *SetIds(string *ids) {
  return pIds = sizeof(ids) ? map(ids, SF(norm_id)) : 0;
}

public string *QueryAds()          { return pAds; }
public string *SetAds(string *ads) {
  return pAds = sizeof(ads) ? map(ads, SF(norm_id)) : 0;
}

public string *QueryClassIds()     { return pCids; }
public string *SetClassIds(string *ids) {
  return pCids = sizeof(ids) ? map(ids, SF(norm_id)) : 0;
}

public string *QueryClassAds()     { return pCads; }
public string *SetClassAds(string *ads) {
  return pCads = sizeof(ads) ? map(ads, SF(norm_id)) : 0;
}

protected mixed _add_id(mixed *prop, mixed str) {
  if (pointerp(str))
    str = map(str, SF(norm_id)) + ({});
  else
    str = ({ norm_id(str) });
  return prop
         ? (prop += str - (prop & str))
         : prop = str;
}

protected mixed _del_id(mixed *prop, mixed str) {
  if (pointerp(str))
    str = map(str, SF(norm_id)) + ({});
  else
    str = ({ norm_id(str) });
  return prop && (prop -= str);
}

public string *AddId(mixed str)      { return pIds = _add_id(pIds, str); }
public string *AddClassId(mixed str) { return pCids = _add_id(pCids, str); }
public string *AddAdjective(mixed str) { return pAds = _add_id(pAds, str); }
public string *AddClassAdj(mixed str)  { return pCads = _add_id(pCads, str); }

public string *RemoveId(mixed str)      { return pIds = _del_id(pIds, str); }
public string *RemoveClassId(mixed str) { return pCids = _del_id(pCids, str); }
public string *RemoveAdjective(mixed str) { return pAds = _del_id(pAds, str); }
public string *RemoveClassAdj(mixed str) { return pCads = _del_id(pCads,str); }

// Take a string and check if it matches an adjective/id combo.
// If we have some adjectives, then first cut them all out of the given
// string and then check if it matches.

protected int _id(string str, string * ids, string * ads) {
  int i, pos;
  string work, tmp;

  //[i] Retornar 0 si el objeto está escondido.
  if (Query(P_HIDDEN) &&
      PO->Query(P_SEE_HIDDEN)<Query(P_HIDDEN)) return 0;

  //[t] No devuelve Ids si el objeto es invisible y TP player.
  if (Query(P_INVIS) &&
      PO->Query(P_SEE_INVIS)<Query(P_INVIS)) return 0;

  work = str = str && lower_case(str);
  if (str && sizeof(ids))
    {
      make_subcache();

      // Check for a subdetail
      if (sizeof(cSuball)
      &&  (   1 <= (i = strstr(work, " de "))
           || 1 <= (i = strstr(work, " en "))
          )
      &&  -1 != member(cSuball, work[0..i-1])
         )
      {
        if (TP)
          TP->SetCmdData(SUBID, work[0..i-1]);
        work = work[i+4..];
      }
      else if (TP)
        TP->SetCmdData(SUBID, 0);

      if (sizeof(ads -= ids))
      {
        // [Kastwey] lo cambio, que creo que de esta forma es más rápido
        work = implode(explode(work, " ") - ads, " ");
        work = norm_id(work);
      }

	     if (member(ids, work) >= 0)
      {
        pLastId = str;
        pLastVerb = query_verb();
        pLastPl = TP;
        return 1;
      }
    }
  pLastId = 0;
  pLastVerb = 0;
  pLastPl = 0;
  if (TP) TP->SetCmdData(SUBID, 0);
  return 0;
}

// Take a string and check if it matches on of our ids.
// Consider both the objeto ids and the class id.

public int id(string str) {
  str = str && lower_case(str);
  if (!pIds && str == "objeto" && IS_WIZARD(TP))
    {
      pLastId = str;
      pLastVerb = query_verb();
      pLastPl = TP;
      if (TP)
        TP->SetCmdData(SUBID, 0);
      return 1;
    }
  return _id(str, (pIds||({}))+(pCids||({})), (pAds||({}))+(pCads||({})) );
}

// Take a string and check if it matches on of our ids.
// First check the objeto ids, then the class id.

public int class_id(string str) {
  str = str && lower_case(str);
  if (!pIds && str == "objeto" && IS_WIZARD(TP))
    {
      pLastId = str;
      pLastVerb = query_verb();
      pLastPl = TP;
      if (TP)
        TP->SetCmdData(SUBID, 0);
      return 1;
    }
  return _id(str, (pCids||({})), (pAds||({}))+(pCads||({})) );
}

public string QueryLastId()            { return pLastId; }
public string SetLastId(string id)     { return pLastId; }
public string QueryLastVerb()          { return pLastVerb; }
public string SetLastVerb(string v)    { return pLastVerb; }
public object QueryLastPlayer()        { return pLastPl; }
public object SetLastPlayer(object pl) { return pLastPl; }

//--- basic properties of a thing -------------------------------------------

public int QueryValue()             { return pValue; }
public int SetValue(int i)          { return pValue = i; }

public mapping QueryExtraDesc()     { return pExtra || ([]); }
public mapping SetExtraDesc(mapping m) { return pExtra = m; }

public string QueryLong()           { return (string)funcall(pLong); }
public string SetLong(mixed s)      { return (string)funcall(pLong = s); }

public string QueryExaLong()        { return (string)funcall(pExaLong); }
public string SetExaLong(mixed s)   { return (string)funcall(pExaLong = s); }

public string QueryReadMsg()        { return (string)funcall(pReadMsg); }
public string SetReadMsg(mixed s)   { return (string)funcall(pReadMsg = s); }

public string QueryShort()          { return (string)funcall(pShort); }
public string SetShort(mixed s)     { return (string)funcall(pShort = s); }

public varargs string QuerySmell(string what) { return (string)funcall(pSmell); }
public string SetSmell(mixed s)               { return (string)funcall(pSmell = s); }

public varargs string QueryNoise(string what) { return (string)funcall(pNoise); }
public string SetNoise(mixed s)             { return (string)funcall(pNoise = s); }

public varargs mapping QuerySubDetails()    { return pSubdetails; }
public mapping SetSubDetails(mapping m)     { clear_subcache(); return pSubdetails = flat_keys(m); }

public varargs mapping QuerySubReadMsgs()   { return pSubread; }
public mapping SetSubReadMsgs(mapping m)    { clear_subcache(); return pSubread = flat_keys(m); }

public int QuerySize()          { return pSize; }
public int SetSize(int i)       { return pSize = i; }

public int QueryMagic()         { return pMagic; }
public int SetMagic(int i)      { return pMagic = i; }

public string SetDieMsg(mixed s)    { return (string)funcall(pDieMsg = s); }
public string QueryDieMsg()         { return (string)funcall(pDieMsg); }

public int QueryGender () { return pGender; }
public int SetGender (int i) {
  switch (i) {
    case GENDER_MALE:
    case GENDER_FEMALE:
      pGender = i;
      break;
    default: pGender = GENDER_OTHER;
  }
  return QueryGender();
}

/****************************************************************************/
//-----------------------------------------------------------------------------
// Gender supporting functions.

// Sufijo para sustantivos del tipo /-o/-a (ej. elf[o], elf[a])
public string QueryGenderEndString() {
  return ({ " ", "o", "a" })[QueryGender()];
}

// Sufijo para sustantivos del tipo //-a  (ej. dragon[], dragon[a])
public string QueryGenderEndString2() {
  return ({ "", "", "a" })[QueryGender()];
}

// Artículo determinado el/el/la
public string QueryArtDetString() {
  return ({ "el", "el", "la" })[QueryGender()];
}

// Artículo indeterminado un(o)/un/una
public string QueryArtIndString() {
  return ({ "un", "un", "una" })[QueryGender()];
}

// Género
public string QueryGenderString() {
  return ({ "neutro", "masculino", "femenino" })[QueryGender()];
}

// Pronombre
public string QueryPronoun() {
  return ({ "ello", "el", "ella" })[QueryGender()];
}

// Posesivo
public string QueryPossessive() {
  return ({ "su", "su", "su" })[QueryGender()];
}

// Objetivo
public string QueryObjective() {
  return ({ "ello", "el", "ella" })[QueryGender()];
}

// End gender supporting functions.
//-----------------------------------------------------------------------------
/****************************************************************************/

//--- light handling of a thing ---------------------------------------------
/** public varargs int emit_light(int l)
emit_light() -> Le digo al environment la luz q desprendo.
*/
public void emit_light() {
    //dtell("nyh",sprintf("%O llamó a %O->emit_light()\n", PO, TO));
    if (ENV) ENV->AddLightSource(TO);
}

public int QueryBright()    { return pBright; }
public int SetBright(int l) {
    pBright = l;
    emit_light();
    return QueryBright();
}

// Compatibilidad
public int QueryLight()     { return QueryBright(); }
public int SetLight(int i)  { return SetBright(i); }

//--- adding subdetails -----------------------------------------------------

public varargs void AddSubDetail(mixed det, mixed desc, string exa) {
  if (stringp(desc) && stringp(exa))
    desc = ({ desc, exa });
  map_add(&pSubdetails, det, desc);
  clear_subcache();
}

public void AddSubReadMsg(mixed k, mixed v) { map_add(&pSubread, k, v); clear_subcache(); }

//--- removing subdetails ----------------------------------------------------

public void RemoveSubDetail(mixed k) { map_rm(&pSubdetails, k); clear_subcache(); }
public void RemoveSubReadMsg(mixed k)  { map_rm(&pSubread, k); clear_subcache(); }

//--- searching for a subdetail --------------------------------------------

public mixed GetSubDetail(string str) {
  //dtell("nyh",sprintf("%O->GetSubDetail(%O)\n", TO, str));
  return pSubdetails && funcall(pSubdetails[str], str);
}

public string GetSubReadMsg(string str) {
  return pSubread && funcall(pSubread[str], str);
}

//--- Actual appearance -----------------------------------------------------

public string * filterExtra (string prop) {
  mixed data, tmp;
  int   i;
  string *rc;

  if (!(data = QueryExtraDesc()))
    return ({});
  data = map(m_values(data), SF(funcall));
  rc = allocate(sizeof(data));
  for (i = 0; i < sizeof(data); i++) {
    if (mappingp(data[i]) && stringp(tmp = funcall(data[i][prop])))
      rc[i] = tmp;
  }
  return rc - ({ 0, "" });
}

public varargs string Long(string what)  {
  string subid = 0;

  if (TP && (subid = TP->QueryCmdData(SUBID)))
  {
    mixed rc;
    rc = GetSubDetail(subid) || "No ves nada en especial.\n";
    return (pointerp(rc) ? rc[0] : rc);
  }
  return QueryLong()+implode(filterExtra(P_LONG), "");
}
public varargs string ExaLong(string what)  {
  mixed rc;
  string subid;

  subid = 0;
  if (TP && (subid = TP->QueryCmdData(SUBID)))
  {
    rc = GetSubDetail(subid) || "No ves nada en especial.\n";
    return pointerp(rc) ? rc[1] : "No ves nada en especial.\n"+rc;
  }
  rc = QueryExaLong();
  return (rc ? rc : "No ves nada en especial.\n"+QueryLong())
         +implode(filterExtra(P_LONG), "");
}
public varargs string Short(string what) {
  string *rc, sh;
  if (!(sh = QueryShort()) || sh == "") return sh;
  return sh+implode(filterExtra(P_SHORT), "");
}
public varargs string InvShort(string what) {
  string w;

  // Objetos invisibles, inwizibles, escondidos y mágicos
  w = capitalize(Short(what)||"");
  if (Query(P_MAGIC) && (TP->Query(MP_DETECTMAGIC) || IS_LEARNER(TP))) {
    w="~"+w+"~";
  }
  if (Query(P_INWIZ)) {
    if (IS_LEARNER(TP)) return("<("+ w + ")>");
    return "";
  }
  if (Query(P_INVIS)) {
    if (TP->Query(P_SEE_INVIS)>=Query(P_INVIS)) return("("+ w + ")");
    return "";
  }
  if (Query(P_HIDDEN)) {
    if (TP->Query(P_SEE_HIDDEN)>=Query(P_HIDDEN)) return(w+" (oculto)");
    return "";
  }

  return w;
}

public varargs string Noise(string what) {
  string str;

  str = (QueryNoise()||"")+implode(filterExtra(P_NOISE), "");
  return str != "" ? str : 0;
}
public varargs string Smell(string what) {
  string str;

  str = (QuerySmell()||"")+implode(filterExtra(P_SMELL), "");
  return str != "" ? str : 0;
}

public varargs string Read(string what)  {
  string str;
  string subid;

  subid = 0;
  if (TP && (subid = TP->QueryCmdData(SUBID))) str = GetSubReadMsg(subid);
  else str = QueryReadMsg();
  str = funcall(str||"");
  return str != "" ? str : 0;
}

public varargs int CompareSize (mixed with) {
  int size1, size2;

  if (objectp(with)) size2 = (int)with->Query(P_SIZE);
  else if (intp(with)) size2 = with;
  else return 0;

  size1 = Query(P_SIZE);

  if (!size1 || !size2 || (size1 == size2)) return 0;
  if (size1 < size2) return -1;

  return 1;
}

//--- Extra descriptions ---------------------------------------------------

public void SetExtra (mixed name, mixed data) {
  mapping m;

  m = QueryExtraDesc();
  m[name] = data;
  SetExtraDesc(m);
}

public mixed QueryExtra (mixed name) {
  return QueryExtraDesc()[name];
}

public void RemoveExtra (mixed name) {
  mapping data;

  data = QueryExtraDesc();
  m_delete(data, name);
  SetExtraDesc(data);
}

public void SetExtraEntry (mixed name, mixed prop, mixed data) {
  mapping xm, m;

  xm = QueryExtraDesc();
  if (mappingp(m = xm[name])) m[prop] = data;
  else m = ([ prop:data ]);
  xm[name] = m;
  SetExtraDesc(xm);
}

public mixed QueryExtraEntry (mixed name, mixed prop) {
  mapping xm, m;

  xm = QueryExtraDesc();
  if (mappingp(m = xm[name])) return m[prop];
  return 0;
}

public void RemoveExtraEntry (mixed name, mixed prop) {
  mapping xm, m;

  xm = QueryExtraDesc();
  if (mappingp(m = xm[name])) m_delete(m, prop);
  if (sizeof(m)) xm[name] = m;
  else m_delete(xm, name);
  SetExtraDesc(xm);
}
