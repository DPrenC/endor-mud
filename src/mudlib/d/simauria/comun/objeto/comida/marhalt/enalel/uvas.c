#include "path.h"
inherit "/std/food";

create(){
  ::create();
  
  SetFoodKind("food");
  SetFoodMsgs("Te comes un racimo de uvas.\n");
  SetFoodStuff(11);
  SetFoodHeal(6);
  SetShort("un racimo de uvas");
  SetLong("Es un apetitoso racimo de uvas verdes.\n");
  AddId("uva");
  AddId("uvas");
  AddId("racimo de uvas");
  AddId("racimo");
  AddId("comida");
  SetWeight(120);
  SetValue(35);
}
