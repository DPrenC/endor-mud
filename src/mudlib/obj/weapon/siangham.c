/**
 * /obj/weapon/siangham.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("un siangham");
  SetLong("Un siangham.\n");
  SetWeapon(W_SIANGHAM);
  SetBaseDamage(6);
  SetDamageType(DT_PIERCE);
  SetCriticalThreat(20);
  SetCriticalMultiplier(2);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_EXOTIC_LIGHT);
  SetMeleeWeapon(1);
  SetMonkWeapon(1);
  SetValue(300);  // 3 gp
  SetWeight(500); // 1 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

