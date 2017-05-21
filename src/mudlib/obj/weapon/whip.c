/**
 * /obj/weapon/whip.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("un látigo");
  SetLong("Un látigo.\n");
  SetWeapon(W_LATIGO);
  SetBaseDamage(3);
  SetDamageType(DT_SLASHING);
  SetCriticalThreat(20);
  SetCriticalMultiplier(2);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_EXOTIC_ONE_HANDED);
  SetMeleeWeapon(1);
  SetReachWeapon(1);
  SetSubdual(1);
  SetCanTrip(1);
  SetDisarmBonus(1);
  SetFinesse(1);
  //  It deals no damage to any creature with an armor bonus of +1 or higher or a natural armor bonus of +3 or higher.
  //  The whip is treated as a melee weapon with 15-foot reach, though you don’t threaten the area into which you can make an attack.
  //  Using a whip provokes an attack of opportunity, just as if you had used a ranged weapon.
  SetValue(100);  // 1 gp
  SetWeight(1000);// 2 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

