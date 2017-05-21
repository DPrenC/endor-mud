#include "path.h"
inherit "/std/food";

create(){
  ::create();
  
  SetFoodKind("food");
  SetFoodMsgs("Te comes un pedazo de pan.\n");
  SetFoodStuff(20);
  SetFoodHeal(10);
  SetShort("un pedazo de pan");
  SetLong("Es un pedazo de pan claro.\nTiene grabado a fuego una gran E.\n");
  AddId("pan");
  AddId("pedazo de pan");
  AddId("pedazo");
  AddId("comida");
  SetWeight(70);
  SetValue(30);
}
