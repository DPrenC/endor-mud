
#include <herbs.h>

inherit HERB;

create() {
  ::create();

  SetType(HERB_TYPE_MUSHROOM);
  SetClass(HERB_CLASS_TOXIC);
  SetPower(random(200));
  SetWeight(100);
  SetValue(QueryPowerNumber());

  AddId( ({ "setas",
         }) );
  AddAdjective( ({ "amarillas",
                   "de color amarillo pálido",
                   "de color amarillo palido",
                   "de color amarillo",
              }) );

  SetShort("algunas setas de color amarillo pálido");
  SetLong("Algunas setas medianas de color amarillo pálido.\n");
  SetSmell("Huelen a tierra humeda.\n");
}


