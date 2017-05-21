
#include <herbs.h>

inherit HERB;

create() {
  ::create();

  SetType(HERB_TYPE_MUSHROOM);
  SetClass(HERB_CLASS_NARCOTIC);
  SetPower(random(200));
  SetWeight(100);
  SetValue(QueryPowerNumber());

  AddId( ({ "setas",
         }) );
  AddAdjective( ({ "de color pardo",
                   "de color oscuro",
                   "pardas",
               }) );

  SetShort("unas pequeñas setas de color pardo");
  SetLong("Unas pequeñas setas de color pardo y sin un olor especial.\n");
  SetSmell("No tienen un olor especial.\n");
}


