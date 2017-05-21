/**
 * SIMAURIA '/std/equipment.c'
 */

#include <config.h>
#include <properties.h>
#include <equipment.h>
#include <moving.h>

public mixed Query(string name); // std/base
public string *AddAdjective(mixed ads);            // std/thing/description
public string *RemoveAdjective(mixed ads);         // std/thing/description

public string QualityMsg (int quality);

//---------------------------------------------------------------------------

private int     pQuality = 100, pResetQuality = 100;
private int     pNumberHands;
private int     pMode = EQM_WEAR;
private string  pQualityMsg;

private static object pEquipped;

//---------------------------------------------------------------------------

private string _get_sufix() {
  string sufijo = "";
  sufijo = (TO->Query(P_GENDER)==GENDER_FEMALE ?
               (TO->Query(P_NUMBER)==NUMBER_SINGULAR?"a":"as") :
               (TO->Query(P_NUMBER)==NUMBER_SINGULAR?"o":"os"));
  return sufijo;
}

public int QueryNumberHands()    { return pNumberHands; }
public int SetNumberHands(int i) { return pNumberHands = i; }

public int QueryQuality()        { return pQuality; }
public int SetQuality(int i)     { return pQuality = (i >= 0 ? i : 0); }
public int AddQuality(int delta) { return SetQuality(QueryQuality() + delta); }

public int QueryResetQuality()   { return pResetQuality; }
public int SetResetQuality(int i){ return pResetQuality = i; }

public int QueryUsage()          { return pMode; }
public int SetUsage(int i)       { return pMode = i; }

public string *QueryEquipData() {
  switch (pMode)
  {
    case EQM_WEAR:  return DEFAULT_WEARDATA;
    case EQM_WIELD: return DEFAULT_WIELDDATA;
    case EQM_BOTH:  return DEFAULT_EQUIPDATA;
    case EQM_NONE:
  }
  return 0;
}

public object QueryEquipped()          { return pEquipped; }
public object SetEquipped(object ob) {
  if (ob) AddAdjective(QueryEquipData()[EQD_ADJ]+_get_sufix());
  else RemoveAdjective(QueryEquipData()[EQD_ADJ]+_get_sufix());
  return pEquipped = ob;
}

//---------------------------------------------------------------------------

void Aloha (int flag)
{
  if (flag < 0) SetQuality(QueryResetQuality());
}

//---------------------------------------------------------------------------

static int modifyValue  (int v) { return (v * (40+QueryQuality())) / 140; }

static string modifyLong(string long) {
  int size;
  long += (Query(P_NUMBER)==0 ? "Está " : "Están ")+QualityMsg(QueryQuality());
  switch (Query(P_SIZE))
  {
  case P_SIZE_SMALL : long += " y es de pequeño tamaño"; break;
  case P_SIZE_MEDIUM: long += " y es de tamaño medio"; break;
  case P_SIZE_LARGE : long += " y es de tamaño normal"; break;
  	  case P_SIZE_HUGE : long += " y es de tamaño enorme"; break;

  }
  return long+".\n";
}

static string modifyShort (string ishort) {
  string tmp, adj;
  int qual;

  if ((qual = QueryQuality()) >= 95) return ishort;
  return ishort+" "+QualityMsg(qual);
}

static string modifyInvShort (string ishort) {
  string tmp, adj, sufijo = _get_sufix();
  int qual;

  tmp = (qual = QueryQuality()) < 95 ? QualityMsg(qual) : "";
  adj = QueryEquipData()[EQD_ADJ]+sufijo;
  if (QueryEquipped() && -1 == strstr(ishort, adj))
    tmp += (tmp != "" ? ", " : "")+adj;
  adj = QueryEquipData()[EQD_ADJ]+sufijo;
  return tmp == "" ? ishort : ishort+" ("+tmp+")";
}

//---------------------------------------------------------------------------
public string QualityMsg (int quality)
// Devuelve una descripcion de la Quality del objeto.

{
  string sufijo = _get_sufix();

  switch (quality) {
  case 95.. 99: return "en perfecto estado";
  case 75.. 94: return "ligeramente dañad"+sufijo;
  case 50.. 74: return "dañad"+sufijo;
  case 25.. 49: return "seriamente dañad"+sufijo;
  case  5.. 24: return "seriamente machacad"+sufijo;
  case  0..  4: return "rot"+sufijo+" y doblad"+sufijo;
  }
  if (quality < 0)
    return "casi destruido"+sufijo;
  return "en perfectas condiciones";
}

public string SetQualityMsg (string s) { return pQualityMsg = s; }

public varargs string QueryQualityMsg (int trueq) {
  return (!trueq && pQualityMsg) || QualityMsg(QueryQuality());
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

// Equipa este objeto <ob>
public varargs mixed Equip(object ob, int flags)
{
  return ob->Equip(TO, flags);
}

// Desequipa este objeto <QueryEquipped()>
public varargs mixed Unequip(int flags)
{
  if (!QueryEquipped()) return EQ_ALREADY;
  return QueryEquipped()->Unequip(TO, flags);
}

//===========================================================================

public varargs mixed ChkEquip     (object liv, object what, int flags) { return EQ_OK; }
public varargs mixed ChkUnequip   (object liv, object what, int flags) { return EQ_OK; }
public varargs void  NotifyEquip  (object liv, object what, int flags) { }
public varargs void  NotifyUnequip(object liv, object what, int flags) { }

//===========================================================================

public void notify_move (mixed dest, int method, mixed extra)
{
  int flags = 0;

  if (method == M_NOCHECK || method == M_SILENT || method == M_DESTRUCT) {
    flags = EWF_SILENT;
  }

  if (QueryEquipped()) Unequip(flags);
}

//---------------------------------------------------------------------------
