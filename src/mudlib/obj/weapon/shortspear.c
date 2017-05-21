/**
 * /obj/weapon/shortspear.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("una lanza corta");
  SetLong("Una lanza corta.\n");
  SetWeapon(W_LANZA_CORTA);
  SetBaseDamage(6);
  SetDamageType(DT_PIERCE);
  SetCriticalThreat(20);
  SetCriticalMultiplier(2);
  SetRangeIncrement(20);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_SIMPLE_ONE_HANDED);
  SetMeleeWeapon(1);
  SetValue(100);  // 1gp
  SetWeight(1500);// 3 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

