/**
 * /obj/weapon/sap.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una cachiporra");
  SetLong("Una cachiporra.\n");
  SetWeapon(W_CACHIPORRA);
  SetBaseDamage(6);
  SetDamageType(DT_BLUDGEON);
  SetCriticalThreat(20);
  SetCriticalMultiplier(2);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_LIGHT);
  SetMeleeWeapon(1);
  SetSubdual(1);
  SetValue(100);  // 1 gp
  SetWeight(1000);// 2 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

