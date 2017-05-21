/**
 * /obj/weapon/greatsword.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("un espadón");
  SetLong("Un espadón.\n");
  SetWeapon(W_ESPADON);
  SetBaseDamage("2d6");
  SetDamageType(DT_SLASH);
  SetCriticalThreat(19);
  SetCriticalMultiplier(2);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_TWO_HANDED);
  SetMeleeWeapon(1);
  SetValue(5000); // 50 gp
  SetWeight(4000);// 8 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

