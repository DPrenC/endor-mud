/**
 * /obj/weapon/longspear.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una lanza larga");
  SetLong("Una lanza larga.\n");
  SetWeapon(W_LANZA_LARGA);
  SetBaseDamage(8);
  SetDamageType(DT_PIERCE);
  SetCriticalThreat(20);
  SetCriticalMultiplier(3);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_SIMPLE_TWO_HANDED);
  SetReachWeapon(1);
  SetReadyVsCharge(1);
  SetValue(500);  // 5 gp
  SetWeight(4500);// 9 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

