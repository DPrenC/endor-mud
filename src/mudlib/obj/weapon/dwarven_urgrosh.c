/**
 * /obj/weapon/dwarven_urgrosh.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit DOUBLE_WEAPON;

create_clone() {
  ::create_clone();
  SetShort("un urgrosh enano");
  SetLong("Un urgrosh enano.\n");
  SetWeapon(W_URGROSH_ENANO);
  SetBaseDamage();
  SetDamageType(DT_);
  SetCriticalThreat();
  SetCriticalMultiplier();
  SetRangeIncrement();
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_);
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

