/**
 * /obj/weapon/handaxe.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("un hacha de mano");
  SetLong("Un hacha de mano.\n");
  SetWeapon(W_HACHA_DE_MANO);
  SetBaseDamage(6);
  SetDamageType(DT_SLASH);
  SetCriticalThreat(20);
  SetCriticalMultiplier(3);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_LIGHT);
  SetMeleeWeapon(1);
  SetValue(600);  // 6 gp
  SetWeight(1500);// 3 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

