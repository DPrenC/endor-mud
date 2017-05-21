/* SIMAURIA '/obj/effects/effect_paralyzed.c'
   ==========================================

   [h] Nyh@Simauria

   06-04-08 [h] Creación

*/

#include <properties.h>
#include <ts.h>

inherit EFFECT;

private int pSaveType;
private int pSaveDC;

//------------------------------------------------------------------------------

public int QuerySaveDC()      { return pSaveDC; }
public int SetSaveDC(int i)   { return pSaveDC = i; }

public int QuerySaveType()    { return pSaveType; }
public int SetSaveType(int i) {
  switch (i) { //El switch es una forma de solo permitir salvaciones legales
  case SAVE_TYPE_NOSAVE:    pSaveType = SAVE_TYPE_NOSAVE;    break;
  case SAVE_TYPE_FORTITUDE: pSaveType = SAVE_TYPE_FORTITUDE; break;
  case SAVE_TYPE_REFLEX:    pSaveType = SAVE_TYPE_REFLEX;    break;
  case SAVE_TYPE_WILL:      pSaveType = SAVE_TYPE_WILL;      break;
  }
  return QuerySaveType();
}

//------------------------------------------------------------------------------

// [Nyh] El hacerlo sumando y restando es para poder apilar varios efectos
public int InitEffect() {
  QueryAffected()->SetParalyzed(QueryAffected()->QueryParalyzed()+1);
  return ::InitEffect();
}

// Hago que si pasa una tirada de salvación salga de la paralisis (devuelva 0)
public int ExecEffect() {
  if (find_object("nyh") && find_object("nyh")->Query("DebugEffects"))
    dtell("nyh",sprintf("[Effects][Paralyze] %O->ExecEffect()\tpAffected = [%O]%O\tpTimeLeft = %O\tSaveBonus = %O\tSaveType = %O\tDC= %O \n"
         , TO, QueryAffected()->QueryGuildLevel(), QueryAffected()->QueryName(), QueryTimeLeft(), QueryAffected()->QuerySaveBonusType(QuerySaveType()), QuerySaveType(), QuerySaveDC()));
  if (   QuerySaveType()
      && ( d20() + QueryAffected()->QuerySaveBonusType(QuerySaveType()) > QuerySaveDC() )
     )
  {
    return 0;
  }
  return ::ExecEffect();
}

public int EndEffect() {
  QueryAffected()->SetParalyzed(QueryAffected()->QueryParalyzed()-1);
  return ::EndEffect();
}

//------------------------------------------------------------------------------

create_clone()
{
  ::create_clone();
  AddId("_paralyzed");
  SetExecChat("Estás paralizado.\n");
}

//------------------------------------------------------------------------------
