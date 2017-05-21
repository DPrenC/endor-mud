/* SIMAURIA '/obj/effects/effect_luz_cegadora.c'
   ============================================

   [h] Nyh@Simauria

   05-04-08 [h] Rehecho todo desde la bola de luz vieja

*/

#include <properties.h>

inherit EFFECT;

//------------------------------------------------------------------------------

// [Nyh] El hacerlo sumando y restando es para poder apilar varios efectos
public int InitEffect() { // Le sumo uno a su ceguera
  if (QueryAffected()->Query(P_BLIND)) return 0; // Si no ve, ¿como cegarlo?
  QueryAffected()->Set(P_BLIND, QueryAffected()->Query(P_BLIND)+1);
  return ::InitEffect();
}

public int EndEffect() {  // Le resto uno a la ceguera para 'curarle'
  QueryAffected()->Set(P_BLIND, QueryAffected()->Query(P_BLIND)-1);
  return ::EndEffect();
}

//------------------------------------------------------------------------------

create_clone()
{
  ::create_clone();
  AddId("_luz_cegadora");
}

//------------------------------------------------------------------------------
