/**
 * /obj/weapon/two_bladed_sword.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit DOUBLE_WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una espada de dos hojas");
  SetLong("Una espada de dos hojas.\n");
  SetWeapon(W_ESPADA_DE_DOS_HOJAS);
  SetBaseDamage();
  SetDamageType(DT_);
  SetCriticalThreat();
  SetCriticalMultiplier();
  SetRangeIncrement();
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_EXOTIC_TWO_HANDED);
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

