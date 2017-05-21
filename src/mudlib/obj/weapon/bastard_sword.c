/**
 * /obj/weapon/bastard_sword.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una espada bastarda");
  SetLong("Una espada bastarda.\n");
  SetWeapon(W_ESPADA_BASTARDA);
  SetBaseDamage(10);
  SetDamageType(DT_SLASH);
  SetCriticalThreat(19);
  SetCriticalMultiplier(2);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_EXOTIC_ONE_HANDED);
  SetMeleeWeapon(1);
  SetValue(3500); // 35 gp
  SetWeight(3000);// 6 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

