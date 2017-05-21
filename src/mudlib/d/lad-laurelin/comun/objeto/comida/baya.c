#include "path.h"
#include <properties.h>


inherit FOOD;

create() {
   ::create();
   SetFoodKind("food");
   SetFoodMsgs("Te comes una baya.\n");
   SetFoodStuff(10);
   SetFoodHeal(10);
   SetShort("una baya");
   SetLong("Es una baya grande que huele bien.\n");
   AddId("baya");
   AddId("comida");
   Set(P_GENDER,GENERO_FEMENINO);
   Set(P_NUMBER,NUMERO_SINGULAR);
   SetWeight(200);
   SetValue(30);
}
