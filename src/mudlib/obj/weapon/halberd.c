/**
 * /obj/weapon/halberd.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una alabarda");
  SetLong("Una alabarda.\n");
  SetWeapon(W_ALABARDA);
  SetBaseDamage(10);
  SetDamageType(DT_SLASH_AND_PIERCE);
  SetCriticalThreat(20);
  SetCriticalMultiplier(3);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_TWO_HANDED);
  SetReachWeapon(1);
  SetReadyVsCharge(1);
  SetCanTrip(1);
  SetValue(1000); // 10 gp
  SetWeight(6000);// 12 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

