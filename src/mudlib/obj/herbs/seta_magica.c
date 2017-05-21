
#include <herbs.h>

inherit HERB;

create() {
  ::create();

  SetType(HERB_TYPE_MUSHROOM);
  SetClass(HERB_CLASS_MAGIC);
  SetPower(random(200));
  SetWeight(100);
  SetValue(QueryPowerNumber());

  AddId( ({ "setas",
         }) );
  AddAdjective( ({ "con estrias",
                   "con estrias oscuras",
                   "algunas",
                   "rojizas",
               }) );

  SetShort("algunas setas rojizas con estrias oscuras");
  SetLong("Algunas setas rojizas con estrias oscuras con un olor a madera.\n");
  SetSmell("Huelen a madera reseca.\n");
}

