/* SIMAURIA '/obj/effects/effect_vision_nocturna.c'
   ================================================

   [h] Nyh@Simauria

   05-04-08 [h] Rehecho todo desde la vision vieja

*/

#include <properties.h>

inherit EFFECT;

//------------------------------------------------------------------------------

// [Nyh] El hacerlo sumando y restando es para poder apilar varios efectos
public int InitEffect() {
  QueryAffected()->ModifyAttr("IVision", -500);
  return ::InitEffect();
}

public int EndEffect() {
  QueryAffected()->ModifyAttr("IVision", 500);
  return ::EndEffect();
}

//------------------------------------------------------------------------------

create_clone()
{
  ::create_clone();
  AddId("_vision_nocturna");
}

//------------------------------------------------------------------------------
