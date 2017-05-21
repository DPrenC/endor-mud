/**
 * /obj/weapon/warhammer.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("un martillo de guerra");
  SetLong("Un martillo de guerra.\n");
  SetWeapon(W_MARTILLO_DE_GUERRA);
  SetBaseDamage(8);
  SetDamageType(DT_BLUDGEON);
  SetCriticalThreat(20);
  SetCriticalMultiplier(3);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_MARTIAL_ONE_HANDED);
  SetMeleeWeapon(1);
  SetValue(1200); // 12 gp
  SetWeight(2500);// 5 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

