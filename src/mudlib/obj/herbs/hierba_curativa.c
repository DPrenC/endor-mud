
#include <herbs.h>

inherit HERB;

create() {
  ::create();

  SetType(HERB_TYPE_HERB);
  SetClass(HERB_CLASS_HEALING);
  SetPower(random(100));
  SetWeight(100);
  SetValue(QueryPowerNumber());

  AddId( ({ "hierbas",
         }) );
  AddAdjective( ({ "verdes",
                   "de color verde",
                   "con brotes",
              }) );

  SetShort("algunas hierbas verdes con brotes");
  SetLong("Algunas hierbas verdes con brotes y de un olor agradable.\n");
  SetSmell("Tienen un olor parecido al de las flores.\n");
}
