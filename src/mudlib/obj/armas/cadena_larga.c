/* cadena_larga.c */
#include <combat.h>
#include <properties.h>

inherit WEAPON;


create() {
  ::create();
  SetStandard(WT_CADENA, 9, P_SIZE_GENERIC, M_HIERRO);
  SetAds(({"una","larga", "de", "hierro", "pesada"}));
  SetIds(({"arma","cadena","cadena"}));
  SetShort("una larga cadena de hierro");
  SetLong(
  "Es una cadena formada por gruesos eslabones de hierro basto. Es bastante pesada y "
  "mide unos dos metros de largo, lo que le da una considerable potencia como arma.\n");
  SetNumberHands(2);
  SetWeight(5000);
}
