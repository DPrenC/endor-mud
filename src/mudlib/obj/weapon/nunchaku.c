/**
 * /obj/weapon/nunchaku.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("un nunchaku");
  SetLong("Un nunchaku.\n");
  SetWeapon(W_NUNCHAKU);
  SetBaseDamage(6);
  SetDamageType(DT_BLUDGEON);
  SetCriticalThreat(20);
  SetCriticalMultiplier(2);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_EXOTIC_LIGHT);
  SetMeleeWeapon(1);
  SetMonkWeapon(1);
  SetDisarmBonus(1);
  SetValue(200);  // 2 gp
  SetWeight(1000);// 2 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

