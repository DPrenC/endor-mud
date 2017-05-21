
#include <herbs.h>

inherit HERB;

create() {
  ::create();

  SetType(HERB_TYPE_HERB);
  SetClass(HERB_CLASS_NORMAL);
  //SetPower(random(100));
  SetWeight(100);
  //SetValue(QueryPowerNumber());

  AddId( ({ "hierbas",
         }) );
  AddAdjective( ({ "normales",
              }) );

  SetShort("unas hierbas");
  SetLong("Unas hierbas normales y corrientes.\n");
  SetSmell("Huelen a humedad.\n");
}