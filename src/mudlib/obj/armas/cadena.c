/* cadena.c */
#include <combat.h>
#include <properties.h>

inherit WEAPON;


create() {
  ::create();
  SetStandard(WT_CADENA, 5, P_SIZE_GENERIC, M_HIERRO);
  SetAds(({"una", "de", "hierro"}));
  SetIds(({"arma","cadena"}));
  SetShort("una cadena de hierro");
  SetLong(
"Es una cadena de aproximadamente un metro de largo, formada por gruesos eslabones "
"de hierro. Podría ser usada como arma.\n");
}