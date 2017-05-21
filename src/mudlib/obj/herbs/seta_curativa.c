
#include <herbs.h>

inherit HERB;

create() {
  ::create();

  SetType(HERB_TYPE_MUSHROOM);
  SetClass(HERB_CLASS_HEALING);
  SetPower(random(200));
  SetWeight(100);
  SetValue(QueryPowerNumber());

  AddId( ({ "setas",
         }) );
  AddAdjective( ({ "de color blanco",
                   "blancas",
                   "pequeñas",
                   "apiñadas",
                   "apinyadas",
              }) );

  SetShort("algunas pequeñas setas blancas");
  SetLong("Algunas pequeñas setas blancas apiñadas que han crecido en un racimo.\n");
  SetSmell("Tienen un olor un tanto dulzón.\n");
}
