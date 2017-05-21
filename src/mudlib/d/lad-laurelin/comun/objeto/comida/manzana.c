#include "path.h"
#include <properties.h>
inherit FOOD;

create() {
  ::create();
  SetShort("una manzana");
  SetLong("Es una apetitosa manzana de color verde.\n");

  AddId("manzana");
  AddId("manzana verde");
  Set(P_GENDER, GENDER_FEMALE);
  SetFood(1);
  SetFoodStuff(5);
  SetWeight(150);
  SetValue(1);
}
