
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
                   "de color marr�n claro",
                   "de color marron",
                   "de color marr�n",
                   "marron",
                   "marr�n",
               }) );

  SetShort("una gran seta de color marr�n claro");
  SetLong("Una gran seta de color marr�n claro.\n");
  SetSmell("No huele a nada especial.\n");
}


