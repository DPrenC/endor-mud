/**
 * /obj/weapon/trident.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("un tridente");
  SetLong("Un tridente.\n");
  SetWeapon(W_TRIDENTE);
  SetBaseDamage(8);
  SetDamageType(DT_PIERCE);
  SetCriticalThreat(20);
  SetCriticalMultiplier(2);
  SetRangeIncrement(10);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_ONE_HANDED);
  SetMeleeWeapon(1);
  SetReadyVsCharge(1);
  SetValue(1500); // 15 gp
  SetWeight(2000);// 4 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

