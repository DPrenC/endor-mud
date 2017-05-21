/* SIMAURIA '/std/living/stats_new.c'
   ==============================
   [h] Nyh@Simauria

   24-12-04 [h] Creación

   NOTA: Todas las funciones son identicas a las de Str, asi q con mirar esas
         vale para enterarse...

*/

#include <living.h>
#include <stats.h>
#include <properties.h>

#ifndef REAL
#define REAL 1
#endif

#ifndef FAKE
#define FAKE 0
#endif

#ifndef P_WIS
#define P_WIS   "Wis"
#endif

#ifndef P_CHA
#define P_CHA   "Cha"
#endif

#ifdef STATS //Pa por si acaso
#undef STATS
#define STATS ({"Str", "Dex", "Con", "Int", "Wis", "Cha" })
#endif
//----------------------------------------------------------------------------

public int UpdateValue(string prop);    // std/core/properties
public void GetHeart(int user); // std/living/heart
public varargs mixed Query(string prop, int real);         // core/properties
public varargs mixed Set(string prop, mixed to, int real); // core/properties
public int Affect(mapping effect); // core/properties

//----------------------------------------------------------------------------

private int pStr, pDex, pCon, pInt, pWis, pCha; // Valores base
private nosave int pStrRace, pDexRace, pConRace, pIntRace, pWisRace, pChaRace; // Raza
private static int tmpStr, tmpDex, tmpCon, tmpInt, tmpWis, tmpCha; //temporales

//----------------------------------------------------------------------------

public varargs int QueryStr(int real) { return real ? pStr : tmpStr; }

public varargs int SetStr(int i, int real) {
        log_file("/GetHeart",sprintf("[%O] %O llamó a %O->SetStr(%O, %O)\n",ctime(),PO,TO, i, real));

    GetHeart(HEART_HEAL);

    if (real)
    {
        if ( i < 0 ) return pStr = -1;
        pStr = i;
        return UpdateValue(P_STR);
    }
    else
    {
        if (pStr < 0) return -1; //No puedes afectar un stat q no existe
        else if (i < 0) return tmpStr = 0; //No puede desaparecer un stat
        return tmpStr = i;
    }
}

public varargs int QueryStrRace() { return pStrRace; }
public varargs int SetStrRace(int i) {
    log_file("/GetHeart",sprintf("[%O] %O llamó a %O->SetStrRace(%O)\n\tQueryStr(REAL) = %O\n",ctime(),PO,TO, i, QueryStr(REAL)));
    if (QueryStr(REAL) < 1) return pStrRace = 0; //No modificar un stat q no existe
//    pStrRace = QueryStr(REAL) - QueryStrRace() + i; //Tener en cuenta antiguos mod de raza
//    SetStr( pStrRace<1 ? 1 : pStrRace, REAL);
    return pStrRace = i;
}
public varargs int ModifyStrRace(int i) {
    log_file("/GetHeart",sprintf("[%O] %O llamó a %O->ModifyStrRace(%O)\n\tQueryStr(REAL) = %O\n",ctime(),PO,TO, i, QueryStr(REAL)));
    if (QueryStr(REAL) < 1) return pStrRace = 0; //No modificar un stat q no existe
    pStrRace = QueryStr(REAL) - QueryStrRace() + i; //Tener en cuenta antiguos mod de raza
    SetStr( pStrRace<1 ? 1 : pStrRace, REAL);
    return pStrRace = i;
}


//----------------------------------------------------------------------------

public varargs int QueryDex(int real) { return real ? pDex : tmpDex; }

public varargs int SetDex(int i, int real) {
        log_file("/GetHeart",sprintf("[%O] %O llamó a %O->SetDex(%O, %O)\n",ctime(),PO,TO, i, real));

    GetHeart(HEART_HEAL);

    if (real)
    {
        if ( i < 0 ) return pDex = -1;
        pDex = i;
        return UpdateValue(P_DEX);
    }
    else
    {
        if (pDex < 0) return -1; //No puedes afectar un stat q no existe
        else if (i < 0) return tmpDex = 0; //No puede desaparecer un stat
        return tmpDex = i;
    }
}

public varargs int QueryDexRace() { return pDexRace; }
public varargs int SetDexRace(int i) {
     log_file("/GetHeart",sprintf("[%O] %O llamó a %O->SetDexRace(%O)\n\tQueryDex(REAL) = %O\n",ctime(),PO,TO, i, QueryDex(REAL)));
    if (QueryDex(REAL) < 1) return pDexRace = 0; //No modificar un stat q no existe
//    i = QueryDex(REAL) - QueryDexRace() + i; //Tener en cuenta antiguos mod de raza
//    SetDex( i<1 ? 1 : i, REAL);
    return pDexRace = i;
}
public varargs int ModifyDexRace(int i) {
    log_file("/GetHeart",sprintf("[%O] %O llamó a %O->ModifyDexRace(%O)\n\tQueryDex(REAL) = %O\n",ctime(),PO,TO, i, QueryDex(REAL)));
    if (QueryDex(REAL) < 1) return pDexRace = 0; //No modificar un stat q no existe
    pDexRace = QueryDex(REAL) - QueryDexRace() + i; //Tener en cuenta antiguos mod de raza
    SetDex( pDexRace<1 ? 1 : pDexRace, REAL);
    return pDexRace = i;
}

//----------------------------------------------------------------------------

public varargs int QueryCon(int real) { return real ? pCon : tmpCon; }

public varargs int SetCon(int i, int real) {
    log_file("/GetHeart",sprintf("[%O] %O llamó a %O->SetCon(%O, %O)\n",ctime(),PO,TO, i, real));
    GetHeart(HEART_HEAL);

    if (real)
    {
        if ( i < 0 ) return pCon = -1;
        pCon = i;
        return UpdateValue(P_CON);
    }
    else
    {
        if (pCon < 0) return -1; //No puedes afectar un stat q no existe
        else if (i < 0) return tmpCon = 0; //No puede desaparecer un stat
        return tmpCon = i;
    }
}

public varargs int QueryConRace() { return pConRace; }
public varargs int SetConRace(int i) {
     log_file("/GetHeart",sprintf("[%O] %O llamó a %O->SetConRace(%O)\n\tQueryCon(REAL) = %O\n",ctime(),PO,TO, i, QueryCon(REAL)));
    if (QueryCon(REAL) < 1) return pConRace = 0; //No modificar un stat q no existe
//    i = QueryCon(REAL) - QueryConRace() + i; //Tener en cuenta antiguos mod de raza
//    SetCon( i<1 ? 1 : i, REAL);
    return pConRace = i;
}
public varargs int ModifyConRace(int i) {
    log_file("/GetHeart",sprintf("[%O] %O llamó a %O->ModifyConRace(%O)\n\tQueryCon(REAL) = %O\n",ctime(),PO,TO, i, QueryCon(REAL)));
    if (QueryCon(REAL) < 1) return pConRace = 0; //No modificar un stat q no existe
    pConRace = QueryCon(REAL) - QueryConRace() + i; //Tener en cuenta antiguos mod de raza
    SetCon( pConRace<1 ? 1 : pConRace, REAL);
    return pConRace = i;
}

//----------------------------------------------------------------------------

public varargs int QueryInt(int real) { return real ? pInt : tmpInt; }

public varargs int SetInt(int i, int real) {
        log_file("/GetHeart",sprintf("[%O] %O llamó a %O->SetInt(%O, %O)\n",ctime(),PO,TO, i, real));

    GetHeart(HEART_HEAL);

    if (real)
    {
        if ( i < 0 ) return pInt = -1;
        pInt = i;
        return UpdateValue(P_INT);
    }
    else
    {
        if (pInt < 0) return -1; //No puedes afectar un stat q no existe
        else if (i < 0) return tmpInt = 0; //No puede desaparecer un stat
        return tmpInt = i;
    }
}

public varargs int QueryIntRace() { return pIntRace; }
public varargs int SetIntRace(int i) {
     log_file("/GetHeart",sprintf("[%O] %O llamó a %O->SetIntRace(%O)\n\tQueryInt(REAL) = %O\n",ctime(),PO,TO, i, QueryInt(REAL)));
    if (QueryInt(REAL) < 1) return pIntRace = 0; //No modificar un stat q no existe
//    i = QueryInt(REAL) - QueryIntRace() + i; //Tener en cuenta antiguos mod de raza
//    SetInt( i<1 ? 1 : i, REAL);
    return pIntRace = i;
}
public varargs int ModifyIntRace(int i) {
    log_file("/GetHeart",sprintf("[%O] %O llamó a %O->ModifyIntRace(%O)\n\tQueryInt(REAL) = %O\n",ctime(),PO,TO, i, QueryInt(REAL)));
    if (QueryInt(REAL) < 1) return pIntRace = 0; //No modificar un stat q no existe
    pIntRace = QueryInt(REAL) - QueryIntRace() + i; //Tener en cuenta antiguos mod de raza
    SetInt( pIntRace<1 ? 1 : pIntRace, REAL);
    return pIntRace = i;
}

//----------------------------------------------------------------------------

public varargs int QueryWis(int real) { return real ? pWis : tmpWis; }

public varargs int SetWis(int i, int real) {
    log_file("/GetHeart",sprintf("[%O] %O llamó a %O->SetWis(%O, %O)\n",ctime(),PO,TO, i, real));
    GetHeart(HEART_HEAL);

    if (real)
    {
        if ( i < 0 ) return pWis = -1;
        pWis = i;
        return UpdateValue(P_WIS);
    }
    else
    {
        if (pWis < 0) return -1; //No puedes afectar un stat q no existe
        else if (i < 0) return tmpWis = 0; //No puede desaparecer un stat
        return tmpWis = i;
    }
}

public varargs int QueryWisRace() { return pWisRace; }
public varargs int SetWisRace(int i) {
         log_file("/GetHeart",sprintf("[%O] %O llamó a %O->SetWisRace(%O)\n\tQueryWis(REAL) = %O\n",ctime(),PO,TO, i, QueryWis(REAL)));

    if (QueryWis(REAL) < 1) return pWisRace = 0; //No modificar un stat q no existe
//    i = QueryWis(REAL) - QueryWisRace() + i; //Tener en cuenta antiguos mod de raza
//    SetWis( i<1 ? 1 : i, REAL);
    return pWisRace = i;
}
public varargs int ModifyWisRace(int i) {
    log_file("/GetHeart",sprintf("[%O] %O llamó a %O->ModifyWisRace(%O)\n\tQueryWis(REAL) = %O\n",ctime(),PO,TO, i, QueryWis(REAL)));
    if (QueryWis(REAL) < 1) return pWisRace = 0; //No modificar un stat q no existe
    pWisRace = QueryWis(REAL) - QueryWisRace() + i; //Tener en cuenta antiguos mod de raza
    SetWis( pWisRace<1 ? 1 : pWisRace, REAL);
    return pWisRace = i;
}

//----------------------------------------------------------------------------

public varargs int QueryCha(int real) { return real ? pCha : tmpCha; }

public varargs int SetCha(int i, int real) {
    log_file("/GetHeart",sprintf("[%O] %O llamó a %O->SetCha(%O, %O)\n",ctime(),PO,TO, i, real));
    GetHeart(HEART_HEAL);

    if (real)
    {
        if ( i < 0 ) return pCha = -1;
        pCha = i;
        return UpdateValue(P_CHA);
    }
    else
    {
        if (pCha < 0) return -1; //No puedes afectar un stat q no existe
        else if (i < 0) return tmpCha = 0; //No puede desaparecer un stat
        return tmpCha = i;
    }
}

public varargs int QueryChaRace() { return pChaRace; }
public varargs int SetChaRace(int i) {
     log_file("/GetHeart",sprintf("[%O] %O llamó a %O->SetChaRace(%O)\n\tQueryCha(REAL) = %O\n",ctime(),PO,TO, i, QueryCha(REAL)));
    if (QueryCha(REAL) < 1) return pChaRace = 0; //No modificar un stat q no existe
//    i = QueryCha(REAL) - QueryChaRace() + i; //Tener en cuenta antiguos mod de raza
//    SetCha( i<1 ? 1 : i, REAL);
    return pChaRace = i;
}
public varargs int ModifyChaRace(int i) {
    log_file("/GetHeart",sprintf("[%O] %O llamó a %O->ModifyChaRace(%O)\n\tQueryCha(REAL) = %O\n",ctime(),PO,TO, i, QueryCha(REAL)));
    if (QueryCha(REAL) < 1) return pChaRace = 0; //No modificar un stat q no existe
    pChaRace = QueryCha(REAL) - QueryChaRace() + i; //Tener en cuenta antiguos mod de raza
    SetCha( pChaRace<1 ? 1 : pChaRace, REAL);
    return pChaRace = i;
}

//----------------------------------------------------------------------------
public varargs int QueryStatRace(string stat) {
  return to_int(Query(stat+"Race"));
}

public varargs int QueryStrBase()   { return QueryStr(REAL) - QueryStrRace(); }
public varargs int QueryConBase()   { return QueryCon(REAL) - QueryConRace(); }
public varargs int QueryDexBase()   { return QueryDex(REAL) - QueryDexRace(); }
public varargs int QueryIntBase()   { return QueryInt(REAL) - QueryIntRace(); }
public varargs int QueryWisBase()   { return QueryWis(REAL) - QueryWisRace(); }
public varargs int QueryChaBase()   { return QueryCha(REAL) - QueryChaRace(); }

public varargs int QueryStatBase(string stat) {
  return to_int(Query(stat+"Base"));
}

public varargs int SetStrBase(int i, int real)   { return SetStr(i + QueryStrRace(), real); }
public varargs int SetConBase(int i, int real)   { return SetCon(i + QueryConRace(), real); }
public varargs int SetDexBase(int i, int real)   { return SetDex(i + QueryDexRace(), real); }
public varargs int SetIntBase(int i, int real)   { return SetInt(i + QueryIntRace(), real); }
public varargs int SetWisBase(int i, int real)   { return SetWis(i + QueryWisRace(), real); }
public varargs int SetChaBase(int i, int real)   { return SetCha(i + QueryChaRace(), real); }

public varargs int SetStatBase(string stat, int i, int real) {
  return to_int(Set(stat+"Base", i, real));
}

//----------------------------------------------------------------------------

public int CalcModifier(int i)      { return i<0 ? 0 : i/2-5; }

public varargs int QueryStrModifier(int real) { return CalcModifier(QueryStr(real)); }
public varargs int QueryDexModifier(int real) { return CalcModifier(QueryDex(real)); }
public varargs int QueryConModifier(int real) { return CalcModifier(QueryCon(real)); }
public varargs int QueryIntModifier(int real) { return CalcModifier(QueryInt(real)); }
public varargs int QueryWisModifier(int real) { return CalcModifier(QueryWis(real)); }
public varargs int QueryChaModifier(int real) { return CalcModifier(QueryCha(real)); }

public varargs int QueryStatModifier(string stat, int real) {
  return call_other(TO,"Query"+stat+"Modifier", real);
}

//----------------------------------------------------------------------------
// Esto es muy chorra, pero bueno...
protected int StatHighest()
{ return sum(sort_array(({d6(), d6(), d6(), d6(), d6() }),SF(<))[0..2]); }
protected int StatHigh()
{ return sum(sort_array(({d6(), d6(), d6(), d6() }),SF(<))[0..2]); }
protected int StatNormal()
{ return d6(3); }
protected int StatLow()
{ return sum(sort_array(({d6(), d6(), d6(), d6() }),SF(>))[0..2]); }
protected int StatLowest()
{ return sum(sort_array(({d6(), d6(), d6(), d6(), d6() }),SF(>))[0..2]); }

public varargs int SetRandomStats(int mode) {
  closure dice;

/*
  switch (mode) {
    case RANDOM_STATS_HIGHEST: dice = symbol_function("StatHighest"); break;
    case RANDOM_STATS_HIGH:    dice = symbol_function("StatHigh");    break;
    case RANDOM_STATS_LOW:     dice = symbol_function("StatLow");     break;
    case RANDOM_STATS_LOWEST:  dice = symbol_function("StatLowest");  break;
    case RANDOM_STATS_NORMAL:
    default:
*/
        dice = symbol_function("StatNormal");
/*
  }
*/
  SetStr( to_int(funcall(dice)), REAL);
  SetDex( to_int(funcall(dice)), REAL);
  SetCon( to_int(funcall(dice)), REAL);
  SetInt( to_int(funcall(dice)), REAL);
  SetWis( to_int(funcall(dice)), REAL);
  SetCha( to_int(funcall(dice)), REAL);

  return 1;
}

// [Nyh] Compatibilidad... comprobar si aun se usa o ya he matado todo.
// Basic routines.
//mod: modificador a la tirada
//CD: clase de dificultad
// result mayor que cero para acierto.
public int ApplyValue(int mod, int cd) {
  return d20Check() + mod - cd;
}

public int ApplyStat(string name, int cd) {
  return ApplyValue(QueryStatModifier(name), cd);
}

public int UseStat(string name, int cd) {
  return ApplyStat(name, cd);
}

/***************************************************************************/
/* Creo q no es necesario con el nuevo sistema...

//Traido del attributes... por q coño estaba alli?
//Esta hecho de forma tan rara por q el original era mas o menos asin...

//Usada solo en el racemaster
public mapping QueryStats()
{
  mapping rc;
  string *statlist;
  int i;

  statlist = STATS;
  rc = ([]);
  for (i = 0; i < sizeof(statlist); i++)
    rc[statlist[i]] = Query(statlist[i]);
  return rc;
}

//Usada solo en el racemaster
//Nota: modificar el racemaster para que lo ponga con real = 1 en caso de ser
//necesario (comprobar)
public varargs mapping SetStats(mixed stats, int real)
{
  mapping rc;
  string *statlist;
  int i, val;

  statlist = STATS;
  if (pointerp(stats))
  {
    for (i = 0; i < sizeof(stats[0]); i++)
      Set(stats[0][i], stats[1][i], real);
  }
  else if (mappingp(stats))
  {
    for (i = 0; i < sizeof(statlist); i++)
      if (m_contains(&val, stats, statlist[i]))
        Set(statlist[i], val, real);
  }
  return QueryStats();
}
//Fin traido del attributes
*/

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Compatibilidad
public varargs int QueryTrueStr()   {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->QueryTrueStr()",ctime(),PO, TO));
    return QueryStr(REAL); }
public varargs int QueryTrueCon()   {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->QueryTrueCon()",ctime(),PO, TO));
    return QueryCon(REAL); }
public varargs int QueryTrueDex()   {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->QueryTrueDex()",ctime(),PO, TO));
    return QueryDex(REAL); }
public varargs int QueryTrueInt()   {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->QueryTrueInt()",ctime(),PO, TO));
    return QueryInt(REAL); }
public varargs int QueryTrueWis()   {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->QueryTrueWis()",ctime(),PO, TO));
    return QueryWis(REAL); }
public varargs int QueryTrueCha()   {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->QueryTrueCha()",ctime(),PO, TO));
    return QueryCha(REAL); }

public varargs int QueryTmpStr()    {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->QueryTmpStr()",ctime(),PO, TO));
    return QueryStr(FAKE); }
public varargs int QueryTmpCon()    {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->QueryTmpCon()",ctime(),PO, TO));
    return QueryCon(FAKE); }
public varargs int QueryTmpDex()    {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->QueryTmpDex()",ctime(),PO, TO));
    return QueryDex(FAKE); }
public varargs int QueryTmpInt()    {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->QueryTmpInt()",ctime(),PO, TO));
    return QueryInt(FAKE); }


public int QueryStrBonus()      {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->QueryStrBonus()",ctime(),PO, TO));
    return 0; }
public int SetStrBonus(int v)   {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->SetStrBonus()",ctime(),PO, TO));
    return 0; }
public int AddStrBonus(int v)   {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->AddStrBonus()",ctime(),PO, TO));
    return 0; }

// Bonus a la Inteligencia
public int QueryIntBonus()      {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->QueryIntBonus()",ctime(),PO, TO));
    return 0; }
public int SetIntBonus(int v)   {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->SetIntBonus()",ctime(),PO, TO));
    return 0; }
public int AddIntBonus(int v)   {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->AddIntBonus()",ctime(),PO, TO));
    return 0; }

// Bonus a la Constitución
public int QueryConBonus()      {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->QueryConBonus()",ctime(),PO, TO));
    return 0; }
public int SetConBonus(int v)   {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->SetConBonus()",ctime(),PO, TO));
    return 0; }
public int AddConBonus(int v)   {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->AddConBonus()",ctime(),PO, TO));
    return 0; }

// Bonus a la Destreza
public int QueryDexBonus()      {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->QueryDexBonus()",ctime(),PO, TO));
    return 0; }
public int SetDexBonus(int v)   {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->SetDexBonus()",ctime(),PO, TO));
    return 0; }
public int AddDexBonus(int v)   {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->AddDexBonus()",ctime(),PO, TO));
    return 0; }

// Manejo de las características temporales
public int SetTmpStr(int v) {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->SetTmpStr()",ctime(),PO, TO));
    return 0; }
public int SetTmpCon(int v) {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->SetTmpCon()",ctime(),PO, TO));
    return 0; }
public int SetTmpDex(int v) {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->SetTmpDex()",ctime(),PO, TO));
    return 0; }
public int SetTmpInt(int v) {
    log_file("/STATS",sprintf("[%O] %O llamó a %O->SetTmpInt()",ctime(),PO, TO));
    return 0; }

// Fin compatibilidad
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
