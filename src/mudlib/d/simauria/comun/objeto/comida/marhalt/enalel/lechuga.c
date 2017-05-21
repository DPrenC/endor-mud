#include "path.h"
inherit "/std/food";

create(){
  ::create();
  
  SetFoodKind("food");
  SetFoodMsgs("Te comes una lechuga.\n");
  SetFoodStuff(14);
  SetFoodHeal(6);
  SetShort("una lechuga");
  SetLong("Es una fresca lechuga del huerto de Enalel\n");
  AddId("lechuga");
  AddId("comida");
  SetWeight(140);
  SetValue(25);
}
