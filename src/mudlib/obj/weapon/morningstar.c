/**
 * /obj/weapon/morningstar.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una maza de armas");
  SetLong("Una maza de armas.\n");
  SetWeapon(W_MAZA_DE_ARMAS);
  SetBaseDamage(8);
  SetDamageType(DT_PIERCE_AND_BLUDGEON);
  SetCriticalThreat(20);
  SetCriticalMultiplier(2);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_SIMPLE_ONE_HANDED);
  SetMeleeWeapon(1);
  SetValue(800); // 8 gp
  SetWeight(3000); // 6 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

