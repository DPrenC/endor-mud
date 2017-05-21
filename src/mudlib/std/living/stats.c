/* ENDOR-MUD'/std/living/stats.c'
   ==============================

                	Ahora no hay malus, si pondría el bonus a negativo.
       	Para cambiar un stat totalmente, en vez de añadir, se
       	hará con 'SetTmpCon', 'SetTmpDex', ...
   24-12-04 [h] Empiezo la migracion a el nuevo sistema de stats.
*/

#include "/secure/config.h"
#include <living.h>

#define MAXBONUS        5
#define MAXMALUS        5

public void DropOverload(); // std/living/restrictions
public mixed Query(string pn); // std/base
public void GetHeart(int user); // std/living/heart

public int QueryStatusHelpless(); // std/living/body
public int QueryParalyzed();      // std/living/body

public int SetHP(int i); // /std/living/body
public int QueryHP(); // /std/living/body
public int QueryMaxHP(); // /std/living/body

public int SetSP(int i); // /std/living/body
public int QuerySP(); // /std/living/body
public int QueryMaxSP(); // /std/living/body

public int SetTP(int i); // /std/living/body
public int QueryTP(); // /std/living/body
public int QueryMaxTP(); // /std/living/body




//---------------------------------------------------------------------------

private int Str, Dex, Con, Int, Wis, Cha;
private static int mpStrBonus, mpDexBonus, mpConBonus,
                   mpIntBonus, mpWisBonus, mpChaBonus;
private static int mpStr, mpDex, mpCon, mpInt, mpWis, mpCha;

//---------------------------------------------------------------------------

// normalización de características al aplicar bonos:
public int NormalizeSP()
{
    if (QuerySP() > QueryMaxSP())
    {
        TO->catch_msg("Notas como tu poder disminuye.\n");
        SetSP(QueryMaxSP());
        return 1;
    }
    return 0;
}

public int NormalizeHP()
{
    if (QueryHP() > QueryMaxHP())
    {
        SetHP(QueryMaxHP());
        return 1;
    }
    return 0;
}

public int NormalizeTP()
{
    if (QueryTP() > QueryMaxTP())
    {
        SetTP(QueryMaxTP());
        return 1;
    }
    return 0;
}

// Bonus a la Fuerza
public int QueryStrBonus()      { return mpStrBonus; }
public int SetStrBonus(int v) {
    mpStrBonus = v;
    NormalizeTP();
    DropOverload();
    return mpStrBonus;
}
public int AddStrBonus(int v)
{
    mpStrBonus += v;
    NormalizeTP();
    GetHeart(HEART_HEAL);
    DropOverload();
    return mpStrBonus;
}

// Bonus a la Inteligencia
public int QueryIntBonus()      { return mpIntBonus; }
public int SetIntBonus(int v)
{
    mpIntBonus = v;
    NormalizeSP();
    return mpIntBonus;
}
public int AddIntBonus(int v)
{
    mpIntBonus += v;
    NormalizeSP();
    GetHeart(HEART_HEAL);
    return mpIntBonus;
}

// Bonus a la Constitución
public int QueryConBonus()      { return mpConBonus; }
public int SetConBonus(int v)
{
    mpConBonus = v;
    NormalizeHP();
    return mpConBonus;
}
public int AddConBonus(int v)
{
    mpConBonus += v;
    NormalizeHP();
    return mpConBonus;
}

// Bonus a la Destreza
public int QueryDexBonus()      { return mpDexBonus; }
public int SetDexBonus(int v)   { return mpDexBonus = v; }
public int AddDexBonus(int v)   { return mpDexBonus  +=  v; }

// Bonus a la Sabiduría
public int QueryWisBonus()      { return mpWisBonus; }
public int SetWisBonus(int v)   { return mpWisBonus = v; }
public int AddWisBonus(int v)   { return mpWisBonus += v; }

// Bonus a la Carisma
public int QueryChaBonus()      { return mpChaBonus; }
public int SetChaBonus(int v)   { return mpChaBonus = v; }
public int AddChaBonus(int v)   { return mpChaBonus += v; }

// Manejo de las características temporales
public int SetTmpStr(int v) { return mpStr = v; }
public int SetTmpCon(int v) { return mpCon = v; }
public int SetTmpDex(int v) { return mpDex = v; }
public int SetTmpInt(int v) { return mpInt = v; }
public int SetTmpWis(int v) { return mpWis = v; }
public int SetTmpCha(int v) { return mpCha = v; }

public int QueryTmpStr()    { return mpStr; }
public int QueryTmpCon()    { return mpCon; }
public int QueryTmpDex()    { return mpDex; }
public int QueryTmpInt()    { return mpInt; }
public int QueryTmpWis()    { return mpWis; }
public int QueryTmpCha()    { return mpCha; }

public int QueryTrueStr()   { return Str; }
public int QueryTrueCon()   { return Con; }
public int QueryTrueDex()   { return Dex; }
public int QueryTrueInt()   { return Int; }
public int QueryTrueWis()   { return Wis; }
public int QueryTrueCha()   { return Cha; }

//---------------------------------------------------------------------------
// Setting and querying of the stats

public varargs int QueryStr(int real) {
  if (QueryParalyzed() && !real) return 0;
  return (mpStr?mpStr:Str) + QueryStrBonus();
}
public int SetStr(int v) {
  GetHeart(HEART_HEAL);
  Str = v;
  NormalizeTP();
  DropOverload();
  return Str;
}

public varargs int QueryDex(int real) {
    if (QueryStatusHelpless() && !real) return 0;
    return (mpDex?mpDex:Dex) + QueryDexBonus();
}
public int SetDex(int v) {
  GetHeart(HEART_HEAL);
  return Dex = v;
}

public int QueryCon()    { return (mpCon?mpCon:Con) + QueryConBonus(); }
public int SetCon(int v) {
  GetHeart(HEART_HEAL);
  Con = v;
  NormalizeHP();
  return Con;
}

public int QueryInt()    { return (mpInt?mpInt:Int) + QueryIntBonus(); }
public int SetInt(int v) {
  GetHeart(HEART_HEAL);
  Int = v;
  NormalizeSP();
  return Int;
}

public int QueryWis()    { return (mpWis?mpWis:Wis) + QueryWisBonus(); }
public int SetWis(int v) {
  GetHeart(HEART_HEAL);
  return Wis = v;
}

public int QueryCha()    { return (mpCha?mpCha:Cha) + QueryChaBonus(); }
public int SetCha(int v) {
  GetHeart(HEART_HEAL);
  return Cha = v;
}

//---------------------------------------------------------------------------

protected int _calc_modifier(int i) {
  return (i>>2)-4; //division entre 4 y menos 4, por ejemplo
}

public int QueryStrModifier() { return _calc_modifier(QueryStr()); }
public int QueryDexModifier() { return _calc_modifier(QueryDex()); }
public int QueryConModifier() { return _calc_modifier(QueryCon()); }
public int QueryIntModifier() { return _calc_modifier(QueryInt()); }
public int QueryWisModifier() { return _calc_modifier(QueryWis()); }
public int QueryChaModifier() { return _calc_modifier(QueryCha()); }

//---------------------------------------------------------------------------
// Basic routines.

public int ApplyValue(int value, int diff)
{
  int res;
  res = random(100) + value - 100 - diff;
  return res > 100 ? 101 : res < -100 ? -101 : res;
}

public int ApplyStat(string name, int diff) {
  return ApplyValue(STAT_SCALE * Query(name), diff);
}

public int UseStat(string name, int diff) {
  return ApplyStat(name, diff);
}

/***************************************************************************/
