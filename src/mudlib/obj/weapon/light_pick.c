/**
 * /obj/weapon/light_pick.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("un pico ligero");
  SetLong("Un pico ligero.\n");
  SetWeapon(W_PICO_LIGERO);
  SetBaseDamage(4);
  SetDamageType(DT_PIERCE);
  SetCriticalThreat(20);
  SetCriticalMultiplier(4);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_LIGHT);
  SetMeleeWeapon(1);
  SetValue(400);  // 4 gp
  SetWeight(1500);// 3 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

