/**
 * /obj/weapon/lance.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una lanza de caballería");
  SetLong("Una lanza de caballería.\n");
  SetWeapon(W_LANZA_DE_CABALLERIA);
  SetBaseDamage(8);
  SetDamageType(DT_PIERCE);
  SetCriticalThreat(20);
  SetCriticalMultiplier(3);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_TWO_HANDED);
  SetReachWeapon(1);
  // A lance deals double damage when used from the back of a charging mount
  // While mounted, you can wield a lance with one hand.
  SetValue(1000); // 10 gp
  SetWeight(5000);// 10 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

