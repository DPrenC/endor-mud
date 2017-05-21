
#include <herbs.h>

inherit HERB;

create() {
  ::create();

  SetType(HERB_TYPE_MUSHROOM);
  SetClass(HERB_CLASS_POISONOUS);
  SetPower(random(200));
  SetWeight(100);
  SetValue(QueryPowerNumber());

  AddId( ({ "setas",
         }) );
  AddAdjective( ({ "de color rojo",
                   "de color rojizo",
                   "rojizas",
                   "con motas blancas",
               }) );

  SetShort("algunas pequeñas setas de color rojizo con motas blancas");
  SetLong("Algunas pequeñas setas de color rojizo con motas blancas.\n");
  SetSmell("Estas setas tienen un olor un poco asqueroso.\n");
}


