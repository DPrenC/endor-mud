/**
 * /obj/weapon/club.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una clava");
  SetLong("Una clava.\n");
  SetWeapon(W_CLAVA);
  SetBaseDamage(6);
  SetDamageType(DT_BLUDGEON);
  SetCriticalThreat(20);
  SetCriticalMultiplier(2);
  SetRangeIncrement(10);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_SIMPLE_ONE_HANDED);
  SetMeleeWeapon(1);
  SetValue(0); // 0 gp, es un puto palo
  SetWeight(1500);  // 3 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

