/**
 * /obj/weapon/heavy_pick.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("un pico pesado");
  SetLong("Un pico pesado.\n");
  SetWeapon(W_PICO_PESADO);
  SetBaseDamage(6);
  SetDamageType(DT_PIERCE);
  SetCriticalThreat(20);
  SetCriticalMultiplier(4);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_ONE_HANDED);
  SetMeleeWeapon(1);
  SetValue(800);  // 8 gp
  SetWeight(3000);// 6 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

