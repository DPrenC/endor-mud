#include "path.h"
inherit "/std/food";

create(){
  ::create();
  
  SetFoodKind("food");
  SetFoodMsgs("Te comes una jugosa manzana.\n");
  SetFoodStuff(15);
  SetFoodHeal(10);
  SetShort("una jugosa manzana de Enalel");
  SetLong("Es una jugosa manzana.\nTiene grabada en su base una marca de Enalel.\n");
  AddId("manzana");
  AddId("manzana de enalel");
  AddId("manzana de Enalel");
  AddId("comida");
  SetWeight(100);
  SetValue(20);
}
