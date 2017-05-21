
#include <herbs.h>

inherit HERB;

create() {
  ::create();

  SetType(HERB_TYPE_HERB);
  SetClass(HERB_CLASS_FOOD);
  SetPower(random(100));
  SetWeight(100);
  SetValue(QueryPowerNumber());

  AddId( ({ "hierbas",
         }) );
  AddAdjective( ({ "marrones",
                   "peque�as",
                   "pequenyas",
              }) );

  SetShort("algunas peque�as hierbas marrones");
  SetLong("Algunas peque�as hierbas marrones con apariencia comestible.\n");
  SetSmell("No huelen a nada raro.\n");
}
