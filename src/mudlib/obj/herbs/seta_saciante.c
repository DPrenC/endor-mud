
#include <herbs.h>

inherit HERB;

create() {
  ::create();

  SetType(HERB_TYPE_MUSHROOM);
  SetClass(HERB_CLASS_FOOD);
  SetPower(random(200));
  SetWeight(100);
  SetValue(QueryPowerNumber());

  AddId( ({
         }) );
  AddAdjective( ({ "gran",
                   "de color marron claro",
                   "de color marrón claro",
                   "de color marron",
                   "de color marrón",
                   "marron",
                   "marrón",
               }) );

  SetShort("una gran seta de color marrón claro");
  SetLong("Una gran seta de color marrón claro.\n");
  SetSmell("No huele a nada especial.\n");
}


