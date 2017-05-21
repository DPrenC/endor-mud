/**
 * /obj/weapon/falchion.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("un alfanjón");
  SetLong("Un alfanjón.\n");
  SetWeapon(W_ALFANJON);
  SetBaseDamage("2d4");
  SetDamageType(DT_SLASH);
  SetCriticalThreat(18);
  SetCriticalMultiplier(2);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_TWO_HANDED);
  SetMeleeWeapon(1);
  SetValue(7500); // 75 gp
  SetWeight(4000);// 8 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

