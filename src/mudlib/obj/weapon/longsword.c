/**
 * /obj/weapon/longsword.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una espada larga");
  SetLong("Una espada larga.\n");
  SetWeapon(W_ESPADA_LARGA);
  SetBaseDamage(8);
  SetDamageType(DT_SLASH);
  SetCriticalThreat(19);
  SetCriticalMultiplier(2);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_ONE_HANDED);
  SetMeleeWeapon(1);
  SetValue(1500); // 15 gp
  SetWeight(2000);// 4 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

