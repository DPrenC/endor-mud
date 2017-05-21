
#include <herbs.h>

inherit HERB;

create() {
  ::create();

  SetType(HERB_TYPE_HERB);
  SetClass(HERB_CLASS_MAGIC);
  SetPower(random(100));
  SetWeight(100);
  SetValue(QueryPowerNumber());

  AddId( ({ "hierbas",
         }) );
  AddAdjective( ({ "largas",
                   "verdes",
                   "de color verde",
                   "con brotes",
              }) );

  SetShort("algunas largas hierbas de color verde con brotes");
  SetLong("Algunas largas hierbas de color verde con brotes con un olor agradable.\n");
  SetSmell("Tienen un aroma dulzon.\n");
}


