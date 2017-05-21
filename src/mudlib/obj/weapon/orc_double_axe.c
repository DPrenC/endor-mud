/**
 * /obj/weapon/orc_double_axe.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit DOUBLE_WEAPON; // arma doble

create_clone() {
  ::create_clone();
  SetShort("un hacha doble orca");
  SetLong("Un hacha doble orca.\n");
  SetWeapon(W_HACHA_DOBLE_ORCA);
  SetBaseDamage();
  SetDamageType(DT_);
  SetCriticalThreat();
  SetCriticalMultiplier();
  SetRangeIncrement();
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_EXOTIC_TWO_HANDED);
  SetDoubleWeapon(1);
  SetMeleeWeapon(1);
  SetValue();
  SetWeight();
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

