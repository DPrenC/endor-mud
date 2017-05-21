/**
 * /obj/weapon/ranseur.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una ronca");
  SetLong("Una ronca.\n");
  SetWeapon(W_RONCA);
  SetBaseDamage("2d4");
  SetDamageType(DT_PIERCE);
  SetCriticalThreat(20);
  SetCriticalMultiplier(3);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_TWO_HANDED);
  SetReachWeapon(1);
  SetDisarmBonus(1);
  SetValue(1000); // 10 gp
  SetWeight(6000);// 12 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

