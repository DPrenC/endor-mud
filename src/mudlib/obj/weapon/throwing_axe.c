/**
 * /obj/weapon/throwing_axe.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("un hacha arrojadiza");
  SetLong("Un hacha arrojadiza.\n");
  SetWeapon(W_HACHA_ARROJADIZA);
  SetBaseDamage(6);
  SetDamageType(DT_SLASH);
  SetCriticalThreat(20);
  SetCriticalMultiplier(2);
  SetRangeIncrement(10);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_LIGHT);
  SetMeleeWeapon(1);
  SetValue(800);  // 8 gp
  SetWeight(1000);// 2 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

