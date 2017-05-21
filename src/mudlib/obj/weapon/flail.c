/**
 * /obj/weapon/flail.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("un mangual");
  SetLong("Un mangual.\n");
  SetWeapon(W_MANGUAL);
  SetBaseDamage(8);
  SetDamageType(DT_BLUDGEON);
  SetCriticalThreat(20);
  SetCriticalMultiplier(2);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_ONE_HANDED);
  SetMeleeWeapon(1);
  SetDisarmBonus(1);
  SetCanTrip(1);
  SetValue(800);  // 8 gp
  SetWeight(2500);// 5 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

