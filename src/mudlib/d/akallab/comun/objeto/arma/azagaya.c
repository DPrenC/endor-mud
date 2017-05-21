inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include <materials.h>

create() {
  ::create();
  SetStandard(WT_LANZA, 3, P_SIZE_MEDIUM, M_ACERO);
  SetAds(({"una","ligera"}));
  SetIds(({"arma","lanza","azagaya"}));
  SetShort("una azagaya");
  SetLong(
"Es una ligera lanza con fuste de encina y punta de acero. Puede ser útil "
"para lanzarla contra jabalíes u otros enemigos.\n");
  SetResetQuality(80);
  SetNumberHands(1);
}
