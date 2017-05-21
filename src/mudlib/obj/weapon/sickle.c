/**
 * /obj/weapon/sickle.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una hoz");
  SetLong("Una hoz.\n");
  SetWeapon(W_HOZ);
  SetBaseDamage(6);
  SetDamageType(DT_SLASH);
  SetCriticalThreat(20);
  SetCriticalMultiplier(2);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_SIMPLE_LIGHT);
  SetMeleeWeapon(1);
  SetCanTrip(1);
  SetValue(600);  // 6gp
  SetWeight(1000);// 2lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

