/**
 * /obj/weapon/light_hammer.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("un martillo ligero");
  SetLong("Un martillo ligero.\n");
  SetWeapon(W_MARTILLO_LIGERO);
  SetBaseDamage(4);
  SetDamageType(DT_BLUDGEON);
  SetCriticalThreat(20);
  SetCriticalMultiplier(2);
  SetRangeIncrement(20);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_LIGHT);
  SetMeleeWeapon(1);
  SetValue(100);  // 1 gp
  SetWeight(1000);// 2 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

