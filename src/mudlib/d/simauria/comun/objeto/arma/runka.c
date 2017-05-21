inherit WEAPON;
#include <combat.h>
#include <properties.h>

create() {
  ::create();
  SetStandard(WT_ALABARDA, 6, P_SIZE_MEDIUM, M_ACERO);
  SetAds(({"un","larga"}));
  SetIds(({"arma","runka","alabarda"}));
  SetShort("un runka");
  SetLong(
"Es una alabarda con hoja en tridente. Es de acero, y tiene gran calidad.\n");
  SetDamType(DT_PIERCE);
  SetResetQuality(90);
}
