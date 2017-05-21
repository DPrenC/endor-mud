/**
 * /obj/weapon/dwarven_waraxe.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("un hacha de guerra enana");
  SetLong("Un hacha de guerra enana.\n");
  SetWeapon(W_HACHA_DE_GUERRA_ENANA);
  SetBaseDamage(10);
  SetDamageType(DT_SLASH);
  SetCriticalThreat(20);
  SetCriticalMultiplier(3);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_EXOTIC_ONE_HANDED);
  SetMeleeWeapon(1);
  // Racial enana
  SetValue(3000); // 30 gp
  SetWeight(4000);// 8 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

