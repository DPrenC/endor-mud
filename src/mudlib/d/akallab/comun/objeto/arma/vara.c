inherit WEAPON;
#include <combat.h>
#include <properties.h>

create() {
  ::create();
  SetStandard(WT_VARA, 5, P_SIZE_MEDIUM, M_MADERA);
  SetAds(({"una","larga"}));
  SetIds(({"arma","vara"}));
  SetShort("una vara");
  SetLong("Una larga vara de roble usada para golpear.\n");
  SetResetQuality(90);
}
