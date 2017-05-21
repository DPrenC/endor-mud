/**
 * /obj/weapon/spear.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una lanza");
  SetLong("Una lanza.\n");
  SetWeapon(W_LANZA);
  SetBaseDamage(8);
  SetDamageType(DT_PIERCE);
  SetCriticalThreat(20);
  SetCriticalMultiplier(3);
  SetRangeIncrement(20);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_SIMPLE_TWO_HANDED);
  SetMeleeWeapon(1);
  SetReadyVsCharge(1);
  SetValue(200);  // 2 gp
  SetWeight(3000);// 6 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

