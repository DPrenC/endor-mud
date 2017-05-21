inherit ARMOUR;

#include <properties.h>
#include <combat.h>
#include <materials.h>

create() {
  ::create();
  SetStandard(AT_ANILLO, 0, P_SIZE_GENERIC, M_ORO);
  SetAds(({"un","simple", "de oro"}));
  AddId(({"armadura","anillo"}));
  SetShort("un anillo");
  SetLong(
"Es un anillo de oro. La parte superior tiene forma de cabeza\n\
de águila.\n");
  SetResetQuality(95);
  }