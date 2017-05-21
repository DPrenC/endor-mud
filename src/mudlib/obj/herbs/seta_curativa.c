
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
                   "peque�as",
                   "api�adas",
                   "apinyadas",
              }) );

  SetShort("algunas peque�as setas blancas");
  SetLong("Algunas peque�as setas blancas api�adas que han crecido en un racimo.\n");
  SetSmell("Tienen un olor un tanto dulz�n.\n");
}
