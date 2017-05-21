/**
 * /obj/weapon/sai.c
 */

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("un sai");
  SetLong("Un sai.\n");
  SetWeapon(W_SAI);
  SetBaseDamage(4);
  SetDamageType(DT_BLUDGEON);
  SetCriticalThreat(20);
  SetCriticalMultiplier(2);
  SetRangeIncrement(10);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_EXOTIC_LIGHT);
  SetMeleeWeapon(1);
  SetMonkWeapon(1);
  SetDisarmBonus(1); // Esto da bono de +4 a desarmar
  SetValue(100);  // 1 gp
  SetWeight(500); // 1 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tamaños
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

