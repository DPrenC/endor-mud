
#include <herbs.h>

inherit HERB;

create() {
  ::create();

  SetType(HERB_TYPE_HERB);
  SetClass(HERB_CLASS_TOXIC);
  SetPower(random(100));
  SetWeight(100);
  SetValue(QueryPowerNumber());

  AddId( ({ "hierbas",
         }) );
  AddAdjective( ({ "amarillas",
                   "de color amarillo",
                   "con brotes",
              }) );

  SetShort("algunas hierbas amarillas con brotes");
  SetLong("Algunas perfumadas hierbas amarillas con brotes.\n");
  SetSmell("Su olor te recuerda al del perfume.\n");
}


