/**
 * /obj/weapon/heavy_mace.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una maza pesada");
  SetLong("Una maza pesada.\n");
  SetWeapon(W_MAZA_PESADA);
  SetBaseDamage(8);
  SetDamageType(DT_BLUDGEON);
  SetCriticalThreat(20);
  SetCriticalMultiplier(2);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_SIMPLE_ONE_HANDED);
  SetMeleeWeapon(1);
  SetValue(1200); // 12gp
  SetWeight(4000); // 8lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

