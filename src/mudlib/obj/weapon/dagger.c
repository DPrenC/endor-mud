/**
 * /obj/weapon/dagger.c
 */

#include <combat.h>
#include <size.h>
#include <weapon2.h>

inherit "/std/weapon2";

create_blueprint() {
  ::create_blueprint();
  SetShort("una daga");
  SetLong("Una daga.\n");
  SetWeapon(W_DAGA);
  SetDamage("1d4");
  //SetDamageType(DT_SLASH_AND_PIERCE);
  SetDamageType(DT_SLASH);
  SetCriticalThreat(19);
  SetCriticalMultiplier(2);
  SetRangeIncrement(10);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_SIMPLE_LIGHT);
  // +2 bonus on Sleight of Hand checks made to conceal it on your body
  SetValue(200);  // 2gp
  SetWeight(500); // 1lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_clone() {
  ::create_clone();
  replace_program();
}
