/**
 * /obj/weapon/rapier.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("un estoque");
  SetLong("Un estoque.\n");
  SetWeapon(W_ESTOQUE);
  SetBaseDamage(6);
  SetDamageType(DT_PIERCE);
  SetCriticalThreat(18);
  SetCriticalMultiplier(2);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_ONE_HANDED);
  SetMeleeWeapon(1);
  SetFinesse(1);
  // You can’t wield a rapier in two hands
  SetValue(2000); // 20 gp
  SetWeight(1000);// 2 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

