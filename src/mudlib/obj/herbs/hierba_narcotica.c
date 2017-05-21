
#include <herbs.h>

inherit HERB;

create() {
  ::create();

  SetType(HERB_TYPE_HERB);
  SetClass(HERB_CLASS_NARCOTIC);
  SetPower(random(100));
  SetWeight(100);
  SetValue(QueryPowerNumber());

  AddId( ({ "hierbas",
         }) );
  AddAdjective( ({ "verdes",
                   "de color verde",
                   "de color verde oscuro",
             }) );

  SetShort("algunas hierbas de color verde oscuro");
  SetLong("Algunas hierbas de color verde oscuro con un olor agradable.\n");
  SetSmell("Tienen un olor parecido al de las flores.\n");
}


