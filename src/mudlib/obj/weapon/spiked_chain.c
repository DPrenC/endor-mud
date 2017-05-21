/**
 * /obj/weapon/spiked_chain.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una cadena armada");
  SetLong("Una cadena armada.\n");
  SetWeapon(W_CADENA_ARMADA);
  SetBaseDamage("2d4");
  SetDamageType(DT_PIERCE);
  SetCriticalThreat(20);
  SetCriticalMultiplier(2);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_EXOTIC_TWO_HANDED);
  SetMeleeWeapon(1);
  SetReachWeapon(1);
  SetCanTrip(1);
  SetDisarmBonus(1);
  SetFinesse(1);
  SetValue(2500); // 25 gp
  SetWeight(5000);// 10 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

