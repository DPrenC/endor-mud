#include "path.h"
#include <herbs.h>

inherit HERB;

create() {
  ::create();

  AddId("menta");
  SetShort("un poco de menta");
  SetLong("Es un poco de menta. Su olor es bastante agradable.\n");
  SetSmell("Es un olor muy agradable.\n");
  SetWeight(20);
  SetClass(HERB_CLASS_FOOD);
  SetPower(20);
  SetValue(QueryPowerNumber());
}


