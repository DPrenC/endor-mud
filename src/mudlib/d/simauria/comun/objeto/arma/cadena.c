inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include <materials.h>

create() {
  ::create();
  SetStandard(WT_CADENA, 4, P_SIZE_MEDIUM, M_ACERO);
  SetAds(({"una","larga"}));
  SetIds(({"arma","cadena"}));
  SetShort("una cadena");
  SetLong(
"Esto es una cadena. Una vulgar cadena metálica que puede ser usada como\n\
arma.\n");
  SetResetQuality(75);
}
