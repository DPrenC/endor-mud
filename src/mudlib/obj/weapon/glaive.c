/**
 * /obj/weapon/glaive.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una guja");
  SetLong("Una guja.\n");
  SetWeapon(W_GUJA);
  SetBaseDamage(10);
  SetDamageType(DT_SLASH);
  SetCriticalThreat(20);
  SetCriticalMultiplier(3);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_TWO_HANDED);
  SetReachWeapon(1);
  SetValue(800);  // 8 gp
  SetWeight(5000);// 10 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

