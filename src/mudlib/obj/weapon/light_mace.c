/**
 * /obj/weapon/light_mace.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una maza ligera");
  SetLong("Una maza ligera.\n");
  SetWeapon(W_MAZA_LIGERA);
  SetBaseDamage(6);
  SetDamageType(DT_BLUDGEON);
  SetCriticalThreat(20);
  SetCriticalMultiplier(2);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_SIMPLE_LIGHT);
  SetMeleeWeapon(1);
  SetValue(500); // 5gp
  SetWeight(2000); // 4lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

