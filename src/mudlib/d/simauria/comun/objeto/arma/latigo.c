inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include <materials.h>

create() {
  ::create();
  SetStandard(WT_LATIGO, 3, P_SIZE_MEDIUM, M_CUERO);
  SetAds(({"un","elastico"}));
  SetIds(({"arma","latigo"}));
  SetShort("un latigo");
  SetLong("Un latigo de tres colas con unas bolitas de plomo en la punta.");
  SetResetQuality(90);
}
