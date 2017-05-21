/**
 * /obj/weapon/greataxe.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una gran hacha");
  SetLong("Una gran hacha.\n");
  SetWeapon(W_GRAN_HACHA);
  SetBaseDamage(12);
  SetDamageType(DT_SLASH);
  SetCriticalThreat(20);
  SetCriticalMultiplier(3);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_TWO_HANDED);
  SetMeleeWeapon(1);
  SetValue(2000); // 20 gp
  SetWeight(6000);// 12 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

