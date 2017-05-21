/**
 * /obj/weapon/heavy_flail.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("un mangual pesado");
  SetLong("Un mangual pesado.\n");
  SetWeapon(W_MANGUAL_PESADO);
  SetBaseDamage(10);
  SetDamageType(DT_BLUDGEON);
  SetCriticalThreat(19);
  SetCriticalMultiplier(2);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_TWO_HANDED);
  SetMeleeWeapon(1);
  SetDisarmBonus(1);
  SetCanTrip(1);
  SetValue(1500); // 15 gp
  SetWeight(5000);// 10 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

