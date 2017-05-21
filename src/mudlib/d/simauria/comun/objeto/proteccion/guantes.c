inherit ARMOUR;

#include <properties.h>
#include <combat.h>

create() {
  ::create();
  SetStandard(AT_GUANTES, 0, P_SIZE_MEDIUM, M_CUERO);
  SetAds(({"unos","simples", "de cuero"}));
  AddId(({"armadura","guantes"}));
  SetShort("unos guantes");
  SetLong("Son unos guantes de cuero para proteger las manos.\n");
  SetResetQuality(95);
  }