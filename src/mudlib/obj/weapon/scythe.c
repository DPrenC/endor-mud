/**
 * /obj/weapon/scythe.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una guadaña");
  SetLong("Una guadaña.\n");
  SetWeapon(W_GUADAÑA);
  SetBaseDamage("2d4");
  SetDamageType(DT_SLASH_AND_PIERCE);
  SetCriticalThreat(20);
  SetCriticalMultiplier(4);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_TWO_HANDED);
  SetMeleeWeapon(1);
  SetCanTrip(1);
  SetValue(1800); // 18 gp
  SetWeight(5000);// 10 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

