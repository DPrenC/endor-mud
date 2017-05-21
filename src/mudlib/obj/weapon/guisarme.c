/**
 * /obj/weapon/guisarme.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una bisarma");
  SetLong("Una bisarma.\n");
  SetWeapon(W_BISARMA);
  SetBaseDamage("2d4");
  SetDamageType(DT_SLASH);
  SetCriticalThreat(20);
  SetCriticalMultiplier(3);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_TWO_HANDED);
  SetReachWeapon(1);
  SetCanTrip(1);
  SetValue(900);  // 9 gp
  SetWeight(6000);// 12 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

