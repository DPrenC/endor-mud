/**
 * /obj/weapon/quarterstaff.c
 */

// Nota: Esto es un arma doble, pero de momento la hago simple

#include <damage.h>
#include <size.h>
#include <weapon.h>

inherit WEAPON;

create_clone() {
  ::create_clone();
  SetShort("un bast�n");
  SetLong("Un bast�n.\n");
  SetWeapon(W_BASTON);
  SetBaseDamage(6); // 1d6/1d6
  SetDamageType(DT_BLUDGEON);
  SetCriticalThreat(20);
  SetCriticalMultiplier(2);
  SetRangeIncrement(0);
  SetWeaponSize(P_SIZE_MEDIUM);
  SetWeaponCategory(WC_SIMPLE_TWO_HANDED);
  SetMeleeWeapon(1);
  SetMonkWeapon(1);
  SetValue(0);  // Es un puto palo
  SetWeight(2000);// 4 lb
  SetSize(P_SIZE_MEDIUM); // Cambiar cuando se arreglen los tama�os
  replace_program();
}

create_blueprint() {
  ::create_blueprint();
  replace_program();
}

