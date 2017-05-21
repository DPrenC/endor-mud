/**
 * /obj/weapon/short_sword.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una espada corta");
  SetLong("Una espada corta.\n");
  SetWeapon(W_ESPADA_CORTA);
  SetBaseDamage(6);
  SetDamageType(DT_PIERCE);
  SetCriticalThreat(19);
  SetCriticalMultiplier(2);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_LIGHT);
  SetMeleeWeapon(1);
  SetValue(1000); // 10 gp
  SetWeight(1000);// 2 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

